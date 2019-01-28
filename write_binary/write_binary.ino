#include <SPI.h>

// define max7219 registers
const byte max7219_reg_noop        = 0x00;
const byte max7219_reg_digit0      = 0x01;
const byte max7219_reg_digit1      = 0x02;
const byte max7219_reg_digit2      = 0x03;
const byte max7219_reg_digit3      = 0x04;
const byte max7219_reg_digit4      = 0x05;
const byte max7219_reg_digit5      = 0x06;
const byte max7219_reg_digit6      = 0x07;
const byte max7219_reg_digit7      = 0x08;
const byte max7219_reg_decodeMode  = 0x09;
const byte max7219_reg_intensity   = 0x0a;
const byte max7219_reg_scanLimit   = 0x0b;
const byte max7219_reg_shutdown    = 0x0c;
const byte max7219_reg_displayTest = 0x0f;

const int loadPin = 10;

// sendByte function from Nick Gammon
void sendByte (const byte reg, const byte data)
  {    
  digitalWrite (loadPin, LOW);
  SPI.transfer (reg);
  SPI.transfer (data);
  digitalWrite (loadPin, HIGH); 
  }  // end of sendByte

void setup(){

  SPI.begin ();
    
  sendByte (max7219_reg_scanLimit, 7);   // show all 8 digits
  sendByte (max7219_reg_decodeMode, 0);  // using an led matrix (not digits)
  sendByte (max7219_reg_displayTest, 0); // no display test
  
  // clear display
  for (byte col = 0; col < 8; col++)
    sendByte (col + 1, 0);

  sendByte (max7219_reg_intensity, 7);  // character intensity: range: 0 to 15
  sendByte (max7219_reg_shutdown, 1);   // not in shutdown mode (ie. start it up)
  
}

byte board[8] = {B00000001, B0000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};

void loop() {

  for (int i = 0; i < 8; i++) {
    sendByte(i + 1, board[i]);
    delay(1000);
  }

}
