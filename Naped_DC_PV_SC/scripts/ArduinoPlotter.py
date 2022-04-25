import time
import serial
from serial_param import PORT, BAUDRATE, TIMEOUT
from matplotlib import pyplot as plt
from matplotlib.animation import FuncAnimation
import pandas as pd

arduino = serial.Serial()
arduino.port = PORT
arduino.baudrate = BAUDRATE
arduino.timeout = TIMEOUT
arduino.open()

time, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal = [], [], [], [], [], []
fig, axes = plt.subplots(figsize=(10, 5))

# set limit for x and y axis
#axes.set_ylim(-100, 500)
#axes.set_xlim(0, 250)

# style for plotting line
plt.style.use("ggplot")

sensors = pd.read_csv('../data/data.csv')


def log_data(line: str):
    with open('../data/log.txt', "a") as flog:
        flog.write(str(line)[2:-3] + '\n')


def get_params_from_arduino():

    line = b''
    while (line == b''):
        line = arduino.readline()  # ascii
    print(line)

    log_data(line)

    line_as_list = line.split(b',')
    time = int(line_as_list[0])
    speed_ref = int(line_as_list[1].split(b'\n')[0])
    speed_sensor = int(line_as_list[2].split(b'\n')[0])
    curr_ref = int(line_as_list[3].split(b'\n')[0])
    curr_sensor = int(line_as_list[4].split(b'\n')[0])
    control_signal = int(line_as_list[5].split(b'\n')[0])

    return time, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal


def send_n_get_params_from_arduino():
    for val in sensors['curr_sensor']:
        print(int(val))
        arduino.write(bytes(str(int(val)) + '\n', 'utf-8'))
        line = b''

        while (line == b''):
            line = arduino.readline()  # ascii
        print(line)

        log_data(line)

        line_as_list = line.split(b',')
        time = int(line_as_list[0])
        speed_ref = int(line_as_list[1].split(b'\n')[0])
        speed_sensor = int(line_as_list[2].split(b'\n')[0])
        curr_ref = int(line_as_list[3].split(b'\n')[0])
        curr_sensor = int(line_as_list[4].split(b'\n')[0])
        control_signal = int(line_as_list[5].split(b'\n')[0])

        return time, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal


def animate(i):
    time_v, speed_ref_v, speed_sensor_v, curr_ref_v, curr_sensor_v, control_signal_v = get_params_from_arduino()
    time.append(time_v)
    speed_ref.append(speed_ref_v)
    speed_sensor.append(speed_sensor_v)
    curr_ref.append(curr_ref_v)
    curr_sensor.append(curr_sensor_v)
    control_signal.append(control_signal_v)

    axes.plot(time, speed_ref, label="Speed ref")
    axes.plot(time, speed_sensor, label="Speed sensor")
    axes.plot(time, curr_ref, label="Current ref")
    axes.plot(time, curr_sensor, label="Current sensor")
    axes.plot(time, control_signal, label="Control signal")


def PlotSerial():

    anim = FuncAnimation(fig, animate, interval=100)
    plt.show()


def PlotLogs():
    data = pd.read_csv('../data/log.txt')

    axes.plot(data["CLK"], data["speed_ref"], label="Speed ref")
    axes.plot(data["CLK"], data["speed_sensor"], label="Speed sensor")
    axes.plot(data["CLK"], data["curr_ref"], label="Current ref")
    axes.plot(data["CLK"], data["curr_sensor"], label="Current sensor")
    axes.plot(data["CLK"], data["ctr_sig"], label="Control signal")
    plt.legend()
    plt.show()


def logger_params(params: str):
    flog = open('../data/log.txt', 'w')
    flog.write(params + '\n')
    flog.close()


if __name__ == "__main__":
    logger_params("CLK,speed_ref,speed_sensor,curr_ref,curr_sensor,ctr_sig")
    PlotSerial()
    arduino.close()
    # PlotLogs()
