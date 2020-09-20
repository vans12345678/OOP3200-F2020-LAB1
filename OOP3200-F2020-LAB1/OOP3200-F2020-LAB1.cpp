/*
 * File:   OOP3200-F2020-LAB1.cpp
 * Author: Andre Agrippa, Najeebulla Hussaini
 *
 * Purpose: The purpose of this lab is to create a class called WorkTicket which 
 *			will be used to support an IT support tracking application to store information about
 *          client requests.
 *          
 *
 *
 * Created on September 18, 2020, 2:33 p.m.
 */

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()

using namespace std;


class WorkTicket
{

private:

	/* private data members for a work ticket */
	int workTicketNumber;
	int day;
	int month;
	int year;

	string workClientID;
	string workClientIssue;
	
public:
	
	/* initialize default constructor */
	WorkTicket(int ticketNumber = 0, int ticketDay = 1, int ticketMonth = 1, int ticketYear = 2000, std::string id = "", std::string description = "")
	{
		SetWorkTicket(ticketNumber, ticketDay, ticketMonth, ticketYear, id, description);
	}
	
	/* Accessors */

	/*Once called, will return selected attribute of object*/
	int getWorkTicketNumber() { return workTicketNumber; }
	int getWorkTicketDateDay() { return day; }
	int getWorkTicketDateMonth() { return month; }
	int getWorkTicketDateYear() { return year; }
	string getClientID() { return workClientID; }
	string getIssueDescription() { return workClientIssue; }
	
	/*Returns a string that contains ticket info*/
	string ShowWorkTicket() const;
	

	/* Mutators */
	
	/*Once called, sets all the attributes of the object to the entered input*/
	void SetWorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, string id, string description);

	/*Once called, sets day,month and year for date*/
	void SetDate(int dayInput, int monthInput, int yearInput);
	
	/* Once called, sets ticket number, id and issue description */
	void SetTicketNumber(int ticketNumberInput) { workTicketNumber = ticketNumberInput; }
	void SetId(string idInput) { workClientID = idInput; }
	void SetIssue(string issueInput) { workClientIssue = issueInput; }	
};

int main()
{
	//Input variables for ticket attributes
	int inputTicketNumber;
	int inputDay;
	int inputMonth;
	int inputYear;
	string inputClientID;
	string inputClientIssue;
	
	//Constants
	const int NUM_TICKETS = 3; // total tickets being made

	//Objects
	WorkTicket ticket [NUM_TICKETS];

	cout << "You will be making " << NUM_TICKETS << " tickets today..." << endl;

	try
	{
		/*Input loop, prompts user for ticket attributes using getline() for strings and
		 *ConsoleInput::ReadInteger() for integers
		 */
		for (int i = 0; i < NUM_TICKETS; i++) 
		{		
			cout << "Processing Ticket #" << i+1 << endl;
			
			cout << "Enter your ticket ID (alpha-numeric):";
			getline(cin, inputClientID);
			cout << "\nEnter your ticket number (Whole, positive number):";
			inputTicketNumber = ConsoleInput::ReadInteger(1);
			cout << "\nEnter the day the ticket was opened:(min.1 max.31)";
			inputDay = ConsoleInput::ReadInteger(1,31);
			cout << "\nEnter the month the ticket was opened:(min.1 max.12)";
			inputMonth = ConsoleInput::ReadInteger(1, 12);
			cout << "\nEnter the year the ticket was opened:(min.2000 max.2099)";
			inputYear = ConsoleInput::ReadInteger(2000, 2099);
			cout << "\nEnter your work issue description:";
			getline(cin, inputClientIssue);

			//once ticket has all valid inputs, place into object array
			ticket[i].SetWorkTicket(inputTicketNumber, inputDay, inputMonth, inputYear, inputClientID, inputClientIssue);

			//Ticket confirmation
			cout << "Ticket #" << i+1 << " processed." << endl;
			cout << "Press any key to continue...";
			cin.ignore();
			system("CLS");
		}

		//Output loop
		for (int i = 0; i < NUM_TICKETS; i++)
		{
			cout << "TICKET ENTRY:" << i+1 << endl;
			cout << ticket[i].ShowWorkTicket() << endl;
		}
	}
	
	//Will catch any invalid inputs and give an error
	catch (exception& ex)
	{
		cerr << ex.what() << "Ending the program." << endl;
	}
	
}

/*Returns a string that contains ticket info*/
string WorkTicket::ShowWorkTicket() const
{
	stringstream strOutput;

	strOutput << "ID: " << workClientID << "\n" << "TICKET NUMBER: " << workTicketNumber << "\n"
		<< "DATE: " << day << "/" << month << "/" << year << "\n" << "ISSUE: "<< workClientIssue << endl
		<< "=====================================================================================";

	return strOutput.str();
	
}

/*Once called, sets all the attributes of the object to the entered input*/
void WorkTicket::SetWorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, string id, string description)
{
	SetDate(ticketDay, ticketMonth, ticketYear);
	SetTicketNumber(ticketNumber);
	SetId(id);
	SetIssue(description);
}

/*Once called, sets day,month and year for date*/
void WorkTicket::SetDate(int dayInput, int monthInput, int yearInput)
{
	day = dayInput;
	month = monthInput;
	year = yearInput;
}


