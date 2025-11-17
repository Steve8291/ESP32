/*
 * Usees an int array to store several 8 bit binary numbers that are used to 
 * change the working state of the eight LEDs controlled by 74HC595.
 * https://docs.sunfounder.com/projects/esp32-starter-kit/en/latest/arduino/basic_projects/ar_74hc595.html
*/

#include <Arduino.h>

const int STcp = 22;//ST_CP
const int SHcp = 23;//SH_CP 
const int DS = 21; //DS 

int datArray[] = {B00000000, B00000001, B00000011, B00000111, B00001111, B00011111, B00111111, B01111111, B11111111};

void setup ()
{
  //set pins to output
  pinMode(STcp,OUTPUT);
  pinMode(SHcp,OUTPUT);
  pinMode(DS,OUTPUT);
}
void loop()
{
  for(int num = 0; num < 9; ++num)
  {
    digitalWrite(STcp,LOW); //ground ST_CP and hold low for as long as you are transmitting
    shiftOut(DS,SHcp,MSBFIRST,datArray[num]);
    digitalWrite(STcp,HIGH); //pull the ST_CPST_CP to save the data
    delay(1000);
  }
}
