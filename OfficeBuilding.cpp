#include "OfficeBuilding.h"

OfficeBuilding::OfficeBuilding() : Building(), corpName("FizzyEnts"), officeCount(7) {
    officesPerFloor = new int[officeCount];
    for (int i = 0; i < officeCount; i++) officesPerFloor[i] = i * 2;
}

OfficeBuilding::~OfficeBuilding() {
    delete[] officesPerFloor;
}

OfficeBuilding::OfficeBuilding(const OfficeBuilding& other) : Building(other), corpName(other.corpName), officeCount(other.officeCount) {
    officesPerFloor = new int[officeCount];
    for (int i = 0; i < officeCount; i++) officesPerFloor[i] = other.officesPerFloor[i];
}

OfficeBuilding& OfficeBuilding::operator=(const OfficeBuilding& other) {
    if (this != &other) {
        Building::operator=(other);
        corpName = other.corpName;
        officeCount = other.officeCount;
        delete[] officesPerFloor;
        officesPerFloor = new int[officeCount];
        for (int i = 0; i < officeCount; i++) officesPerFloor[i] = other.officesPerFloor[i];
    }
    return *this; \
}