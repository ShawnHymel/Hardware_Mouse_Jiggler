EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:SparkFun-Connectors
LIBS:SparkFun-Aesthetics
LIBS:SparkFun-Electromechanical
LIBS:SparkFun-Hardware
LIBS:USB_Male-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "USB Male Breakout"
Date ""
Rev "v01"
Comp "SparkFun Electronics"
Comment1 ""
Comment2 "https://creativecommons.org/licenses/by-sa/4.0/"
Comment3 "License: CC BY-SA 4.0"
Comment4 "Author: Shawn Hymel"
$EndDescr
$Comp
L Conn_01x04 J2
U 1 1 5A95D5B3
P 5350 3750
F 0 "J2" H 5350 3950 50  0000 C CNN
F 1 "Conn_01x04" H 5350 3450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 5350 3750 50  0001 C CNN
F 3 "" H 5350 3750 50  0001 C CNN
	1    5350 3750
	1    0    0    -1  
$EndComp
$Comp
L USB_A_PTH_MALE J1
U 1 1 5A95D754
P 4850 3800
F 0 "J1" H 4700 4100 45  0000 L BNN
F 1 "USB_A_PTH_MALE" H 4700 3450 45  0000 L BNN
F 2 "Connectors:USB-A-H" H 4850 4200 20  0001 C CNN
F 3 "" H 4850 3800 50  0001 C CNN
F 4 "CONN-08367" H 4850 4250 60  0000 C CNN "Field4"
	1    4850 3800
	-1   0    0    -1  
$EndComp
$Comp
L STAND-OFF H2
U 1 1 5A95DAA1
P 10900 7000
F 0 "H2" H 10900 7100 45  0001 C CNN
F 1 "STAND-OFF" H 10900 6900 45  0001 C CNN
F 2 "Hardware:STAND-OFF" H 10900 7150 20  0001 C CNN
F 3 "" H 10900 7000 50  0001 C CNN
F 4 "XXX-00000" H 10900 7200 60  0000 C CNN "Field4"
	1    10900 7000
	1    0    0    -1  
$EndComp
$Comp
L STAND-OFF H1
U 1 1 5A95DAD3
P 10350 7000
F 0 "H1" H 10350 7100 45  0001 C CNN
F 1 "STAND-OFF" H 10350 6900 45  0001 C CNN
F 2 "Hardware:STAND-OFF" H 10350 7150 20  0001 C CNN
F 3 "" H 10350 7000 50  0001 C CNN
F 4 "XXX-00000" H 10350 7200 60  0000 C CNN "Field4"
	1    10350 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3650 5150 3650
Wire Wire Line
	5100 3750 5150 3750
Wire Wire Line
	5100 3850 5150 3850
Wire Wire Line
	5100 3950 5150 3950
$EndSCHEMATC
