#include<bits/stdc++.h>
#include"costFunction.h"
using namespace std;

double sigmoid_fu(double n){
	return 1/(double)(1+pow(exp(1),(-1*n)));
}

int main(){
	
	long double X[1000][10];
    long double y[1000];
	
	int m,n,i,j;
	i=0;
	long double a,b;
	int c;
	
	FILE *fp=fopen("ex2data1.txt","r");
	while(fscanf(fp,"%llf,%llf,%d\n",&a,&b,&c)!=EOF){
	
		X[i][0]=1;
		X[i][1]=a;
		X[i][2]=b;
		y[i]=c;
		i++;
	}
	
	m=3;
	n=i;
	
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<m ; j++){
			cout<<X[i][j]<<" ";
		}
		
		cout<<endl;
	}
	
	long double theta[10]={1.0};
	double alpha=0.04;
	int no_of_iteration=400;
	long double cost=0;
	int lamda=100;
	
	costfunction(X,y,theta,cost,alpha,no_of_iteration,n,m,lamda);
	
	cout<<" cost is -> "<<cost<<endl;
	cout<<" theta[0] -> "<<theta[0]<<endl;
	cout<<" theta[1] -> "<<theta[1]<<endl;
	cout<<" theta[2] -> "<<theta[2]<<endl;
	
	
	
	long double p;
	long double lr,rr;
	
	int accurate=0;
	 

	for(i=0 ; i<n ; i++){
		p=theta[0]*X[i][0] + theta[1]*X[i][1] + theta[2]*X[i][2];
		p=sigmoid_fu(p);
		
		lr=p-0.002;
		rr=p+0.002;
		
		if(y[i]<=rr && y[i]>=lr ){
			accurate++;
		}
		
		//cout<<p<<"    ffffffffffffff   "<<y[i]<<"             "<<accurate<<endl;
	}
	
	p=(double)accurate/(double)n;
	p=p*100;
	cout<<"Accuracy Percentage is -> "<<p<<"%";	
	
}
