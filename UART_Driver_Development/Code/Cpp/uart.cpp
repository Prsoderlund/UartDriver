#include "UART.h" //Hämtar vår samlingsfil för headers och funktioner

void USART2_Init(void) { //Deklarerar en funktion för att initiera USART-protkokollet och dess beståndsdelar, 

// 1. Enablea klocktillgång för uart2

RCC->APB1ENR |= 0x20000; //Atkiverar UART2 genom att sätta bit 17 i APB1ENR till 1. // Denna är som AHB men för lowspeed utrustning medans AHB är för highspeed utrustning.


// 2. Enablea klocktillgång för portA

RCC->AHB1ENR |= 0x01; //Atkiverar GPIOA genom att sätta bit 0 i AHB1ENR till 1. //Reset and clock control, kontrollerar utrustingen genom att kontrollera alla dess klocksignaler. Man kan antingen enabla eller disaabla klocksignaler med denna
 
 
// 3. Enablea pins relaterade till vald port, för alternativ funktion
GPIOA->MODER &= ~0x00F0; //Rensar bitarna 4-7 för att förbereda pins PA2 och PA3 //moder används för att kontrollera pinsen på genral purpose input output. Dessa pins används för serial output.

  //& samt ~forcerar en invertering som leder till att bitarna som via hex betecknas med 1, i realvärde ersätts med 0

GPIOA->MODER |= 0x00A0; //Sätter bitarna 5 och 7 till 1 för att aktivera alternativ funktionalitet på pins PA2 och PA3

// 4. Välja typen av alternativ funktion för de valde pinsen
GPIOA->AFR[0] &= ~0xFF00; //Rensar bitarna 8-15 för att förbereda pins PA2 och PA3 // Efter att man användt moder för att kontrollera pinsen så används afr för att konfiguera och ändra /registrera för att assigna uart utrustningen till de pinsen.
GPIOA->AFR[0] |= 0x7700; //Sätter vi bitarna 8-11 samt 12-15 till formatet 0111

/* Konstruktion av enhetens kommunikation avslutas */

// Konfiguration utav UART

USART2->BRR = 0x0683; //Sätter vi standard baud-rate med hjälp av hexadecimalen 0x0683 (9600bps) //denna används för att välja baudrate på usart. 

USART2->CR1 = 0x000C; //Sätter vi tx och rx till att arbeta i 8 bitars data. (8 bitars data, 1 stop bit, ingen paritet) //16 bitars register som används för att usart2 utrustningen, det finns flera olika kontroll delar inom cr1. Transmitter är det ända som är enablad i detta fall

USART2->CR2 = 0x000; //Nollställer CR2 //Denna 16 bitars register används för exempelvis stop bits,clock enable, clock polarity och clock phase man kan alltså sätta värdet eller ta bort lämpligt värde med detta register. ALLA dessa funtioner är på 0 och är därmed disabled.

USART2->CR3 = 0x000; //Nollställer CR3 //med detta 16 bitars kontroll register så kan man exempelvis kontrollera Error interupt enable eller exempelvis DMAR Dessa används för att genreara en bit vid avbrott medans dmar är använd för att enabla direct memory access. ALLA dessa funtioner är på 0 och är därmed disabled.

USART2->CR1 |= 0x2000; //Omställer bit 13 (UART-Aktiveringen) till 1

}
// UART Write
int USART2_write(int ch){ //Deklarerar skrivfunktionen (Överföringen av data till terminalen)

  while(!(USART2->SR & 0x0080)){} //Sätter vi ett krav som kontrollerar att statusen på överföringen är tom och kan ta emot nästa karaktär (byte) // väntar tills usart2 är 0, fortsätter kolla tills utrustingen är redo att skicka nästa karaktär.
	
  USART2->DR = (ch & 0xFF); //Sätter överföringen av byten till dataregistret //0xFF för att säkerställa att endast den minst signifikanta byten av tecknet skickas. Detta beror på att DR registret är ett 8-bitars register som bara kan innehålla en byte med data.


  return ch;

}
// UART Read
int USART2_read(void){ //Deklarerar läsfunktionen (mottagning av information)

  while(!(USART2->SR & 0x0020)){} //Sätter vi ett krav som kontrollerar om det finns mer data att hämta //väntar tills den har en karaktär som har tagits imot av usart2
	
  return USART2->DR; //Läser ut datan //returnerar den mottagna karaktären

} 