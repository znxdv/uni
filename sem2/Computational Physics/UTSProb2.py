import os
import numpy as np
import matplotlib.pyplot as plt

os.system('cls' if os.name == 'nt' else 'clear')

F = np.array([60, 120, 180, 240, 300, 360, 420, 480, 540, 600])  # Force (N)
x = np.array([2.6, 3.1, 4.6, 6.5, 8.5, 11.0, 15.2, 34.7, 65.8, 69.4])  # Extension (cm)

# Plot the data points
plt.plot(x, F, 'o')
plt.xlabel('Extension (cm)')
plt.ylabel('Force (N)')
plt.title('Experimental Data of a Spring')

# Calculate the correlation coefficient (r) and coefficient of determination (R^2)
r = np.corrcoef(F, x)[0, 1]
R2 = r**2
print("Correlation coefficient (r): {:.3f}".format(r))
print("Coefficient of determination (R^2): {:.3f}".format(R2))

# Plot the linear trendline
z = np.polyfit(x, F, 1)
p = np.poly1d(z)
plt.plot(x, p(x), "r--")
print("\nLinear trendline equation:")
print("F(x) = {:.2f}x + {:.2f}".format(z[0], z[1]))

# Linear interpolation at x = 26 cm
x1 = 26
F1_linear = np.interp(x1, x, F)
print("Force required to extend the spring by 26 cm using linear interpolation:")
print("F({:.1f}) = {:.2f} N".format(x1, F1_linear))

# Quadratic interpolation
z2 = np.polyfit(x, F, 2)
p2 = np.poly1d(z2)
F1_quadratic = p2(x1)
print("Force required to extend the spring by 26 cm using quadratic interpolation:")
print("F({:.1f}) = {:.2f} N".format(x1, F1_quadratic))

# Calculate relative errors
F1_trend = p(x1)
error_linear = abs(F1_linear - F1_trend) / F1_trend * 100
error_quadratic = abs(F1_quadratic - F1_trend) / F1_trend * 100
print("\nRelative error of linear interpolation with respect to the trendline: {:.2f}%".format(error_linear))
print("Relative error of quadratic interpolation with respect to the trendline: {:.2f}%".format(error_quadratic))

# Check if the data is matched with the equation F = k * x
if R2 > 0.99:
    print("\nThe data is matched with the equation F = k * x\n")
else:
    print("\nThe data is not matched with the equation F = k * x\n")

plt.show()