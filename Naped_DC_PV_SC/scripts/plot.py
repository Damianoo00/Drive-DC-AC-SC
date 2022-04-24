import pandas as pd
import matplotlib.pyplot as plt
import if_plot

data = pd.read_csv('../data/log.txt')

ax = plt.subplot()

if if_plot.if_plot['Speed_sensor'] == True:
    ax.plot(data['CLK'], data['speed_sensor'], label="Speed sensor")
if if_plot.if_plot['Speed_ref'] == True:
    ax.plot(data['CLK'], data['speed_ref'], label="Speed ref")
if if_plot.if_plot['Curr_sensor'] == True:
    ax.plot(data['CLK'], data['curr_sensor'], label="Current sensor")
if if_plot.if_plot['Curr_ref'] == True:
    ax.plot(data['CLK'], data['curr_ref'], label="Current ref")
if if_plot.if_plot['Control_signal'] == True:
    ax.plot(data['CLK'], data['ctr_sig'], label="Control Signal")

    # Format plot
    plt.xticks(rotation=45, ha='right')
    plt.subplots_adjust(bottom=0.30)
    plt.title('My Plotter')
    plt.ylabel('Value')
    plt.legend()
    plt.show()
