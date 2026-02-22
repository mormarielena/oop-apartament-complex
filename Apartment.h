#pragma once
#include "IShortTermRental.h"
#include <iostream>
#include <fstream>

class Apartment : public IShortTermRental {
protected:
    int area;
    int roomCount;
    int* maintenanceCosts;
    const int maxTenants;
    static int totalApartments;

public:
    Apartment();
    Apartment(int area, int roomCount, const int maxTenants, int* costs);
    virtual ~Apartment();

    // Rule of Three
    Apartment(const Apartment& other);
    Apartment& operator=(const Apartment& other);

    // IShortTermRental implementations
    void showAvailableRooms() const override;
    int getGuestCapacity() const override;
    void displayApartment() const;

    // Operators
    friend std::ostream& operator<<(std::ostream& out, const Apartment& a);
    friend std::istream& operator>>(std::istream& in, Apartment& a);
    Apartment operator++(int);
    Apartment operator--(int);

    // Getters & Setters
    int getArea() const { return area; }
    void setArea(int a) { area = a; }
    int getRoomCount() const { return roomCount; }
    int getMaxTenants() const { return maxTenants; }
    static int getTotalApartments() { return totalApartments; }

    // File operations
    std::fstream& writeToBinaryFile(std::fstream& file) const;
    std::fstream& readFromBinaryFile(std::fstream& file);
};