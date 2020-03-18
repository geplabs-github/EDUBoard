/*
  EDU Board - PWM tutorial
  Updated 30.7.2019
  It changes the light intensity of the LED, gradually turns it on and off.
  ----------------------------------------
  Updated By  Jiří Povolný (www.geplabs.com)

*/

//Constants
const int LED_PIN = 6;       //Pin number where LED is connected

//Variables
int cnt;                     //Variable to store a value in the FOR cycle

void setup() {
  pinMode(LED_PIN, OUTPUT);  //Set pin as output
}

void loop() {
  //The LED lights up gradually
  for(cnt = 0; cnt <= 255; cnt++){
    analogWrite(LED_PIN, cnt);
    delay(5);
  }
  
  //The LED goes off gradually
  for(cnt = 255; cnt >= 0; cnt--){
    analogWrite(LED_PIN, cnt);
    delay(5);
  }
}
