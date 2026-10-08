#pragma once

#include "Showroom.h"
#include "Vehicle.h"

class Dealership {

public:
    Dealership(std::string name = "Generic Dealership", std::size_t capacity = 0);

    void AddShowroom(Showroom s);
    float GetAveragePrice();
    void ShowInventory();

private:
    std::string _DealershipName;
    std::vector<Showroom> _showrooms;
    std::size_t _MaxShowrooms;
    
};