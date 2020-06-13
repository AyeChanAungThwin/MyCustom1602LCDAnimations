#include "WaterTank.h"

class LCDAnimation {

  private:
    WaterTank wt;
    
  public:
    LCDAnimation() {
      screen.begin();
      screen.backlight();
    }
    ~LCDAnimation() {
      
    }
    void clearScreen() {
      screen.clear();
    }
    WaterTank getWaterTankAnimation() {
      return wt;
    }
    void setText(String first, String second, int cur1, int cur2) {
      screen.setCursor(cur1, 0);
      screen.print(first);
      screen.setCursor(cur2, 1);
      screen.print(second);
      delay(3000);
    }
};
