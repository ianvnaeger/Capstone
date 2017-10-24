#include <SoftwareSerial.h>

// select the input pin for the potentiometer
// select the pin for the LED
// variable to store the value coming from the sensor
#include <Arduino.h>
int btn1 = 0, btn2 = 0, btn3 = 0, btn4 = 0;
char bluetooth = 'E';
int btn1Pin = 2; 
int btn2Pin = 3; 
int btn3Pin = 4; 
int btn4Pin = 5; 
//int bluetoothPin = 6;
int Drink1Pin = 7;
int Drink2Pin = 8;
int Mixer1Pin = 9;
int Mixer2Pin = 10;
int Mixer3Pin = 11;

class DrinkProfile{
  public:
    int Mixer1;
    int Mixer2;
    int Mixer3;
    int Drink1;
    int Drink2;
    void MakeDrink();
};

void DrinkProfile::MakeDrink() {
  if( Drink1 == 1) {
    digitalWrite( Drink1Pin, HIGH);
    delay(500);
    digitalWrite(Drink1Pin, LOW);
  }
  if( Drink2 == 1) {
    digitalWrite( Drink2Pin, HIGH);
    delay(500);
    digitalWrite(Drink2Pin, LOW);
  }
  if( Mixer1 == 1 ) {
    digitalWrite( Mixer1Pin, HIGH);
    delay(1500);
    digitalWrite( Mixer1Pin, LOW);
  }
  if( Mixer2 == 1 ) {
    digitalWrite( Mixer2Pin, HIGH);
    delay(1500);
    digitalWrite( Mixer2Pin, LOW);
  }
  if( Mixer3 == 1 ) {
    digitalWrite( Mixer3Pin, HIGH);
    delay(1500);
    digitalWrite( Mixer3Pin, LOW);
  }
}

DrinkProfile A, B, C, D;

void setup() {
  A.Drink1 = 1;
  A.Mixer1 = 1;
  B.Drink2 = 1;
  B.Mixer2 = 1;
  C.Drink1 = 1;
  C.Mixer2 = 1;
  C.Mixer3 = 1;
  D.Drink2 = 1;
  D.Mixer3 = 1;
  pinMode(Drink1Pin, OUTPUT);
  pinMode(Drink2Pin, OUTPUT);
  pinMode(Mixer1Pin, OUTPUT);
  pinMode(Mixer2Pin, OUTPUT);
  pinMode(Mixer3Pin, OUTPUT);
  pinMode(btn1Pin, INPUT);
  pinMode(btn2Pin, INPUT);
  pinMode(btn3Pin, INPUT);
  pinMode(btn4Pin, INPUT);
  //pinMode(bluetoothPin, INPUT);
  Serial.begin(38400);
}

void loop() {
  //DrinkProfile selection;
  //signal = recieve_instruct()
  //if( btn1 == 1 ){
  //selection = profile1
  //}
  //else if.....
  //makedrink(selection)
  btn1 = digitalRead( btn1Pin );
  btn2 = digitalRead( btn2Pin );
  btn3 = digitalRead( btn3Pin );
  btn4 = digitalRead( btn4Pin );
  bluetooth = Serial.read();
  if( btn1 == 1 ){
    //selection = A;
    
    A.MakeDrink();
  }
  else if( btn2 == 1 ){
    //selection = B;
    B.MakeDrink();
  }
  else if( btn3 == 1 ){
    //selection = C;
    C.MakeDrink();
  }
  else if( btn4 == 1 ){
    //selection = D;
    D.MakeDrink();
  }
  else if( bluetooth == 'A'){
    //selection = A;
    Serial.println("Drink 1 Selected");
    A.MakeDrink();
    bluetooth = 'E';
  }
  else if( bluetooth == 'B'){
    //selection = B;
    Serial.println("Drink 2 Selected");
    B.MakeDrink();
    bluetooth = 'E';
  }
  else if( bluetooth == 'C'){
    //selection = C;
    Serial.println("Drink 3 Selected");
    C.MakeDrink();
    bluetooth = 'E';
  }
  else if( bluetooth == 'D'){
    //selection = D;
    Serial.println("Drink 4 Selected");
    D.MakeDrink();
    bluetooth = 'E';
  }

  //Serial.println(sensorValue, DEC);
}
