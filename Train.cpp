#include <iostream>
#include <vector>
#include "Train.h"

void inputData(std::vector<Train>& trains) {
    int numTrains;
    std::cout << "Enter the number of trains: ";
    std::cin >> numTrains;

    for (int i = 0; i < numTrains; ++i) {
        Train train;
        std::cout << "Enter train number: ";
        std::cin >> train.number;
        std::cout << "Enter departure time: ";
        std::cin >> train.departureTime;
        std::cout << "Enter destination station: ";
        std::cin >> train.destinationStation;

        trains.push_back(train);
    }
}

void displayTrains(const std::vector<Train>& trains) {
    std::cout << "Train Information:\n";
    for (const auto& train : trains) {
        std::cout << "Train Number: " << train.number << std::endl;
        std::cout << "Departure Time: " << train.departureTime << std::endl;
        std::cout << "Destination Station: " << train.destinationStation << std::endl;
        std::cout << std::endl;
    }
}