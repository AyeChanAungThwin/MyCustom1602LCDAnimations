# MyCustom1602LCDAnimations (JFX)

## How it looks like
<iframe width="436" height="256" src="videos/water-level-controller-lcd.mp4" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen>

## Abstract
> You need Arduino and 1604 LCD display.
> Call ```LCDAnimation.h``` and call its function for animation.

## How to test
- Open command or terminal.
- Type ```git clone https://github.com/AyeChanAungThwin/MyCustom1602LCDAnimations``` and press enter.

## About
- [ ] Arduino
- [ ] 1604 LCD display
- [X] LCDAnimation.h Library

## How to use animation
- call LCDAnimation in setup function.
```
	#include "LCDAnimation.h"

	void setup() {
  	// put your setup code here, to run once:
  		LCDAnimation lcd;
  	}
```
- Note that we must use any ONE of them in a loop function concerning your usage. Or else your animation will be messed up!
```
	void loop() {
		lcd.getWaterTankAnimation().setFull(); //full
    	//lcd.getWaterTankAnimation().setHalf(); //half
    	//lcd.getWaterTankAnimation().setEmpty(); //empty
    	//lcd.getWaterTankAnimation().setFilling(false); //empty and filling
    	//lcd.getWaterTankAnimation().setFilling(true); //half and filling
	}

```


## Electronics Engineer-cum-J2EE Backend Developer ##
-  Created by - Aye Chan Aung Thwin