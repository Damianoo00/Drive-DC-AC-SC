""" Tool to plot values sended from board working as DC controller """

import serial
import time
import src.plot_mode as plot_mode
import src.log as log
import argparse
from src.log_data import LogData
import pandas as pd

# Termial params
parser = argparse.ArgumentParser(
    description="To plot saved data run programm without any '-live' flag")
parser.add_argument('-live', action='store_true', default=False,
                    help="Set flag to plot live recived data from UART")
parser.add_argument('-send', action='store_true', default=False,
                    help="Set flag to send data from file to UART")
parser.add_argument('--send_data', default="../data/data.csv",
                    help="Set path to file, from where will get data and send to UART\
                        [default=../data/data.csv]")
parser.add_argument('--log_file', default="../data/log.txt",
                    help="Set path to log file [default=../data/log.txt]")
parser.add_argument('--column', default="Current,Speed",
                    help="Choose column from datafile, which will send to device [default=curr_sensor]")
parser.add_argument('--port', default='COM3',
                    help="Set port of board [default=COM3]")
parser.add_argument('--baudrate', default=115200,
                    help="Set baudrate of UART [default=115200]")
parser.add_argument('--timeout', default=0.1,
                    help="Set UART timeout [s] [default=0.1]")


if __name__ == "__main__":

    args = parser.parse_args()

    if args.live:

        # serial connection params
        arduino = serial.Serial()
        arduino.port = args.port
        arduino.baudrate = args.baudrate
        arduino.timeout = args.timeout
        arduino.open()
        time.sleep(1.64)

        # header of values saved in logger file
        log.get_logger_header(
            arduino, args.log_file)


        log_data = log.get_paramlist(args.log_file)

        if args.send:
            # Send data and plot board recive on it

            send_data = pd.DataFrame()
            columns = args.column.split(",")
            for column in columns:
                send_data[column] = pd.read_csv(args.send_data)[column]
            
            plot_mode.SendPlotSerial(
                send_data, arduino, args.log_file, log_data)
        else:
            # Only plot live recived data
            plot_mode.PlotSerial(arduino, args.log_file, log_data)

        arduino.close()
    else:
        # Plot data saved in log file
        log_data = log.get_paramlist(args.log_file)

        plot_mode.PlotLogs(args.log_file, log_data)
