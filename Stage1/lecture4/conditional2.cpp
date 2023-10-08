#include<iostream>
using namespace std;

int main(){
	float a,b;
	cout<<"give 2 floating point numbers as input"<<endl;
	cin>>a>>b;
	if(a>0.01 && b>a){
		cout<<"The condition in if statement is correct";  //will only be executed if the statement in the paranthesis is correct
	}
	else{
		cout<<"The condition is false";
	}
	return 0;
}
