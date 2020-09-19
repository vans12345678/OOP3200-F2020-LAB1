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

	int getWorkTicketNumber() { return workTicketNumber; }
	int getWorkTicketDateDay() { return day; }
	int getWorkTicketDateMonth() { return month; }
	int getWorkTicketDateYear() { return year; }
	
	string getClientID() { return workClientID; }
	string getIssueDescription() { return workClientIssue; }
	string ShowWorkTicket() const;//returns a string that contains ticket info
	

	/* Mutators */
	
	void SetWorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, string id, string description)
	{
		SetDate(ticketDay, ticketMonth, ticketYear);
		SetTicketNumber(ticketNumber);
		SetId(id);
		SetIssue(description);
	}
	
	/*Once called, sets day,month and year for date*/
	void SetDate(int dayInput, int monthInput, int yearInput)
	{
		day = dayInput;
		month = monthInput;
		year = yearInput;
	}
	
	/* Once called, sets ticket number, id and issue description */
	void SetTicketNumber(int ticketNumberInput) { workTicketNumber = ticketNumberInput; }
	void SetId(string idInput) { workClientID = idInput; }
	void SetIssue(string issueInput) { workClientIssue = issueInput; }	
};

int main()
{
	int inputTicketNumber;
	int inputDay;
	int inputMonth;
	int inputYear;
	
	const int NUM_TICKETS = 3;
	
	string inputClientID;
	string inputClientIssue;
	
	WorkTicket ticket [NUM_TICKETS];

	cout << "You will be making " << NUM_TICKETS << " today." << endl;
	//start for loop?
	try
	{
		cout << "What's your ID:";
		cin >> inputClientID;

		cout << "\nWhat's your ticket number:";
		inputTicketNumber = ConsoleInput::ReadInteger(1);
		

		cout << "\nWhat day is it today:";
		inputDay = ConsoleInput::ReadInteger(1, 31);

		cout << "\nWhat month is it:";
		inputMonth = ConsoleInput::ReadInteger(1, 12);

		cout << "\nWhat year is it:";
		inputYear = ConsoleInput::ReadInteger(2000, 2099);

		ticket[0].SetWorkTicket(inputTicketNumber, inputDay, inputMonth, inputYear, inputClientID,inputClientIssue);

		cout << "Enter your work description:";
		cin >> inputClientIssue;

		cout << ticket[0].ShowWorkTicket();

	}
	catch (exception& ex)
	{
		cerr << ex.what() << "Ending the program." << endl;
	}
	

}

string WorkTicket::ShowWorkTicket() const
{
	stringstream strOutput;

	strOutput << "ID:" << workClientID << "\n" << "TICKET NUMBER:" << workTicketNumber << "\n"
			  << "DATE:" << day << "/" << month << "/" << year << "\n" << workClientIssue << endl;

	return strOutput.str();
	
}
 


