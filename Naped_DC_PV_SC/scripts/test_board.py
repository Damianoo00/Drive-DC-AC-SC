import serial
import time
import pandas as pd


sensors = pd.read_csv('../data/data.csv')
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.1)

with open('log.txt', 'w') as flog:
    flog.write("CLK,speed_ref,speed_sensor,curr_ref,curr_sensor,ctr_sig\n")
    for val in sensors['curr_sensor']:
        print(int(val))
        arduino.write(bytes(str(int(val)) + '\n', 'utf-8'))
        time.sleep(1)
        print(str(arduino.readline())[2:-3] + '\n')
        flog.write(str(arduino.readline())[2:-3] + '\n')
