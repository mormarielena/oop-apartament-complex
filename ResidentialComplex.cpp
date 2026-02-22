#include "ResidentialComplex.h"

ResidentialComplex::ResidentialComplex() : complexName("CORESI TOWN"), buildYear(2021), totalAps(1) {
    apartmentList = new Apartment[totalAps];
}

ResidentialComplex::ResidentialComplex(std::string name, int year, int count, Apartment* list)
    : complexName(name), buildYear(year), totalAps(count) {
    apartmentList = new Apartment[totalAps];
    for (int i = 0; i < totalAps; i++) apartmentList[i] = list[i];
}

ResidentialComplex::~ResidentialComplex() {
    delete[] apartmentList;
}

ResidentialComplex::ResidentialComplex(const ResidentialComplex& other)
    : complexName(other.complexName), buildYear(other.buildYear), totalAps(other.totalAps) {
    apartmentList = new Apartment[totalAps];
    for (int i = 0; i < totalAps; i++) apartmentList[i] = other.apartmentList[i];
}

ResidentialComplex& ResidentialComplex::operator=(const ResidentialComplex& other) {
    if (this != &other) { 
        complexName = other.complexName;
        buildYear = other.buildYear;
        totalAps = other.totalAps;
        delete[] apartmentList;
        apartmentList = new Apartment[totalAps];
        for (int i = 0; i < totalAps; i++) apartmentList[i] = other.apartmentList[i];
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const ResidentialComplex& c) {
    out << "Complex: " << c.complexName << " (Built: " << c.buildYear << ")\n";
    for (int i = 0; i < c.totalAps; i++) out << c.apartmentList[i];
    return out;
}