#include <iostream>
#include <string>

using namespace std;

void printSystem (string message, int m, int n, double *A, double *b){
    cout << endl << "----------------------------" << endl << message << endl << "----------------------------" << endl;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%15.5e ", A[i*n + j]); 
        }
        cout << endl;
    }
}

int main(){
    int m; // num rows
    int n; // num columns

    // -----------------------
    // Set Matrix and right hand side, Ax = b
    // -----------------------

    n = 3;
    m = 3;
    double A[n][m] = { {1., 2., 3}, {3., 4., 5}, {1, 1, 1} }; // "A" matrix
    double b[n]    =   {1., 2., 10}            ; // "b" right hand side

    printSystem("Original", m, n, &A[0][0], &b[0]);

    // -----------------------
    // Forward Phase - going to Echelon Form
    // -----------------------

    //going top down, row 0 to row n-1, identify pivots then use to eliminate non-zeros below pivots

    for(int pivotRow = 0; pivotRow < m; pivotRow++){
        //cout << "pivotRow = " << pivotRow  << " ... Eliminating all entries under A[" << pivotRow << "[]" << pivotRow  << "]" << endl;

        //eliminate non-zero entries underneath the top-most row we're considering
        for (int elimRow = pivotRow + 1; elimRow < m; elimRow++){
            double factor = A[elimRow][pivotRow] / A[pivotRow][pivotRow];

            //cout << "-- now effecting row " << pivotRow << endl;
            
            //loop over columns, performing elementary row operations
            for(int i = 0; i < n; i++){
                A[elimRow][i] += A[pivotRow][i] * factor;
            }
        }  
    }

    printSystem("After Forward Phase", m, n, &A[0][0], &b[0]);

    // -----------------------
    // Backward Phase
    // -----------------------

    // -----------------------
    // Check Results
    // -----------------------

    // -----------------------
    // Find Free Variables
    // -----------------------

    // -----------------------
    // Print Solution Space
    // -----------------------
}