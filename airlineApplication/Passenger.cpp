/* W04
 * Passenger.cpp
 * Ivy Leano
 */

#include<iostream>
#include<iomanip>
#include<cstring>
#include"Passenger.h"
using namespace std;

namespace sict 
{
	Passenger::Passenger() 
	{
		passName[0] = '\0';
		destin[0] = '\0';
		yearDepart = 0;
		monthDepart = 0;
		dayDepart = 0;
	}

	Passenger::Passenger(const char * passengerName, const char * destination) 
	{
		if (passengerName == nullptr || destination == nullptr || passengerName == '\0' || destination == '\0') 
		{
			*this = Passenger();
		}
		
		else 
		{
			strncpy(passName, passengerName, MAXLENGTH);
			strncpy(destin, destination, MAXLENGTH);
			passName[MAXLENGTH - 1] = '\0';
			yearDepart = 2018;
			monthDepart = 10;
			dayDepart = 1;
		}
	}

	Passenger::Passenger(const char * passengerName, const char * destination, int yearDepar, int monthDepar, int dayDepar) 
	{
		bool year = yearDepar >= 2018 && yearDepar <= 2020;
		bool months = monthDepar >= 1 && monthDepar <= 12;
		bool days = dayDepar >= 1 && dayDepar <= 31;
		bool name = passengerName != nullptr && passengerName != '\0';
		bool dest = destination != nullptr && destination != '\0';

		if (year && months && days && name && dest) 
		{
			yearDepart = yearDepar;
			monthDepart = monthDepar;
			dayDepart = dayDepar;
			strncpy(passName, passengerName, MAXLENGTH);
			strncpy(destin, destination, MAXLENGTH);
			passName[MAXLENGTH - 1] = '\0';
		}

		else 
		{
			*this = Passenger();
		}
	}
	
	const char * Passenger::name() const 
	{
		return passName;
	}

	bool Passenger::canTravelWith(const Passenger& passenger) const 
	{
		bool sameDay = (*this).dayDepart == passenger.dayDepart;
		bool sameMonth = (*this).monthDepart == passenger.monthDepart;
		bool sameYear = (*this).yearDepart == passenger.yearDepart;
		bool sameDestin = strcmp((*this).destin, passenger.destin) == 0;

		return sameDay && sameMonth && sameYear && sameDestin;
	}

	bool Passenger::isEmpty() const 
	{
		bool tru1 = strlen(passName) > 0;
		bool tru2 = strlen(destin) > 0;

		return !(tru1 && tru2);
	}

	void Passenger::display() const 
	{
		if (!isEmpty()) 
		{
			cout << passName << " - " << destin << " on " << yearDepart << "/";
			cout << setfill('0') << setw(2);
			cout << monthDepart << "/";
			cout << setfill('0') << setw(2);
			cout << dayDepart << endl;
		}

		else 
		{
			cout << "No passenger!" << endl;
		}
	}
}
