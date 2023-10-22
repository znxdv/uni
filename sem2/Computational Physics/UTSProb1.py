import os
import numpy as np

os.system('cls' if os.name == 'nt' else 'clear')

#Function to create a dialog with the user. The user will input the coefficients of the equations to be solved. The function returns the equation matrix and the number of unknown variables.
def input_dialog():
    m = int(input("Enter the number of variables: "))
    a = [[0.0] * (m + 1) for i in range(m)]  # Create a matrix to store the coefficients and constants.
    for i in range(m):
        print("Enter the coefficients and the result of equation %d" % (i + 1))
        for j in range(m + 1):
            if j == m:
                b = float(input("Result of the equation: "))
                a[i][j] = b
            else:
                b = float(input("Coefficient %d: " % (j + 1)))
                a[i][j] = b
    a = np.array(a, dtype=float)
    return (a, m)

#Function to perform forward elimination. The function returns the matrix after elimination.
def forward_elimination(b, n):
    for i in range(n):
        if b[i][i] == 0.0:
            print("Error! The system of equations cannot be solved.")
            return None
        for j in range(i + 1, n):
            ratio = b[j][i] / b[i][i]
            for k in range(n + 1):
                b[j][k] = b[j][k] - ratio * b[i][k]
    return b  # Return the matrix after elimination.

#Function to perform back substitution. The function returns an array containing the solutions to the equations.
def back_substitution(c, n):
    y = np.zeros(n)
    y[n - 1] = c[n - 1][n] / c[n - 1][n - 1]
    for i in range(n - 2, -1, -1):
        y[i] = c[i][n]
        for j in range(i + 1, n):
            y[i] = y[i] - c[i][j] * y[j]
        y[i] /= c[i][i]
    return y  # Return an array of solutions.

matrix, m = input_dialog()  # Get the equation matrix and the number of variables from the user.
eliminated_matrix = forward_elimination(matrix, m)  # Perform forward elimination.
if eliminated_matrix is None:
    exit()
result = back_substitution(eliminated_matrix, m)  # Perform back substitution to find solutions.

print("Bricks: Rp {:.2f} /kg".format(result[0]))
print("Cement: Rp {:.2f} /kg".format(result[1]))
print("Steel: Rp {:.2f} /kg".format(result[2]))