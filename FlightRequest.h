#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<iomanip>
#include<sstream>
using namespace std;
class FlightRequest
{
private: 
	int flightID;
	int timeRequested;
	bool landingStatus;
public:
	FlightRequest();
	FlightRequest(int);
	int getFlightID();
	bool isLanding();
	void printRequest();
	int getTimeReq();
};

string convertTime(int minutes);
