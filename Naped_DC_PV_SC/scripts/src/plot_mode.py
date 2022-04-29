from cmath import log
from matplotlib.animation import FuncAnimation
import src.animations as animations
from matplotlib import pyplot as plt
import pandas as pd
import serial
import params


def PlotSerial(serial_device: serial.Serial, log_file: str):
    """ Only plot live recived data """

    fig, axes = plt.subplots(figsize=(10, 5))
    plt.style.use("ggplot")

    time, pv_voltage, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal = [], [], [], [], [], [], []

    anim = FuncAnimation(fig, animations.get_animate, fargs=(
        log_file, time, pv_voltage, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal, axes, serial_device), interval=100)

    plt.show()


def SendPlotSerial(send_uart_dest: str, column: str, serial_device: serial.Serial, log_file: str):
    """ Send data and plot board recive on it """

    fig, axes = plt.subplots(figsize=(10, 5))
    plt.style.use("ggplot")

    time, pv_voltage, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal = [], [], [], [], [], []

    prepard_data = pd.read_csv(send_uart_dest)[column]
    anim = FuncAnimation(fig, animations.send_n_get_animate, fargs=(
        log_file, prepard_data, time, pv_voltage, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal, axes, serial_device), interval=100)

    plt.show()


def PlotLogs(log_file: str):
    """ Plot data saved in log file """

    fig, axes = plt.subplots(figsize=(10, 5))
    plt.style.use("ggplot")
    data = pd.read_csv(log_file)
    if params.PV_VOLTAGE:
        axes.plot(data["CLK"], data["pv_voltage"], label="PV Voltage")
    if params.SPEED_REF:
        axes.plot(data["CLK"], data["speed_ref"], label="Speed ref")
    if params.SPEED_SENSOR:
        axes.plot(data["CLK"], data["speed_sensor"], label="Speed sensor")
    if params.CURR_REF:
        axes.plot(data["CLK"], data["curr_ref"], label="Current ref")
    if params.CURR_SENSOR:
        axes.plot(data["CLK"], data["curr_sensor"], label="Current sensor")
    if params.CTR_SIG:
        axes.plot(data["CLK"], data["ctr_sig"], label="Control signal")
    plt.legend()
    plt.xlabel("Time [ms]")
    plt.show()
