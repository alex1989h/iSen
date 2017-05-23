from pylab import *

from numpy import genfromtxt
d = genfromtxt('feature_gen_dataset1.csv', delimiter=',')

#matplotlib:
plot(d[:,1])
#clf()
#plot(d[:,2])


#xlabel('Time (s)')
xlabel('Samples (Index)')
ylabel('Acceleration (m/s^2)')
title('IMU Linear Acceleration Measurements')
grid(True)
savefig("test.png")
show()

#t = arange(0.0, 2.0, 0.01)
#s = sin(2*pi*t)
#plot(t, s)

#d[:,0] = d[:,0]-1403770240184760
#d[:,0] = d[:,0]/1000000
#
#plot(d[:,0],d[:,1])

