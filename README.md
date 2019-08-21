#Program to plot the required hyperbola
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA




fig = plt.figure()
ax = fig.add_subplot(111, aspect='equal')
len = 1000
theta = np.linspace(-5,5,len)

#
#Eqn : x.T@V@x = F
V = np.array(([9,0],[0,-16]))
F = 144

eigval,eigvec = LA.eig(V)

D = np.diag(eigval)
P = eigvec
print("D=\n",D)
print("P=\n",P)



y = np.zeros((2,len))
y[0,:] = 1/eigval[0]*np.cosh(theta)
y[1,:] = 1/eigval[1]*np.sinh(theta)


y1 = np.linspace(-1,1,len)
y2 = np.sqrt((1-D[0,0]*np.power(y1,2))/(D[1,1]))
y3 = -1*np.sqrt((1-D[0,0]*np.power(y1,2))/(D[1,1]))
y = np.hstack((np.vstack((y1,y2)),np.vstack((y1,y3))))


#Plotting required hyperbola
plt.plot(x[0,:len],x[1,:len],color='r',label='Hyperbola')
plt.plot(x[0,len+1:],x[1,len+1:],color='r')

#Plotting the Normal
P = np.array([8,3*(3**0.5)]) 
B = np.array([25/2,0]) 
len =10

x_PB= np.zeros((2,len))
lam = np.linspace(-0.5,1,len)
for i in range(len):
  temp1 = P + lam[i]*(B-P)
  x_PB[:,i]= temp1.T
  
#PLotting the point on the hyperbola 
plt.plot(P[0], P[1], 'o')
plt.text(P[0] * (1 + 0.1), P[1] * (1 - 0.1) , 'P') 
 
#PLotting the Lines on the hyperbola
plt.plot(x_PB[0,:],x_PB[1,:],label='$Normal$')

plt.grid() 
ax.plot()
plt.xlabel('$x$');plt.ylabel('$y$')
plt.legend(loc='best')
plt.axis('equal')

plt.show()
