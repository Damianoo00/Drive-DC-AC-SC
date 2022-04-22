import serial
import time
import pandas as pd


def logg_data_from_uart(serial_device: serial.Serial, log_path: str):
    logg_dest = open(logg_dest, 'w')
    while True:
        logg_dest.write(str(serial_device.readline())[2:-1])
    logg_dest.close()


arduino = serial.Serial(port='COM3', baudrate=9600, timeout=1)
logg_data_from_uart(arduino, 'log.txt')
