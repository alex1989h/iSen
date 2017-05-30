from pylab import *
from numpy import genfromtxt
import numpy as np
#import math

def quadrat(x):
  return x ** 2

def compute_standard_deviation(data,size):
  result = np.zeros(len(data)-size+1)
  average = 0.0
  variance = 0.0
  for i in range(0,len(result)):
    average = 0.0
    variance = 0.0
    # Den Durchschnitt berechnen
    for j in range (i,size+i):
      average = average + data[j]
    average = average/size
    # Die Varianz berechnen
    for j in range (i,size+i):
      variance = variance + quadrat(data[j] - average)
    variance = variance/(size-1)
    # Noch die Wurzel ziehen
    result[i] = sqrt(variance)
  return result



p = 5

d = genfromtxt('feature_gen_dataset1.csv', delimiter=',')
#d = [3,4,1,10,11,20,5,6,7,8,20]
subplot(p,1,1)
plot(d[:,3])
ylabel('Acceleration (m/s^2)')
title('IMU Linear Acceleration Measurements')
grid(True)


f = compute_standard_deviation(d[:,3],50)
subplot(p,1,3)
plot(f)
ylabel('Acceleration (m/s^2)')
title('Standard Deviation with buffer of 50')
grid(True)

f = compute_standard_deviation(d[:,3],300)
subplot(p,1,5)
plot(f)
ylabel('Acceleration (m/s^2)')
title('Standard Deviation with buffer of 300')
grid(True)

savefig("standard_deviation.png")
show()
