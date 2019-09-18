/***********************************************************
Nick Child	        Total Points:  10
Due Date:  9/2/2019
Course:  C0P3014
Assignment:  Assignment 1
Professor: Dr. Lofton Bullard

Description: The purpose of this program is to calculate the total cost of a phone call by doing calculations from the entered data about the length and number of relay station used during a phone call..


*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class

using namespace std;

int main()
{
	 string user_response = "y";
	 double total_cost, call_rate, net_cost, tax_rate,call_tax;
	 int relays, call_length ;
	 string cell_num;


	while (user_response == "y" || user_response == "Y")
	{
                  cout<<"Enter cell phone number: "<< endl;
		  cin>>cell_num;
		  cout<<"Enter number of relay stations: "<< endl;
		  cin>>relays;
		  cout<<"Enter call length in minutes: " << endl;
		  cin>>call_length;

		if (relays<1) 
			tax_rate=0.0;
		else if( relays <=5)
			tax_rate=0.01;
		else if (relays<=11)
			tax_rate=0.03;
		else if( relays<=20)
			tax_rate=0.05;
		else if(relays<=50)
			tax_rate=0.08;
		else
			tax_rate=0.12;

		  net_cost=(relays/50.0 *0.40 *call_length);
		  call_tax=net_cost*tax_rate;
		  total_cost=net_cost+call_tax;
		
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout<<"\n\n CELL PHONE:\t"<<cell_num<<"\n NUMBER OF RELAY STATIONS:\t"<<relays<<"\n MINUTES USED\t"<<call_length<<"\n NET COST:\t"<<net_cost<<"\n CALL TAX\t"<<call_tax<<"\n TOTAL COST OF CALL:\t"<<total_cost<<endl;  
	
	    cout<<"Would you like to do another calculation (Y or N): "<<endl;
	    cin>>user_response;
	}

	return  0;
}





