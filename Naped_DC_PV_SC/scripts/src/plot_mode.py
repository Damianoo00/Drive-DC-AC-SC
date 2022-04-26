from matplotlib.animation import FuncAnimation
import src.animations as animations
from matplotlib import pyplot as plt
import pandas as pd
import serial
import params


def PlotSerial(send_uart_dest: str, column: str, serial_device: serial.Serial):
    fig, axes = plt.subplots(figsize=(10, 5))
    plt.style.use("ggplot")

    time, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal = [], [], [], [], [], []

    if send_uart_dest == "":
        anim = FuncAnimation(fig, animations.get_animate, fargs=(
            time, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal, axes, serial_device), interval=100)

    else:
        prepard_data = pd.read_csv(send_uart_dest)[column]
        anim = FuncAnimation(fig, animations.recive_n_get_animate, fargs=(
            prepard_data, time, speed_ref, speed_sensor, curr_ref, curr_sensor, control_signal, axes, serial_device), interval=100)

    plt.show()


def PlotLogs():
    fig, axes = plt.subplots(figsize=(10, 5))
    plt.style.use("ggplot")
    data = pd.read_csv('../data/log.txt')
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
