import numpy as np
import scipy
import mpmath as mp
import matplotlib.pyplot as plt


x = np.loadtxt('./data/x_values.dat',dtype='double')
y = np.loadtxt('./data/y_values.dat',dtype='double')
z = np.loadtxt('./data/z_values.dat',dtype='double')
k = 0*np.ones(100)


plt.plot(x,y,label="Hyperbola")
plt.plot(x,z,label="Normal")
plt.plot(x,y)


plt.grid() 
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend()
plt.axis('equal')
plt.xlim((-5,40))
plt.ylim((-15,15))
plt.show() 
