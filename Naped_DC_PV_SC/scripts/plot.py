import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('log.txt')

print(data.head())

plt.plot(data["CLK"], data["curr_ref"], data['curr_sensor'])
plt.legend(['curr_ref', 'curr_sens'])
plt.show()
