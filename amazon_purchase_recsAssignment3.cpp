


/************************************************************************************************************************

Name:Nicholas Child                                 Z#:23537683
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:9/16/19                      Due Time:24:00
Total Points: 20
Assignment #: amazon_purchase_recs.cpp

Description:This program generates billing info from an Amazon order. The data is read in from a input file and calculations are made to generate billing costs.it then outputs the results

*************************************************************************************************************************/


#include <iostream>
#include <string>
#include <fstream>  
using namespace std;


void input(ifstream &, string &, string &, double &, double &, int &);
void output(string, string, double, double, int, double, double, double, double);
void process(double, double, int, double &, double &, double &, double &);


///*************************************************************************************
//Name:  input
//Precondition: All Values are not initialized
//Postcondition: cell_number, item_number,quantity,price and processing_plant are initialized 
// //Description: Get input (values of cell_number, item_number, quantity, price, processing_plant ) 
//from data file.

//PURPOSE: SHOW THAT I  KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream & in, string & cell_number, string & item_number, double & quantity, double & price, int & processing_plant) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	in >> cell_number;
	in>>item_number;
	  in>> quantity;
	in>> price; 
      in>> processing_plant;
}

///*************************************************************************************
//Name:  output
//Precondition: all variables are initialized
//Postcondition: all variabels have been printed to screen
//Description:  Display values of variables
//*************************************************************************************


void output(string cell_number, string item_number, double quantity, double price, int processing_plant, double tax_rate, double order_tax, double net_cost, double total_cost)
{

	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/


	cout << cell_number << "\t"<<item_number<< "\t"<<quantity<< "\t"<< price<< "\t"<<processing_plant<< "\t"<< (100*tax_rate)<< "\t"<< order_tax<< "\t"<< net_cost<< "\t"<< total_cost<<endl;
	


}

///*************************************************************************************
//Name:  process
////Precondition: tax_rate, order_tax, net_cost and total_cost are not calculated but everything else is
//Postcondition: Every variable is initialized
//Description:  this function calculates values from the given data from input()
//*************************************************************************************



void process(double quantity, double price, int processing_plant, double & tax_rate, double & order_tax, double & net_cost, double & total_cost)
{
		
	if(processing_plant<=50)
                tax_rate=0.06;
        else if(processing_plant<=110)
                tax_rate=0.07;
        else if(processing_plant<=200)
                tax_rate=0.08;
        else if(processing_plant<=500)
                tax_rate=0.09;
        else tax_rate=0.11;




        order_tax=quantity*price*tax_rate;

        net_cost=quantity*price;
        total_cost=net_cost+order_tax;



}

//Here is your driver to test the program
int main()
{
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;

	ifstream in;    //declaring an input file stream
	in.open("purchase_data.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{

			input(in, cell_number, item_number, quantity, price, processing_plant);
	process(quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
			output(cell_number,item_number,quantity,price,processing_plant,tax_rate,order_tax,net_cost,total_cost);
		}
	}

	in.close();

	return 0;
}


