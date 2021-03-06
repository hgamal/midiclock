EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Midiclock"
Date "2020-12-23"
Rev "1.0"
Comp "Haroldo Gamal"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L arduino:ArduinoProMicro U3
U 1 1 5FE2E884
P 7900 3450
F 0 "U3" H 7877 4265 50  0000 C CNN
F 1 "ArduinoProMicro" H 7877 4174 50  0000 C CNN
F 2 "" H 7470 3955 50  0001 C CNN
F 3 "" H 7470 3955 50  0001 C CNN
	1    7900 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5FE30860
P 5900 3150
F 0 "R4" H 5970 3196 50  0000 L CNN
F 1 "2.2k" H 5970 3105 50  0000 L CNN
F 2 "" V 5830 3150 50  0001 C CNN
F 3 "~" H 5900 3150 50  0001 C CNN
	1    5900 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3300 5900 3500
Wire Wire Line
	5900 3600 7200 3600
$Comp
L power:GND #PWR02
U 1 1 5FE31F15
P 5800 3650
F 0 "#PWR02" H 5800 3400 50  0001 C CNN
F 1 "GND" H 5805 3477 50  0000 C CNN
F 2 "" H 5800 3650 50  0001 C CNN
F 3 "" H 5800 3650 50  0001 C CNN
	1    5800 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3600 5800 3600
Wire Wire Line
	5800 3600 5800 3650
$Comp
L Connector:Conn_01x05_Male J4A1
U 1 1 5FE32958
P 5500 4200
F 0 "J4A1" H 5608 4581 50  0000 C CNN
F 1 "Encoder" H 5608 4490 50  0000 C CNN
F 2 "" H 5500 4200 50  0001 C CNN
F 3 "~" H 5500 4200 50  0001 C CNN
	1    5500 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5FE3475B
P 5800 4500
F 0 "#PWR03" H 5800 4250 50  0001 C CNN
F 1 "GND" H 5805 4327 50  0000 C CNN
F 2 "" H 5800 4500 50  0001 C CNN
F 3 "" H 5800 4500 50  0001 C CNN
	1    5800 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 4400 5800 4400
Wire Wire Line
	5800 4400 5800 4500
Wire Wire Line
	5700 4000 6200 4000
$Comp
L Device:R R5
U 1 1 5FE38862
P 6200 3150
F 0 "R5" H 6270 3196 50  0000 L CNN
F 1 "2.2k" H 6270 3105 50  0000 L CNN
F 2 "" V 6130 3150 50  0001 C CNN
F 3 "~" H 6200 3150 50  0001 C CNN
	1    6200 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3300 6200 4000
Connection ~ 6200 4000
Wire Wire Line
	6200 4000 7200 4000
Wire Wire Line
	5700 4100 6400 4100
Wire Wire Line
	6400 4100 6400 3900
Wire Wire Line
	6400 3900 7200 3900
Wire Wire Line
	5700 4200 6500 4200
Wire Wire Line
	6500 4200 6500 3800
Wire Wire Line
	6500 3800 7200 3800
$Comp
L Device:R R6
U 1 1 5FE3A99E
P 6500 3150
F 0 "R6" H 6570 3196 50  0000 L CNN
F 1 "2.2k" H 6570 3105 50  0000 L CNN
F 2 "" V 6430 3150 50  0001 C CNN
F 3 "~" H 6500 3150 50  0001 C CNN
	1    6500 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3300 6500 3800
Connection ~ 6500 3800
$Comp
L Device:R R7
U 1 1 5FE3B57E
P 6750 3700
F 0 "R7" V 6543 3700 50  0000 C CNN
F 1 "4.7k" V 6634 3700 50  0000 C CNN
F 2 "" V 6680 3700 50  0001 C CNN
F 3 "~" H 6750 3700 50  0001 C CNN
	1    6750 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	5700 4300 6300 4300
Wire Wire Line
	6300 4300 6300 3700
Wire Wire Line
	6300 3700 6600 3700
Wire Wire Line
	6900 3700 7200 3700
$Comp
L power:GND #PWR08
U 1 1 5FE3D741
P 7100 4200
F 0 "#PWR08" H 7100 3950 50  0001 C CNN
F 1 "GND" H 7105 4027 50  0000 C CNN
F 2 "" H 7100 4200 50  0001 C CNN
F 3 "" H 7100 4200 50  0001 C CNN
	1    7100 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 4200 7100 3200
Wire Wire Line
	7100 3100 7200 3100
Wire Wire Line
	7200 3200 7100 3200
Connection ~ 7100 3200
Wire Wire Line
	7100 3200 7100 3100
$Comp
L Connector:Conn_01x03_Male J3A1
U 1 1 5FE3E6E3
P 5500 1800
F 0 "J3A1" H 5608 2081 50  0000 C CNN
F 1 "PWR" H 5608 1990 50  0000 C CNN
F 2 "" H 5500 1800 50  0001 C CNN
F 3 "~" H 5500 1800 50  0001 C CNN
	1    5500 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5FE4021D
P 5800 2150
F 0 "#PWR01" H 5800 1900 50  0001 C CNN
F 1 "GND" H 5805 1977 50  0000 C CNN
F 2 "" H 5800 2150 50  0001 C CNN
F 3 "" H 5800 2150 50  0001 C CNN
	1    5800 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 1800 5800 1800
$Comp
L Regulator_Linear:L7905 U2
U 1 1 5FE4453C
P 7850 1700
F 0 "U2" H 7850 1458 50  0000 C CNN
F 1 "L7905" H 7850 1549 50  0000 C CNN
F 2 "" H 7850 1500 50  0001 C CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/c9/16/86/41/c7/2b/45/f2/CD00000450.pdf/files/CD00000450.pdf/jcr:content/translations/en.CD00000450.pdf" H 7850 1700 50  0001 C CNN
	1    7850 1700
	1    0    0    1   
$EndComp
Wire Wire Line
	5700 1900 5750 1900
Wire Wire Line
	5750 1900 5750 1700
Wire Wire Line
	5750 1700 5700 1700
Wire Wire Line
	8150 1700 8250 1700
Wire Wire Line
	6500 2550 6500 3000
Wire Wire Line
	6200 2550 6200 3000
Connection ~ 6200 2550
Wire Wire Line
	6200 2550 6500 2550
Wire Wire Line
	5900 2550 5900 3000
Wire Wire Line
	5900 2550 6200 2550
Wire Wire Line
	6500 2550 8650 2550
Wire Wire Line
	8650 2550 8650 3200
Wire Wire Line
	8650 3200 8550 3200
Connection ~ 6500 2550
Connection ~ 5750 1700
Wire Wire Line
	6850 1700 6950 1700
$Comp
L Device:C C3
U 1 1 5FE53DA4
P 6950 1900
F 0 "C3" H 7065 1946 50  0000 L CNN
F 1 "100n" H 7065 1855 50  0000 L CNN
F 2 "" H 6988 1750 50  0001 C CNN
F 3 "~" H 6950 1900 50  0001 C CNN
	1    6950 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 1700 6050 1700
$Comp
L Device:L L1
U 1 1 5FE4F82E
P 6700 1700
F 0 "L1" V 6890 1700 50  0000 C CNN
F 1 "220u" V 6799 1700 50  0000 C CNN
F 2 "" H 6700 1700 50  0001 C CNN
F 3 "~" H 6700 1700 50  0001 C CNN
	1    6700 1700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6450 1750 6450 1700
Connection ~ 6450 1700
Wire Wire Line
	6450 1700 6550 1700
Wire Wire Line
	6950 1750 6950 1700
Connection ~ 6950 1700
Wire Wire Line
	6950 1700 7400 1700
Wire Wire Line
	7850 2000 7850 2150
Wire Wire Line
	5800 1800 5800 2150
$Comp
L Device:CP C1
U 1 1 5FE5C276
P 6050 1900
F 0 "C1" H 6168 1946 50  0000 L CNN
F 1 "220u" H 6168 1855 50  0000 L CNN
F 2 "" H 6088 1750 50  0001 C CNN
F 3 "~" H 6050 1900 50  0001 C CNN
	1    6050 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 1750 6050 1700
Connection ~ 6050 1700
Wire Wire Line
	6050 1700 6450 1700
$Comp
L Device:CP C4
U 1 1 5FE63714
P 7400 1900
F 0 "C4" H 7518 1946 50  0000 L CNN
F 1 "100u" H 7518 1855 50  0000 L CNN
F 2 "" H 7438 1750 50  0001 C CNN
F 3 "~" H 7400 1900 50  0001 C CNN
	1    7400 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 1750 7400 1700
Connection ~ 7400 1700
Wire Wire Line
	7400 1700 7550 1700
$Comp
L power:GND #PWR04
U 1 1 5FE64EFC
P 6050 2150
F 0 "#PWR04" H 6050 1900 50  0001 C CNN
F 1 "GND" H 6055 1977 50  0000 C CNN
F 2 "" H 6050 2150 50  0001 C CNN
F 3 "" H 6050 2150 50  0001 C CNN
	1    6050 2150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5FE6545D
P 6450 2150
F 0 "#PWR05" H 6450 1900 50  0001 C CNN
F 1 "GND" H 6455 1977 50  0000 C CNN
F 2 "" H 6450 2150 50  0001 C CNN
F 3 "" H 6450 2150 50  0001 C CNN
	1    6450 2150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5FE656E7
P 6950 2150
F 0 "#PWR06" H 6950 1900 50  0001 C CNN
F 1 "GND" H 6955 1977 50  0000 C CNN
F 2 "" H 6950 2150 50  0001 C CNN
F 3 "" H 6950 2150 50  0001 C CNN
	1    6950 2150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5FE6596A
P 7400 2150
F 0 "#PWR010" H 7400 1900 50  0001 C CNN
F 1 "GND" H 7405 1977 50  0000 C CNN
F 2 "" H 7400 2150 50  0001 C CNN
F 3 "" H 7400 2150 50  0001 C CNN
	1    7400 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 2050 6050 2150
Wire Wire Line
	6450 2050 6450 2150
Wire Wire Line
	6950 2050 6950 2150
Wire Wire Line
	7400 2050 7400 2150
$Comp
L power:GND #PWR011
U 1 1 5FE6F9C0
P 7850 2150
F 0 "#PWR011" H 7850 1900 50  0001 C CNN
F 1 "GND" H 7855 1977 50  0000 C CNN
F 2 "" H 7850 2150 50  0001 C CNN
F 3 "" H 7850 2150 50  0001 C CNN
	1    7850 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5FE71536
P 8250 1900
F 0 "C5" H 8365 1946 50  0000 L CNN
F 1 "100n" H 8365 1855 50  0000 L CNN
F 2 "" H 8288 1750 50  0001 C CNN
F 3 "~" H 8250 1900 50  0001 C CNN
	1    8250 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 2050 8250 2150
$Comp
L power:GND #PWR012
U 1 1 5FE724DE
P 8250 2150
F 0 "#PWR012" H 8250 1900 50  0001 C CNN
F 1 "GND" H 8255 1977 50  0000 C CNN
F 2 "" H 8250 2150 50  0001 C CNN
F 3 "" H 8250 2150 50  0001 C CNN
	1    8250 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 1750 8250 1700
Connection ~ 8250 1700
Wire Wire Line
	8250 1700 8650 1700
Wire Wire Line
	8650 1700 8650 2550
Connection ~ 8650 2550
$Comp
L Connector:Conn_01x07_Male J4
U 1 1 5FE8BDF7
P 9900 3800
F 0 "J4" H 9872 3824 50  0000 R CNN
F 1 "OLED" H 9872 3733 50  0000 R CNN
F 2 "" H 9900 3800 50  0001 C CNN
F 3 "~" H 9900 3800 50  0001 C CNN
	1    9900 3800
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5FE8EAB0
P 9400 4200
F 0 "#PWR015" H 9400 3950 50  0001 C CNN
F 1 "GND" H 9405 4027 50  0000 C CNN
F 2 "" H 9400 4200 50  0001 C CNN
F 3 "" H 9400 4200 50  0001 C CNN
	1    9400 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 3500 9300 3200
Wire Wire Line
	9300 3200 8650 3200
Connection ~ 8650 3200
Wire Wire Line
	8550 3700 9700 3700
Wire Wire Line
	9700 3800 8650 3800
Wire Wire Line
	8650 3800 8650 3900
Wire Wire Line
	8650 3900 8550 3900
Wire Wire Line
	8550 3600 9200 3600
Wire Wire Line
	9200 3600 9200 3900
Wire Wire Line
	9200 3900 9700 3900
Wire Wire Line
	8550 3500 9100 3500
Wire Wire Line
	9100 3500 9100 4000
Wire Wire Line
	9100 4000 9700 4000
Wire Wire Line
	8550 3400 9000 3400
Wire Wire Line
	9000 3400 9000 4100
Wire Wire Line
	9000 4100 9700 4100
Wire Wire Line
	8550 3000 9400 3000
$Comp
L Switch:SW_Push SW3
U 1 1 5FE9EA30
P 9650 3100
F 0 "SW3" H 9650 3385 50  0000 C CNN
F 1 "Reset" H 9650 3294 50  0000 C CNN
F 2 "" H 9650 3300 50  0001 C CNN
F 3 "~" H 9650 3300 50  0001 C CNN
	1    9650 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5FEA6492
P 9850 3150
F 0 "#PWR016" H 9850 2900 50  0001 C CNN
F 1 "GND" H 9855 2977 50  0000 C CNN
F 2 "" H 9850 3150 50  0001 C CNN
F 3 "" H 9850 3150 50  0001 C CNN
	1    9850 3150
	1    0    0    -1  
$EndComp
$Comp
L Isolator:6N138 U1
U 1 1 5FEB3B9F
P 6550 5350
F 0 "U1" H 6550 5817 50  0000 C CNN
F 1 "6N138" H 6550 5726 50  0000 C CNN
F 2 "" H 6840 5050 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/HCPL2731-D.pdf" H 6840 5050 50  0001 C CNN
	1    6550 5350
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4007 D2
U 1 1 5FEBC32C
P 5900 5400
F 0 "D2" V 5854 5480 50  0000 L CNN
F 1 "1N4007" V 5945 5480 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 5900 5225 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 5900 5400 50  0001 C CNN
	1    5900 5400
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5FEBDA2E
P 5350 5250
F 0 "R2" V 5143 5250 50  0000 C CNN
F 1 "220" V 5234 5250 50  0000 C CNN
F 2 "" V 5280 5250 50  0001 C CNN
F 3 "~" H 5350 5250 50  0001 C CNN
	1    5350 5250
	0    1    1    0   
$EndComp
Wire Wire Line
	5500 5250 5900 5250
Connection ~ 5900 5250
Wire Wire Line
	5900 5250 6250 5250
Wire Wire Line
	6200 5550 6200 5450
Wire Wire Line
	6200 5450 6250 5450
Wire Wire Line
	5900 5550 6200 5550
Connection ~ 5900 5550
$Comp
L Connector:Conn_01x04_Male J1A1
U 1 1 5FEC6BBA
P 4300 5350
F 0 "J1A1" H 4408 5631 50  0000 C CNN
F 1 "MIDI" H 4408 5540 50  0000 C CNN
F 2 "" H 4300 5350 50  0001 C CNN
F 3 "~" H 4300 5350 50  0001 C CNN
	1    4300 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 5250 5200 5250
Wire Wire Line
	4500 5350 5800 5350
Wire Wire Line
	5800 5350 5800 5550
Wire Wire Line
	5800 5550 5900 5550
$Comp
L Device:R R1
U 1 1 5FECCFA2
P 4750 5550
F 0 "R1" V 4850 5550 50  0000 C CNN
F 1 "220" V 4950 5550 50  0000 C CNN
F 2 "" V 4680 5550 50  0001 C CNN
F 3 "~" H 4750 5550 50  0001 C CNN
	1    4750 5550
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 5550 4600 5550
Wire Wire Line
	4900 5550 5000 5550
Wire Wire Line
	5000 5550 5000 2900
Wire Wire Line
	5000 2900 7200 2900
$Comp
L Device:R R3
U 1 1 5FED5294
P 5350 5450
F 0 "R3" V 5450 5450 50  0000 C CNN
F 1 "220" V 5550 5450 50  0000 C CNN
F 2 "" V 5280 5450 50  0001 C CNN
F 3 "~" H 5350 5450 50  0001 C CNN
	1    5350 5450
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 5450 5200 5450
Wire Wire Line
	5500 5450 5700 5450
Wire Wire Line
	5700 5450 5700 4800
Wire Wire Line
	5700 4800 7050 4800
Wire Wire Line
	7050 4800 7050 5150
Wire Wire Line
	7050 5150 6850 5150
$Comp
L Device:R R9
U 1 1 5FEE213D
P 7300 5450
F 0 "R9" H 7230 5404 50  0000 R CNN
F 1 "4.7k" H 7230 5495 50  0000 R CNN
F 2 "" V 7230 5450 50  0001 C CNN
F 3 "~" H 7300 5450 50  0001 C CNN
	1    7300 5450
	-1   0    0    1   
$EndComp
Wire Wire Line
	6850 5250 7300 5250
Wire Wire Line
	7300 5250 7300 5300
$Comp
L power:GND #PWR09
U 1 1 5FEE62BC
P 7300 5650
F 0 "#PWR09" H 7300 5400 50  0001 C CNN
F 1 "GND" H 7305 5477 50  0000 C CNN
F 2 "" H 7300 5650 50  0001 C CNN
F 3 "" H 7300 5650 50  0001 C CNN
	1    7300 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 5600 7300 5650
$Comp
L power:GND #PWR07
U 1 1 5FEED683
P 7000 5650
F 0 "#PWR07" H 7000 5400 50  0001 C CNN
F 1 "GND" H 7005 5477 50  0000 C CNN
F 2 "" H 7000 5650 50  0001 C CNN
F 3 "" H 7000 5650 50  0001 C CNN
	1    7000 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 5550 7000 5550
Wire Wire Line
	7000 5550 7000 5650
$Comp
L Device:R R8
U 1 1 5FEF1939
P 7150 5000
F 0 "R8" H 7080 4954 50  0000 R CNN
F 1 "220" H 7080 5045 50  0000 R CNN
F 2 "" V 7080 5000 50  0001 C CNN
F 3 "~" H 7150 5000 50  0001 C CNN
	1    7150 5000
	-1   0    0    1   
$EndComp
Wire Wire Line
	7050 4800 7150 4800
Wire Wire Line
	7150 4800 7150 4850
Connection ~ 7050 4800
Wire Wire Line
	7150 5150 7150 5450
Wire Wire Line
	7150 5450 6950 5450
Wire Wire Line
	7200 3000 6950 3000
Wire Wire Line
	6950 3000 6950 5450
Connection ~ 6950 5450
Wire Wire Line
	6950 5450 6850 5450
Wire Wire Line
	5900 2550 5350 2550
Wire Wire Line
	5350 2550 5350 4800
Wire Wire Line
	5350 4800 5700 4800
Connection ~ 5900 2550
Connection ~ 5700 4800
Text Notes 9550 3500 0    50   ~ 0
Vcc
Text Notes 9550 3600 0    50   ~ 0
GND
Text Notes 9400 3700 0    50   ~ 0
D0/SCK
Text Notes 9400 3800 0    50   ~ 0
D1/MOSI
Text Notes 9550 3900 0    50   ~ 0
RES
Text Notes 9550 4000 0    50   ~ 0
DC
Text Notes 9550 4100 0    50   ~ 0
CS
$Comp
L aqy21:AQY21 U5
U 1 1 5FE42E99
P 8900 5000
F 0 "U5" H 9050 5100 60  0000 L CNN
F 1 "AQY211EH" H 9050 5000 60  0000 L CNN
F 2 "" H 8900 4950 60  0000 C CNN
F 3 "" H 8900 4950 60  0000 C CNN
	1    8900 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 5FE4753D
P 8900 4500
F 0 "R11" H 8970 4546 50  0000 L CNN
F 1 "4.7k" H 8970 4455 50  0000 L CNN
F 2 "" V 8830 4500 50  0001 C CNN
F 3 "~" H 8900 4500 50  0001 C CNN
	1    8900 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 5FE48098
P 8900 5350
F 0 "#PWR014" H 8900 5100 50  0001 C CNN
F 1 "GND" H 8905 5177 50  0000 C CNN
F 2 "" H 8900 5350 50  0001 C CNN
F 3 "" H 8900 5350 50  0001 C CNN
	1    8900 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 4000 8650 4000
Wire Wire Line
	8550 3300 8900 3300
Wire Wire Line
	8900 3300 8900 4350
Wire Wire Line
	8900 4650 8900 4750
Wire Wire Line
	8900 5250 8900 5350
Wire Wire Line
	8650 5250 8650 5350
Wire Wire Line
	8650 4650 8650 4750
Wire Wire Line
	8650 4000 8650 4350
$Comp
L power:GND #PWR013
U 1 1 5FE47C15
P 8650 5350
F 0 "#PWR013" H 8650 5100 50  0001 C CNN
F 1 "GND" H 8655 5177 50  0000 C CNN
F 2 "" H 8650 5350 50  0001 C CNN
F 3 "" H 8650 5350 50  0001 C CNN
	1    8650 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 5FE46AAB
P 8650 4500
F 0 "R10" H 8400 4550 50  0000 L CNN
F 1 "4.7k" H 8400 4450 50  0000 L CNN
F 2 "" V 8580 4500 50  0001 C CNN
F 3 "~" H 8650 4500 50  0001 C CNN
	1    8650 4500
	1    0    0    -1  
$EndComp
$Comp
L aqy21:AQY21 U4
U 1 1 5FE412B1
P 8650 5000
F 0 "U4" H 8350 5100 60  0000 L CNN
F 1 "AQY211EH" H 8050 5000 60  0000 L CNN
F 2 "" H 8650 4950 60  0000 C CNN
F 3 "" H 8650 4950 60  0000 C CNN
	1    8650 5000
	1    0    0    -1  
$EndComp
$Comp
L aqy21:AQY21 U4
U 2 1 5FE8A724
P 9800 5200
F 0 "U4" H 9750 5450 60  0000 C CNN
F 1 "AQY211EH" H 9900 5350 60  0000 C CNN
F 2 "" H 9800 5150 60  0000 C CNN
F 3 "" H 9800 5150 60  0000 C CNN
	2    9800 5200
	1    0    0    -1  
$EndComp
$Comp
L aqy21:AQY21 U5
U 2 1 5FE8BE42
P 9800 5850
F 0 "U5" H 9750 5700 60  0000 C CNN
F 1 "AQY211EH" H 9900 5600 60  0000 C CNN
F 2 "" H 9800 5800 60  0000 C CNN
F 3 "" H 9800 5800 60  0000 C CNN
	2    9800 5850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J5A1
U 1 1 5FE941F1
P 10400 5500
F 0 "J5A1" H 10372 5474 50  0000 R CNN
F 1 "SWITCHES" H 10372 5383 50  0000 R CNN
F 2 "" H 10400 5500 50  0001 C CNN
F 3 "~" H 10400 5500 50  0001 C CNN
	1    10400 5500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10200 5400 10100 5400
Wire Wire Line
	10100 5400 10100 5200
Wire Wire Line
	10100 5200 10050 5200
Wire Wire Line
	9550 5200 9500 5200
Wire Wire Line
	9500 5200 9500 5500
Wire Wire Line
	9500 5500 10200 5500
Wire Wire Line
	10050 5850 10100 5850
Wire Wire Line
	10100 5850 10100 5600
Wire Wire Line
	10100 5600 10200 5600
Wire Wire Line
	9550 5850 9500 5850
Wire Wire Line
	9500 5850 9500 5700
Wire Wire Line
	9500 5700 10200 5700
Wire Wire Line
	9850 3100 9850 3150
$Comp
L Device:C C2
U 1 1 5FE517CF
P 6450 1900
F 0 "C2" H 6565 1946 50  0000 L CNN
F 1 "100n" H 6565 1855 50  0000 L CNN
F 2 "" H 6488 1750 50  0001 C CNN
F 3 "~" H 6450 1900 50  0001 C CNN
	1    6450 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 3100 9450 3100
Wire Wire Line
	5700 3500 5900 3500
Connection ~ 5900 3500
Wire Wire Line
	5900 3500 5900 3600
Wire Wire Line
	9400 3000 9400 3600
Wire Wire Line
	9300 3500 9700 3500
Wire Wire Line
	9400 3600 9700 3600
Connection ~ 9400 3600
Wire Wire Line
	9400 3600 9400 4200
Wire Wire Line
	2600 5800 2600 5250
Wire Wire Line
	2600 5250 3600 5250
Wire Wire Line
	1900 5800 1900 5350
Wire Wire Line
	1900 5350 3600 5350
Wire Wire Line
	3450 5800 3450 5450
Wire Wire Line
	3450 5450 3600 5450
$Comp
L Connector:DIN-5_180degree J1
U 1 1 5FF69FB8
P 2250 5700
F 0 "J1" H 2250 5333 50  0000 C CNN
F 1 "MIDI IN" H 2250 5424 50  0000 C CNN
F 2 "" H 2250 5700 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 2250 5700 50  0001 C CNN
	1    2250 5700
	-1   0    0    1   
$EndComp
$Comp
L Connector:DIN-5_180degree J2
U 1 1 5FF6AA61
P 3050 5700
F 0 "J2" H 3050 5333 50  0000 C CNN
F 1 "MIDI OUT" H 3050 5424 50  0000 C CNN
F 2 "" H 3050 5700 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 3050 5700 50  0001 C CNN
	1    3050 5700
	-1   0    0    1   
$EndComp
Wire Wire Line
	3450 5800 3350 5800
Wire Wire Line
	2750 5800 2700 5800
Wire Wire Line
	2700 6050 3550 6050
Wire Wire Line
	3550 6050 3550 5550
Wire Wire Line
	3550 5550 3600 5550
Wire Wire Line
	2700 5800 2700 6050
Wire Wire Line
	2550 5800 2600 5800
Wire Wire Line
	1950 5800 1900 5800
$Comp
L Switch:SW_Push SW2
U 1 1 5FFBDEA1
P 3200 3500
F 0 "SW2" H 3200 3785 50  0000 C CNN
F 1 "Footswitch" H 3200 3694 50  0000 C CNN
F 2 "" H 3200 3700 50  0001 C CNN
F 3 "~" H 3200 3700 50  0001 C CNN
	1    3200 3500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J3B1
U 1 1 5FFBF37B
P 3800 3500
F 0 "J3B1" H 3750 3650 50  0000 L CNN
F 1 "TAP Switch" H 3750 3550 50  0000 L CNN
F 2 "" H 3800 3500 50  0001 C CNN
F 3 "~" H 3800 3500 50  0001 C CNN
	1    3800 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 3500 2950 3500
Wire Wire Line
	2950 3500 2950 3600
Wire Wire Line
	2950 3600 3600 3600
Wire Wire Line
	3400 3500 3600 3500
$Comp
L Device:Rotary_Encoder_Switch SW1
U 1 1 5FFEEB68
P 2150 4200
F 0 "SW1" V 2350 3950 50  0000 R CNN
F 1 "ENCODER" V 2250 3950 50  0000 R CNN
F 2 "" H 2000 4360 50  0001 C CNN
F 3 "~" H 2150 4460 50  0001 C CNN
	1    2150 4200
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x05_Female J4B1
U 1 1 5FFF2CD4
P 3800 4200
F 0 "J4B1" H 3828 4226 50  0000 L CNN
F 1 "Encoder Board" H 3828 4135 50  0000 L CNN
F 2 "" H 3800 4200 50  0001 C CNN
F 3 "~" H 3800 4200 50  0001 C CNN
	1    3800 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 4500 2050 4600
Wire Wire Line
	2050 4600 3100 4600
Wire Wire Line
	3100 4600 3100 4000
Wire Wire Line
	3100 4000 3600 4000
Wire Wire Line
	2250 4700 3200 4700
Wire Wire Line
	3200 4700 3200 4100
Wire Wire Line
	3200 4100 3600 4100
Wire Wire Line
	2250 4500 2250 4700
Wire Wire Line
	2150 4500 2150 4800
Wire Wire Line
	2150 4800 2550 4800
Wire Wire Line
	3300 4800 3300 4400
Wire Wire Line
	3300 4400 3600 4400
$Comp
L Device:LED D1
U 1 1 6001D6F2
P 2850 4300
F 0 "D1" H 2850 4200 50  0000 C CNN
F 1 "TAPLED" H 2850 4100 50  0000 C CNN
F 2 "" H 2850 4300 50  0001 C CNN
F 3 "~" H 2850 4300 50  0001 C CNN
	1    2850 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 4300 3600 4300
Wire Wire Line
	2700 4300 2550 4300
Wire Wire Line
	2550 4300 2550 4800
Connection ~ 2550 4800
Wire Wire Line
	2550 4800 3300 4800
Wire Wire Line
	2050 3900 2050 3850
Wire Wire Line
	2050 3850 1850 3850
Wire Wire Line
	1850 3850 1850 4800
Wire Wire Line
	1850 4800 2150 4800
Connection ~ 2150 4800
Wire Wire Line
	2250 3900 2250 3850
Wire Wire Line
	2250 3850 3300 3850
Wire Wire Line
	3300 3850 3300 4200
Wire Wire Line
	3300 4200 3600 4200
$Comp
L Connector:Conn_01x04_Female J1B1
U 1 1 5FF415DA
P 3800 5350
F 0 "J1B1" H 3650 5000 50  0000 L CNN
F 1 "MIDI Conn" H 3550 4900 50  0000 L CNN
F 2 "" H 3800 5350 50  0001 C CNN
F 3 "~" H 3800 5350 50  0001 C CNN
	1    3800 5350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Jack-DC J3
U 1 1 600B762C
P 2850 1800
F 0 "J3" H 2907 2125 50  0000 C CNN
F 1 "9V" H 2907 2034 50  0000 C CNN
F 2 "" H 2900 1760 50  0001 C CNN
F 3 "~" H 2900 1760 50  0001 C CNN
	1    2850 1800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J3B1
U 1 1 600B9B35
P 3800 1800
F 0 "J3B1" H 3828 1826 50  0000 L CNN
F 1 "Power" H 3828 1735 50  0000 L CNN
F 2 "" H 3800 1800 50  0001 C CNN
F 3 "~" H 3800 1800 50  0001 C CNN
	1    3800 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 1700 3350 1700
Wire Wire Line
	3350 1700 3350 1800
Wire Wire Line
	3350 1800 3600 1800
Wire Wire Line
	3150 1900 3500 1900
Wire Wire Line
	3500 1900 3500 1700
Wire Wire Line
	3500 1700 3600 1700
Connection ~ 3500 1900
Wire Wire Line
	3500 1900 3600 1900
$Comp
L Connector:Conn_01x02_Male J3A1
U 1 1 5FE3163C
P 5500 3500
F 0 "J3A1" H 5608 3681 50  0000 C CNN
F 1 "TAP" H 5608 3590 50  0000 C CNN
F 2 "" H 5500 3500 50  0001 C CNN
F 3 "~" H 5500 3500 50  0001 C CNN
	1    5500 3500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J5B1
U 1 1 600FA2E2
P 3800 2550
F 0 "J5B1" H 3650 2200 50  0000 L CNN
F 1 "SWITCHES" H 3550 2100 50  0000 L CNN
F 2 "" H 3800 2550 50  0001 C CNN
F 3 "~" H 3800 2550 50  0001 C CNN
	1    3800 2550
	1    0    0    -1  
$EndComp
$Comp
L jack:Jack-Mono J5
U 1 1 5FE4ABF4
P 1450 2650
F 0 "J5" H 1323 2554 50  0000 R CNN
F 1 "SWITCH 1" H 1323 2645 50  0000 R CNN
F 2 "Jack-Mono" H 1450 2800 50  0001 C CNN
F 3 "" H 1450 2650 50  0001 C CNN
	1    1450 2650
	1    0    0    1   
$EndComp
$Comp
L jack:Jack-Mono J6
U 1 1 5FE4C274
P 2550 2650
F 0 "J6" H 2423 2554 50  0000 R CNN
F 1 "SWITCH 2" H 2423 2645 50  0000 R CNN
F 2 "Jack-Mono" H 2550 2800 50  0001 C CNN
F 3 "" H 2550 2650 50  0001 C CNN
	1    2550 2650
	1    0    0    1   
$EndComp
Wire Wire Line
	3050 2450 3600 2450
Wire Wire Line
	3050 2850 3300 2850
Wire Wire Line
	3300 2850 3300 2550
Wire Wire Line
	3300 2550 3600 2550
Wire Wire Line
	1950 2450 2200 2450
Wire Wire Line
	2200 2450 2200 2950
Wire Wire Line
	2200 2950 3400 2950
Wire Wire Line
	3400 2950 3400 2650
Wire Wire Line
	3400 2650 3600 2650
Wire Wire Line
	1950 2850 1950 3050
Wire Wire Line
	1950 3050 3500 3050
Wire Wire Line
	3500 3050 3500 2750
Wire Wire Line
	3500 2750 3600 2750
$EndSCHEMATC
