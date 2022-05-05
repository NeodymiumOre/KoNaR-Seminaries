#include <Arduino.h>

#define LED_PIN 9

int x;
int pwm_val = 0;

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(1);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0)
  {
    x = Serial.readString().toInt();
    //x = Serial.read();
    pwm_val = map(x, 0, 100, 0, 255);
    analogWrite(LED_PIN, pwm_val);
    //Serial.print("Ustawilem PWM na ");
    Serial.print(pwm_val);
  }
}