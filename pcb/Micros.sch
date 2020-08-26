EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "ENG10032 - Microcontroladores "
Date "2020-08-20"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 10700 3250 2    50   Output ~ 0
ELB1
Text GLabel 10700 3350 2    50   Output ~ 0
ELB2
Text GLabel 10450 1450 0    50   Output ~ 0
PWM
Text GLabel 10450 1250 0    50   Input ~ 0
ELB1
Text GLabel 10450 1350 0    50   Input ~ 0
ELB2
Text GLabel 10450 2500 0    50   Output ~ 0
#SS
Text GLabel 10450 2400 0    50   Output ~ 0
MOSI
Text GLabel 10450 2200 0    50   Output ~ 0
SCLK
Wire Wire Line
	5650 1950 5050 1950
Wire Wire Line
	5050 1950 5050 2000
$Comp
L power:+5V #PWR0101
U 1 1 5F2E7DD9
P 7300 1500
F 0 "#PWR0101" H 7300 1350 50  0001 C CNN
F 1 "+5V" H 7315 1673 50  0000 C CNN
F 2 "" H 7300 1500 50  0001 C CNN
F 3 "" H 7300 1500 50  0001 C CNN
	1    7300 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 1750 7300 1750
Wire Wire Line
	7300 1750 7300 1500
Text GLabel 5650 2050 0    50   Input ~ 0
#SS
Text GLabel 5650 2150 0    50   Input ~ 0
SCLK
Text GLabel 5650 2250 0    50   Output ~ 0
MISO
Text GLabel 5650 2350 0    50   Input ~ 0
MOSI
$Comp
L pspice:CAP C1
U 1 1 5F2E936A
P 3250 1250
F 0 "C1" V 2935 1250 50  0000 C CNN
F 1 "10pF" V 3026 1250 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 3250 1250 50  0001 C CNN
F 3 "~" H 3250 1250 50  0001 C CNN
	1    3250 1250
	0    1    1    0   
$EndComp
$Comp
L pspice:CAP C2
U 1 1 5F2F5555
P 3250 1850
F 0 "C2" V 2935 1850 50  0000 C CNN
F 1 "10pF" V 3026 1850 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 3250 1850 50  0001 C CNN
F 3 "~" H 3250 1850 50  0001 C CNN
	1    3250 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 1250 3000 1250
$Comp
L Shield_Galileo-rescue:Connector_Encoder-Quanser_2DSFJE_Library J2
U 1 1 5F2F72BA
P 7700 1950
F 0 "J2" H 7700 1675 50  0000 C CNN
F 1 "Connector Encoder" H 7700 1584 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 7700 1950 50  0001 C CNN
F 3 "" H 7700 1950 50  0001 C CNN
	1    7700 1950
	-1   0    0    1   
$EndComp
$Comp
L Device:Crystal Crystal1
U 1 1 5F2FA4D4
P 3800 1600
F 0 "Crystal1" V 3754 1731 50  0000 L CNN
F 1 "30MHz" V 3845 1731 50  0000 L CNN
F 2 "Crystal:Crystal_HC52-6mm_Vertical" H 3800 1600 50  0001 C CNN
F 3 "~" H 3800 1600 50  0001 C CNN
	1    3800 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	3500 1250 3800 1250
Wire Wire Line
	3800 1250 3800 1450
$Comp
L Device:R R1
U 1 1 5F2FC510
P 4400 1600
F 0 "R1" H 4470 1646 50  0000 L CNN
F 1 "1M" H 4470 1555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4330 1600 50  0001 C CNN
F 3 "~" H 4400 1600 50  0001 C CNN
	1    4400 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 1250 4400 1250
Wire Wire Line
	4400 1250 4400 1450
Connection ~ 3800 1250
Wire Wire Line
	5650 1750 5050 1750
Wire Wire Line
	5050 1750 5050 1250
Wire Wire Line
	5050 1250 4400 1250
Connection ~ 4400 1250
Wire Wire Line
	9600 1250 9350 1250
$Comp
L power:+5V #PWR0102
U 1 1 5F2E56A3
P 9050 1250
F 0 "#PWR0102" H 9050 1100 50  0001 C CNN
F 1 "+5V" H 9065 1423 50  0000 C CNN
F 2 "" H 9050 1250 50  0001 C CNN
F 3 "" H 9050 1250 50  0001 C CNN
	1    9050 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 1950 8400 1950
$Comp
L power:+5V #PWR0103
U 1 1 5F31E67A
P 8250 1750
F 0 "#PWR0103" H 8250 1600 50  0001 C CNN
F 1 "+5V" H 8265 1923 50  0000 C CNN
F 2 "" H 8250 1750 50  0001 C CNN
F 3 "" H 8250 1750 50  0001 C CNN
	1    8250 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 2050 8250 2050
Wire Wire Line
	8250 2050 8250 1750
$Comp
L Driver_Motor:LMD18200 U1
U 1 1 5F3866DE
P 6750 4700
F 0 "U1" H 6750 5681 50  0000 L TNN
F 1 "LMD18200" H 6750 5590 50  0000 L TNN
F 2 "Package_TO_SOT_THT:TO-220-11_P3.4x5.08mm_StaggerOdd_Lead4.85mm_Vertical" H 5300 3350 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/lmd18200.pdf" H 6650 4700 50  0001 C CNN
	1    6750 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 5600 6750 5700
$Comp
L pspice:CAP C3
U 1 1 5F38EF9A
P 8150 4250
F 0 "C3" H 8328 4296 50  0000 L CNN
F 1 "10nF" H 8328 4205 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 8150 4250 50  0001 C CNN
F 3 "~" H 8150 4250 50  0001 C CNN
	1    8150 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 4100 7600 4100
Wire Wire Line
	7600 4100 7600 4000
Wire Wire Line
	7600 4000 8150 4000
Wire Wire Line
	7450 4400 7600 4400
Wire Wire Line
	7600 4400 7600 4500
Wire Wire Line
	7600 4500 8150 4500
$Comp
L pspice:CAP C4
U 1 1 5F3977D7
P 8150 4800
F 0 "C4" H 8328 4846 50  0000 L CNN
F 1 "10nF" H 8328 4755 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 8150 4800 50  0001 C CNN
F 3 "~" H 8150 4800 50  0001 C CNN
	1    8150 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 4600 7600 4600
Wire Wire Line
	7600 4600 7600 4550
Wire Wire Line
	7600 4550 8150 4550
Wire Wire Line
	7450 4900 7600 4900
Wire Wire Line
	7600 4900 7600 5050
Wire Wire Line
	7600 5050 8150 5050
Text GLabel 5650 4700 0    50   Input ~ 0
PWM
NoConn ~ 7050 2150
NoConn ~ 7050 2250
NoConn ~ 7050 2350
Wire Wire Line
	6850 2350 7050 2350
Wire Wire Line
	6850 2250 7050 2250
Wire Wire Line
	6850 2150 7050 2150
NoConn ~ 10300 950 
NoConn ~ 10300 1550
NoConn ~ 10300 1800
NoConn ~ 10300 1900
NoConn ~ 10100 3050
NoConn ~ 10100 3150
NoConn ~ 10100 3250
NoConn ~ 10100 3350
NoConn ~ 10100 3450
NoConn ~ 10100 3550
NoConn ~ 10100 3750
NoConn ~ 10100 3650
NoConn ~ 10800 3750
NoConn ~ 10800 3650
NoConn ~ 10800 3550
NoConn ~ 10800 3450
NoConn ~ 10800 3150
NoConn ~ 10800 3050
Wire Wire Line
	10300 950  10450 950 
Wire Wire Line
	10300 1550 10450 1550
Wire Wire Line
	10300 1800 10450 1800
Wire Wire Line
	10300 1900 10450 1900
Wire Wire Line
	10100 3050 10200 3050
Wire Wire Line
	10100 3150 10200 3150
Wire Wire Line
	10100 3250 10200 3250
Wire Wire Line
	10100 3350 10200 3350
Wire Wire Line
	10100 3450 10200 3450
Wire Wire Line
	10100 3550 10200 3550
Wire Wire Line
	10100 3650 10200 3650
Wire Wire Line
	10100 3750 10200 3750
Wire Wire Line
	10800 3750 10700 3750
Wire Wire Line
	10800 3650 10700 3650
Wire Wire Line
	10800 3550 10700 3550
Wire Wire Line
	10800 3450 10700 3450
Wire Wire Line
	10800 3150 10700 3150
Wire Wire Line
	10800 3050 10700 3050
Text GLabel 3900 5000 0    50   Input ~ 0
ENABLE
NoConn ~ 10300 850 
Wire Wire Line
	10300 850  10450 850 
NoConn ~ 7800 2400
Wire Wire Line
	7800 2400 7700 2400
Wire Wire Line
	7700 2400 7700 2250
Wire Wire Line
	8400 1950 8400 2100
$Comp
L power:GND #PWR0104
U 1 1 5F3EBE5F
P 8400 2100
F 0 "#PWR0104" H 8400 1850 50  0001 C CNN
F 1 "GND" H 8405 1927 50  0000 C CNN
F 2 "" H 8400 2100 50  0001 C CNN
F 3 "" H 8400 2100 50  0001 C CNN
	1    8400 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5F3FA9D5
P 5050 2000
F 0 "#PWR0105" H 5050 1750 50  0001 C CNN
F 1 "GND" H 5055 1827 50  0000 C CNN
F 2 "" H 5050 2000 50  0001 C CNN
F 3 "" H 5050 2000 50  0001 C CNN
	1    5050 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5F430DB7
P 6750 5700
F 0 "#PWR0106" H 6750 5450 50  0001 C CNN
F 1 "GND" H 6755 5527 50  0000 C CNN
F 2 "" H 6750 5700 50  0001 C CNN
F 3 "" H 6750 5700 50  0001 C CNN
	1    6750 5700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5F439DA2
P 9400 5100
F 0 "#PWR0107" H 9400 4850 50  0001 C CNN
F 1 "GND" H 9405 4927 50  0000 C CNN
F 2 "" H 9400 5100 50  0001 C CNN
F 3 "" H 9400 5100 50  0001 C CNN
	1    9400 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 5100 9400 5100
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J1
U 1 1 5F44C7CF
P 10400 3350
F 0 "J1" H 10450 3775 50  0000 C CNN
F 1 "Conn_02x08" H 10450 3776 50  0001 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x08_P2.00mm_Vertical" H 10400 3350 50  0001 C CNN
F 3 "~" H 10400 3350 50  0001 C CNN
	1    10400 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5F4783A7
P 2400 2000
F 0 "#PWR0108" H 2400 1750 50  0001 C CNN
F 1 "GND" H 2405 1827 50  0000 C CNN
F 2 "" H 2400 2000 50  0001 C CNN
F 3 "" H 2400 2000 50  0001 C CNN
	1    2400 2000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x10 J3
U 1 1 5F486E94
P 10650 2200
F 0 "J3" H 10730 2146 50  0000 L CNN
F 1 "Conn_01x10" H 10730 2101 50  0001 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x10_P2.00mm_Vertical" H 10650 2200 50  0001 C CNN
F 3 "~" H 10650 2200 50  0001 C CNN
	1    10650 2200
	1    0    0    -1  
$EndComp
Text GLabel 10450 2300 0    50   Input ~ 0
MISO
NoConn ~ 10300 2000
NoConn ~ 10300 2100
Wire Wire Line
	10300 2000 10450 2000
Wire Wire Line
	10300 2100 10450 2100
NoConn ~ 10300 2600
NoConn ~ 10300 2700
Wire Wire Line
	10300 2600 10450 2600
Wire Wire Line
	10300 2700 10450 2700
$Comp
L Connector_Generic:Conn_01x08 J4
U 1 1 5F4DA758
P 10650 1150
F 0 "J4" H 10730 1096 50  0000 L CNN
F 1 "Conn_01x08" H 10730 1051 50  0001 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x08_P2.00mm_Vertical" H 10650 1150 50  0001 C CNN
F 3 "~" H 10650 1150 50  0001 C CNN
	1    10650 1150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J5
U 1 1 5F4EDD0B
P 9800 1150
F 0 "J5" H 9880 1096 50  0000 L CNN
F 1 "Conn_01x08" H 9880 1051 50  0001 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x08_P2.00mm_Vertical" H 9800 1150 50  0001 C CNN
F 3 "~" H 9800 1150 50  0001 C CNN
	1    9800 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5F3F6365
P 9250 1400
F 0 "#PWR0109" H 9250 1150 50  0001 C CNN
F 1 "GND" H 9255 1227 50  0000 C CNN
F 2 "" H 9250 1400 50  0001 C CNN
F 3 "" H 9250 1400 50  0001 C CNN
	1    9250 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 1350 9500 1350
Wire Wire Line
	9250 1350 9250 1400
Wire Wire Line
	9600 1450 9500 1450
Wire Wire Line
	9500 1450 9500 1350
Connection ~ 9500 1350
NoConn ~ 9450 1550
Wire Wire Line
	9450 1550 9600 1550
NoConn ~ 9450 1150
Wire Wire Line
	9450 1150 9600 1150
NoConn ~ 9450 1050
Wire Wire Line
	9450 1050 9600 1050
NoConn ~ 9450 950 
Wire Wire Line
	9450 950  9600 950 
NoConn ~ 9450 850 
Wire Wire Line
	9450 850  9600 850 
Text GLabel 10450 1150 0    50   Output ~ 0
ENABLE
Wire Wire Line
	8150 4000 8600 4000
Wire Wire Line
	8600 4000 8600 4450
Connection ~ 8150 4000
Wire Wire Line
	5550 4400 5550 4350
$Comp
L power:+5V #PWR0111
U 1 1 5F4137B3
P 5550 4350
F 0 "#PWR0111" H 5550 4200 50  0001 C CNN
F 1 "+5V" H 5565 4523 50  0000 C CNN
F 2 "" H 5550 4350 50  0001 C CNN
F 3 "" H 5550 4350 50  0001 C CNN
	1    5550 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 4400 6050 4400
Wire Wire Line
	5650 4700 6050 4700
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5F461616
P 9350 1250
F 0 "#FLG0101" H 9350 1325 50  0001 C CNN
F 1 "PWR_FLAG" H 9350 1423 50  0000 C CNN
F 2 "" H 9350 1250 50  0001 C CNN
F 3 "~" H 9350 1250 50  0001 C CNN
	1    9350 1250
	1    0    0    -1  
$EndComp
Connection ~ 9350 1250
Wire Wire Line
	9050 1250 9350 1250
$Comp
L Device:R R2
U 1 1 5F4700BD
P 8950 5100
F 0 "R2" V 9157 5100 50  0000 C CNN
F 1 "0.1R" V 9066 5100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 8880 5100 50  0001 C CNN
F 3 "~" H 8950 5100 50  0001 C CNN
	1    8950 5100
	0    1    -1   0   
$EndComp
Text GLabel 8000 5800 2    50   Output ~ 0
TH_FLAG
$Comp
L Device:R R3
U 1 1 5F480CFC
P 7700 5500
F 0 "R3" H 7630 5454 50  0000 R CNN
F 1 "10K" H 7630 5545 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7630 5500 50  0001 C CNN
F 3 "~" H 7700 5500 50  0001 C CNN
	1    7700 5500
	-1   0    0    1   
$EndComp
Wire Wire Line
	7450 5100 8800 5100
$Comp
L power:+5V #PWR0113
U 1 1 5F4B047E
P 7700 5350
F 0 "#PWR0113" H 7700 5200 50  0001 C CNN
F 1 "+5V" H 7715 5523 50  0000 C CNN
F 2 "" H 7700 5350 50  0001 C CNN
F 3 "" H 7700 5350 50  0001 C CNN
	1    7700 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 5650 7700 5800
Text GLabel 10450 1050 0    50   Input ~ 0
TH_FLAG
Wire Wire Line
	7450 5200 7550 5200
Wire Wire Line
	7700 5800 8000 5800
Wire Wire Line
	7550 5800 7700 5800
Wire Wire Line
	7550 5200 7550 5800
Connection ~ 7700 5800
Wire Wire Line
	9150 2050 9150 2150
Wire Wire Line
	9150 2150 9400 2150
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5F50D140
P 9400 2150
F 0 "#FLG0102" H 9400 2225 50  0001 C CNN
F 1 "PWR_FLAG" H 9400 2323 50  0000 C CNN
F 2 "" H 9400 2150 50  0001 C CNN
F 3 "~" H 9400 2150 50  0001 C CNN
	1    9400 2150
	1    0    0    -1  
$EndComp
Connection ~ 9400 2150
Wire Wire Line
	9400 2150 9450 2150
Wire Wire Line
	4850 5000 6050 5000
Wire Wire Line
	3900 5000 4300 5000
$Comp
L 74xGxx:74LVC1G04 U3
U 1 1 5F56311C
P 4600 5000
F 0 "U3" H 4575 5175 50  0000 C CNN
F 1 "74LVC1G04" H 4575 5176 50  0001 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x03_P2.00mm_Vertical" H 4600 5000 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74LVC1G04.pdf" H 4600 5000 50  0001 C CNN
	1    4600 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:Fuse F1
U 1 1 5F56CD65
P 6750 3600
F 0 "F1" H 6810 3600 50  0000 L BNN
F 1 "3A" H 6810 3555 50  0000 L CNN
F 2 "Fuse:Fuse_2010_5025Metric_Pad1.52x2.65mm_HandSolder" V 6680 3600 50  0001 C CNN
F 3 "~" H 6750 3600 50  0001 C CNN
	1    6750 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3750 6750 3900
Wire Wire Line
	6750 3200 6750 3450
$Comp
L Connector:Screw_Terminal_01x02 J7
U 1 1 5F5856D5
P 9650 2150
F 0 "J7" H 9730 2096 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9730 2051 50  0001 L CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 9650 2150 50  0001 C CNN
F 3 "~" H 9650 2150 50  0001 C CNN
	1    9650 2150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5F58B609
P 9150 2300
F 0 "#PWR0116" H 9150 2050 50  0001 C CNN
F 1 "GND" H 9155 2127 50  0000 C CNN
F 2 "" H 9150 2300 50  0001 C CNN
F 3 "" H 9150 2300 50  0001 C CNN
	1    9150 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 2250 9150 2300
Wire Wire Line
	9150 2250 9450 2250
$Comp
L LS7366R:LS7366R U2
U 1 1 5F48F67C
P 6250 2050
F 0 "U2" H 6250 2525 50  0000 C TNN
F 1 "LS7366R" H 6250 2526 50  0000 C BNN
F 2 "footNovo:DIP-14_W7.62mm" H 6250 2050 50  0001 L BNN
F 3 "" H 6250 2050 50  0001 C CNN
	1    6250 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1850 4400 1850
Wire Wire Line
	4400 1750 4400 1850
Wire Wire Line
	6850 1850 7300 1850
Wire Wire Line
	7300 1850 7300 1750
Connection ~ 7300 1750
Wire Wire Line
	6850 1950 7400 1950
Wire Wire Line
	6850 2050 7400 2050
Wire Wire Line
	4400 1850 3800 1850
Wire Wire Line
	3800 1850 3800 1750
Connection ~ 4400 1850
Wire Wire Line
	3800 1850 3500 1850
Connection ~ 3800 1850
Wire Wire Line
	3000 1850 2400 1850
Wire Wire Line
	2400 1850 2400 1250
Wire Wire Line
	2400 1850 2400 2000
Connection ~ 2400 1850
$Comp
L +27v:+27V #PWR0110
U 1 1 5F54B278
P 6750 3200
F 0 "#PWR0110" H 6750 3050 50  0001 C CNN
F 1 "+27V" H 6750 3373 50  0000 C CNN
F 2 "" H 7000 3250 50  0001 C CNN
F 3 "" H 7000 3250 50  0001 C CNN
	1    6750 3200
	1    0    0    -1  
$EndComp
$Comp
L +27v:+27V #PWR0114
U 1 1 5F54BCD2
P 9150 2050
F 0 "#PWR0114" H 9150 1900 50  0001 C CNN
F 1 "+27V" H 9150 2223 50  0000 C CNN
F 2 "" H 9400 2100 50  0001 C CNN
F 3 "" H 9400 2100 50  0001 C CNN
	1    9150 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J6
U 1 1 5F47AB49
P 8800 4450
F 0 "J6" H 8880 4396 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 8880 4351 50  0001 L CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 8800 4450 50  0001 C CNN
F 3 "~" H 8800 4450 50  0001 C CNN
	1    8800 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 5050 8600 5050
Wire Wire Line
	8600 5050 8600 4550
Connection ~ 8150 5050
$Comp
L power:VCC #PWR?
U 1 1 5F49DD67
P 8850 1250
F 0 "#PWR?" H 8850 1100 50  0001 C CNN
F 1 "VCC" H 8867 1423 50  0000 C CNN
F 2 "" H 8850 1250 50  0001 C CNN
F 3 "" H 8850 1250 50  0001 C CNN
	1    8850 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 1250 8850 1250
Connection ~ 9050 1250
$Comp
L power:GNDREF #PWR?
U 1 1 5F4A2B76
P 9050 1350
F 0 "#PWR?" H 9050 1100 50  0001 C CNN
F 1 "GNDREF" H 9055 1177 50  0000 C CNN
F 2 "" H 9050 1350 50  0001 C CNN
F 3 "" H 9050 1350 50  0001 C CNN
	1    9050 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 1350 9500 1350
Wire Wire Line
	9050 1350 9250 1350
Connection ~ 9250 1350
$Comp
L power:GNDREF #PWR?
U 1 1 5F4AC639
P 9350 2250
F 0 "#PWR?" H 9350 2000 50  0001 C CNN
F 1 "GNDREF" H 9355 2077 50  0000 C CNN
F 2 "" H 9350 2250 50  0001 C CNN
F 3 "" H 9350 2250 50  0001 C CNN
	1    9350 2250
	1    0    0    -1  
$EndComp
$EndSCHEMATC
