#include <stdio.h>
#include <math.h>

// Gauss Jacobi
const int n = 4; // Fixed grid size for 4x4 matrix

// Function to perform the Jacobi iteration for 2D Laplace equation
void jacobi(float u[n][n], int iterations) {
    float u_new[n][n];
    for (int iter = 0; iter < iterations; ++iter) {
        // Copy the current values of u to u_new
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                u_new[i][j] = u[i][j];
        }
        // Initial case: Apply diagonal formula for u[1][1]
        if (iter == 0) {
            u_new[1][1] = 0.25 * (u[0][0] + u[0][2] + u[2][0] + u[2][2]);
            u[1][1] = 0.25 * (u[0][0] + u[0][2] + u[2][0] + u[2][2]);
        }
        // Update values using Jacobi iteration for all points
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                // Use the standard Jacobi formula for all points
                if(iter == 0 && i ==1 && j==1){
                    continue;
                }
                if(iter == 0)
                u_new[i][j] = 0.25 * (u_new[i + 1][j] + u_new[i - 1][j] + u_new[i][j + 1] + u_new[i][j - 1]);
                else
                    u_new[i][j] = 0.25 * (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1]);
            }
        }
        // Copy the new values back to u
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                u[i][j] = u_new[i][j];
        }

        // Print the matrix after each iteration
        printf("Iteration:%d\n",iter + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                printf("%7.2f\t",u[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int iterations;
    float u[n][n];
    printf("Enter the number of iterations: ");
    scanf("%d",&iterations);
    // Input boundary conditions
    printf("Enter the boundary conditions:\n");
    printf("top boundary (4 values):\n");
    for (int j = 0; j < n; ++j) {
        scanf("%f",&u[0][j]); // Bottom row
    }
    printf("Bottom boundary (4 values):\n");
    for (int j = 0; j < n; ++j) {
        scanf("%f",&u[n - 1][j]); // Top row
    }
    printf("Left middle boundary (2 values):\n");
    for (int i = 1; i < n - 1; ++i) {
        scanf("%f",&u[i][0]); // Left column
    }
    printf("Right middle boundary (2 values):\n");
    for (int i = 1; i < n - 1; ++i) {
        scanf("%f",&u[i][n - 1]); // Right column
    }
    // Initialize interior points to zero or another initial guess
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            u[i][j] = 0.0; // Initial guess
        }
    }
    // Solve using Jacobi iteration
    jacobi(u, iterations);
    return 0;
}

