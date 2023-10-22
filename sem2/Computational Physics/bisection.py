import os

os.system('cls' if os.name == 'nt' else 'clear')
print("2602225201 - Mhd. Fauzan Devinto - LAB Scientific Assignment\n")

def bisection(f, a, b, tol):
    R = [(a + b) / 2]
    E = [abs(f(R[0]))]

    # Continue iterating as long as the error at the last iteration is greater than or equal to tol
    while E[-1] >= tol:
        # Check if f(a) and f(R[-1]) have opposite signs
        if f(a) * f(R[-1]) < 0:
            b = R[-1]
        else:
            a = R[-1]

        # Calculate the new midpoint for the [a, b] interval and add it to the list R
        R.append((a + b) / 2)

        # Calculate the new error and add it to the list E
        E.append(abs(f(R[-1])))

    return R, E

import numpy as np

# Define the first function f(x) = x^2 - 2
f = lambda x: x ** 2 - 2

# Use the bisection method on f with the interval [0, 2] and tolerance 1e-1
[R, E] = bisection(f, 0, 2, 1e-1)

print(f"R = {R}")
print(f"E = {E}")

# Define the second function f(x) = sin(x) - cos(x)
f = lambda x: np.sin(x) - np.cos(x)

# Use the bisection method on f with the interval [0, 2] and tolerance 1e-2
[R, E] = bisection(f, 0, 2, 1e-2)

print(f"R = {R}")
print(f"E = {E}\n")