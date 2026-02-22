#pragma once
#include <iostream>
#include <string>

class Resident {
private:
    std::string name;
    int apNumber;
    int age;
    double* monthlyUsage;
    const double expenseShare;
    static int maxResidents;

public:
    Resident();
    Resident(std::string name, int apNumber, int age, const double share, double* usage);
    ~Resident();

    Resident(const Resident& other);
    Resident& operator=(const Resident& other);

    void displayResident() const;
};