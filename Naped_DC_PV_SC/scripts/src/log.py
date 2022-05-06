import serial
import time
from src.log_data import LogData

def get_logger_header(device: serial.Serial(), log_file: str):
    """ Write header to log file """
    device.write(b'?')
    header = str(device.readline())[2:-3]
    
    flog = open(log_file, 'w')
    flog.write(header + '\n')
    flog.close()


def log_data(line: str, log_file: str):
    """ log data as str in log file """

    with open(log_file, "a") as flog:
        flog.write(str(line)[2:-3] + '\n')

def get_paramlist(log_file: str) -> list:
    """ read list of parameters from log header """
    list_of_params = []
    with open(log_file, 'r') as fheader:
            params = fheader.readline()[:-1].split(',')
            for param in params:
                list_of_params.append(LogData(label=param, visible=True))
    return list_of_params