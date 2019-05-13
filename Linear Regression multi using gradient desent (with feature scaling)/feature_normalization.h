#include<bits/stdc++.h>
using namespace std;

feature_normalization(double X[1000][5],int size,int m,node s[10]){
	int i,j;
	
	unsigned long long int sum=0; 
	double sum1=0;
	
	double mu,si;
	
	for(j=1 ; j<m ; j++){
		sum=0;
		sum1=0;
    	for(i=0 ; i<size ; i++)	 sum=sum+X[i][j];
	
	    mu=(double)sum/size;
	 	sum1=0;
	    
		for(i=0 ; i<size ; i++)    sum1=sum1+pow((X[i][j]-mu),2);
	
	 	si=sum1/size;
	    si=sqrt(si);
    	
		for(i=0 ; i<size ; i++)   X[i][j]=(X[i][j]-mu)/si;
	    
	    
	    s[j].mu=mu;
    	s[j].si=si;
	    
	}
	
}
