// Classes Lab, Part 3: Dealership
// Save this file as main.cpp next to your Vehicle, Showroom, and Dealership files.
// Build:  g++ -std=c++20 -Wall -Wextra -Werror main.cpp Vehicle.cpp Showroom.cpp Dealership.cpp -o part3
// Run it, then type a test number (1-6) and press Enter.
#include "Vehicle.h"
#include "Showroom.h"
#include "Dealership.h"
#include <iostream>
#include <iomanip>

void TestOne();
void TestTwo(Vehicle vehicles[]);
void TestThree(Vehicle vehicles[]);
void TestFour(Vehicle vehicles[]);
void TestFive(Vehicle vehicles[]);
void TestSix(Vehicle vehicles[]);

int main()
{
    // Initialize some data. It's hard-coded here, but this data could come from a file, database, etc
    Vehicle vehicles[] =
    {
        Vehicle("Ford", "Mustang", 1973, 9500, 113000),
        Vehicle("Mazda", "CX-5", 2017, 24150, 5900),
        Vehicle("Dodge", "Charger", 2016, 18955, 9018),
        Vehicle("Tesla", "Model S", 2018, 74500, 31),
        Vehicle("Toyota", "Prius", 2015, 17819, 22987),
        Vehicle("Nissan", "Leaf", 2016, 12999, 16889),
        Vehicle("Chevrolet", "Volt", 2015, 16994, 12558),
    };

    // Set the precision for showing prices with 2 decimal places
    std::cout << std::fixed << std::setprecision(2);

    int testNum;
    std::cin >> testNum;

    if (testNum == 1)
        TestOne();
    else if (testNum == 2)
        TestTwo(vehicles);
    else if (testNum == 3)
        TestThree(vehicles);
    else if (testNum == 4)
        TestFour(vehicles);
    else if (testNum == 5)
        TestFive(vehicles);
    else if (testNum == 6)
        TestSix(vehicles);

    return 0;
}

void TestOne()
{
    Dealership testDealership;
    testDealership.ShowInventory();
}

void TestTwo(Vehicle vehicles[])
{
    // Showrooms to store the vehicles
    Showroom one("Test Room One", 3);
    one.AddVehicle(vehicles[2]);
    one.AddVehicle(vehicles[6]);

    Showroom two("Test Room Two", 4);
    two.AddVehicle(vehicles[1]);
    two.AddVehicle(vehicles[2]);
    two.AddVehicle(vehicles[3]);

    // A "parent" object to store the Showrooms
    Dealership dealership("COP3504C Vehicle Emporium", 2);
    dealership.AddShowroom(one);
    dealership.AddShowroom(two);

    dealership.ShowInventory();
}

void TestThree(Vehicle vehicles[])
{
    // Showrooms to store the vehicles
    Showroom one("Test Room One", 3);
    one.AddVehicle(vehicles[1]);
    one.AddVehicle(vehicles[2]);

    Showroom two("Test Room Two", 4);
    two.AddVehicle(vehicles[3]);
    two.AddVehicle(vehicles[4]);
    two.AddVehicle(vehicles[0]);

    // A "parent" object to store the Showrooms
    Dealership dealership("COP3504C Vehicle Emporium", 2);
    dealership.AddShowroom(one);
    dealership.AddShowroom(two);

    // Should get an error message here
    dealership.AddShowroom(two);

    dealership.ShowInventory();
}

void TestFour(Vehicle vehicles[])
{
    // Showrooms to store the vehicles
    Showroom showroom("Primary Showroom", 3);
    showroom.AddVehicle(vehicles[0]);
    showroom.AddVehicle(vehicles[1]);
    showroom.AddVehicle(vehicles[6]);

    Showroom secondary("Fuel-Efficient Showroom", 4);
    secondary.AddVehicle(vehicles[4]);
    secondary.AddVehicle(vehicles[5]);

    Showroom third("Electric Showroom", 4);
    third.AddVehicle(vehicles[3]);
    third.AddVehicle(vehicles[3]);
    third.AddVehicle(vehicles[3]);

    // A "parent" object to store the Showrooms
    Dealership dealership("COP3504C Vehicle Emporium", 3);
    dealership.AddShowroom(showroom);
    dealership.AddShowroom(secondary);
    dealership.AddShowroom(third);

    std::cout << "Average price of the cars in the dealership: $"
              << dealership.GetAveragePrice() << std::endl;
}

void TestFive(Vehicle vehicles[])
{
    // Showrooms to store the vehicles
    Showroom showroom("Primary Showroom", 6);
    showroom.AddVehicle(vehicles[0]);
    showroom.AddVehicle(vehicles[1]);
    showroom.AddVehicle(vehicles[2]);
    showroom.AddVehicle(vehicles[3]);
    showroom.AddVehicle(vehicles[4]);
    showroom.AddVehicle(vehicles[5]);

    Showroom secondary("Fuel-Efficient Showroom", 4);
    secondary.AddVehicle(vehicles[4]);
    secondary.AddVehicle(vehicles[5]);
    secondary.AddVehicle(vehicles[5]);

    Showroom third("Electric Showroom", 4);
    third.AddVehicle(vehicles[3]);
    third.AddVehicle(vehicles[4]);
    third.AddVehicle(vehicles[5]);
    third.AddVehicle(vehicles[6]);

    // A "parent" object to store the Showrooms
    Dealership dealership("COP3504C Vehicle Emporium", 3);
    dealership.AddShowroom(showroom);
    dealership.AddShowroom(secondary);
    dealership.AddShowroom(third);

    std::cout << "Average price of the cars in the dealership: $"
              << dealership.GetAveragePrice() << std::endl;
}

void TestSix(Vehicle vehicles[])
{
    // Showrooms to store the vehicles
    Showroom showroom("Primary Showroom", 4);
    showroom.AddVehicle(vehicles[2]);
    showroom.AddVehicle(vehicles[4]);
    showroom.AddVehicle(vehicles[6]);

    Showroom third("Electric Showroom", 4);
    third.AddVehicle(vehicles[3]);
    third.AddVehicle(vehicles[5]);
    third.AddVehicle(vehicles[6]);

    // A "parent" object to store the Showrooms
    Dealership dealership("COP3504C Vehicle Emporium", 3);
    dealership.AddShowroom(showroom);
    dealership.AddShowroom(third);

    std::cout << "Average price of the cars in the dealership: $"
              << dealership.GetAveragePrice() << std::endl;
}
