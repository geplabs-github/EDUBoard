/*
  EDU Board - Potentiometer tutorial
  Updated 22.8.2019
  Reads analog value from the input A6,
  where the slider of the potentiometer is connected
  and turns on the LED according to the angle of rotation.
  ------------------------------------
  Updated By Jiří Povolný (www.geplabs.com)
*/

//Constants
const int P_POT = A6;        //Potentiometer on the input A6 (analog input)

const int LPIN_1 = 4;       
const int LPIN_2 = 5;       
const int LPIN_3 = 6;

//Proměnné (variables)
int value;                  //The variable to store value from the input

void setup(){
  //Setting the pins where LEDs are connected as output.
  pinMode(LPIN_1, OUTPUT);  
  pinMode(LPIN_2, OUTPUT);  
  pinMode(LPIN_3, OUTPUT);  
}

void loop(){
  value = analogRead(P_POT);       //Read analog value from A6 pin

  //If the value is less than 300, the LED 1 lights up, the others turn off
  if (value < 300){                
    digitalWrite(LPIN_1, HIGH);  
    digitalWrite(LPIN_2, LOW);
    digitalWrite(LPIN_3, LOW);
  }
  //If the value is between 300 and 700, the LED 2 lights up, the others turn off
  else if(value <= 700 && value >= 300) {
    digitalWrite(LPIN_1, LOW);  
    digitalWrite(LPIN_2, HIGH);
    digitalWrite(LPIN_3, LOW);
  }
  //If the value is greater than 700, the LED 3 lights up, the others turn off
  else if(value > 700) {
    digitalWrite(LPIN_1, LOW);  
    digitalWrite(LPIN_2, LOW);
    digitalWrite(LPIN_3, HIGH);
  }

  delay(100);                     //Wait 100ms
}
