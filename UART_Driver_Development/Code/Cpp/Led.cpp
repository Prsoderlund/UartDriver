#include "LED.h" //Inkluderar header filen för att även denna fil skall känna till de olika LED-beteckningarna och funktioner

//Konstruktorn för LED-lamporna
Led::Led(LedColor_Type _color, LedState_Type _state)
{

  this->color = _color;
  this->state = _state;

  //Enablea klockan för LED-porten (GPIOB)
  RCC->AHB1ENR |= LED_PORT_CLOCK;

  //Konfigurera LED-pinsen baserad på deras färg och status
  // Rad 4-11 - refererar till instansen av klassen Led som håller på att skapas, och (->) används för att komma åt dess egenskaper. Egenskaperna color och state sätts till värdena av argumenten. Sammanfattningsvis sätter den här koden den initiala färgen och tillståndet för ett LED-objekt när det skapas
  switch(_color){

    case RED: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;
// rad 17-27 LED:ens aktuella tillstånd (state) för att avgöra om den ska vara på eller av. Om tillståndet är ON så används |= för att sätta LED_RED_PIN-pinnen i LED_PORT->ODR-registret för att slå på LED:en. Om tillståndet är OFF används istället &=. Detta gäller för all de olika färgerna och deras egna case.

      case YELLOW: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;

  }


}

void Led::setState(LedState_Type _state){

  //Sätta statusen av LED:n
  this->state = _state;
// rad 71-74 I funktionen sätts LED:ens state till värdet av det _state-argumentet med hjälp av this->state = _state;.
// -||- På så sätt kan LED:ens tillstånd ändras beroende på den instruktion som skickats via UART-kommunikationen

  //Kolla färgen på LED för att veta att korrekt LED manipuleras
  switch(this->color){

      //om LED Röd
    case RED:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;
// rad 82-94 För att sätta LED-porten till output, används |= för att ställa in LED_RED_MODE_BIT-biten i LED_PORT->MODER-registret. LED:ens tillstånd this->state kontrolleras därefter för att se om det är av eller på. Om tillståndet är ON, används (|=) för att kommunicera detta. Detta är ännu en gång relevant till alla de olike färgerna imon switch case:et.
      case YELLOW:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}

LedState_Type Led::getState(void)const{

  //Kontrollera färgen av den LED som efterfrågas, printa sedan statusen
  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
             //Returnerar LED-lampans status av vald färg
             return this->state;
}
// rad 141-159 Denna koden används för att hämta tillståndet av LED via uart kommunikationen inom en mikrokontroller. Inne i funktionen används switch satsen för att kontrollera färgen this->color på LED-komponenten. 