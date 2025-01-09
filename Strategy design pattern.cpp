// StrategyDesignPattern: It defines a family of algorithms encapuslates each one ,and make
//  them interchangeable allowing client 
// to switch algorithms dynamically without allowing the code structure.


#include <bits/stdc++.h>
using namespace std;

// DriveStrategy Interface 
class DriveStrategy {
public:
    virtual void drive() = 0; // Pure virtual function
    virtual ~DriveStrategy() {} // Virtual destructor
};

// NormalDriveStrategy Class
class NormalDriveStrategy : public DriveStrategy {
public:
    void drive() override {
        cout << "Normal Drive Strategy driving" << endl;
    }
};

// SportsDriveStrategy Class
class SportsDriveStrategy : public DriveStrategy {
public:
    void drive() override {
        cout << "Sports Drive Strategy runnings" << endl;
    }
};

// XYZDriveStrategy Class
class XYZDriveStrategy : public DriveStrategy {
public:
    void drive() override {
        cout << "XYZ Drive Strategy driving" << endl;
    }
};

// Vehicle Class
class Vehicle {
private:
    DriveStrategy* driveObject;

public:
    Vehicle(DriveStrategy* driveObject) {
        this->driveObject = driveObject;
    }

    void drive() {
        driveObject->drive(); // Corrected to use the -> operator
    }

    // Destructor to delete the dynamically allocated DriveStrategy object
    ~Vehicle() {
        delete driveObject;
    }
};

// SportsVehicle Class
class SportsVehicle : public Vehicle {
public:
    SportsVehicle() : Vehicle(new SportsDriveStrategy()) {}
};

// GoodsVehicle Class
class GoodsVehicle : public Vehicle {
public:
    GoodsVehicle() : Vehicle(new NormalDriveStrategy()) {}
};

// OffRoadVehicle Class
class OffRoadVehicle : public Vehicle {
public:
    OffRoadVehicle() : Vehicle(new XYZDriveStrategy()) {}
};

// Main Function
int main() {
    // Create a SportsVehicle and call drive
    Vehicle* vehicle = new SportsVehicle();
    vehicle->drive(); // Corrected to use the -> operator for pointers

    // Clean up dynamically allocated memory
    delete vehicle;

    return 0;
}
