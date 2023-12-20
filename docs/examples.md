---
icon: simple/arduino
---

The SparkFun u-blox Cellular Arduino Library includes a large set of examples to do all sorts of things with supported u-blox cellular modules. Some examples work with all modules, others are limited to specific ones. All examples assume a serial connection between a microcontroller and the LTE Stick (or other supported cellular module) as demonstrated in the Hardware Assembly section. These examples build upon each other so we recommend following them in sequential order to get everything set up and working properly.

!!! note "LARA-R6 Power"
	Make sure to power on the module using the "ON" button 

If you have not used m-center or AT commands to configure the network information and register the network operator for your device before using this library, you may need to go through Example 2 - Network Info and Example 3 - Register Operator to get the LARA-R6 registered and configured properly on your network. Otherwise, feel free to skip ahead to the Ping and other more complex examples.

## Example 1 - Device Identification

The first example  performs the basic AT commands to return the device information of a connected module:

* Manufacturer ID
* Model
* Firmware Version
* Serial Number
* IMEI ID
* IMSI ID
* SIM CCID
* Subscriber Number (from the SIM)
* Capabilities
* SIM state

Open the example by navigating to <b>File < Examples < SparkFun u-blox Cellular Arduino Library < Example 1 - Device Identification</b> or copy the code below into a blank sketch.

??? "Example 1 - Device Information"
	```
	--8<-- "Raw Example URL"
	```

!!! warning "Serial Port Selection"
	This and all following examples default to use <code>Serial1</code> for serial communication between the LTE Stick and microcontroller. If your selected microcontroller does not have this serial port, uncomment the following line and, if necessary, adjust the pins set for software serial depending on the [software serial library limitations](https://docs.arduino.cc/learn/built-in-libraries/software-serial).

	```c++
		// SoftwareSerial mySerial(16, 17);
	```

Select your board (SparkFun Thing Plus ESP32 if you're following along with this tutorial verbatim) and Port and click the "Upload" button. When the code finishes compiling and uploading, open the [serial monitor](https://learn.sparkfun.com/tutorials/terminal-basics/arduino-serial-monitor-windows-mac-linux) with the baud set to <b>115200</b>. The code waits on a user prompt to begin so press any key when prompted in the serial monitor and you should see the device information and SIM status print out.

## Example 2 - Network Info

The second example verifies the LARA-R6 is receiving an LTE signal on a selected network and prints out the network information and IDs. The code creates the LARA-R6 object and assigns a network operator value.

??? "Example 2 -Network Info"
	```
	--8<-- "Raw Example URL"
	```

After uploading the code, open a terminal window with the baud set to <b>115200</b> and enter any key to start the example. After initializing everything needed, the code attempts to set the Network Profile to the Mobile Network Operator entered. If successful, the code prints out the RSSI (Received Signal Strength), Network Registration Status and Context IDs, Access Point Names and IP Addresses.

## Example 3 - Register Operator

Example 4 checks to see if the LARA-R6 is connected to a network and lets you register on a different network if available and if the SIM supports this. This example can also be used to list all the LTE operators the LARA-R6 can detect. Note, you can only connect to networks supported by your SIM card. Refer to your SIM card manufacturer's documentation for supported networks.

??? "Example 3 - Register Operator"
	```
	--8<-- "Raw Example URL"
	```	

## Example 5 - Ping

The eighth example tests the LTE Stick's data connection by a standard server ping. Open a terminal window and follow the prompts then enter a server to ping. Any valid web address like <b>www.google.com</b> or <b>www.sparkfun.com</b> works. If the ping succeeds the code prints out the time to send and receive the ping in milliseconds.

??? "Example 5 - Ping"
	```
	--8<-- "Raw Example URL"
	```

If the ping fails, try uncommenting this line that enables debugging over serial:

```c++
// myModule.enableDebugging(); // Uncomment this line to enable helpful debug messages on Serial
```

Upload the code again, retry the ping and look for any messages that include +UUPINGER:. Refer to the list of Ping error codes in Appendix A. 9 of the [AT Command Reference](./assets/component_documentation/LARA-R6-L6-AT-Commands.pdf) to decipher the error code.

## Further Examples

These examples perform the basic tests for making sure everything is working properly on the LTE Stick but the SparkFun u-blox Cellular Arduino Library includes many more examples to take full advantage of the LARA-R6's capabilities including audio examples for playing audio tones and phonecall control. The audio examples require external hardware including an audio codec and are beyond the scope of this tutorial.