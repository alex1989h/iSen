from pylab import *
from numpy import genfromtxt
import numpy as np

def my_iir(data,alpha):
  filtered = np.zeros_like(data)
  for i in range(1,len(data)):
      filtered[i] = alpha*data[i]+(1-alpha)*filtered[i-1]
  return filtered

p = 11

d = genfromtxt('feature_gen_dataset1.csv', delimiter=',')
subplot(p,1,1)
plot(d[:,1])
ylabel('Acceleration (m/s^2)')
title('IMU Linear Acceleration Measurements')
grid(True)


f = my_iir(d[:,1],0.1)
subplot(p,1,3)
plot(f)
ylabel('Acceleration (m/s^2)')
title('Gefiltert mit alpha 0,1')
grid(True)

f = my_iir(d[:,1],0.02)
subplot(p,1,5)
plot(f)
ylabel('Acceleration (m/s^2)')
title('Gefiltert mit alpha 0,02')
grid(True)

f = my_iir(d[:,1],0.01)
subplot(p,1,7)
plot(f)
ylabel('Acceleration (m/s^2)')
title('Gefiltert mit alpha 0,01')
grid(True)

f = my_iir(d[:,1],0.005)
subplot(p,1,9)
plot(f)
ylabel('Acceleration (m/s^2)')
title('Gefiltert mit alpha 0,005')
grid(True)

f = my_iir(d[:,1],0.9)
subplot(p,1,11)
plot(f)
xlabel('Samples (Index)')
ylabel('Acceleration (m/s^2)')
title('Gefiltert mit alpha 0,9')
grid(True)

savefig("gefiltert_iir.png")
show()
