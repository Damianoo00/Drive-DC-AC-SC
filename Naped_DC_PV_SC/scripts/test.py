# Importing Libraries
import serial
from serial_param import BAUDRATE, PORT, TIMEOUT
import time
arduino = serial.Serial(port=PORT, baudrate=BAUDRATE, timeout=TIMEOUT)


def write_read(x):
    arduino.write(bytes(x + '\n', 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data


while True:
    num = input("Enter a number: ")  # Taking input from user
    value = write_read(num)
    print(value)  # printing the value
