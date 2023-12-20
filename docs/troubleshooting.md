
## Arduino Library Serial Selection

All examples in the [SparkFun u-blox Cellular Arduino Library](https://github.com/sparkfun/SparkFun_u-blox_Cellular_Arduino_Library) default to use <code>Serial1</code> for serial communication between the LTE Stick and microcontroller. If your selected microcontroller does not have this serial port, adjust this line to the correct serial port name:

```c++
#define mySerial Serial1
```

Otherwise, you can set up Software Serial by uncommenting the following line and, if necessary, adjusting the pins set for software serial (RX/TX) depending on the [software serial library limitations](https://docs.arduino.cc/learn/built-in-libraries/software-serial).

```c++
// SoftwareSerial mySerial(16, 17);
```

## Test Point Cluster Precautions

Reminder, all the test point clusters on the back of the board (UART2, I<sup>2</sup>C, and GPIO) are <i>not</i> level shifted and run at <b>1.8V</b>. Also note these are directly connected to the LARA-R6 and may be damaged by ESD shocks beyond the LARA-R6's ESD rating.

## General Troubleshooting

!!! info
    <p><span class="glyphicon glyphicon-question-sign" aria-hidden="true"></span> <strong>Not working as expected and need help? </strong></p>
    <p>If you need technical assistance and more information on a product that is not working as you expected, we recommend heading on over to the <a href="https://www.sparkfun.com/technical_assistance">SparkFun Technical Assistance</a> page for some initial troubleshooting.</p>
    <center>
    [SparkFun Technical Assistance Page](https://www.sparkfun.com/technical_assistance){ .md-button .md-button--primary }
    </center>
    <p>If you can't find what you need there, you'll need a <a href="https://forum.sparkfun.com/ucp.php?mode=register">Forum Account</a> to search product forums and post questions.<p>