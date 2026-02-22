#pragma once
#include <iostream>
#include <string>

class ICommercialBuilding {
protected:
    std::string name;
    int area;

public:
    virtual ~ICommercialBuilding() = default;
    virtual void hasFoodCourt() const = 0;
    virtual void showCommercialDetails() const = 0;

    ICommercialBuilding() : name("Winmarkt"), area(44) {}
};