#include<bits/stdc++.h>
using namespace std;

void gradient_descent(double X[100][5],double y[100],double theta[10],double alp,int no_of_iter,int size,int lamda){

	int i,j,k,l;
	double sum1,sum2,sum;

	for(i=0 ; i<no_of_iter ; i++){

		for(j=0 ; j<3 ; j++){

         sum1=0.0;
         sum2=0.0;
           for(k=0 ; k<size ; k++){
 
           	sum1=0.0;
           	for(l=0  ; l<3 ; l++){
           		sum1=sum1+theta[l]*X[k][l];
           	}

           	sum1=sum1-y[k];
           	sum1=sum1*X[k][j];
           	sum2=sum2+sum1;

              

           }

           sum=sum2;
           sum=sum+(lamda)*(theta[j]);
	  
	  	   theta[j]=theta[j]-((alp)*(sum))/(size);

		   
		}
	}

}
