import serial
from time import sleep
import src.log as log
import params


def get_params_from_serial_device(serial_device: serial.Serial):

    line = b''
    while (line == b''):
        line = serial_device.readline()  # ascii
    print(line)

    log.log_data(line)

    line_as_list = line.split(b',')
    time = int(line_as_list[0])
    speed_ref = int(line_as_list[1].split(b'\n')[0])
    speed_sensor = int(line_as_list[2].split(b'\n')[0])
    curr_ref = int(line_as_list[3].split(b'\n')[0])
    curr_sensor = int(line_as_list[4].split(b'\n')[0])
    control_signal = int(line_as_list[5].split(b'\n')[0])

    return time, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal


def send_n_get_params_from_serial_device(value, serial_device: serial.Serial):

    print(int(value))
    serial_device.write(bytes(str(int(value)) + '\n', 'utf-8'))
    sleep(0.05)

    line = serial_device.readline()  # ascii
    if line != b'':
        print(line)
        log.log_data(line)

        line_as_list = line.split(b',')
        time = int(line_as_list[0])
        speed_ref = int(line_as_list[1].split(b'\n')[0])
        speed_sensor = int(line_as_list[2].split(b'\n')[0])
        curr_ref = int(line_as_list[3].split(b'\n')[0])
        curr_sensor = int(line_as_list[4].split(b'\n')[0])
        control_signal = int(line_as_list[5].split(b'\n')[0])

        return time, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal
    return 0, 0, 0, 0, 0, 0


def recive_n_get_animate(i, data_to_send: str, time: int, speed_ref: int, speed_sensor: int, curr_ref: int, curr_sensor: int, control_signal: int, axes, serial_device: serial.Serial):
    if (i > data_to_send.size):
        exit()

    time_v, speed_ref_v, speed_sensor_v, curr_ref_v, curr_sensor_v, control_signal_v = send_n_get_params_from_serial_device(
        data_to_send[i], serial_device)
    time.append(time_v)
    speed_ref.append(speed_ref_v)
    speed_sensor.append(speed_sensor_v)
    curr_ref.append(curr_ref_v)
    curr_sensor.append(curr_sensor_v)
    control_signal.append(control_signal_v)

    if params.SPEED_REF:
        axes.plot(time, speed_ref, label="Speed ref")
    if params.SPEED_SENSOR:
        axes.plot(time, speed_sensor, label="Speed sensor")
    if params.CURR_REF:
        axes.plot(time, curr_ref, label="Current ref")
    if params.CURR_SENSOR:
        axes.plot(time, curr_sensor, label="Current sensor")
    if params.CTR_SIG:
        axes.plot(time, control_signal, label="Control signal")


def get_animate(i, time: int, speed_ref: int, speed_sensor: int, curr_ref: int, curr_sensor: int, control_signal: int, axes, serial_device: serial.Serial):

    time_v, speed_ref_v, speed_sensor_v, curr_ref_v, curr_sensor_v, control_signal_v = get_params_from_serial_device(
        serial_device)
    time.append(time_v)
    speed_ref.append(speed_ref_v)
    speed_sensor.append(speed_sensor_v)
    curr_ref.append(curr_ref_v)
    curr_sensor.append(curr_sensor_v)
    control_signal.append(control_signal_v)

    if params.SPEED_REF:
        axes.plot(time, speed_ref, label="Speed ref")
    if params.SPEED_SENSOR:
        axes.plot(time, speed_sensor, label="Speed sensor")
    if params.CURR_REF:
        axes.plot(time, curr_ref, label="Current ref")
    if params.CURR_SENSOR:
        axes.plot(time, curr_sensor, label="Current sensor")
    if params.CTR_SIG:
        axes.plot(time, control_signal, label="Control signal")
