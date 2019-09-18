


/************************************************************************************************************************

Name:Nicholas Child                                 

Assignment #: amazon_orders.cpp

Description:The purpose of this program is to generate order information from a file with data about amazon purchases

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/
class order_record
{
public:
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;
};



void input(ifstream &, order_record &);
void output(const order_record &);
void process(order_record &);



///*************************************************************************************
//Name:  input
//Precondition: 
// 		order record is defined but all variables are without values
//Postcondition: 
//		the variables cell_number, item_number, quantity, price and processing plant are initialized
//Description:  
// Get input (values of cell_number, item_number, quantity, price, processing_plant ) 
//from data file order record (p_record).

//*************************************************************************************

void input(ifstream & in, order_record & p_record)
{
	in >> p_record.cell_number;
	in>> p_record.item_number;
	in>>p_record.quantity;
	in>>p_record.price;
	in>>p_record.processing_plant;
	
}

///*************************************************************************************
//Name:  output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

void output(const order_record & p_record)
{
	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/
	cout << p_record.cell_number << "\t"<<p_record.item_number<< "\t"<<p_record.quantity<< "\t"<<p_record.price<< "\t"<<p_record.processing_plant<< "\t"<<p_record.tax_rate<< "\t"<<p_record.order_tax<< "\t"<<p_record.net_cost<< "\t"<<p_record.total_cost<<endl;
	
	

}

///*************************************************************************************
//Name:  process
//Precondition: tax_rate, order_tax, net_cost and total_cost are not calculated but everything else in order_record is
//Postcondition: Every variable in order_record has a value
//Description:  this function calculates values from the given data from input()
//*************************************************************************************


void process(order_record & p_record)
{

	if(p_record.processing_plant<=50)
		p_record.tax_rate=0.06;
	else if(p_record.processing_plant<=110)
                p_record.tax_rate=0.07;
        else if(p_record.processing_plant<=200)
                p_record.tax_rate=0.08;
        else if(p_record.processing_plant<=500)
                p_record.tax_rate=0.09;
        else p_record.tax_rate=0.11;



	       
	p_record.order_tax=p_record.quantity*p_record.price*p_record.tax_rate;

	p_record.net_cost=p_record.quantity*p_record.price;
	p_record.total_cost=p_record.net_cost+p_record.order_tax;
	

}

//Here is your driver to test the program
int main()
{

	order_record customer_record;

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
			input(in, customer_record);
			process(customer_record);
			output(customer_record);
		}
	}

	in.close();

	return 0;
}


