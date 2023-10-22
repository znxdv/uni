import os
import numpy as np
import matplotlib.pyplot as plt

os.system('cls' if os.name == 'nt' else 'clear')

year = [1981, 1983, 1985, 1987, 1989, 1991, 1993, 1995, 1997, 1999]
temperature = [14.1999, 14.2411, 14.0342, 14.2696, 14.197, 14.3055, 14.1853, 14.3577, 14.4187, 14.3438]

# Calculate the coefficients for a linear regression line
coefficients = np.polyfit(year, temperature, 1)

# Create a polynomial function using the coefficients
line = np.poly1d(coefficients)

# Generate x-values for the regression line
x = np.linspace(min(year), max(year), 100)

# Calculate corresponding y-values for the regression line
y = line(x)

# Create a scatter plot of the temperature data points
plt.scatter(year, temperature, color='blue', label='Temperature')

# Plot the regression line
plt.plot(x, y, color='red', label='Regression Line')

# Set labels and title for the plot
plt.xlabel('Year')
plt.ylabel('Temperature (Celsius)')
plt.title('Temperature Variation Over Time')

# Add a legend and grid to the plot
plt.legend()
plt.grid(True)

plt.show()