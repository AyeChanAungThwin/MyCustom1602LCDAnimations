#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C screen = LiquidCrystal_I2C(0x3F, 16, 2);

#include "WaterDropWaterTank.h"
#include "WaterWaveWaterTank.h"

byte emptyChar[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte tankUpEmpty1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B10000,
  B10000,
  B10000,
  B10000
};
    
byte tankUpEmpty2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
    
byte tankUpEmpty3[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00001,
  B00001,
  B00001,
  B00001
};

byte tankDownEmpty1[8] = {
  B10000,
  B10000,
  B10000,
  B01000,
  B01000,
  B00100,
  B00100,
  B00011
};
    
byte tankDownEmpty2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte tankDownEmpty3[8] = {
  B00001,
  B00001,
  B00001,
  B00010,
  B00010,
  B00100,
  B00100,
  B11000
};

class WaterTank {
  
  private:

    WaterDrops waterDrop;
    WaterWaves waterWave;

    void showOnLCD(int charPosition, byte customChar[], int cur1, int cur2) {
      screen.createChar(charPosition, customChar);
      //screen.home();
      screen.setCursor(cur1, cur2);
      screen.write(charPosition);
    }

    void emptyTopNeglect2nd(boolean isFilling) {
      showOnLCD(1, tankUpEmpty1, 1, 0);
      if (!isFilling) {
        showOnLCD(2, tankUpEmpty2, 2, 0);
      }
      showOnLCD(3, tankUpEmpty3, 3, 0);
    }

    void fullWater() {
      waterWave.createFullWaterAnimation();
      showOnLCD(1, waterWave.animation1, 1, 0);
      showOnLCD(2, waterWave.animation2, 2, 0);
      showOnLCD(3, waterWave.animation3, 3, 0);
    }

    void halfWater() {
      waterWave.createHalfWaterAnimation();
      showOnLCD(4, waterWave.animation1, 1, 1);
      showOnLCD(5, waterWave.animation2, 2, 1);
      showOnLCD(6, waterWave.animation3, 3, 1);
    }

    void emptyWater() {
      waterWave.createLowWaterAnimation();
      showOnLCD(4, waterWave.animation1, 1, 1);
      showOnLCD(5, waterWave.animation2, 2, 1);
      showOnLCD(6, waterWave.animation3, 3, 1);
    }

    void emptyBottom() {
      showOnLCD(4, tankDownEmpty1, 1, 1);
      showOnLCD(5, tankDownEmpty2, 2, 1);
      showOnLCD(6, tankDownEmpty3, 3, 1);
    }

    void printText(String first, String second) {
      screen.setCursor(4, 0);
      screen.print(first);
      screen.setCursor(4, 1);
      screen.print(second);
    }

  public:
    WaterTank() {
      screen.begin();
      screen.backlight();
    }
    ~WaterTank() {
      
    }
    void clearScreen() {
      screen.clear();
    }
    void setFull() {
      fullWater(); //1
      emptyBottom(); //2
      printText(" Full water ", " in tank    ");
      delay(50);
    }
    void setHalf() {
      emptyTopNeglect2nd(0);//1
      halfWater();//2
      printText(" Half water ", " in tank    ");
      delay(50);
    }
    void setEmpty() {
      emptyTopNeglect2nd(0);//1
      emptyWater();//2
      printText(" Low water  ", " in tank    ");
      delay(50);
    }
    void setFilling(boolean isHalf) {
      emptyTopNeglect2nd(1);//1
      
      waterDrop.createWaterDropAnimation();
      showOnLCD(2, waterDrop.animation, 2, 0);//1Mid

      if (isHalf) {
        halfWater();//2
      }
      else {
        emptyWater();//2
      }
      printText(" water pump ", " has started");
      delay(50);
    }
};
