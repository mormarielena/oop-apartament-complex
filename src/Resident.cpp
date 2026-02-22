#include "../include/Resident.h"

int Resident::maxResidents = 4;

Resident::Resident() : name("Prodan Lucian"), apNumber(8), age(28), expenseShare(0.2) {
    monthlyUsage = new double[age]();
}

Resident::Resident(std::string name, int apNumber, int age, const double share, double* usage)
    : name(name), apNumber(apNumber), age(age), expenseShare(share) {
    monthlyUsage = new double[age];
    for (int i = 0; i < age; i++) monthlyUsage[i] = usage[i];
}

Resident::~Resident() {
    delete[] monthlyUsage;
}

Resident::Resident(const Resident& other) : name(other.name), apNumber(other.apNumber), age(other.age), expenseShare(other.expenseShare) {
    if (age > 0) {
        monthlyUsage = new double[age];
        for (int i = 0; i < age; i++) monthlyUsage[i] = other.monthlyUsage[i];
    }
    else {
        monthlyUsage = nullptr;
    }
}

Resident& Resident::operator=(const Resident& other) {
    if (this != &other) {
        name = other.name;
        apNumber = other.apNumber;
        age = other.age;
        delete[] monthlyUsage;
        monthlyUsage = new double[age];
        for (int i = 0; i < age; i++) monthlyUsage[i] = other.monthlyUsage[i];
    }
    return *this;
}

void Resident::displayResident() const {
    std::cout << "Name: " << name << ", Ap: " << apNumber << ", Share: " << expenseShare << "\n";
}