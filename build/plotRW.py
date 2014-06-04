import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt
import sys

x,y,z = np.loadtxt(sys.argv[1], unpack = True)

mpl.rcParams['legend.fontsize'] = 10

fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot(x, y, z, label='parametric curve')
plt.title(r'Random Walk with $N = 100$ steps')
plt.show()