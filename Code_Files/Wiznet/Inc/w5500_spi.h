
#ifndef INC_W5500_SPI_H_
#define INC_W5500_SPI_H_

#include "main.h"



extern SPI_HandleTypeDef *spi_handle;

#define MAX_SOCK_NUM 8

void W5500Init(void);
void W5500_Enable_Interrupts(void);
void W5500_Init_Sockets(void);

#endif /* INC_W5500_SPI_H_ */
