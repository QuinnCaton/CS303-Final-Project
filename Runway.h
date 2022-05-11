#pragma once
#include<list>
#include<vector>
#include<string>
#include<iostream>
#include"FlightRequest.h"
using namespace std;

class Runway
{
private:
	int numTakeoffs;
	int numLandings;
	int runwayID;
	int timer;
public:
	Runway();
	Runway(int);
	void processRequest(list<FlightRequest*>* &landing, list<FlightRequest*>* &takeoff, double&, double&, int);
	int getNumTakeoffs();
	int getNumLandings();
};

