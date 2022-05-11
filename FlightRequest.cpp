#include "FlightRequest.h"

FlightRequest::FlightRequest()
{
    landingStatus = false; //odd flight ID indicates takeoff request
    timeRequested = -1;
    flightID = (1 + (rand() % 999999));
    if (flightID % 2 == 0) {
        landingStatus = true; //even flight ID indicates landing request
    }
}

/*
pre: input of the time of the request in minutes
post: a flight request object initialized with random 
      flight ID and landing status
*/
FlightRequest::FlightRequest(int timeRequested)
{
    landingStatus = false; //odd flight ID indicates takeoff request
    this->timeRequested = timeRequested;
    flightID = (1 + (rand() % 999999));
    if (flightID % 2 == 0) {
        landingStatus = true; //even flight ID indicates landing request
    }
}

int FlightRequest::getFlightID()
{
    return flightID;
}

bool FlightRequest::isLanding()
{
    return landingStatus;
}

//outputs flight request info to terminal
void FlightRequest::printRequest()
{
    string landStat;
    if (landingStatus) {
        landStat = "LANDING";
    }
    else {
        landStat = "TAKEOFF";
    }
    cout << "\tNew " << landStat << " request: Flight ID " << flightID << endl;
}

int FlightRequest::getTimeReq()
{
    return timeRequested;
}

//pre: int indicating time in minutes
//post: returns string formatted to military time
//NOTE: Only made for purposes of this 2 hour simulation and won't loop at 24hrs
string convertTime(int minutes) {
    int min = minutes % 60;
    int hr = minutes / 60;
    ostringstream ss;
    ss << setw(2) << setfill('0') << to_string(hr) << setw(1) << ":" << setw(2) << to_string(min);
    return ss.str();
}
