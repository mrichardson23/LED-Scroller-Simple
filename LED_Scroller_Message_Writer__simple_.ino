/*
  Commands for Alpha Sign Communication Protocol
  
  This basic function shows how to write text to
  LED scrolling signs with an Arduino using the 
  Alpha Sign Communication Protocol.
  
  Full guide to come.
  
  By Matt Richardson
  http://mattrichardson.com/
*/ 
byte NUL = 0x00;
byte START_HEADER = 0x01;
byte START_TEXT = 0x02;
byte END_TRANSMISSION = 0x04;
byte ESC = 0x1B;
byte FILL = 0x30;
byte ROTATE = 0x61;
byte SLOW = 0x15;
byte FAST = 0x19;
byte TIME = 0x13;
byte CALL_STRING = 0x10;
byte CALL_SIZE = 0x1A;
byte SIZE_LARGE = 0x33;
byte SIZE_SMALL = 0x31;

void setup() {
  Serial.begin(9600);
  writeText("If you can read this, you've got it working!");
}

void loop() {
  
  
}

void writeText(String text) {
  Serial.write(NUL); // Start frame sync chars
  Serial.write(NUL);
  Serial.write(NUL);
  Serial.write(NUL);
  Serial.write(NUL); // end frame sync chars
  Serial.write(START_HEADER); // start of header
  Serial.write("Z00"); // all sign types, all addresses
  Serial.write(START_TEXT); //start of text
  Serial.write("AA"); // write command, text file A
  Serial.write(ESC);
  Serial.write(FILL);
  Serial.write(ROTATE);
  Serial.print(text);
  Serial.write(END_TRANSMISSION);
}
