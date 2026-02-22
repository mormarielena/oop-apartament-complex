#pragma once
#include "Apartment.h"
#include <string>

class ResidentialComplex {
private:
    std::string complexName;
    int buildYear;
    Apartment* apartmentList;
    int totalAps;

public:
    ResidentialComplex();
    ResidentialComplex(std::string name, int year, int count, Apartment* list);
    ~ResidentialComplex();

    ResidentialComplex(const ResidentialComplex& other);
    ResidentialComplex& operator=(const ResidentialComplex& other);

    friend std::ostream& operator<<(std::ostream& out, const ResidentialComplex& c);
};