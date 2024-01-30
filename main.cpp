#include <iostream>
#include <vector>
#include "Train.h"

void inputData(std::vector<Train>& trains);
void displayTrains(const std::vector<Train>& trains);

int main() {
    std::vector<Train> trains;

    inputData(trains);

    displayTrains(trains);

    return 0;
}