#include<bits/stdc++.h>

struct node{
	double mu;
	double si;
};

#include"feature_normalization.h"
#include"gradient_desent.h"
using namespace std;

int main(){
	
	double X[1000][5],y[1000];   // input amd output matrix.
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
	
	node s[10];
	
	feature_normalization(X,n,m,s);
	
	/*
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<m ; j++){
			cout<<X[i][j]<<" ";
		}  
		cout<<"             ";
		cout<<y[i]<<endl;
	}
	
   */	

	double theta[10]={0.0};
	double alpha=0.02;
	int no_of_iteration=400;
	
    gradient_descent(X,y,theta,alpha,no_of_iteration,n);
	
	double temp_a,temp_b,temp_c;
	double input_a,input_b;
	
	 cout<<"value of theta after gradient descent \n";
	 cout<<"Q1 "<<theta[0]<<endl;
	 cout<<"Q2 "<<theta[1]<<endl;
	 cout<<"Q3 "<<theta[2]<<endl;	
	 
	 
	 cout<<"Now enter the value of 1. size of house and 2. # of bedrooms to preict the price of house ."<<endl;
	 cout<<"Enter the Size  of house -> ";
	 cin>>input_a;
	 cout<<"Enter the # of bedrooms -> ";
	 cin>>input_b;
	 
	 

	 temp_a=(input_a-s[1].mu)/(s[1].si);
	 temp_b=(input_b-s[2].mu)/(s[2].si);
	
	 
	 double temp=theta[0]+theta[1]*(temp_a)+theta[2]*(temp_b);
	 
	 cout<<"Predicted price of house is ->> "<<temp;
	 
	 
	 
	 
	 
	 	
		
	return 0;
}
