#include<bits/stdc++.h>
using namespace std;

int determinant(double A[3][3], int n) 
{ 
    int D = 0; // Initialize result 
  
    //  Base case : if matrix contains single element 
    if (n == 1) 
        return A[0][0]; 
  
    double temp[3][3]; // To store cofactors 
  
    int sign = 1;  // To store sign multiplier 
  
     // Iterate for each element of first row 
    for (int f = 0; f < n; f++) 
    { 
        // Getting Cofactor of A[0][f] 
        getCofactor(A, temp, 0, f, n); 
        D += sign * A[0][f] * determinant(temp, n - 1); 
  
        // terms are to be added with alternate sign 
        sign = -sign; 
    } 
  
    return D; 
} 
