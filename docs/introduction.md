---
icon: material/book-open-page-variant
---

## Introduction


<div class="grid cards desc" markdown>

-    <a href="https://www.sparkfun.com/products/23618">
    **SparkFun LTE Stick - LARA-R6**<br>
    **SKU:** CEL-23618

    ---

    <figure markdown>
    ![Product Thumbnail](https://cdn.sparkfun.com/r/600-600/assets/parts/2/3/9/0/9/CEL-23618-LTE-Stick-LARA-R6-Feature.jpg)
    </figure></a>

    <center>
    <article class="video_desc">
    <iframe src="<Embedded Video>" title="Product Showcase: SparkFun LTE Stick - LARA-R6" frameborder="0" allow="accelerometer; autoplay; clipboard-write;encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
    </article>
    </center>

-    The SparkFun LTE Stick - LARA-R6 is a development and prototyping platform for the LARA-R6401 LTE module from ublox<sup>&trade;</sup>. The LTE Stick uses the LARA-R6401 version which supports both data and voice for North America and works with LTE bands used by these mobile networks: AT&T, Verizon, T-Mobile, and FirstNet. The board includes a nanoSIM card slot for users to select their preferred network. Check with your network provider for compatibility with the LARA-R6.

    The LARA-R6 workss on multiple LTE FDD frequency bands (2, 4, 5, 12, 13, 14, 66, and 71) and includes a host of common features users expect from u-blox modules including uFOTA (over-the-air firmware update), Root of Trust, secure boot/update, jamming detection, antenna and SIM detection, and much more. 
    
    The LTE Stick routes the UART and I<sup>2</sup>S interfaces to a 0.1"-spaced plated-through-hole (PTH) header along with the Reset and Power On signals and we designed the board to specifically mount on to a breadboard for easy prototyping. The board has two SMA connectors for the LARA-R6's primary and secondary antennas.

    <center>
    [Purchase from SparkFun :fontawesome-solid-cart-plus:{ .heart }](https://www.sparkfun.com/products/23618){ .md-button .md-button--primary }
    </center>

</div>

## Required Materials

The LTE Stick requires a few peripheral items including antennas, USB-C cable, and supported SIM card to get it up and running. Below are a few recommended options for each.

### USB-C Cable

For basic use and conifguration of the LTE Stick using AT commands or u-blox's m-center software you'll need USB-C cable to connect the dev board to your computer:

<div class="grid cards" markdown>

-   <a href="https://www.sparkfun.com/products/14743">

    <figure markdown>
    ![USB 3.1 Cable A to C - 3 Foot](https://cdn.sparkfun.com//assets/parts/1/2/9/7/2/14743-USB_3.1_Cable_A_to_C_-_3_Foot-01.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/14743">
    **USB 3.1 Cable A to C - 3 Foot**<br>
    CAB-14743
    </a>

-   <a href="https://www.sparkfun.com/products/15424">
    
    <figure markdown>
    ![Reversible USB A to C Cable - 2m](https://cdn.sparkfun.com//assets/parts/1/3/9/8/3/15424-Reversible_USB_A_to_C_Cable_-_2m-01.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/15424">
    **Reversible USB A to C Cable - 2m**<br>
    CAB-15424
    </a>
</div>

### LTE Antenna

The LTE Stick has two SMA connectors for the Primary and Secondary antenna signals on the LARA-R6. The LARA-R6 only requires the Primary antenna for basic functionality but u-blox recommends connecting the Secondary antenna for best signal quality. We recommend using an antenna like the one below:

<div class="grid cards" markdown>

-   <a href="https://www.sparkfun.com/products/16432">

    <figure markdown>
    ![LTE Hinged External Antenna - 698MHz-2.7GHz, SMA Male](https://cdn.sparkfun.com//assets/parts/1/5/1/8/7/16432-698MHz-2.7GHz_LTE_Hinged_External_Antenna__with_SMA_Male_Connector-01.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/16432">
    **LTE Hinged External Antenna - 698MHz-2.7GHz, SMA Male**<br>
    CEL-16432
    </a>
</div>

### SIM Card

Finally, the LTE Stick requires a nano SIM card for cellular network connectivity. As mentioned above, the LTE Stick uses the LARA-R6401 module and supports <i>only</i> North American LTE networks and works with the AT&T, Verizon, T-Mobile, and FirstNet cellular networks though make sure to check with your selected network provider for compatibility with the LARA-R6 before purchasing. The Hologram SIM card listed below works with the LARa-R6 for data and receiving SMS but not voice or sending SMS:

<div class="grid cards" markdown>

-   <a href="https://www.sparkfun.com/products/17117">

    <figure markdown>
    ![Hologram SIM Card](https://cdn.sparkfun.com//assets/parts/1/6/0/8/0/17117-Hologram_eUICC_SIM_Card-01.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/17117">
    **Hologram SIM Card**<br>
    CEL-17117
    </a>
</div>

## Optional Materials

Using the LTE Stick with the SparkFun u-blox Cellular Arduino Library requires a connection to a microcontroller/development board. Below are a few options that will work with the LTE Stick out of the box.

### Development Boards

??? warning "Logic Levels"
    The LTE Stick operates at <b>3.3V</b> logic so make sure your chosen development board operates at the same logic level or use a [level shifter](https://www.sparkfun.com/categories/361).

<div class="grid cards" markdown>

-   <a href="https://www.sparkfun.com/products/20168">

    <figure markdown>
    ![SparkFun Thing Plus - ESP32 WROOM (USB-C)](https://cdn.sparkfun.com//assets/parts/1/9/9/6/8/20168Diagonal.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/20168">
    **SparkFun Thing Plus - ESP32 WROOM (USB-C)**<br>
    DEV-20168
    </a>

-   <a href="https://www.sparkfun.com/products/19177">

    <figure markdown>
    ![SparkFun IoT RedBoard - ESP32 Development Board](https://cdn.sparkfun.com//assets/parts/1/8/8/0/0/ESP32_03.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/19177">
    **SparkFun IoT RedBoard - ESP32 Development Board**<br>
    DEV-19177
    </a>

-   <a href="https://www.sparkfun.com/products/15574">
    
    <figure markdown>
    ![SparkFun Thing Plus - Artemis](https://cdn.sparkfun.com//assets/parts/1/4/1/7/0/15574-SparkFun_Thing_Plus_-_Artemis-01.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/15574">
    **SparkFun Thing Plus - Artemis**<br>
    DEV-18158
    </a>

-   <a href="https://www.sparkfun.com/products/20168">

    <figure markdown>
    ![SparkFun Qwiic Pocket Development Board - ESP32-C6](https://cdn.sparkfun.com//assets/parts/2/3/0/8/6/22925_QwiicPocket_Feature1.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/22925">
    **SparkFun Qwiic Pocket Development Board - ESP32-C6**<br>
    DEV-22925
    </a>

-   <a href="https://www.sparkfun.com/products/23386">

    <figure markdown>
    ![SparkFun ESP32 Qwiic Pro Mini](https://cdn.sparkfun.com//assets/parts/2/3/7/4/4/23386-Pro-Mini-ESP32-Feature-new.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/23386">
    **SparkFun ESP32 Qwiic Pro Mini**<br>
    DEV-23386
    </a>

-   <a href="https://www.sparkfun.com/products/15444">

    <figure markdown>
    ![SparkFun RedBoard Artemis](https://cdn.sparkfun.com//assets/parts/1/4/0/1/9/15444-SparkFun_RedBoard_Artemis-01.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/15444">
    **SparkFun RedBoard Artemis**<br>
    DEV-15444
    </a>    
</div>

If you prefer to use the LTE Stick with a development board or simply prefer a soldered connection or want to modify the solder jumpers on these Qwiic breakouts you you may need some of the products listed below:

## Soldering Tools & Accessories

<div class="grid cards" markdown align="center">

-   <a href="https://www.sparkfun.com/products/116">

    <figure markdown>
    ![Break Away Headers - Straight)](https://cdn.sparkfun.com//assets/parts/1/0/6/00116-02-L.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/116">
    **Break Away Headers - Straight**<br>
    PRT-00116
    </a>

-   <a href="https://www.sparkfun.com/products/14681">
    
    <figure markdown>
    ![SparkFun Beginner Tool Kit](https://cdn.sparkfun.com//assets/parts/1/2/8/8/3/14681-SparkFun_Beginner_Tool_Kit.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/14681">
    **SparkFun Beginner Tool Kit**<br>
    TOL-14681
    </a>

-   <a href="https://www.sparkfun.com/products/22133">

    <figure markdown>
    ![Weller WLSK3012A Soldering Station](https://cdn.sparkfun.com//assets/parts/2/1/9/9/7/22133-_01.jpg)
    </figure>
    ---
    <a href="https://www.sparkfun.com/products/22133">**Weller WLSK3012A Soldering Station**<br>
    TOL-22133
    </a>

-   <a href="https://www.sparkfun.com/products/9325">

    <figure markdown>
    ![Solder Lead Free - 100-gram Spool](https://cdn.sparkfun.com//assets/parts/2/8/7/3/09325_9161-Solder_Lead_Free_-_100-gram_Spool-01.jpg)
    </figure>
    ---
    <a href="https://www.sparkfun.com/products/9325">**Solder Lead Free - 100-gram Spool**<br>
    TOL-09325
    </a>

-   <a href="https://www.sparkfun.com/products/9200">
    
    <figure markdown>
    ![Hobby Knife](https://cdn.sparkfun.com//assets/parts/2/6/4/6/09200-Hobby_Knife-01.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/9200">
    **Hobby Knife**<br>
    TOL-09200
    </a>

-   <a href="https://www.sparkfun.com/products/14579">

    <figure markdown>
    ![Chip Quik No-Clean Flux Pen - 10mL](https://cdn.sparkfun.com//assets/parts/1/2/7/2/5/14579-Chip_Quik_No-Clean_Flux_Pen_-_10mL-01.jpg)
    </figure>
    </a>
    ---
    <a href="https://www.sparkfun.com/products/14579">**Chip Quik No-Clean Flux Pen - 10mL**<br>
    CAB-14579
    </a>
</div>

## Suggested Reading

Before getting started with this Hookup Guide, you may want to read through the tutorials below if you are not familiar with the concepts covered in them or want a refresher. If you are using either of the Qwiic Shields linked above, we recommend reading through their respective Hookup Guides before continuing with this tutorial:

<div class="grid cards hide col-4" markdown align="center">

-   <a href="https://learn.sparkfun.com/tutorials/8">
    <figure markdown>
    ![Serial Communication](https://cdn.sparkfun.com/c/264-148/assets/7/d/f/9/9/50d24be7ce395f1f6c000000.jpg)
    </figure>
    </a>
    <a href="https://learn.sparkfun.com/tutorials/8">**Serial Communication**
    </a>

-   <a href="https://learn.sparkfun.com/tutorials/62">
    <figure markdown>
    ![Logic Levels](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/6/2/Input_Output_Logic_Level_Tolerances_tutorial_tile.png)
    </figure>
    </a>
    <a href="https://learn.sparkfun.com/tutorials/62">**Logic Levels**
    </a>

-   <a href="https://learn.sparkfun.com/tutorials/61">
    <figure markdown>
    ![Installing Arduino IDE](https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/6/1/arduinoThumb.jpg)
    </figure>
    </a>
    <a href="https://learn.sparkfun.com/tutorials/61">**Installing Arduino IDE**
    </a>

-   <a href="https://learn.sparkfun.com/tutorials/15">
    <figure markdown>
    ![Installing an Arduino Library](https://cdn.sparkfun.com/c/178-100/assets/b/e/4/b/2/50f04b99ce395fd95e000001.jpg)
    </figure>
    </a>
    <a href="https://learn.sparkfun.com/tutorials/15">**Installing an Arduino Library**
    </a>

-   <a href="https://learn.sparkfun.com/tutorials/112">
    <figure markdown>
    ![Serial Terminal Basics](https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/1/1/2/terminalThumb.jpg)
    </figure>
    </a>
    <a href="https://learn.sparkfun.com/tutorials/112">**Serial Terminal Basics**
    </a>

-   <a href="https://learn.sparkfun.com/tutorials/664">
    <figure markdown>
    ![How to Work with Jumper Pads and PCB Traces](https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/6/6/4/PCB_TraceCutLumenati.jpg)
    </figure>
    </a>
    <a href="https://learn.sparkfun.com/tutorials/664">**How to Work with Jumper Pads and PCB Traces**
    </a>
</div>