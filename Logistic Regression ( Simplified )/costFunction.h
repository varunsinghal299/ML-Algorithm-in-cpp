#include<bits/stdc++.h>
#include"sigmoid.h"

using namespace std;

costfunction(long double X[1000][10],long double y[1000],long double theta[10],long double &cost,double alpha,int no_of_iteration,int n,int m){
	
	int i,j,k;
	double temp; 
	cost=0.0;
	
	for(i=0 ; i<n ; i++){
		
		if(y[i]==1){
			temp=theta[0]*X[i][0] + theta[1]*X[i][1] + theta[2]*X[i][2];
			temp=sigmoid_func(temp);
			
			cost=cost+(-1)*(log(temp));
		}
		else if(y[i]==0){
			temp=theta[0]*X[i][0] + theta[1]*X[i][1] + theta[2]*X[i][2];
			cost=cost+(-1)*(log(1-temp));
		}
		
	}
	
	cost=cost/n;
	
	
	
	long double J;
	
	
	for(i=0 ; i<no_of_iteration ; i++){
		
		for(j=0 ; j<m  ; j++){
			
			temp=0;
			J=0;
			for(k=0 ; k<n ; k++){
				
				temp=theta[0]*X[k][0] + theta[1]*X[k][1] + theta[2]*X[k][2];
				temp=sigmoid_func(temp);
				
				temp=temp-y[k];
				temp=temp*X[k][j];
				
				J=J+temp;
			}
			J=J/n;
			theta[j]=theta[j]-(alpha)*J;
		}
					
	}
	
	
}



