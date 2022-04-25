import serial
import time
import pandas as pd
from serial_param import PORT, BAUDRATE, TIMEOUT


sensors = pd.read_csv('../data/data.csv')
arduino = serial.Serial(port=PORT, baudrate=BAUDRATE, timeout=TIMEOUT)

with open('../data/log.txt', 'w') as flog:
    flog.write("CLK,speed_ref,speed_sensor,curr_ref,curr_sensor,ctr_sig\n")
    for val in sensors['curr_sensor']:
        print(int(val))
        arduino.write(bytes(str(int(val)) + '\n', 'utf-8'))
        time.sleep(0.05)
        response = str(arduino.readline())[2:-3]
        print(response)
        flog.write(response + '\n')
