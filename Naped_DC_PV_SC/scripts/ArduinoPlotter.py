""" Tool to plot values sended from board working as DC controller """

import serial
import src.plot_mode as plot_mode
import src.log as log
import argparse

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
parser.add_argument('--column', default="curr_sensor",
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

        # header of values saved in logger file
        log.logger_params(
            "CLK,pv_voltage,speed_ref,speed_sensor,curr_ref,curr_sensor,ctr_sig", args.log_file)

        if args.send:
            # Send data and plot board recive on it
            plot_mode.SendPlotSerial(
                args.send_data, args.column, arduino, args.log_file)
        else:
            # Only plot live recived data
            plot_mode.PlotSerial(arduino, args.log_file)

        arduino.close()
    else:
        # Plot data saved in log file
        plot_mode.PlotLogs(args.log_file)
