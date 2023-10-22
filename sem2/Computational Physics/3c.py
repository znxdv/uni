import os
import numpy as np

os.system('cls' if os.name == 'nt' else 'clear')

# Given data points (x, y).
x = [-1.1, -0.3, 0.8, 1.9]
y = [15.180, 10.962, 1.920, -2.040]

# Point at which you want to find the interpolated value.
xi = 0

# Number of data points.
n = len(x)

# Initialize a matrix for divided differences.
mOt = np.zeros((n, n))
mOt[:, 0] = y

# Calculate the divided differences.
for j in range(1, n):
    for i in range(0, n - j):
        mOt[i, j] = (mOt[i + 1, j - 1] - mOt[0, j - 1]) / (x[i + j] - x[j - 1])

# Initialize the interpolating polynomial value.
p = mOt[0, 0]

# Calculate the polynomial value at xi using Horner's method.
for i in range(1, n):
    a = mOt[0, i]
    for j in range(0, i):
        a = a * (xi - x[j])
    p = p + a

print("Interpolated value at xi =", p)
print("Divided Differences Matrix (mOt):")
print(mOt)