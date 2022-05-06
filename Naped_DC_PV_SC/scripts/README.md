# ArduinoPlotter

Plot, log and sand (to) from arduino in real time

## Befor first run
Run in Terminal
```sh
pip install -r requirements.txt
```
To download necessery python libs

## How to run

### From comand line
Go to terminal and enter:
```sh
python ArduinoPlotter.py -h
```
To get quick helper

#### To plot data from log file
```sh
python ArduinoPlotter.py
```
logs are located in *data/log.txt*

#### To plot live in time of reciving data from UART
Add line to *src/main.cp*
```cpp
#define LOG
```
Build project -> Upload -> Open terminal and run
```sh
python ArduinoPlotter.py -live
```

#### To send any data to daveice and plot its response
Add line to *src/main.cp*
```cpp
#define SET_CURR
or 
#define SET_VALUES
```
Build project -> Upload -> Open terminal and run
```sh
python ArduinoPlotter.py -live -send
```
#### You can also change some parameters via terminal
```sh
--send_data=[path]
```
Set path to file, from where will get data and send to UART (default=*../data/data.csv*)

```sh
--column=[str]
```
Choose columns from datafile (.csv), which will send to device [default=*Current,Speed*)

```sh
--baudrate=[number]
```
Set baudrate of UART (default=*115200*)

```sh
--timeout=[number]
```
Set UART timeout [s] (default=*0.1*)

```sh
--log_file=[str]
```
Set path to log file [default=../data/log.txt]

```sh
--port=[str]
```
Set port of board [default=COM3]

### Run From Tasks


>You must be in *Drive-DC-AC-SC/Naped_DC_PV_SC/* directory !!!!


Click *ctrl+alt+T* to open tasks list and choose one from:

>> Plotter: Live Plot

To plot in real time logs from device and save it in *data/log.txt*

>>Plotter: Logs Plot

To plot data from *data/log.txt*

>> Plotter: Send Live Plot

To send data from *data/data.csv* from columns current and speed to arduino and plot in real time it and save in *data/lpg.txt*

# PV Simulator

Recive voltage via uart from Arduino and set current pass from PV characteristic

## Befor first run
Run in Terminal
```sh
pip install -r requirements.txt
```
To download necessery python libs

## How to run

### From comand line
Go to terminal and enter:
```sh
python PV_Sim.py -h
```
To get quick helper

### Change parameters via terminal

```sh
--arduino_port=[str]
```
Set arduino USB port [default=COM3]

```sh
--dc_supply_port=[str]
```
Set dc supply USB port [default=COM7]

### From Tasks

> You must be in *Drive-DC-AC-SC/Naped_DC_PV_SC/* directory !!!!

Click *ctrl+alt+T* to open task:

>> Simulator: Simulate PV by DC supply

# Submodule Activate

Project consist of separate submodules:
- DC_CURR_CTR
- DC_SPEED_CTR
- ENC_Interface
- PV_CTR
- SC_CTR
- SYSTEM_CTR

And common space with libs and scripts.

Every submodule consist *main.cpp* function with main program and *README.md* file with some information about this them.

> To build and upload submodule you must previusly activate them 

## Befor first run
Run in Terminal
```sh
pip install -r requirements.txt
```
To download necessery python libs

## How to activate submodule

### By Hand
> Go to *Drive-DC-AC-SC/Naped_DC_PV_SC/src* and run
```sh
git submodule update --init [submodule_name]
```
And add to *Drive-DC-AC-SC/Naped_DC_PV_SC/platformio.ini*
```
[env:[submodule_name]]
platform = atmelavr
board = [board_model]
framework = arduino
src_filter = -<*> +<[submodule_name]/> +<share/>
lib_deps = mathertel/RotaryEncoder@^1.5.2
monitor_speed = [uart_baudrate]
```
which allow to build code from submodule


### Via terminal

Run in Terminal
```sh
python scripts/SubmoduleActivator.py -h
```
To show quick helper

```sh
python scripts/SubmoduleActivator.py -clear
```
To deactive all submodules and clear *platformio.ini* file

```sh
python scripts/SubmoduleActivator.py -activate
```
To activate any submodule and add necessary lines

#### You can also set parameters
```sh
--submodule=[str]
```
Set submodule name [default=SYSTEM_CTR]

```sh
--board=[str]
```
Set arduino board [default=uno]

```sh
--uart_baudrate=[str]
```
Set uart baudrate for board [default=115200]


### Via Tasks
> You must be in *Drive-DC-AC-SC/Naped_DC_PV_SC/* directory !!!!

Click *ctrl+alt+T* to open tasks list and choose one from:

>> Submodules: activate [submodule_name]

To active submodule and add necessery lines to *Drive-DC-AC-SC/Naped_DC_PV_SC/platformio.ini*

>> Submodules: clear all

To deactive all submodules and clear *Drive-DC-AC-SC/Naped_DC_PV_SC/platformio.ini*