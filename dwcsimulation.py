import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

width = 10  # cm
height = 5  # cm

particle_x = -1 
particle_y = height / 2  

np.random.seed(42)
num_gas_molecules = 20
gas_x = np.random.uniform(0, width, num_gas_molecules)
gas_y = np.random.uniform(0, height, num_gas_molecules)

num_anode_wires = 5
anode_x = np.full(num_anode_wires, width) 
anode_y = np.linspace(0, height, num_anode_wires)

electrons_x = []
electrons_y = []

def update(frame):
    global particle_x, electrons_x, electrons_y

    particle_x += 0.5 

    for i in range(num_gas_molecules):
        if abs(particle_x - gas_x[i]) < 0.3: 
            electrons_x.append(gas_x[i])
            electrons_y.append(gas_y[i])

    for i in range(len(electrons_x)):
        electrons_x[i] += (width - electrons_x[i]) * 0.1

    ax.clear()
    ax.set_xlim(-1, width + 1)
    ax.set_ylim(0, height)
    ax.set_title("Parçacık Geçişi ve İyonizasyon Süreci")
    ax.scatter(gas_x, gas_y, c='blue', marker='o', label="Gaz Molekülleri", alpha=0.5)
    ax.scatter(particle_x, particle_y, c='red', marker='o', s=100, label="Yüklü Parçacık")
    ax.scatter(electrons_x, electrons_y, c='cyan', marker='x', label="Serbest Elektronlar")
    ax.scatter(anode_x, anode_y, c='gold', marker='s', s=100, label="Anot Telleri")

    ax.legend(loc="upper right")

fig, ax = plt.subplots(figsize=(8, 4))
ani = animation.FuncAnimation(fig, update, frames=20, interval=300)

ani.save("dwc_iyonizasyon.gif", writer="pillow")

plt.show()
