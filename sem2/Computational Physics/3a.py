import os   
import numpy as np

os.system('cls' if os.name == 'nt' else 'clear')

def f(x):
    return x**3 - 0.3*x**2 - 8.56*x + 8.448

# Define the interval [a, b] and the number of subintervals (n).
a = 0
b = 2*np.pi
n = 20

# Calculate the width of each subinterval (h).
h = (b - a) / (n - 1)

# Create an array of x values evenly spaced between a and b.
x = np.linspace(a, b, n)

# Calculate the corresponding y values for the function f(x).
y = f(x)

# Calculate the left Riemann sum using the formula (h * sum of y values excluding the last one).
left = h * sum(y[:n-1])

# Calculate the right Riemann sum using the formula (h * sum of y values excluding the first one).
right = h * sum(y[1:])

# Calculate the x values at the midpoint of each subinterval.
x_new = (x[:n-1] + x[1:]) / 2

# Calculate the corresponding y values for the function f(x_new).
y_new = f(x_new)

# Calculate the middle Riemann sum using the formula (h * sum of y values at the midpoints).
mid = h * sum(y_new)

# Calculate the Trapezoidal rule using the formula (h/2 * sum of y values with adjusted weights).
trpz = (h/2) * (y[0] + 2 * sum(y[1:n-1]) + y[n-1])

# Calculate Simpson's rule using the formula (h/3 * sum of y values with adjusted weights).
simp = (h/3) * (y[0] + 2 * sum(y[:n-2:2]) + 4 * sum(y[1:n-1:2]) + y[n-1])

print('Trapezoid : %.4f' % trpz)
print("Simpson : %.4f" % simp)
print("Right Riemann : %.4f" % right)
print("Middle Riemann : %.4f" % mid)
print("Left Riemann : %.4f\n" % left)