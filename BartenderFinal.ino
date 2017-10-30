#include <SoftwareSerial.h>
#include <Arduino.h>
// select the input pin for the potentiometer
// select the pin for the LED
// variable to store the value coming from the sensor

#define rxPin 0
#define txPin 1

int btn1 = 0, btn2 = 0, btn3 = 0, btn4 = 0;int rxd = 1;


int btn1Pin = 8; 
int btn2Pin = 9; 
int btn3Pin = 10; 
int btn4Pin = 11; 

int Drink1Pin = 2;
int Drink2Pin = 3;
int Mixer1Pin = 4;
int Mixer2Pin = 5;
int Mixer3Pin = 6;

//Set up a new serial object
//SoftwareSerial bluetoothSerial = SoftwareSerial( rxPin,txPin);

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

  //Define pin modes for tx,rx
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  //Set the Baud rate for the serial port
  Serial.begin(38400);
  
}


void loop() {
  
  btn1 = digitalRead( btn1Pin );
  btn2 = digitalRead( btn2Pin );
  btn3 = digitalRead( btn3Pin );
  btn4 = digitalRead( btn4Pin );
  rxd = digitalRead(rxPin);
  
 


  
  if( btn1 == 1 ){
    //selection = A;
    Serial.println("Button: Drink 1 Selected");
    A.MakeDrink();
  }
  else if( btn2 == 1 ){
    //selection = B;
    Serial.println("Button: Drink 2 Selected");
    B.MakeDrink();
  }
  else if( btn3 == 1 ){
    //selection = C;
    Serial.println("Button: Drink 3 Selected");
    C.MakeDrink();
  }
  else if( btn4 == 1 ){
    //selection = D;
    Serial.println("Button: Drink 4 Selected");
    D.MakeDrink();
  }
  else if( rxd == 0){
    //selection = A;
    Serial.println("Drink Ordered");
    A.MakeDrink();
    
  }

  
}
