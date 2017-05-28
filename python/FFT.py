from pylab import *
from numpy import genfromtxt
import numpy as np

def my_iir(data,alpha):
  filtered = np.zeros_like(data)
  for i in range(1,len(data)):
      filtered[i] = alpha*data[i]+(1-alpha)*filtered[i-1]
  return filtered

p = 2

d = genfromtxt('feature_gen_dataset1.csv', delimiter=',')
subplot(p,1,1)
plot(d[:,1])
ylabel('Acceleration (m/s^2)')
title('IMU Linear Acceleration Measurements')
grid(True)
savefig("Original.png")

t = np.linspace(0,2*np.pi, 1000, endpoint=True)
dt = t[1]-t[0]
fa = 1.0/dt
x = np.linspace(0,fa/2,1000,endpoint=True)
f = np.fft.fft(d[:,1])
subplot(p,1,2)
plt.plot(x[:1500],np.abs(f[:1000])/1000)
plt.xlim(-10,70)
plt.xlabel('Frequency ($Hz$)')
plt.ylabel('Amplitude')

title('')
grid(True)
savefig("Original.png")
show()


