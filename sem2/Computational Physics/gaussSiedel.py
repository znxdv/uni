import os
import numpy as np

def diagonallyDominanceCheck(array):
    diagonal = np.diagonal(np.abs(array))
    off = np.sum(np.abs(array), axis=1) - diagonal
    print('\n')
    if np.all(diagonal > off):
        print(f'{"<< Matrix diagonally dominant >>":^108}\n\n')
    else:
        print(f'{"<< Matrix not diagonally dominant >>":^108}\n\n')

def gaussSiedel(prediction, iteration, epsilon):
    os.system('cls' if os.name == 'nt' else 'clear')
    
    # Define the coefficient matrix (array) of the system of equations
    array = np.array([10, -2, -1, -1], [-2, 10, -1, -1], [-1, -1, -2, 10], [-1, -1, 10, -2])
    
    # Initialize the solution vector (x) with the provided prediction
    xOld = np.array(prediction)
    konvergen = False
    print(f'\n\n{"[Iteration Results]":^108}')
    diagonallyDominanceCheck(array)
    print(f'{"Iter":^8} {"x1":^25} {"x2":^25} {"x3":^25} {"x4":^25}\n')

    # Perform Gauss-Seidel iterations
    for i in range(iteration):
        # Update x1 to x4 based on the Gauss-Seidel formula
        prediction[0] = (2 * prediction[1] + prediction[2] + prediction[3] + 3) / 10
        prediction[1] = (2 * prediction[0] + prediction[2] + prediction[3] + 15) / 10
        prediction[2] = (prediction[0] + prediction[1] - 10 * prediction[3] - 9) / (-2)
        prediction[3] = (prediction[0] + prediction[1] - 10 * prediction[2] + 27) / (-2)
        
        # Make a copy of the updated solution vector
        xCopy = np.array(prediction[0], prediction[1], prediction[2], prediction[3])
        
        # Calculate the change in x between iterations
        dx = np.sqrt(np.dot(xCopy - xOld, xCopy - xOld))
        print(f"{i+1:^8} {prediction[0]:^25.4f} {prediction[1]:^25.4f} {prediction[2]:^25.4f} {prediction[3]:^25.4f}\n")
        
        # Check for convergence based on the change in x
        if dx < epsilon:
            konvergen = True
            print('Converged')
            break

        # Update the old solution vector for the next iteration
        xOld = xCopy

    if not konvergen:
        print(f'\n{"Did not converge, increase the number of iterations!":^108}\n')

os.system('cls' if os.name == 'nt' else 'clear')

print("""

    2602225201 - Mhd. Fauzan Devinto
    -LA 75-

    Lab Assignment 1 : System of Linear Equations

    Given 4 equations:

    10x1 - 2x2 - x3 - x4 = 3
    -2x1 + 10x2 - x3 - x4 = 15
    -x1 - x2 - 2x3 + 10x4 = -9
    -x1 - x2 + 10x3 - 2x4 = 27

    Enter the following data to run the Gauss-Seidel operation...

    """)

prediction = list(map(float, input('Enter the initial predictions for x1, x2, x3, and x4: ').split()))
iteration = int(input('\nEnter the desired maximum number of iterations: '))
epsilon = float(input('\nEnter the value of Epsilon: '))

gaussSiedel(prediction, iteration, epsilon)