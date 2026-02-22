#include "../include/Building.h"

int Building::totalBuildings = 5;

Building::Building() : adminName("D.A.W Administration"), address("Calea Vitan 2"), floorCount(2), tenant("Motca Valentin") {
    apPerFloor = new int[floorCount] {4, 4};
}

Building::Building(std::string address, int floorCount, std::string tenant, const std::string adminName, int* apPerFloor)
    : adminName(adminName), address(address), floorCount(floorCount), tenant(tenant) {
    this->apPerFloor = new int[floorCount];
    for (int i = 0; i < floorCount; i++) this->apPerFloor[i] = apPerFloor[i];
}

Building::~Building() {
    delete[] apPerFloor;
    apPerFloor = nullptr;
}

Building::Building(const Building& other) : ICommercialBuilding(other), adminName(other.adminName) {
    address = other.address;
    floorCount = other.floorCount;
    tenant = other.tenant;
    if (floorCount > 0) {
        apPerFloor = new int[floorCount];
        for (int i = 0; i < floorCount; i++) apPerFloor[i] = other.apPerFloor[i];
    }
    else {
        apPerFloor = nullptr;
    }
}

Building& Building::operator=(const Building& other) {
    if (this != &other) {
        address = other.address;
        floorCount = other.floorCount;
        tenant = other.tenant;
        delete[] apPerFloor;
        apPerFloor = new int[floorCount];
        for (int i = 0; i < floorCount; i++) apPerFloor[i] = other.apPerFloor[i];
    }
    return *this;
}

void Building::hasFoodCourt() const {
    std::cout << (floorCount >= 2 ? "Has Food Court.\n" : "No Food Court.\n");
}

void Building::showCommercialDetails() const {
    std::cout << "Address: " << address << ", Tenant: " << tenant << "\n";
}

void Building::displayBuilding() const {
    std::cout << "Address: " << address << "\nFloors: " << floorCount << "\nAdmin: " << adminName << "\nAp per floor: ";
    for (int i = 0; i < floorCount; i++) std::cout << apPerFloor[i] << " ";
    std::cout << "\n";
}

std::ostream& operator<<(std::ostream& out, const Building& b) {
    out << "Address: " << b.address << ", Floors: " << b.floorCount << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Building& b) {
    std::cout << "Address: "; in >> b.address;
    std::cout << "Floors: "; in >> b.floorCount;
    delete[] b.apPerFloor;
    b.apPerFloor = new int[b.floorCount];
    std::cout << "Ap per floor: ";
    for (int i = 0; i < b.floorCount; i++) in >> b.apPerFloor[i];
    return in;
}

void checkBuildingStatus(const Building& b) {
    std::cout << (Building::totalBuildings >= 5 ? "Enough buildings.\n" : "Too few buildings.\n");
}

void displayTotalApartments(const Building& b) {
    int total = 0;
    for (int i = 0; i < b.floorCount; ++i) total += b.apPerFloor[i];
    std::cout << "Total apartments in " << b.address << ": " << total << "\n";
}