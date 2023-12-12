The SparkFun u-blox Cellular Arduino Library includes a large set of examples to do all sorts of things with supported u-blox cellular modules. Some examples work with all modules, others are limited to specific ones. All examples assume a serial connection between a microcontroller and the LTE Stick (or other supported cellular module) as demonstrated in the Hardware Assembly section. These examples build upon each other so we strongly recommend following them in sequential order to get everything set up and working properly.

??? note Module Power
	Make sure to power on the module using the "ON" button 

## Example 1 - Device Identification

The first example performs the basic AT commands to return the device information of a connected module. Open the example by navigating to <b>File < Examples < SparkFun u-blox Cellular Arduino Library > Example 1 - Device Identification</b> or copy the code below into a blank sketch.

??? "Example 1 Arduino Code"
	```
	--8<-- "Raw Example URL"
	```

Select your board (SparkFun Thing Plus ESP32 if you're following along with this tutorial verbatim) and Port and click the "Upload" button. When the code finishes compiling and uploading, open the [serial monitor]() with the baud set to <b>115200</b>. The code waits on a user prompt to begin so press any key when prompted in the serial monitor and you should see the device information print out similar to the screenshot below:

** Screenshot of serial printout - ML**

After a successful device information printout, the code loops to attempt to retrieve SIM card status. 

## Example 2 - Network Info

The second example 

## Example 3 - Register Operator

## Example 5 - Ping