import serial
import src.plot_mode as plot_mode
import src.log as log
import argparse

parser = argparse.ArgumentParser(
    description="To plot saved data run programm without any '-live' flag")
parser.add_argument('-live', action='store_true', default=False,
                    help="Set flag to plot live recived data from UART")
parser.add_argument('--send_data', default="",
                    help="Set path to file, from where will get data and send to UART (if not set only revive data without sending anything)")
parser.add_argument('--column', default="",
                    help="Choose column from datafile, which will send to device")
parser.add_argument('--port', default='COM3', help="Set port of board")
parser.add_argument('--baudrate', default=115200, help="Set baudrate of UART")
parser.add_argument('--timeout', default=0.1, help="Set UART timeout [s]")

if __name__ == "__main__":

    args = parser.parse_args()

    if args.live:
        arduino = serial.Serial()
        arduino.port = args.port
        arduino.baudrate = args.baudrate
        arduino.timeout = args.timeout
        arduino.open()
        log.logger_params(
            "CLK,speed_ref,speed_sensor,curr_ref,curr_sensor,ctr_sig")

        plot_mode.PlotSerial(args.send_data, args.column, arduino)
        arduino.close()
    else:
        plot_mode.PlotLogs()
