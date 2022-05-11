#include "Runway.h"

Runway::Runway()
{
	runwayID = -1;
	numTakeoffs = 0;
	numLandings = 0;
	timer = 0;
}

Runway::Runway(int ID)
{
	runwayID = ID;
	numTakeoffs = 0;
	numLandings = 0;
	timer = 15;
}

void Runway::processRequest(list<FlightRequest*>* &landingRequests, list<FlightRequest*>* &takeoffRequests, 
	double &landWaitTime, double &flightWaitTime, int currentTime)
{
	//iterators used to check if the list is empty
	auto iterLanding = landingRequests->begin();
	auto iterTakeoff = takeoffRequests->begin();
	if (iterLanding == landingRequests->end() && iterTakeoff == takeoffRequests->end()) {
		cout << "\tRunway " << runwayID << ": No flight request to process..." << endl;
		timer = 15; //timer remains at 15 for next flight request
	}
	else {
		//processing request at 15min timer end (runway no longer in use)
		if (timer == 15) {
			//landing requests priority
			if (iterLanding != landingRequests->end()) {
				cout << "\tRunway " << runwayID << ": Landing request approved" << endl;
				cout << "\t   Flight ID: " << (*iterLanding)->getFlightID() << endl;
				landWaitTime += (currentTime - (*iterLanding)->getTimeReq());
				landingRequests->erase(iterLanding);
				numLandings++;
			}
			//takeoff requests secondary
			else {
				cout << "\tRunway " << runwayID << ": Takeoff request approved" << endl;
				cout << "\t   Flight ID: " << (*iterTakeoff)->getFlightID() << endl;
				flightWaitTime += (currentTime - (*iterTakeoff)->getTimeReq());
				takeoffRequests->erase(iterTakeoff);
				numTakeoffs++;
			}
			timer = 0; //reset timer to 0
		}
		else {
			timer += 5; //increment timer (runway in use)
		}
	}
}

int Runway::getNumTakeoffs()
{
	return numTakeoffs;
}

int Runway::getNumLandings()
{
	return numLandings;
}



