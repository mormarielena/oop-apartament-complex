#pragma once
#include "Apartment.h"

class Penthouse : public Apartment {
private:
    int bedrooms;
    int bathrooms;
    int* energyConsumption;

public:
    Penthouse();
    Penthouse(int area, int roomCount, int* costs, const int maxTenants, int bedrooms, int bathrooms, int* energyConsump);
    ~Penthouse();

    Penthouse(const Penthouse& other);
    Penthouse& operator=(const Penthouse& other);

    int getBedrooms() const { return bedrooms; }
};