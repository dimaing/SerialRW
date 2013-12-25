#include <SerialRW.h>

int x=0,y=0,z=0;
int delayTime=10000;
void setup(){
  SerialRW::begin(9600); //configure Serial
}
void loop(){
  non_blocking_scanf();
  delay(delayTime);
}
/*
Do not block execution if no Serial input
 */
void non_blocking_scanf(){
  if(Serial.available()){
    scanf ("%i %i %i",&x,&y,&z); //blocks execution until all expected values entered (3 integers in this case)
    printf("You entered: %i, %i, %i \n", x, y, z);
  }
  else
    printf("Nothing entered, are you ignoring me? Will wait for %d sec \n", delayTime/1000);  


}

