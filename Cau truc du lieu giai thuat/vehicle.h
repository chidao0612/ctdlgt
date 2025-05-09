#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>
using namespace std;

class Vehicle {
private:
    string id, type, brand, status;
    int year;

public:
    Vehicle() {}
    Vehicle(string _id, string _type, string _brand, int _year, string _status)
        : id(_id), type(_type), brand(_brand), year(_year), status(_status) {}

    string getId() const { return id; }
    string getType() const { return type; }
    string getBrand() const { return brand; }
    int getYear() const { return year; }
    string getStatus() const { return status; }

    void update(string t, string b, int y, string s) {
        type = t; brand = b; year = y; status = s;
    }

    void display() const {
        cout << "ID: " << id << ", Type: " << type
             << ", Brand: " << brand << ", Year: " << year
             << ", Status: " << status << endl;
    }

    void fromStream(ifstream& in) {
        in >> id >> type >> brand >> year >> status;
    }
};

#endif
