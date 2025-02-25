import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 10, 100)
ion_density = np.exp(-x/2) * 6000  
plt.figure(figsize=(8, 5))
plt.plot(x, ion_density,                    label="İyonizasyon Yoğunluğu",                     color='r')
plt.xlabel("Dedektördeki Mesafe (cm)")
plt.ylabel("Üretilen Elektron Sayısı")
plt.title("Parçacık Geçişine Bağlı İyonizasyon Yoğunluğu")
plt.legend()
plt.grid()
plt.show()
