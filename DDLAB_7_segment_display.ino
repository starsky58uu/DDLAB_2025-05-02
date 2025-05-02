byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                             };

const int buttonPin = 12;
int buttonState = 0;
int num = 0;
byte pin_num[7] = {2,3,4,5,6,7,8};

void setup() {   
  for(byte pin = 0;pin < 7;pin++){
    pinMode(pin_num[pin],OUTPUT);
  }         
  
  digitalWrite(9, 0);  // 關閉小數點
  digitalWrite(buttonPin,HIGH);
  pinMode(buttonPin,INPUT);
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte seg = 0; seg < 7; seg++) {
    digitalWrite(pin, 1 - seven_seg_digits[digit][seg]);
    ++pin;
  }
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == LOW){
     num ++;
    if(num > 9){
       num = 0;
    }
}
  sevenSegWrite(num); 
 delay(1000);

}
