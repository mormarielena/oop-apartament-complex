# Apartment Complex Management System

![C++](https://img.shields.io/badge/C++-11%2B-blue.svg)
![OOP](https://img.shields.io/badge/Paradigm-Object--Oriented-success.svg)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio-purple.svg)

A comprehensive C++ application designed to simulate and manage the operations of a residential and commercial complex. This project serves as a practical implementation of advanced **Object-Oriented Programming (OOP)** concepts, focusing on modular architecture, memory safety, and robust data handling.

## Key Features
* **Property Management:** Handles various types of real estate, including standard Apartments, Penthouses, and Office Buildings.
* **Resident Tracking:** Manages resident data, including age, apartment numbers, and dynamic monthly usage logs.
* **Complex Composition:** Supports grouping multiple properties into a single managed residential complex ecosystem.
* **Commercial Capabilities:** Differentiates between short-term rentals (AirBnb style) and large commercial buildings with dedicated administrative rules.
* **Data Persistence:** Includes foundational logic for reading and writing object states to text and binary files.

## Core OOP Concepts Demonstrated
This project was built to showcase a strong understanding of C++ memory management and OOP principles:

* **Memory Management (The Rule of Three):** Implemented custom Destructors, Copy Constructors, and Copy Assignment Operators (`operator=`) across classes to safely manage dynamically allocated arrays and prevent memory leaks.
* **Inheritance (IS-A Relationships):** Base classes like `Apartment` and `Building` are extended by specialized derived classes like `Penthouse` and `OfficeBuilding`.
* **Abstraction & Interfaces:** Utilized abstract base classes (`ICommercialBuilding`, `IShortTermRental`) with pure virtual functions to enforce contracts across different property types.
* **Polymorphism:** Dynamic method resolution for capacity and availability checking using `virtual` and `override` keywords.
* **Composition (HAS-A Relationships):** The `ResidentialComplex` class contains and manages the lifecycle of a dynamic array of `Apartment` objects.
* **Operator Overloading:** Custom `<<` and `>>` operators for seamless console I/O streaming, alongside arithmetic/unary operators (`++`, `--`) for internal tracking.

## Project Architecture
The project strictly separates declarations from implementations for clean, maintainable code:
* **Interfaces:** `ICommercialBuilding.h`, `IShortTermRental.h`
* **Base Classes:** `Apartment`, `Building`, `Resident`
* **Derived Classes:** `Penthouse`, `OfficeBuilding`
* **Composed Classes:** `ResidentialComplex`
