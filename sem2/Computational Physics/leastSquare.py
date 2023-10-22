import os
import numpy as np

os.system('cls' if os.name == 'nt' else 'clear')

year = np.array([1981, 1983, 1985, 1987, 1989, 1991, 1993, 1995, 1997, 1999])
temperature = np.array([14.1999, 14.2411, 14.0342, 14.2696, 14.197, 14.3055, 14.1853, 14.3577, 14.4187, 14.3438])

# Select even years and corresponding temperatures
evenYears = year[1::2]
evenTemperatur = temperature[1::2]

# Calculate deviations from the means of years and temperatures
X = evenYears - np.mean(evenYears)
Y = evenTemperatur - np.mean(evenTemperatur)

# Calculate the slope (b) and intercept (a) of the linear regression line
b = np.sum(X * Y) / np.sum(X ** 2)
a = np.mean(evenTemperatur) - b * np.mean(evenYears)

# Estimate temperatures for even years using the linear regression model
estimatedTemperatur = a + b * evenYears

for year, temperature in zip(evenYears, estimatedTemperatur):
    print(f"The estimated temperature for the {year} : {temperature:.4f} Celsius")
