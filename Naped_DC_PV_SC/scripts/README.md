# ArduinoPlotter

This programm allow to plot:
- speed_ref
- speed_sensor
- curr_ref
- curr_sensor

To test of Analog inputs, Comunication protocols and writing code.

## Choose showing plots
It's possible to hide any plot by set appropriate parametr in *scripts/params.py* to *False*

```python
# scripts/params.py

SPEED_REF = False
SPEED_SENSOR = False
CURR_REF = True
CURR_SENSOR = True
CTR_SIG = False
```

## Befor first run
Run in Terminal
```sh
pip install -r requirements.txt
```
To download essensial python libs
## How to run
Go to terminal and enter:
```sh
python ArduinoPlotter.py -h
```
To get quick helper

### To plot data from log file
```sh
python ArduinoPlotter.py
```
logs are located in *data/log.txt*

### To plot live in time of reciving data from UART
Add line to *src/main.cp*
```cpp
#define LOG
```
Build project -> Upload -> Open terminal and run
```sh
python ArduinoPlotter.py -live
```

### To send any data to daveice and plot its response
Add line to *src/main.cp*
```cpp
#define SET_CURR
```
Build project -> Upload -> Open terminal and run
```sh
python ArduinoPlotter.py -live -send
```
### You can also change some parameters via terminal
```sh
--send_data=[path]
```
Set path to file, from where will get data and send to UART (default=*../data/data.csv*)

```sh
--column=[str]
```
Choose column from datafile (.csv), which will send to device [default=*curr_sensor*)

```sh
--baudrate=[number]
```
Set baudrate of UART (default=*115200*)

```sh
--timeout=[number]
```
Set UART timeout [s] (default=*0.1*)