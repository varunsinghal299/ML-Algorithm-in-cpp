#include<bits/stdc++.h>
#include"convert_X_2_X_transpose.h"
#include"getCofactor.h"
#include"determinant.h"
#include"adjoint.h"
#include"inverse.h"

using namespace std;


int main(){
	
	double X[100][100],y[1000];   // input amd output matrix.
	int n,m;                     //  size of input matrix.
	long long int a,b,c;         // tmep vaialbe.
	
	
	int i,j;
	FILE *fp=fopen("ex1data2_multi.txt","r");
    while(fscanf(fp,"%lld,%lld,%lld\n",&a,&b,&c)!=EOF){
     	 	X[i][0]=1;
     	 	X[i][1]=(double)a;
     	 	X[i][2]=(double)b;
     	 	
     	 	y[i]=c;
     	 	
     	 	i++;
	}
	
	m=3;    // # of features in a train example. 
	n=i;    // # of train example. 
	
	double X_transpose[100][100];        //         transpose of X matrix
	
	function_convert_X_2_Xtranspose(X,X_transpose,m,n);
	
	double X_3x3_matrix[3][3];          //          multiply of   (xT  and X)  as A
	
	int k1,k2;
	long long int sum=0;
	for(i=0 ; i<3 ; i++){
		for(j=0 ; j<3 ; j++){
		 	
		 	sum=0;
			 for(k1=0 ; k1<n ; k1++){
			    sum=sum+X[k1][j]*X_transpose[i][k1];	
			 }	
			X_3x3_matrix[i][j]=sum; 	 
		}
	}

	
	
	double inverse_matrix[3][3];
	f_inverse(X_3x3_matrix,inverse_matrix);          //   inverse of A (3 X 3)
	
	double B[10];
	
	for(i=0 ; i<3 ; ++i){
		sum=0;
		for(k1=0 ; k1<n ; k1++){
			sum=sum+(X_transpose[i][k1]*y[k1]);
		}
		
		B[i]=sum;
		
	}

	
	double theta[10];
	for(i=0 ; i<3 ; i++){
		sum=0;
		for(k1=0 ; k1<3 ; k1++){
			sum=sum+inverse_matrix[i][k2]*B[k1];
		}
				
		theta[i]=sum;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	 cout<<"value of theta after gradient descent \n";
	 cout<<"Q0 "<<theta[0]<<endl;
	 cout<<"Q1 "<<theta[1]<<endl;
	 cout<<"Q2 "<<theta[2]<<endl;	
	 
	 double input_a,input_b;
	 
	 cout<<"Now enter the value of 1. size of house and 2. # of bedrooms to preict the price of house ."<<endl;
	 cout<<"Enter the Size  of house -> ";
	 cin>>input_a;
	 cout<<"Enter the # of bedrooms -> ";
	 cin>>input_b;
	
	 double temp=theta[0]+theta[1]*(input_a)+theta[2]*(input_b);
	 long long int t=temp;
	 cout<<"Predicted price of house is ->> "<<t;
	
	
		
	return 0;
}
