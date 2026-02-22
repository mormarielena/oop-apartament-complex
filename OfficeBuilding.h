#pragma once
#include "Building.h"

class OfficeBuilding : public Building {
private:
    std::string corpName;
    int officeCount;
    int* officesPerFloor;

public:
    OfficeBuilding();
    ~OfficeBuilding();

    OfficeBuilding(const OfficeBuilding& other);
    OfficeBuilding& operator=(const OfficeBuilding& other);
};