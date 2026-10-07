#pragma once
#include "Showroom.h"
#include "Vehicle.h"

class Dealership {

    private:
        std::string _name;
        std::vector<Showroom> _showrooms;
        std::size_t _MaxShowrooms;
    
    public:
        Dealership(std::string name = "Generic Dealership", std::size_t capacity = 0);

        void AddShowroom(Showroom s);
        float GetAveragePrice();
        void ShowInventory();
};