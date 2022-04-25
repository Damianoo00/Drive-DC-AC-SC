# ArduinoPlotter

This programm allow to plot:
- speed_ref
- speed_sensor
- curr_ref
- curr_sensor
To test of Analog inputs, Comunication protocols and writing code.

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
```sh
python ArduinoPlotter.py -live
```

### To send any data to daveice and plot its response
```sh
python ArduinoPlotter.py -live --send_data=[path_to_datafile]
```
data must be in (.csv) format