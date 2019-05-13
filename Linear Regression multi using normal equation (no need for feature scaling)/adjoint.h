#include<bits/stdc++.h>
using namespace std;

void adjoint(double A[3][3],double adj[3][3]) 
{ 

  
    // temp is used to store cofactors of A[][] 
    int sign = 1;
	double temp[3][3]; 
  
    for (int i=0; i<3; i++) 
    { 
        for (int j=0; j<3; j++) 
        { 
            // Get cofactor of A[i][j] 
            getCofactor(A, temp, i, j, 3); 
  
            // sign of adj[j][i] positive if sum of row 
            // and column indexes is even. 
            sign = ((i+j)%2==0)? 1: -1; 
  
            // Interchanging rows and columns to get the 
            // transpose of the cofactor matrix 
            adj[j][i] = (sign)*(determinant(temp, 3-1)); 
        } 
    } 
} 
