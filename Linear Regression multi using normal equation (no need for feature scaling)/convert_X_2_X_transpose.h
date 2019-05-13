#include<bits/stdc++.h>
using namespace std;

void function_convert_X_2_Xtranspose(double X[100][100],double X_transpose[100][100],int m,int n){
	
	int i,j;
	for(i=0 ; i<n ; i++){
		for(j= 0; j<m ; j++){
			X_transpose[j][i]=X[i][j];
		}
	}
	
}
