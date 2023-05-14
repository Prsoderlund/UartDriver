#ifndef __UART_H
#define __UART_H

#include "stm32f4xx.h" //Hämtar källkoden och hänvisningar för arbete på STM-Hårdvara
#include <stdio.h> //Inkluderar standard I/O för C

void USART2_Init(void); // Kallar på och refererar till deklarationen av vår UART-funktion
void test_setup(void); //Kallar på och refererar till vår testfunktion ur UART.c
#endif //Förtydligar avslutningen av vår headerfil


//Detta är en headerfil för en UART-implementering på en STM32F4-mikrokontroller. Det inkluderar STM32F4xx.h som innehåller deklarationer och stdio.h för standard in och output. Det definierar också två funktioner: USART2_Init(), som initierar UART2-kommunikationen