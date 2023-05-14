#include "led.h"

LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

Led led1(RED,ON);

int main(void){ //huvudfunktion konstruerar och hanterar LED-lamporna
  USART2_Init();

  Led led2(BLUE,ON);

  Led *led3 = new Led(YELLOW,ON);

  led1_state = led1.getState();

  led1.setState(OFF);

  delete led3;

  while(1){}

}

//#include "led.h" inkluderar led.h-filen som innehåller klassen för LED-lampor.

//LedState_Type1-3 deklarerar 3 variabler av typen LedState_Type
// rad 6 initierar röd färg med tillståd ON
//rad 12-14 initierar med färgerna blue och yellow med ON som tillstånd
//rad 16 Hämtar Led1's tillstånd 
//rad 18 denna ställer in OFF tillståndet
// 20 frigör minnet som tilldelades led3
