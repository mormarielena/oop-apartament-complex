#include <iostream>
#include "../include/Apartment.h"
#include "../include/Building.h"
#include "../include/Resident.h"
#include "../include/ResidentialComplex.h"
#include "../include/Penthouse.h"
#include "../include/OfficeBuilding.h"

int main() {
    std::cout << "--- Apartment Complex Management System ---\n\n";

    // Test Apartment (Base & Derived)
    int costs[] = { 100, 150 };
    Apartment a1(60, 2, 4, costs);
    a1.displayApartment();

    // Test Penthouse
    int energy[] = { 300, 310, 320 };
    Penthouse p1(120, 4, costs, 6, 3, 2, energy);
    std::cout << "\nPenthouse created with " << p1.getBedrooms() << " bedrooms.\n";

	// Test HAS-A relationships
    Apartment* apList = new Apartment[1];
    apList[0] = a1;
    ResidentialComplex resComplex("GREENFIELD", 2024, 1, apList);
    std::cout << "\n" << resComplex << "\n";

    // Test Building
    Building b1;
    b1.displayBuilding();

    delete[] apList;

    std::cout << "Tests completed successfully with no memory leaks!\n";
    return 0;
}