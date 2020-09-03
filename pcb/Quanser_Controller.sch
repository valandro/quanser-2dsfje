EESchema Schematic File Version 4
LIBS:Quanser_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Quanser Controller"
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
P 5700 5100
F 0 "U1" H 5700 6081 50  0000 L TNN
F 1 "LMD18200" H 5700 5990 50  0000 L TNN
F 2 "Package_TO_SOT_THT:TO-220-11_P3.4x5.08mm_StaggerOdd_Lead4.85mm_Vertical" H 4250 3750 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/lmd18200.pdf" H 5600 5100 50  0001 C CNN
	1    5700 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 6000 5700 6100
$Comp
L pspice:CAP C3
U 1 1 5F38EF9A
P 7100 4650
F 0 "C3" H 7278 4696 50  0000 L CNN
F 1 "10nF" H 7278 4605 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 7100 4650 50  0001 C CNN
F 3 "~" H 7100 4650 50  0001 C CNN
	1    7100 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 4500 6550 4500
Wire Wire Line
	6550 4500 6550 4400
Wire Wire Line
	6550 4400 7100 4400
Wire Wire Line
	6400 4800 6550 4800
Wire Wire Line
	6550 4800 6550 4900
Wire Wire Line
	6550 4900 7100 4900
$Comp
L pspice:CAP C4
U 1 1 5F3977D7
P 7100 5200
F 0 "C4" H 7278 5246 50  0000 L CNN
F 1 "10nF" H 7278 5155 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 7100 5200 50  0001 C CNN
F 3 "~" H 7100 5200 50  0001 C CNN
	1    7100 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 5000 6550 5000
Wire Wire Line
	6550 5000 6550 4950
Wire Wire Line
	6550 4950 7100 4950
Wire Wire Line
	6400 5300 6550 5300
Wire Wire Line
	6550 5300 6550 5450
Wire Wire Line
	6550 5450 7100 5450
Text GLabel 4600 5100 0    50   Input ~ 0
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
NoConn ~ 10300 1800
NoConn ~ 10300 1900
NoConn ~ 10800 3750
NoConn ~ 10800 3650
NoConn ~ 10800 3550
NoConn ~ 10800 3450
NoConn ~ 10800 3150
NoConn ~ 10800 3050
Wire Wire Line
	10300 950  10450 950 
Wire Wire Line
	10300 1800 10450 1800
Wire Wire Line
	10300 1900 10450 1900
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
P 5700 6100
F 0 "#PWR0106" H 5700 5850 50  0001 C CNN
F 1 "GND" H 5705 5927 50  0000 C CNN
F 2 "" H 5700 6100 50  0001 C CNN
F 3 "" H 5700 6100 50  0001 C CNN
	1    5700 6100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5F439DA2
P 8350 5500
F 0 "#PWR0107" H 8350 5250 50  0001 C CNN
F 1 "GND" H 8355 5327 50  0000 C CNN
F 2 "" H 8350 5500 50  0001 C CNN
F 3 "" H 8350 5500 50  0001 C CNN
	1    8350 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 5500 8350 5500
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
	7100 4400 7550 4400
Wire Wire Line
	7550 4400 7550 4850
Connection ~ 7100 4400
$Comp
L power:+5V #PWR0111
U 1 1 5F4137B3
P 2600 4900
F 0 "#PWR0111" H 2600 4750 50  0001 C CNN
F 1 "+5V" H 2615 5073 50  0000 C CNN
F 2 "" H 2600 4900 50  0001 C CNN
F 3 "" H 2600 4900 50  0001 C CNN
	1    2600 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 5100 5000 5100
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
P 7900 5500
F 0 "R2" V 8107 5500 50  0000 C CNN
F 1 "0.1R" V 8016 5500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7830 5500 50  0001 C CNN
F 3 "~" H 7900 5500 50  0001 C CNN
	1    7900 5500
	0    1    -1   0   
$EndComp
Text GLabel 6950 6200 2    50   Output ~ 0
TH_FLAG
$Comp
L Device:R R3
U 1 1 5F480CFC
P 6650 5900
F 0 "R3" H 6580 5854 50  0000 R CNN
F 1 "10K" H 6580 5945 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6580 5900 50  0001 C CNN
F 3 "~" H 6650 5900 50  0001 C CNN
	1    6650 5900
	-1   0    0    1   
$EndComp
Wire Wire Line
	6400 5500 7350 5500
$Comp
L power:+5V #PWR0113
U 1 1 5F4B047E
P 6650 5750
F 0 "#PWR0113" H 6650 5600 50  0001 C CNN
F 1 "+5V" H 6665 5923 50  0000 C CNN
F 2 "" H 6650 5750 50  0001 C CNN
F 3 "" H 6650 5750 50  0001 C CNN
	1    6650 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 6050 6650 6200
Text GLabel 10450 1050 0    50   Input ~ 0
TH_FLAG
Wire Wire Line
	6400 5600 6500 5600
Wire Wire Line
	6650 6200 6950 6200
Wire Wire Line
	6500 6200 6650 6200
Wire Wire Line
	6500 5600 6500 6200
Connection ~ 6650 6200
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
L Quanser_Controller-rescue:+27V-+27v #PWR0110
U 1 1 5F54B278
P 5700 3550
F 0 "#PWR0110" H 5700 3400 50  0001 C CNN
F 1 "+27V" H 5700 3723 50  0000 C CNN
F 2 "" H 5950 3600 50  0001 C CNN
F 3 "" H 5950 3600 50  0001 C CNN
	1    5700 3550
	1    0    0    -1  
$EndComp
$Comp
L Quanser_Controller-rescue:+27V-+27v #PWR0114
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
P 7750 4850
F 0 "J6" H 7830 4796 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 7830 4751 50  0001 L CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 7750 4850 50  0001 C CNN
F 3 "~" H 7750 4850 50  0001 C CNN
	1    7750 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 5450 7550 5450
Wire Wire Line
	7550 5450 7550 4950
Connection ~ 7100 5450
$Comp
L power:VCC #PWR0112
U 1 1 5F49DD67
P 8850 1250
F 0 "#PWR0112" H 8850 1100 50  0001 C CNN
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
L power:GNDREF #PWR0115
U 1 1 5F4A2B76
P 9050 1350
F 0 "#PWR0115" H 9050 1100 50  0001 C CNN
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
L power:GNDREF #PWR0117
U 1 1 5F4AC639
P 9350 2250
F 0 "#PWR0117" H 9350 2000 50  0001 C CNN
F 1 "GNDREF" H 9355 2077 50  0000 C CNN
F 2 "" H 9350 2250 50  0001 C CNN
F 3 "" H 9350 2250 50  0001 C CNN
	1    9350 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 3050 10200 3150
Connection ~ 10200 3150
Wire Wire Line
	10200 3150 10200 3250
Connection ~ 10200 3250
Wire Wire Line
	10200 3250 10200 3350
Connection ~ 10200 3350
Wire Wire Line
	10200 3350 10200 3450
Connection ~ 10200 3450
Wire Wire Line
	10200 3450 10200 3550
Connection ~ 10200 3550
Wire Wire Line
	10200 3550 10200 3650
Connection ~ 10200 3650
Wire Wire Line
	10200 3650 10200 3750
$Comp
L power:GND #PWR0118
U 1 1 5F504C05
P 9900 3800
F 0 "#PWR0118" H 9900 3550 50  0001 C CNN
F 1 "GND" H 9905 3627 50  0000 C CNN
F 2 "" H 9900 3800 50  0001 C CNN
F 3 "" H 9900 3800 50  0001 C CNN
	1    9900 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 3750 9900 3800
Wire Wire Line
	9900 3750 10200 3750
Connection ~ 10200 3750
$Comp
L Transistor_BJT:BC548 Q1
U 1 1 5F4BF13E
P 2500 5750
F 0 "Q1" H 2691 5796 50  0000 L CNN
F 1 "BC548" H 2691 5705 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 2700 5675 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 2500 5750 50  0001 L CNN
	1    2500 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3550 5700 3700
Text GLabel 1350 5750 0    50   Input ~ 0
ENABLE
$Comp
L Device:Fuse F1
U 1 1 5F50642B
P 5700 3850
F 0 "F1" H 5760 3896 50  0000 L CNN
F 1 "5A" H 5760 3805 50  0000 L CNN
F 2 "Fuse:Fuseholder_Cylinder-5x20mm_Schurter_0031_8201_Horizontal_Open" V 5630 3850 50  0001 C CNN
F 3 "~" H 5700 3850 50  0001 C CNN
	1    5700 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 4000 5700 4300
$Comp
L power:GND #PWR0119
U 1 1 5F586E03
P 2600 6400
F 0 "#PWR0119" H 2600 6150 50  0001 C CNN
F 1 "GND" H 2605 6227 50  0000 C CNN
F 2 "" H 2600 6400 50  0001 C CNN
F 3 "" H 2600 6400 50  0001 C CNN
	1    2600 6400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5F598BC1
P 1900 5750
F 0 "R4" V 1693 5750 50  0000 C CNN
F 1 "4K3" V 1784 5750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 1830 5750 50  0001 C CNN
F 3 "~" H 1900 5750 50  0001 C CNN
	1    1900 5750
	0    1    1    0   
$EndComp
Wire Wire Line
	1350 5750 1750 5750
Wire Wire Line
	2050 5750 2200 5750
Wire Wire Line
	2600 5400 2600 5550
$Comp
L Device:R R5
U 1 1 5F5C9923
P 2200 6050
F 0 "R5" H 2270 6096 50  0000 L CNN
F 1 "5K" H 2270 6005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2130 6050 50  0001 C CNN
F 3 "~" H 2200 6050 50  0001 C CNN
	1    2200 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 5950 2600 6300
Wire Wire Line
	2200 5750 2200 5900
Connection ~ 2200 5750
Wire Wire Line
	2200 5750 2300 5750
Wire Wire Line
	2200 6200 2200 6300
Wire Wire Line
	2200 6300 2600 6300
Connection ~ 2600 6300
Wire Wire Line
	2600 6300 2600 6400
$Comp
L Device:R R6
U 1 1 5F5DDD0F
P 2600 5150
F 0 "R6" H 2670 5196 50  0000 L CNN
F 1 "1K" H 2670 5105 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2530 5150 50  0001 C CNN
F 3 "~" H 2600 5150 50  0001 C CNN
	1    2600 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 4900 2600 5000
Wire Wire Line
	2600 5300 2600 5400
Connection ~ 2600 5400
Wire Wire Line
	2600 5400 5000 5400
Text GLabel 3300 4800 0    50   Input ~ 0
ENABLE
$Comp
L Device:R R7
U 1 1 5F665EE7
P 3850 4950
F 0 "R7" H 3920 4996 50  0000 L CNN
F 1 "1K" H 3920 4905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3780 4950 50  0001 C CNN
F 3 "~" H 3850 4950 50  0001 C CNN
	1    3850 4950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 5F68BB45
P 3850 5150
F 0 "#PWR0120" H 3850 4900 50  0001 C CNN
F 1 "GND" H 3855 4977 50  0000 C CNN
F 2 "" H 3850 5150 50  0001 C CNN
F 3 "" H 3850 5150 50  0001 C CNN
	1    3850 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 5100 3850 5150
Wire Wire Line
	3850 4800 5000 4800
Wire Wire Line
	3300 4800 3850 4800
Connection ~ 3850 4800
Text GLabel 8200 1100 0    50   Output ~ 0
AD
Text GLabel 7350 5700 3    50   Output ~ 0
AD
Wire Wire Line
	7350 5500 7350 5700
Connection ~ 7350 5500
Wire Wire Line
	7350 5500 7750 5500
$Comp
L Connector_Generic:Conn_01x06 AD1
U 1 1 5F510A72
P 8400 800
F 0 "AD1" H 8480 746 50  0000 L CNN
F 1 "Conn_01x06" H 8480 701 50  0001 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x06_P2.00mm_Vertical" H 8400 800 50  0001 C CNN
F 3 "~" H 8400 800 50  0001 C CNN
	1    8400 800 
	1    0    0    -1  
$EndComp
$EndSCHEMATC
