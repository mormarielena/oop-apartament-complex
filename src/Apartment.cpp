#include "../include/Apartment.h"

int Apartment::totalApartments = 20;

Apartment::Apartment() : maxTenants(4), area(52), roomCount(2) {
    maintenanceCosts = new int[roomCount];
    for (int i = 0; i < roomCount; i++) maintenanceCosts[i] = 0; 
}

Apartment::Apartment(int area, int roomCount, const int maxTenants, int* costs)
    : maxTenants(maxTenants), area(area), roomCount(roomCount) {
    maintenanceCosts = new int[roomCount];
    for (int i = 0; i < roomCount; i++) maintenanceCosts[i] = costs[i];
}

Apartment::~Apartment() {
    delete[] maintenanceCosts;
    maintenanceCosts = nullptr;
}

Apartment::Apartment(const Apartment& other)
    : IShortTermRental(other), maxTenants(other.maxTenants), area(other.area), roomCount(other.roomCount) {
    if (roomCount > 0 && other.maintenanceCosts != nullptr) {
        maintenanceCosts = new int[roomCount];
        for (int i = 0; i < roomCount; i++) maintenanceCosts[i] = other.maintenanceCosts[i];
    }
    else {
        maintenanceCosts = nullptr;
    }
}

Apartment& Apartment::operator=(const Apartment& other) {
    if (this != &other) { 
        area = other.area;
        roomCount = other.roomCount;
        delete[] maintenanceCosts;

        if (roomCount > 0 && other.maintenanceCosts != nullptr) {
            maintenanceCosts = new int[roomCount];
            for (int i = 0; i < roomCount; i++) maintenanceCosts[i] = other.maintenanceCosts[i];
        }
        else {
            maintenanceCosts = nullptr;
        }
    }
    return *this;
}

void Apartment::showAvailableRooms() const { std::cout << "Available rooms to book: " << roomCount << "\n"; }
int Apartment::getGuestCapacity() const { return maxTenants; }

void Apartment::displayApartment() const {
    std::cout << "Area: " << area << " sqm\nRooms: " << roomCount
        << "\nMax capacity: " << maxTenants << "\nMaintenance costs: ";
    for (int i = 0; i < roomCount; i++) std::cout << maintenanceCosts[i] << " ";
    std::cout << "\n";
}

std::ostream& operator<<(std::ostream& out, const Apartment& a) {
    out << "Area: " << a.area << " sqm, Rooms: " << a.roomCount << ", Costs: ";
    for (int i = 0; i < a.roomCount; i++) out << a.maintenanceCosts[i] << " "; 
    out << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Apartment& a) {
    std::cout << "Area (sqm): "; in >> a.area;
    std::cout << "Number of rooms: "; in >> a.roomCount;
    delete[] a.maintenanceCosts;
    a.maintenanceCosts = new int[a.roomCount];
    std::cout << "Enter costs: ";
    for (int i = 0; i < a.roomCount; i++) in >> a.maintenanceCosts[i];
    return in;
}

Apartment Apartment::operator++(int) {
    Apartment temp = *this;
    totalApartments++;
    return temp;
}

Apartment Apartment::operator--(int) {
    Apartment temp = *this;
    totalApartments--;
    return temp;
}