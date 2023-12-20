---
icon: material/tools
---

## Basic Assembly

The fastest way to get up and running with the LTE Stick is by connecting it to a computer through the USB-C connector and then using u-blox's mcenter software. 

## Soldered Assembly

??? note "New to soldering?"
	If you have never soldered before or need a quick refresher, check out our [How to Solder: Through-Hole Soldering](https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering) guide.
	<p align="center">
		<a href="https://learn.sparkfun.com/tutorials/5">
		<img src="https://cdn.sparkfun.com/c/264-148/assets/e/3/9/9/4/51d9fbe1ce395f7a2a000000.jpg" alt="Tutorial's thumbnail"><br>
        How to Solder: Through-Hole Soldering</a>
	</p>

We specifically designed this board to fit on a breadboard with headers soldered to it for easy prototype circuit building with the LARA-R6. This assembly is strongly recommended for those who wish to use the LTE Stick with the SparkFun u-blox Cellular Library to make connections between the LTE Stick, microcontroller, and other hardware (where necessary).

!!! note
    This assembly assumes the use of the [SparkFun Thing Plus - ESP32 WROOM (USB-C)](https://www.sparkfun.com/products/20168) to make serial connections between the boards. If you are using a different microcontroller, adjust the serial connections between the two boards to the appropriate pins.

Start by soldering [male headers]() to both sets of PTH pins on either side of the board as the photo below shows:

Next, connect the TXD and RXD pins on the LTE Stick to the Serial1 pins on the Thing Plus - ESP32 (USB-C) and your completed assembly should resemble the photo below:



