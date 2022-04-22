import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('data.csv')

print(data.head())

plt.plot(data["Time"], data["Continuous PID Controller"])
plt.legend(['Continous PID'])
plt.show()
