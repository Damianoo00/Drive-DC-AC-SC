import serial
import time
import pandas as pd


sensors = pd.read_csv('sensor_val.txt')
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=0.1)

with open('log.txt', 'w') as flog:
    for val in sensors['curr_sensor']:
        arduino.write(bytes(str(val) + '\n', 'utf-8'))
        time.sleep(0.05)
        flog.write(str(arduino.readline())[2:-3] + '\n')
