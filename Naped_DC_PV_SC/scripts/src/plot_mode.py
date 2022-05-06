from cmath import log
from matplotlib.animation import FuncAnimation
import src.animations as animations
from matplotlib import pyplot as plt
import pandas as pd
import serial
from src.log_data import LogData


def PlotSerial(serial_device: serial.Serial, log_file: str, log_data: tuple):
    """ Only plot live recived data """

    fig, axes = plt.subplots(figsize=(10, 5))
    plt.style.use("ggplot")


    anim = FuncAnimation(fig, animations.get_animate, fargs=(
        log_file, log_data, axes, serial_device), interval=100)

    plt.show()


def SendPlotSerial(send_data: pd.DataFrame, serial_device: serial.Serial, log_file: str, log_data: tuple):
    """ Send data and plot board recive on it """

    fig, axes = plt.subplots(figsize=(10, 5))
    plt.style.use("ggplot")


    anim = FuncAnimation(fig, animations.send_n_get_animate, fargs=(
        log_file, send_data, log_data, axes, serial_device), interval=100)

    plt.show()


def PlotLogs(log_file: str, log_data: tuple):
    """ Plot data saved in log file """

    fig, axes = plt.subplots(figsize=(10, 5))
    plt.style.use("ggplot")

    data = pd.read_csv(log_file)

    for i in range(len(log_data)-1):
        if log_data[i+1].visible:
            axes.plot(data[log_data[0].label], data[log_data[i+1].label], label=log_data[i+1].label)
    
    plt.legend()
    plt.xlabel("Time [ms]")
    plt.show()
