import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import (AutoMinorLocator, MultipleLocator)


with open("res.txt", "r") as f:
    x1=[]
    y1=[]
    i=0
    for line in f:
        data=line.split(" ")
        x1.append(float(data[0]))
        y1.append(float(data[1]))

# Диапазон осей
X_LIM_BOTTOM = 0
Y_LIM_BOTTOM = 0

X_LIM_UP = 100
Y_LIM_UP = 9000

fig, ax = plt.subplots(figsize=(10, 8))

# Диапазоны осей
ax.set_xlim(X_LIM_BOTTOM, X_LIM_UP)
ax.set_ylim(Y_LIM_BOTTOM, Y_LIM_UP)

# Шаг сетки для главных делений
ax.xaxis.set_major_locator(MultipleLocator(10))
ax.yaxis.set_major_locator(MultipleLocator(1000))

# Количество промежутков между главными делениями
ax.xaxis.set_minor_locator(AutoMinorLocator(5))
ax.yaxis.set_minor_locator(AutoMinorLocator(5))

# Сетка для главных и дополнительных делений
ax.grid(which='major', color='#CCCCCC', linestyle='--')
ax.grid(which='minor', color='#CCCCCC', linestyle=':')

# Подписи осей
params = {'mathtext.default': 'regular' }          
plt.rcParams.update(params)
plt.xlabel('n')
plt.ylabel('t')

# Название графика
plt.title('График 1. Зависимость t(n)')

h1 = np.arange(X_LIM_BOTTOM, X_LIM_UP, (X_LIM_UP-X_LIM_BOTTOM)/100)

plt.plot(x1, y1, 'o', markersize = 3, color = '#FF0000')

plt.show()