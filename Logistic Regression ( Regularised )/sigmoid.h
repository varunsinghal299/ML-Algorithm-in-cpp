#include<bits/stdc++.h>
using namespace std;

double sigmoid_func(double n){
	return 1/(double)(1+pow(exp(1),(-1*n)));
}
