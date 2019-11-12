/************************************************************************************************************************

Name:Nicholas Child                                


Description:The purpose of this assignment is to generate the semiperimeter and area of a triangle from side lenghts given by the user
Purpose: To show comitence in pass by value and pas by reference parameters and efficieny in obtaining user input
*************************************************************************************************************************/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void Compute(double a, double b, double c, double & semi, double & area);
int main(){
		double a,b,c, semi,area;
		char cont;
		cout.setf(ios::showpoint);
	        cout.precision(2);
        	cout.setf(ios::fixed);

		while(cont!='n'){
			cout<<"Enter three triangle side lengths:"<<endl;
			cin>>a >>b>>c;
			Compute(a,b,c,semi,area);
			cout<<"Side A\tSide B\tSide C\tSemi\tArea\t"<<endl;
			if(semi>0 && area>0)
			cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<semi<<"\t"<<area<<endl;
			else
			cout<<a<<"\t"<<b<<"\t"<<c<<"\tinvalid\tinvalid"<<endl;
			cout<<"Type 'y' to calculate again, type 'n' to quit"<<endl;
			cin>>cont;
		}







	return 0;
}
///*************************************************************************************
//Name:  Compute
//Precondition:
//              A B and C variables have been initialized
//Postcondition:
//              all variables have been initialized
//Description:
//		 calculate semiperimeter and area given the lengths as well as check to make sure the triangle lengths create a triangle
//

//*************************************************************************************

void Compute(double a, double b,double c ,double & semi, double & area){
	if(a+b>c && a+c>b && b+c>a){

		semi=(a+b+c)/2;
		area=sqrt(semi*(semi-a)*(semi-b)*(semi-c));

	}
	else{ 
		semi=-5;
		area=-5;
	}
}
