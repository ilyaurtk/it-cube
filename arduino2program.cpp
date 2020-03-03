#include <UTFT.h>
UTFT myGLCD(CTE32HR,25,26,27,28);
#include <UTouch.h>
UTouch myTouch(6,5,4,3,2);
void setup() {
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myTouch.InitTouch(PORTRAIT);
  myTouch.setPrecision(PREC_MEDIUM);
}
void loop() {
  long x, y;
  while (myTouch.dataAvailable() == true)  {
    myTouch.read();
    x = myTouch.getX();
    y = myTouch.getY();
    if ((x!=-1) and (y!=-1)) {
      myGLCD.drawPixel (x, y);
    }
  }
}