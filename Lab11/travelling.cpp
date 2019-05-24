// Selinie Wang (jw6qe@virginia.edu)
// November 4, 2018
// travelling.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

// MAIN METHOD FOR TSP
/** @brief Computes the distance of the locations of printed path.
 *
 * @return the printed path and computed distance.
 * @param argc The number of parameters.
 * @param argv The width, height, number of cities, seed, and cities to visit.
 * @todo Need to cycle through permutations except the starting city.
 */

int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    // YOUR CODE HERE
    // printRoute(dests[0], dests);
    sort(dests.begin() + 1, dests.end());
    float smallest = computeDistance(me, dests[0], dests);
    //vector<string> iter1 = dests;
    // startdest = dests.begin() + 1;
    // enddest = dests.end();
    while (next_permutation(dests.begin() + 1, dests.end())) {
        float dist2 = computeDistance(me, dests[0], dests);
        if (smallest > dist2) {
            smallest = dist2;
        }
    }
    // cout << "Minimum path has distance " << smallest << ": ";
    cout << "Your journey will take you along the path ";
    printRoute(dests[0], dests);
    cout << "and will have the length " << smallest << endl;
    return 0;
}

// COMPUTE DISTANCE FOR TSP
/** @brief Computes the full distance of cycle from start.
 *
 * @return floating point distance of cycle.
 * @param me The object for Middle Earth.
 * @param start The starting location to begin cycle.
 * @param dests The vector to store locations.
 * @todo Need to get the distance from one location to another.
 */

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    float distance = 0.0;
    float pathweight = 0;
    for (int i = 0; i < dests.size() - 1; i++) {
        // use get distance from one location to another
        distance = distance + me.getDistance(dests[i], dests[i + 1]);
        start = dests[i];
    }
    int size = dests.size();
    distance = distance + me.getDistance(dests[0], dests[size - 1]);
    return distance;
}

// PRINT ROUTE FOR TSP
/** @brief Computes the entire route.
 *
 * @return the printed route starting from start and ending at start.
 * @param start The starting location to begin cycle.
 * @param dests The vector to store locations.
 * @todo Need to create for loop to print out dest and an arrow.
 */

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
    /*
    if (dests.size() == 1) {
        cout << start;
    } else if (dests.size() > 1) {
        for (int i = 0; i < dests.size(); i++) {
            cout << dests[i] << " -> ";
        } cout << start;
    }
    */
    for (int i = 0; i < dests.size(); i++) {
            cout << dests[i] << " -> ";
        } cout << start;
        cout << endl;
}