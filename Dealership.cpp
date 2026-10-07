#include "Dealership.h"
#include <iostream>

Dealership::Dealership(std::string name, std::size_t capacity) {
    _name = name;
    _MaxShowrooms = capacity;
}

void Dealership::AddShowroom(Showroom s) {
    if (_showrooms.size() >= _MaxShowrooms) {
        std::cout << "Dealership is full, can't add another showroom!" << std::endl;
        return;
    }
    _showrooms.push_back(s);
}

float Dealership::GetAveragePrice() {
    if (_showrooms.empty()) {
        return 0.0;
    }
    float total = 0.0;
    int totalVehicles = 0;
    for (size_t i = 0; i < _showrooms.size(); ++i) {
        total += _showrooms.at(i).GetInventoryValue();
        totalVehicles += _showrooms.at(i).GetVehicleList().size();
    }
   float average = total / totalVehicles;
   return average;
}

void Dealership::ShowInventory() {
    if (_showrooms.empty()) {
        std::cout << _name << " is empty!" << std::endl;
        std::cout << "Average car price: $" << GetAveragePrice() << std::endl;
        return;
    }
    for (size_t i = 0; i < _showrooms.size(); ++i) {
        _showrooms.at(i).ShowInventory();
    }

    std::cout << "Average car price: $" << GetAveragePrice() << std::endl;
}