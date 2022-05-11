//Quinn Caton
//CS303 UMKC
//SID: 16306490

#include <iostream>
#include "Runway.h"
#include "FlightRequest.h"
using namespace std;

int main()
{
    srand(time(0)); //sets seed for random flight ID generation

    int time = 0;
    int totalTakeoffs = 0;
    int totalLandings = 0;

    //for remaining flights in queue at end of two hour simulation
    int numTakeoffQueue = 0;
    int numLandingQueue = 0;

    //running totals for average wait time calculation
    double takeoffWait = 0;
    double landWait = 0;

    //declaration of two runways
    Runway r1(1);
    Runway r2(2);

    list<FlightRequest*>* landRequests = new list<FlightRequest*>;
    list<FlightRequest*>* flightRequests = new list<FlightRequest*>;

    while (time <= 120) {
        cout << "\nTIME: " << convertTime(time) << endl;
        FlightRequest* newFlight = new FlightRequest(time);
        newFlight->printRequest();

        //adding flight pointer to appropriate list queue
        if (newFlight->isLanding()) {
            landRequests->push_back(newFlight);
            totalLandings++;
        }
        else {
            flightRequests->push_back(newFlight);
            totalTakeoffs++;
        }

        r1.processRequest(landRequests, flightRequests, landWait, takeoffWait, time);
        r2.processRequest(landRequests, flightRequests, landWait, takeoffWait, time);

        time += 5; //increment time
    }

    /*
    Iterators to read through remaining flights in each list queue
    and prints to user formatted information with flight ID and 
    timestamp of request made
    */
    cout << "\n\nTotal Landings: " << r1.getNumLandings() + r2.getNumLandings() << endl;
    cout << "Total Takeoffs: " << r1.getNumTakeoffs() + r2.getNumTakeoffs() << endl;

    auto it1 = landRequests->begin();
    auto it2 = flightRequests->begin();

    cout << "\n\nFlights Still Processing:\n" << endl;
    cout << "   Landing Requests:" << endl;
    for (; it1 != landRequests->end(); it1++) {
        cout << left << "\tFlight ID: " << setw(9) << (*it1)->getFlightID();
        cout << right << setw(25) << "Time Requested: " << convertTime((*it1)->getTimeReq()) << endl;
        landWait+=(time-(*it1)->getTimeReq());
    }

    cout << "\n   Takeoff Requests:" << endl;
    for (; it2 != flightRequests->end(); it2++) {
        cout << left << "\tFlight ID: " << setw(9) << (*it2)->getFlightID();
        cout << right << setw(25) << "Time Requested: " << convertTime((*it2)->getTimeReq()) << endl;
        takeoffWait+=(time-(*it2)->getTimeReq());
    }

    cout << "\n\nAverage wait times:" << endl;
    cout << "\tTakeoff Queue: " << convertTime(takeoffWait / totalTakeoffs) << endl;
    cout << "\tLanding Queue: " << convertTime(landWait / totalLandings) << endl;
    cout << "\n\n" << endl;

    system("pause");
    return 0;
}