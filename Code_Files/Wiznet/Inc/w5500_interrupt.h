/*
 * w5500_interrupt.h
 *
 *  Created on: May 26, 2025
 *      Author: User
 */

#ifndef INC_W5500_INTERRUPT_H_
#define INC_W5500_INTERRUPT_H_

#include "main.h"
#include "socket.h"
#include "w5500.h"
#include "w5500_spi.h"

#define MAX_SOCK_NUM 8

extern uint8_t sn;

typedef struct {
    uint8_t socket;
    uint8_t connected;
    uint8_t disconnected;
    uint8_t received;
    uint8_t timeout;
    uint8_t sent;
} W5500_EventFlags;

extern W5500_EventFlags w5500_event_flags[];

typedef enum {
	SOCK_STATUS_CLOSED      = 0x00,
	SOCK_STATUS_INIT        = 0x13,
	SOCK_STATUS_LISTEN      = 0x14,
	SOCK_STATUS_ESTABLISHED = 0x17,
	SOCK_STATUS_CLOSE_WAIT  = 0x1C,
	SOCK_STATUS_FIN_WAIT    = 0x18,
	SOCK_STATUS_TIME_WAIT   = 0x1B,
	SOCK_STATUS_ERROR       = 0xFF
} sock_state_t;

extern sock_state_t sock_status[MAX_SOCK_NUM];

//void process_received_command(uint8_t sn, const char *buffer);
void W5500_Init_Sockets(void);
void W5500_Close_Socket(void);
void W5500_Enable_Interrupts(void);
void W5500_InterruptHandler(void);
void W5500_Handle_Events(void);
void handle_connection(uint8_t sn);
void handle_received(uint8_t sn);
void handle_sent(uint8_t sn);
void handle_disconnection(uint8_t sn);
void handle_timeout(uint8_t sn);
int8_t SendToSocket(uint8_t sn, const char *msg);


#endif /* INC_W5500_INTERRUPT_H_ */
