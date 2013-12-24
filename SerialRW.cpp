/*
  SerialRW.h - Library for C style Serial IO.
  Created by Dmitry INgerman, December 23 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SerialRW.h"

FILE SerialRW::serial_stdout;
FILE SerialRW::serial_stdin; 

SerialRW::SerialRW(){}

int SerialRW::serial_putchar(char c, FILE* f) {
  if (c == '\n') serial_putchar('\r', f);
  return Serial.write(c) == 1? 0 : 1;
}

int SerialRW::serial_getchar(FILE* f){
  while(!Serial.available()){}
  return Serial.read();  
}

void SerialRW::begin(int speed){
  Serial.begin(speed);
  // Set up stdout
  fdev_setup_stream( &serial_stdout, serial_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &serial_stdout;

  // Set up stdin
  fdev_setup_stream(&serial_stdin, NULL, serial_getchar, _FDEV_SETUP_READ);
  stdin = &serial_stdin;
}







