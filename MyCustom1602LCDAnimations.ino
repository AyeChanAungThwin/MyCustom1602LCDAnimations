#include "LCDAnimation.h"

int count=0;

void setup() {
  // put your setup code here, to run once:
  LCDAnimation lcd;

  /*
  while(true) {
    lcd.getWaterTankAnimation().setFull(); //full
    //lcd.getWaterTankAnimation().setHalf(); //half
    //lcd.getWaterTankAnimation().setEmpty(); //empty
    //lcd.getWaterTankAnimation().setFilling(false); //empty and filling
    //lcd.getWaterTankAnimation().setFilling(true); //half and filling
  }
  */
  
  
  callAll(lcd);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void callAll(LCDAnimation lcd) {
  while(true) {
    if (count<50) {
      lcd.getWaterTankAnimation().setFull(); //full
    }
    else if (count>=50 && count<100) {
      lcd.getWaterTankAnimation().setHalf(); //half
    }
    else if (count>=100 && count<150) {
      lcd.getWaterTankAnimation().setEmpty(); //empty
    }
    else if (count>=150 && count<200) {
      lcd.getWaterTankAnimation().setFilling(false); //empty and filling
    }
    else if (count>=200 && count<250) {
      lcd.getWaterTankAnimation().setFilling(true); //half and filling
    }
    count++;
    if (count>=250) {
      count=0;
    }
  }
}

    //lcd.getWaterTankAnimation().setFull(); //full
    //lcd.getWaterTankAnimation().setHalf(); //half
    //lcd.getWaterTankAnimation().setEmpty(); //empty
    //lcd.getWaterTankAnimation().setFilling(false); //empty and filling
    //lcd.getWaterTankAnimation().setFilling(true); //half and filling
