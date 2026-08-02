// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//




#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// accepts input for matrices row by row
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// prints matrix in a neatly aligned grid
void displayMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << mat[i][j];
        }
        cout << endl;
    }
}

// part a — swaps rows and columns to create the transpose
void transposeMatrix(int rows, int cols) {
    int mat[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];

    cout << "Enter elements of the matrix:" << endl;
    readMatrix(mat, rows, cols);

    // transposed[j][i] = mat[i][j] — swap row and column indices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = mat[i][j];
        }
    }

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(mat, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows);
}

// part b — element-wise addition of two same-sized matrices
void addMatrices() {
    int rows, cols;
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nMatrix A:" << endl;
    readMatrix(mat1, rows, cols);
    cout << "\nMatrix B:" << endl;
    readMatrix(mat2, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    cout << "\nA + B =" << endl;
    displayMatrix(result, rows, cols);
}

// part c — matrix multiplication
void multiplyMatrices() {
    int rowsA, colsA, rowsB, colsB;
    int matA[MAX_SIZE][MAX_SIZE], matB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    cout << "Enter rows and columns for Matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Matrix A:" << endl;
    readMatrix(matA, rowsA, colsA);

    cout << "Enter rows and columns for Matrix B: ";
    cin >> rowsB >> colsB;

    // columns of a must match rows of b for multiplication to work
    if (colsA != rowsB) {
        cout << "Error: Number of columns in A (" << colsA
             << ") must equal number of rows in B (" << rowsB << ")." << endl;
        return;
    }

    cout << "Matrix B:" << endl;
    readMatrix(matB, rowsB, colsB);

    // triple nested loop: row of a x col of b, summing products
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    cout << "\nA x B =" << endl;
    displayMatrix(result, rowsA, colsB);
}

int main() {
    int choice;
    cout << "Select matrix operation:\n"
         << "1. Transpose\n"
         << "2. Add two matrices\n"
         << "3. Multiply two matrices\n"
         << "Enter choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int rows, cols;
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            transposeMatrix(rows, cols);
            break;
        }
        case 2:
            addMatrices();
            break;
        case 3:
            multiplyMatrices();
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}

//end