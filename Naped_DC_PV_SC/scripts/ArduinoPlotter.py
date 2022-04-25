from matplotlib import pyplot as plt


def PlotSerial():
    time = []
    speed_ref = []
    speed_sensor = []
    curr_ref = []
    curr_sensor = []
    control_signal = []

    # Create figure for plotting
    fig = plt.figure()
    ax = fig.add_subplot()
    time_of_simulation = 1000


flog = open('../data/log.txt', 'w')
flog.write("CLK,speed_ref,speed_sensor,curr_ref,curr_sensor,ctr_sig\n")


def logg_to_file():
    pass


def PlotLogs():
    pass


if __name__ == "__main__":
    PlotSerial()
    PlotLogs()
