EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_02x08_Top_Bottom J1
U 1 1 5F0EDBEF
P 1350 1450
F 0 "J1" H 2000 1225 50  0000 C CNN
F 1 "Conn_02x08_Top_Bottom" H 1400 1876 50  0001 C CNN
F 2 "" H 1350 1450 50  0001 C CNN
F 3 "~" H 1350 1450 50  0001 C CNN
	1    1350 1450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 Galileo
U 1 1 5F11F509
P 3500 2100
F 0 "Galileo" H 3580 2092 50  0000 L CNN
F 1 "io0 - io7" H 3580 2001 50  0000 L CNN
F 2 "" H 3500 2100 50  0001 C CNN
F 3 "~" H 3500 2100 50  0001 C CNN
	1    3500 2100
	1    0    0    -1  
$EndComp
Text GLabel 2250 2000 2    50   Input ~ 0
ELB1
Text GLabel 2250 2100 2    50   Input ~ 0
ELB2
Text GLabel 3300 2100 0    50   Input ~ 0
PWM
Text GLabel 3300 1900 0    50   Input ~ 0
ELB1
Text GLabel 3300 2000 0    50   Input ~ 0
ELB2
$EndSCHEMATC
