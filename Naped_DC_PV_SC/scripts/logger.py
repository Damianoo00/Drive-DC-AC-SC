import serial
import time
import pandas as pd


def logg_data_from_uart(serial_device: serial.Serial, log_path: str):
    log_dest = open(log_path, 'w')
    log_dest.write(
        "CLK,speed_ref,speed_sensor,curr_ref,curr_sensor,ctr_sig\n")
    while True:
        # print(str(serial_device.readline())[2:-1])
        log_dest.write(str(serial_device.readline())[2:-3] + '\n')
    logg_dest.close()


arduino = serial.Serial(port='COM3', baudrate=9600, timeout=1)
try:
    logg_data_from_uart(arduino, 'log.txt')
except(KeyboardInterrupt):
    print("Interupt")
