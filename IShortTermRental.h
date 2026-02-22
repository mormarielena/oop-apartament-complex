#pragma once
#include <iostream>
#include <string>

class IShortTermRental {
protected:
    std::string name;
    int pricePerNight;

public:
    virtual ~IShortTermRental() = default;
    virtual int getGuestCapacity() const = 0;
    virtual void showAvailableRooms() const = 0;

    IShortTermRental() : name("Dya's Home"), pricePerNight(220) {}
};