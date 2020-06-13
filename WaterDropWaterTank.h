#include <ArxContainer.h>

byte waterDrop1[8] = {
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
    
byte waterDrop2[8] = {
  B00100,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
    
byte waterDrop3[8] = {
  B00000,
  B00100,
  B00100,
  B01010,
  B01010,
  B00100,
  B00000,
  B00000
};
    
byte waterDrop4[8] = {
  B00000,
  B00000,
  B00100,
  B00100,
  B01010,
  B10001,
  B10001,
  B01110
};
    
byte waterDrop5[8] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B00100,
  B11011,
  B10001,
  B01110
};
    
byte waterDrop6[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00100,
  B10101,
  B11011,
  B01110
};
    
byte waterDrop7[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B01010,
  B10101,
  B00100,
  B00100
};
    
byte waterDrop8[8] = {
  B00000,
  B00000,
  B00000,
  B10001,
  B01010,
  B10001,
  B00000,
  B00000
};
    
byte waterDrop9[8] = {
  B00000,
  B00000, 
  B00000,
  B00000,
  B10001,
  B00000,
  B00000,
  B00000
};
    
byte waterDrop10[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

int waterDropIndex=0;

class WaterDrops {
  
  private:
    int frames = 10;

    byte * getPreparedWaterDrops() {
      switch(waterDropIndex++) {
        case 0:
          return waterDrop1;
        case 1:
          return waterDrop2;
        case 2:
          return waterDrop3;
        case 3:
          return waterDrop4;
        case 4:
          return waterDrop5;
        case 5:
          return waterDrop6;
        case 6:
          return waterDrop7;
        case 7:
          return waterDrop8;
        case 8:
          return waterDrop9;
        case 9:
          reset();
          return waterDrop10;
        default:
          reset();
          return 0;
      }
    }

    void reset() {
      if (waterDropIndex>=frames) {
        waterDropIndex=0;
      }
    }
  
  public:
    WaterDrops() {
      
    }
    
    ~WaterDrops() {
      
    }

    byte animation[8]; //call for animation;
    
    void createWaterDropAnimation() {
      byte *temp = getPreparedWaterDrops();
      for (int i=0; i<8; i++) {
        animation[i]=temp[i];
      }
    }
};
