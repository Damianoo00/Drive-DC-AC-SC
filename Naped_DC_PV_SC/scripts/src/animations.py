import serial
from time import sleep
import src.log as log
import pandas as pd


def get_params_from_serial_device(serial_device: serial.Serial, log_file: str, num_of_params: int) -> list:
    """ read data from UART and print&plot it if response not empty """

    list_of_values = []
    line = b''
    while (line == b''):
        line = serial_device.readline()  # ascii
    print(line)

    log.log_data(line, log_file)

    line_as_list = line.split(b',')

    list_of_values.append(int(line_as_list[0]))
    for i in range(num_of_params - 1):
        list_of_values.append(int(line_as_list[i+1].split(b'\n')[0]))

    return list_of_values


def send_n_get_params_from_serial_device(values: pd.DataFrame, serial_device: serial.Serial, log_file: str, num_of_params: int) -> list:
    """ after sending data read from UART and print&plot it if response not empty """

    list_of_values = []
    #print(values)
    for value in values.values.tolist()[0]:
        print(value)
        serial_device.write(bytes(str(int(value)) + '\n', 'utf-8'))
        sleep(0.05)

    line = serial_device.readline()  # ascii
    print(line)
    if line != b'':
        print(line)
        log.log_data(line, log_file)

        line_as_list = line.split(b',')

        list_of_values.append(int(line_as_list[0]))
        for i in range(num_of_params - 1):
            list_of_values.append(int(line_as_list[i+1].split(b'\n')[0]))

        return list_of_values
    return list_of_values


def send_n_get_animate(i, log_file: str, data_to_send: pd.DataFrame, log_data: tuple, axes, serial_device: serial.Serial):
    """ animate plot function for send&get mode"""


    list_of_values = send_n_get_params_from_serial_device(
        data_to_send.loc[data_to_send.index == i], serial_device, log_file, len(log_data))

    if (len(list_of_values) > 0):
        for i in range(len(log_data)):
            log_data[i].values.append(list_of_values[i])

    for i in range(len(log_data) - 1):
        if log_data[i+1].visible:
            axes.plot(log_data[0].values, log_data[i+1].values, label=log_data[i+1].label)


def get_animate(i, log_file: str,log_data: tuple, axes, serial_device: serial.Serial):
    """ animate plot function for get mode """

    list_of_values = get_params_from_serial_device(
        serial_device, log_file, len(log_data))
    for i in range(len(log_data)):
        log_data[i].values.append(list_of_values[i])

    for i in range(len(log_data) - 1):
        if log_data[i+1].visible:
            axes.plot(log_data[0].values, log_data[i+1].values, label=log_data[i+1].label)
