---
icon: material/cog
---

<!-- This section goes into detail about the various components on the product, solder jumpers as well as the board dimensions with a dimensional drawing exported from Eagle. -->

## LARA-R6 LTE Module

The heart of the LTE Stick is the LARA-R6 LTE Cat 1 module from ublox. The LARA-R6401 supports data <i>and</i> voice over LTE bands and works with most major North American carriers (Verizon, TMobile, AT&T, etc.). 

The LARA-R6 has the following interfaces: USB, 2x UART, I<sup>2</sup>S, I<sup>2</sup>C, SIM interface, and nine GPIO pins. It also has a host of features including device security through Root of Trust (RoT) with secure boot and update, firmware updates both over the air (uFOTA) and through AT commands, dynamic antenna tuning, jamming detection, and much more. For a complete overview of these features and other information on the LARA-R6401, refer to the [datasheet](). The R6401 supports LTE FDD bands from 600 MHz to 1900 MHz

## Pinout

The board breaks out the LARA-R6's UART and I<sup>2</sup>S interfaces as well as the Power On, Reset and voltage pins to a pair of 0.1"-spaced PTH (plated through-hole) headers.

The list below outlines the functionality of pins broken out on the LTE Stick:

  * PWR_On - LARA-R6 power control pin
  * Reset - LARA-R6 reset pin
  * RXD - UART data out
  * TXD - UART data in
  * CTS - UART clear to send
  * RTS - UART ready to send
  * RXA - I<sup>2</sup>S receive data
  * CLK - I<sup>2</sup>S clock
  * TXA - I<sup>2</sup>S transmit data
  * WA - I<sup>2</sup>S word alignment

  * VIN - 5V 
  * 3.3V - Regulated 3.3V
  * 1.8 - Regulated 1.8V  
 
### Test Points

The LTE Stick also has several other interfaces broken out to test points for advanced users to solder to. These test points are small copper pads grouped into three clusters labeled: <b>I2C</b>, <b>UART2</b>, and <b>GPIO</b>.

## Connectors/Connections

Let's take a closer look at the connectors on the LTE Stick.

### Power

The LTE Stick uses a USB-C connector for primary power input and serial communication. The board also has dedicated PTHs for the three voltage inputs on the board: <b>5v</b>, <b>3.3V</b>, and <b>1.8V</b>.

### Antenna Connections

The LARA-R6 has two antenna connections; Primary (ANT1) and Secondary (ANT2). The Primary antenna functions as the main antenna interface and supports TX/RX transmissions. The Secondary antenna communicates over RX only for the LTE / 3G RX diversity configuration. 

### Nano SIM Card Slot

The LTE Stick has an on-board Nano SIM card slot. The LTE Stick uses the LARA-R6401 which works with most major North American carriers (Verizon, TMobile, AT&T, etc.).   

## Buttons

The board has two buttons labeled <b>ON</b> and <b>RST</b>. The <b>ON</b> button connects to the LARA PWR_On pin which turns the module on and off. 

## LEDs

## Solder Jumpers

??? note "Never modified a jumper before?"
	Check out our <a href="https://learn.sparkfun.com/tutorials/664">Jumper Pads and PCB Traces tutorial</a> for a quick introduction!
	<p align="center">
		<a href="https://learn.sparkfun.com/tutorials/664">
		<img src="https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/6/6/4/PCB_TraceCutLumenati.jpg" alt="Tutorial's thumbnail"><br>
        How to Work with Jumper Pads and PCB Traces</a>
	</p>


## Board Dimensions

The board measures 3.25" x 1.00" (82.55mm x 25.40mm) with four mounting holes that fit a [4-40 screw]().

<figure markdown>
[![Board Dimensions](../assets/img/dimensions.png){ width="400" }](../assets/img/dimensions.png "Click to enlarge")
<figcaption markdown>
[Board dimensions (PDF)](../assets/board_files/dimensions.pdf) for the <Product Name>, in inches.
</figcaption>
</figure>


??? tip "Need more measurements?"
	For more information about the board's dimensions, users can download the [Eagle files](../assets/board_files/eagle_files.zip) for the board. These files can be opened in Eagle and additional measurements can be made with the dimensions tool.

	??? info ":octicons-download-16:{ .heart } Eagle - Free Download!"
		Eagle is a [CAD]("computer-aided design") program for electronics that is free to use for hobbyists and students. However, it does require an account registration to utilize the software.

		<center>
		[Download from<br>:autodesk-primary:{ .autodesk }](https://www.autodesk.com/products/eagle/free-download "Go to downloads page"){ .md-button .md-button--primary width="250px" }
		</center>
	
	??? info ":straight_ruler: Dimensions Tool"
		This video from Autodesk demonstrates how to utilize the dimensions tool in Eagle, to include additional measurements:

		<center>
		<div class="video">
		<iframe src="https://www.youtube.com/embed/dZLNd1FtNB8" title="EAGLE Dimension Tool" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
		</div>
		</center>