#include "Boardoza_BA6208.h"

uint8_t pwmPin = 4; 
uint8_t pwmChannel = 0; 
uint16_t pwmFrequency = 10000; 
uint8_t pwmResolution = 8; 

Boardoza_BA6208 motordriver(pwmPin, pwmChannel, pwmFrequency, pwmResolution);

void setup() {
 // Boardoza_BA6208(4, 0, 1000, 8); // 4.Pin, Channel 0, 1 kHz Frequency, 8 bit resolution
  motordriver.begin();
}

void loop() {
    /* dutyCycle = 64 = %25
    dutyCycle = 127 = %50
    dutyCycle = 191 = %75
    dutyCycle = 255 = %100
    */ 
  motordriver.setHardwarePWM(64);

  motordriver.turnForward();

  motordriver.turnReverse();

  motordriver.brake();

  motordriver.setSoftwarePWM(30, 100, FORWARD);
}
