#include<bits/stdc++.h>
using namespace std;

void f_inverse(double A[3][3],double inverse[3][3]) 
{ 
    // Find determinant of A[][] 
    int det = determinant(A, 3); 
    if (det == 0) 
    { 
        cout << "Singular matrix, can't find its inverse"; 
        return ;
    } 
  
    // Find adjoint 
    double adj[3][3]; 
    adjoint(A, adj); 
  
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
    for (int i=0; i<3; i++) 
        for (int j=0; j<3; j++) 
            inverse[i][j] = adj[i][j]/float(det); 
                       
  
} 
