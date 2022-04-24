import enum
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import serial
import args_position
import if_plot


arduino = serial.Serial()
arduino.port = 'COM3'
arduino.baudrate = 9600
arduino.timeout = .1
arduino.open()
if arduino.is_open == True:
    print("Port is open!\n")
    print(arduino, "\n")

# Create figure for plotting
fig = plt.figure()
ax = fig.add_subplot()
time = []
speed_ref = []
speed_sensor = []
curr_ref = []
curr_sensor = []
control_signal = []
time_of_simulation = 1000

flog = open('../data/log.txt', 'w')
flog.write("CLK,speed_ref,speed_sensor,curr_ref,curr_sensor,ctr_sig\n")
# This function is called periodically from FuncAnimation


def animate(i):

    line = b''
    while (line == b''):
        line = arduino.readline()  # ascii
    print(line)
    flog.write(str(line)[2:-3] + '\n')

    line_as_list = line.split(b',')

    time.append(int(line_as_list[args_position.Time]))

    if time[-1] > time_of_simulation:
        exit()

    speed_ref.append(
        int(line_as_list[args_position.Speed_ref].split(b'\n')[0]))
    speed_sensor.append(
        int(line_as_list[args_position.Speed_sensor].split(b'\n')[0]))
    curr_ref.append(
        int(line_as_list[args_position.Curr_ref].split(b'\n')[0]))
    curr_sensor.append(
        int(line_as_list[args_position.Curr_sensor].split(b'\n')[0]))
    control_signal.append(
        int(line_as_list[args_position.Control_signal].split(b'\n')[0]))

    # Draw x and y lists
    ax.clear()
    if if_plot.if_plot['Speed_sensor'] == True:
        ax.plot(time, speed_sensor, label="Speed sensor")
    if if_plot.if_plot['Speed_ref'] == True:
        ax.plot(time, speed_ref, label="Speed ref")
    if if_plot.if_plot['Curr_sensor'] == True:
        ax.plot(time, curr_sensor, label="Current sensor")
    if if_plot.if_plot['Curr_ref'] == True:
        ax.plot(time, curr_ref, label="Current ref")
    if if_plot.if_plot['Control_signal'] == True:
        ax.plot(time, control_signal, label="Control Signal")

    # Format plot
    plt.xticks(rotation=45, ha='right')
    plt.subplots_adjust(bottom=0.30)
    plt.title('My Plotter')
    plt.ylabel('Value')
    plt.legend()
    plt.axis([1, time_of_simulation, None, None])


list_of_args = (time, curr_ref)
ani = animation.FuncAnimation(
    fig, animate, interval=100)
plt.show()


flog.close()
