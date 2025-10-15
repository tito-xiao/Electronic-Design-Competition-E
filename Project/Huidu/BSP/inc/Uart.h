#ifndef _Uart_H
#define _Uart_H

#include "board.h"

void uart0_send_char(char ch); //串口0发送单个字符
void uart0_send_string(char* str); //串口0发送字符串


#endif