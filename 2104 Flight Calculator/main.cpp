#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h>
#include "lib.h"

using namespace std;

int main(){
    //Defining constants
    const double EARTH_RADIUS = 3958.8; //The earth's radius in miles
    const double JET_SPEED = 500; //The speed I chose for the jet in mph
    
    //Define the location data
    vector<string> locations = {"Miami Beach, FL, USA", "Fargo, ND, USA", "Idaho City, ID, USA", "Baltimore, MD, USA", "Fort Worth, TX, USA", "Glendale, AZ, USA", "Honolulu, HI, USA", "Los Angeles, CA, USA", "Santa Fe, NM, USA", "Charleston, South Carolina, USA"};
    vector<double> latitudes = {25.793449, 46.877186, 43.828850, 39.299236, 32.768799, 33.548264, 21.315603, 34.052235, 35.691544, 32.784618};
    vector<double> longitudes = {-80.139198, 96.789803, -115.837860, -76.609383, -97.309341, -112.191696, -157.858093, -118.243683, -105.944183, -79.940918};
    
    //Greet the user, describe the program, and print out the options of locations to choose from
    cout << "Welcome to the Flight Calculator program. You will choose a departure and destination location from the location options below to find the flight time between the two locations." << endl;
    for(int i = 0; i < locations.size(); i++)
    {
        cout << i + 1 << ". " << locations.at(i) << " " << latitudes.at(i) << " " << longitudes.at(i) << endl;
    }
    
    int departureLocationIndex = -1;
    while(departureLocationIndex < 0 || departureLocationIndex >= locations.size())
    {
        cout << "Please choose a departure location by choosing a number from the list above." << endl;
        string departureLocationNum;
        cin >> departureLocationNum;
        departureLocationIndex = atoi(departureLocationNum.c_str()) - 1;
        
        if(departureLocationIndex < 0 || departureLocationIndex >= locations.size())
            cout << "Input isn't valid. Please input a different number." << endl;
    }

    //List the options of destination locations
    int printedLocationNum = 1;
    for(int i = 0; i < locations.size(); i++)
    {
        if(i != departureLocationIndex)
        {
            cout << printedLocationNum << ". " << locations.at(i) << " " << latitudes.at(i) << " " << longitudes.at(i) << endl;
            printedLocationNum++;
        }
    }
    
    int destinationLocationIndex = -1;
    while(destinationLocationIndex < 0 || destinationLocationIndex >= locations.size() - 1)
    {
        cout << "Please choose a destination location by choosing a number from the list above." << endl;
        string destinationLocationNum;
        cin >> destinationLocationNum;
        destinationLocationIndex = atoi(destinationLocationNum.c_str()) - 1;
        
        if(destinationLocationIndex < 0 || destinationLocationIndex >= locations.size() - 1)
            cout << "Input isn't valid. Please input a different number." << endl;
    }
    
    //Calculate the distance between locations and flight time 
    double distance = haversine(latitudes.at(departureLocationIndex), longitudes.at(departureLocationIndex), latitudes.at(destinationLocationIndex), longitudes.at(destinationLocationIndex), EARTH_RADIUS);
    double flightTime = getFlightTime(distance, JET_SPEED);
    
    //Tell the user how long the flight will take
    cout << "It will take " << flightTime << " hours to fly between " << locations.at(departureLocationIndex) << " and " << locations.at(destinationLocationIndex) << endl;
    
    return 0;
}