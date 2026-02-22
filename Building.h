#pragma once
#include "ICommercialBuilding.h"
#include <iostream>
#include <fstream>

class Building : public ICommercialBuilding {
protected:
    std::string address;
    int floorCount;
    int* apPerFloor;
    std::string tenant;
    const std::string adminName;
    static int totalBuildings;

public:
    Building();
    Building(std::string address, int floorCount, std::string tenant, const std::string adminName, int* apPerFloor);
    virtual ~Building();

    Building(const Building& other);
    Building& operator=(const Building& other);

    void hasFoodCourt() const override;
    void showCommercialDetails() const override;
    void displayBuilding() const;

    friend std::ostream& operator<<(std::ostream& out, const Building& b);
    friend std::istream& operator>>(std::istream& in, Building& b);

    std::string getAddress() const { return address; }
    void setAddress(std::string addr) { address = addr; }
    static int getTotalBuildings() { return totalBuildings; }

    friend void checkBuildingStatus(const Building& b);
    friend void displayTotalApartments(const Building& b);
};