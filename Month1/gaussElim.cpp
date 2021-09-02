#include <iostream>
#include <string>
#include <math.h>

using namespace std;

double filter (double val){
    double small = 1.e-10;
    if(fabs(val) > small) return val;
    return 0;
}

bool isZero (double val){
    double small = 1.e-10;
    if(fabs(val) > small) return false;
    return true;
}

void printSystem (string message, int m, int n, double *A, double *b){
    cout << endl << "----------------------------" << endl << message << endl << "----------------------------" << endl;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%15.5e ", A[i*n + j]); 
        }
        cout << "  |  " << b[i];
        cout << endl;
    }
}

void findPivot(int m, int n, double *A, double *b, int row, int col){
    
    for(int colTry = col; colTry < n; colTry++){

    int largest = row;
    for(int i = row; i < n; i++){
        if(fabs(A[i*n + col]) > fabs(A[largest*n + col])){
            largest = i;
        }
    }
    //swapRows(m,n,A,b,row,largest);
    if(){ //if the whol row is zeros, do a dif row

    }
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
    double A[n][m] = { {1., 2., 3}, {0., 4., 5.}, {1, 1, 1} }; // "A" matrix
    double b[n]    =   {1., 2., 10}            ; // "b" right hand side

    printSystem("Original", m, n, &A[0][0], &b[0]);

    // -----------------------
    // Forward Phase - going to Echelon Form
    // -----------------------

    //going top down, row 0 to row n-1, identify pivots then use to eliminate non-zeros below pivots

    for(int pivotRow = 0; pivotRow < m; pivotRow++){
        //cout << "pivotRow = " << pivotRow  << " ... Eliminating all entries under A[" << pivotRow << "[]" << pivotRow  << "]" << endl;
        int pivotCol = 
        //eliminate non-zero entries underneath the top-most row we're considering
        for (int elimRow = pivotRow + 1; elimRow < m; elimRow++){
            double factor = A[elimRow][pivotCol] / A[pivotRow][pivotCol];

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

    //working bottom up (row n-1 to 0) identify pivot positions
    //then eliminate non-zero entries above the pivots

    for(int pivotRow = n-1; pivotRow >= 0; pivotRow--){
        for(int elimRow = pivotRow - 1; elimRow >=0; elimRow--){
            double factor = A[elimRow][pivotRow] / A[pivotRow][pivotRow];

            for(int i = 0; i < n; i++){
                A[elimRow][i] += A[pivotRow][i] * factor;
            }
        }
    }

    printSystem("After backward Phase", m, n, &A[0][0], &b[0]);

    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){

        }
    }

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