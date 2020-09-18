/*
 * File:   OOP3200-F2020-LAB1.cpp
 * Author: Andre Agrippa, Najeebulla Hussaini
 *
 * Purpose: The purpose of this lab is to create a class called WorkTicket which 
 *			will be used to support an IT support tracking application to store information about
 *          client requests.
 *          
 * Modifications: N/A
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
public:
	//initialize constructor
	WorkTicket(int ticketNumber = 0, int ticketDay = 1, int ticketMonth = 1, int ticketYear = 2000, std::string id = "", std::string description = "")
	{
		SetTicketNumber(ticketNumber);
		SetDate(ticketDay, ticketMonth, ticketYear);
	}
	/*Accessors (Getters)*/

	
	/*Show the whole work ticket (similar to toString)
	*sets all attributes of WorkTicket as long as the parameters are valid. If
	*one attribute isn't correct, none of the attributes will change.
	*Returns true if no problems, otherwise false.
	*/
	string ShowWorkTicket() const;

	/*Mutators (Setters)*/
	void SetWorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, std::string id, std::string description)
	{
		SetDate(ticketDay, ticketMonth, ticketYear);
		SetTicketNumber(ticketNumber);
		SetId(id);
		SetIssue(description);
	}
	void SetDate(int dayInput, int monthInput, int yearInput)
	{
		day = dayInput;
		month = monthInput;
		year = yearInput;
	}
	void SetTicketNumber(int ticketInput) { workTicketNumber = ticketInput; }
	void SetId(std::string idInput) { workClientID = idInput; }
	void SetIssue(std::string issueInput) { workClientIssue = issueInput; }
	
	

private:
	
	//private data members for a work ticket
	int workTicketNumber;
	int day;
	int month;
	int year;
	//int workTicketDate[3] = {day, month, year}; //wrong format

	std::string workClientID;
	std::string workClientIssue;
	

	
};
int main()
{
	WorkTicket ticket;

	cout << ticket.ShowWorkTicket();
}

string WorkTicket::ShowWorkTicket() const
{
	stringstream strOutput;

	strOutput << "ID:" << workClientID << "\n" << "TICKET NUMBER:" << workTicketNumber << "\n"
			  << "DATE:" << day << "/" << month << "/" << year << "\n" << workClientIssue << endl;

	return strOutput.str();
	
}
 


