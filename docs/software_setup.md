---
icon: simple/arduino
---

## ublox m-center



## Arduino IDE

Most users may already be familiar with the Arduino IDE and its use. However, for those of you who have never heard the name *Arduino* before, feel free to check out the [Arduino website](https://www.arduino.cc/en/Guide/HomePage). To get started with using the Arduino IDE, check out our tutorials below:


<div class="grid cards" markdown align="center">

<!-- -   <a href="https://learn.sparkfun.com/tutorials/50">
	<figure markdown>
	![What is an Arduino?](https://cdn.sparkfun.com/c/264-148/assets/3/b/6/e/b/512e66bece395f492b000000.jpg)</figure>

    ---
    **What is an Arduino?**
	</a> -->

-   <a href="https://learn.sparkfun.com/tutorials/61">
	<figure markdown>
	![Installing the Arduino IDE](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/6/1/arduinoThumb.jpg)
	</figure>

    ---
        
    **Installing the Arduino IDE**</a>

-   <a href="https://learn.sparkfun.com/tutorials/15">
    ![Installing an Arduino Library](https://cdn.sparkfun.com/c/264-148/assets/b/e/4/b/2/50f04b99ce395fd95e000001.jpg)
	</figure>
    
    ---
    
    **Installing an Arduino Library**</a>

-   <a href="https://learn.sparkfun.com/tutorials/1265">
    <figure markdown>
	![Installing Board Definitions in the Arduino IDE](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/1/2/6/5/sparkfun_boards.PNG)
	</figure>
    
    ---
    
    **Installing Board Definitions in the Arduino IDE**</a>

</div>

## SparkFun SARA-R5 Arduino Library

We do not have a dedicated library for the LARA-R6 but because ublox uses a common [AT Command set](./assets/component_documentation/LARA-R6-L6-AT-Commands.pdf), the SparkFun SARA-R5 Arduino Library works for most of the basic functionality of the LTE Stick with some limitations (the SARA-R5 library does not support voice/audio capability on the LTE Stick, the LTE Stick does not have integrated GNSS, among others). Install the library through the Arduino Library Manager tool by searching for <b>"SparkFun u-blox SARA-R5"</b> or you can manually install from the [GitHub Repository](https://github.com/sparkfun/SparkFun_u-blox_SARA-R5_Arduino_Library) or click the button below to download a ZIP of the repo:

<center>
[SparkFun u-blox Sara-5R5 Arduino Library (ZIP)](https://github.com/sparkfun/SparkFun_u-blox_SARA-R5_Arduino_Library/archive/refs/heads/master.zip){ .md-button .md-button--primary }
</center>