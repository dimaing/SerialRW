/*
  SerialRW.h - Library for C style Serial IO.
  Created by Dmitry INgerman, December 23 2013.
  Released into the public domain.
*/
#ifndef SerialRW_h
#define SerialRW_h

#include "Arduino.h"

class SerialRW
{
  public:
  /*

  */
    static void begin(double speed);
  private:
	SerialRW();
    static FILE serial_stdout;
    static FILE serial_stdin; 
	static int serial_getchar(FILE* f);
	static int serial_putchar(char c, FILE* f) ;
};

#endif