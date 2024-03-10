# Membership Management System

The Membership Management System is a C++ program designed to manage subscribers of a service using object-oriented programming principles. It includes classes to represent subscribers, their subscriptions, and methods to perform various operations related to subscriber management.

## Classes

### 1. `Abonament`
- Represents a subscription with attributes such as name, price, and duration.
- Provides methods to set and get subscription details, calculate total revenue, and apply discounts.

### 2. `Abonament_Premium`
- Inherits from `Abonament` and represents a premium subscription with an additional attribute for discount.
- Overrides methods to calculate total revenue considering discounts.

### 3. `Persoana`
- Represents a person with attributes like ID, name, and CNP (Personal Identification Number).
- Provides methods to set and get person details.

### 4. `Abonat`
- Inherits from `Persoana` and represents a subscriber with additional attributes like phone number and subscription.
- Allows choosing between standard and premium subscriptions during object creation.

### 5. `Clienti`
- Manages a list of subscribers (`Abonat` objects).
- Provides methods to add, display subscriber details, count premium subscribers, and calculate total revenue.

## Functionality

- Users can create and manage lists of subscribers, both standard and premium.
- Users can view details of all subscribers in the list.
- The system can count and display the number of premium subscribers.
- The system calculates and displays the total revenue collected from all subscribers.

## Usage

1. Choose option 1 from the menu to create a new list of subscribers.
2. Choose option 2 to view details of all subscribers.
3. Select option 3 to count and display the number of premium subscribers.
4. Choose option 4 to calculate and display the total revenue collected from all subscribers.
5. Select option 5 to exit the program.

## Notes

- Customize the program as needed to add more features or modify existing functionality.
- Ensure valid input when interacting with the program to avoid errors and unexpected behavior.
