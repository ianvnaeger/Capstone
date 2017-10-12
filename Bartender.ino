// select the input pin for the potentiometer
// select the pin for the LED
// variable to store the value coming from the sensor
int btn1 = 0, btn2 = 0, btn3 = 0, btn4 = 0;
char bluetooth = 'E';
int btn1Pin = 11; 
int btn2Pin = 12; 
int btn3Pin = 13; 
int btn4Pin = 14; 
int bluetoothPin = 15;
int Drink1Pin = 16;
int Drink2Pin = 17;
int Mixer1Pin = 18;
int Mixer2Pin = 19;
int Mixer3Pin = 20;

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
    DigitalWrite( Drink1Pin, HIGH);
    delay(100);
    DigitalWrite(Drink1Pin, LOW);
  }
  if( Drink2 == 1) {
    DigitalWrite( Drink2Pin, HIGH);
    delay(100);
    DigitalWrite(Drink2Pin, LOW);
  }
  if( Mixer1 == 1 ) {
    DigitalWrite( Mixer1Pin, HIGH);
    delay(300);
    DigitalWrite( Mixer1Pin, LOW);
  }
  if( Mixer2 == 1 ) {
    DigitalWrite( Mixer2Pin, HIGH);
    delay(300);
    DigitalWrite( Mixer2Pin, LOW);
  }
  if( Mixer3 == 1 ) {
    DigitalWrite( Mixer2Pin, HIGH);
    delay(300);
    DigitalWrite( Mixer2Pin, LOW);
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
  pinMode(bluetoothPin, INPUT);
  Serial.begin(9600);
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
  bluetooth = digitalRead(bluetoothPin);
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
    A.MakeDrink();
  }
  else if( bluetooth == 'B'){
    //selection = B;
    B.MakeDrink();
  }
  else if( bluetooth == 'C'){
    //selection = C;
    C.MakeDrink();
  }
  else if( bluetooth == 'D'){
    //selection = D;
    D.MakeDrink();
  }

  //Serial.println(sensorValue, DEC);
}