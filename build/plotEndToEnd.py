import numpy as np
import matplotlib.pyplot as plt
import sys

x,y,stdev = np.loadtxt(sys.argv[1], unpack = True)
plt.plot(x,y)
plt.errorbar(x,y, yerr=stdev)

plt.xlabel(r'RW length')
plt.ylabel(r'EndToEnd Dist')
plt.title(r'Average end to end distance plot')
plt.grid(True)
plt.show()

