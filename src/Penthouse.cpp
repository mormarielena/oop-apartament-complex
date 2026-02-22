#include "../include/Penthouse.h"

Penthouse::Penthouse() : Apartment(), bedrooms(4), bathrooms(2) {
    energyConsumption = new int[bedrooms];
    for (int i = 0; i < bedrooms; i++) energyConsumption[i] = i + 120;
}

Penthouse::Penthouse(int area, int roomCount, int* costs, const int maxTenants, int bedrooms, int bathrooms, int* energyConsump)
    : Apartment(area, roomCount, maxTenants, costs), bedrooms(bedrooms), bathrooms(bathrooms) {
    energyConsumption = new int[bedrooms];
    for (int i = 0; i < bedrooms; i++) energyConsumption[i] = energyConsump[i];
}

Penthouse::~Penthouse() {
    delete[] energyConsumption;
}

Penthouse::Penthouse(const Penthouse& other) : Apartment(other), bedrooms(other.bedrooms), bathrooms(other.bathrooms) {
    energyConsumption = new int[bedrooms]; 
    for (int i = 0; i < bedrooms; i++) energyConsumption[i] = other.energyConsumption[i];
}

Penthouse& Penthouse::operator=(const Penthouse& other) {
    if (this != &other) {
        Apartment::operator=(other);
        bedrooms = other.bedrooms;
        bathrooms = other.bathrooms;
        delete[] energyConsumption;
        energyConsumption = new int[bedrooms];
        for (int i = 0; i < bedrooms; i++) energyConsumption[i] = other.energyConsumption[i];
    }
    return *this;
}