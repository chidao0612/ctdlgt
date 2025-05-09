#ifndef MANAGER_H
#define MANAGER_H

#include "node.h"
#include <fstream>

class Manager {
private:
    Node* head;

public:
    Manager() : head(nullptr) {}
    ~Manager();

    void addVehicle(const Vehicle& v);
    void deleteVehicle(const string& id);
    void updateVehicle(const string& id);
    void searchVehicle(const string& keyword);
    void sortByYear();
    void displayAll();
    void loadFromFile(const string& filename);
};

// Destructor
Manager::~Manager() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Manager::addVehicle(const Vehicle& v) {
    Node* newNode = new Node(v);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "[+] Vehicle added.\n";
}

void Manager::deleteVehicle(const string& id) {
    Node* temp = head;
    while (temp && temp->data.getId() != id)
        temp = temp->next;

    if (!temp) {
        cout << "[!] Vehicle not found.\n";
        return;
    }

    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;

    if (temp->next) temp->next->prev = temp->prev;

    delete temp;
    cout << "[+] Vehicle deleted.\n";
}

void Manager::updateVehicle(const string& id) {
    Node* temp = head;
    while (temp && temp->data.getId() != id)
        temp = temp->next;

    if (!temp) {
        cout << "[!] Vehicle not found.\n";
        return;
    }

    string type, brand, status;
    int year;
    cout << "New Type: "; cin >> type;
    cout << "New Brand: "; cin >> brand;
    cout << "New Year: "; cin >> year;
    cout << "New Status: "; cin >> status;
    temp->data.update(type, brand, year, status);
    cout << "[+] Vehicle updated.\n";
}

void Manager::searchVehicle(const string& keyword) {
    Node* temp = head;
    bool found = false;

    while (temp) {
        if (temp->data.getId() == keyword || temp->data.getBrand() == keyword ||
            temp->data.getType() == keyword || temp->data.getStatus() == keyword) {
            temp->data.display();
            found = true;
        }
        temp = temp->next;
    }

    if (!found) cout << "[!] No matching vehicle found.\n";
}

void Manager::sortByYear() {
    if (!head) return;

    bool swapped;
    do {
        swapped = false;
        Node* temp = head;

        while (temp->next) {
            if (temp->data.getYear() > temp->next->data.getYear()) {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);

    cout << "[+] Sorted by year.\n";
}

void Manager::displayAll() {
    if (!head) {
        cout << "[!] No vehicles to display.\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        temp->data.display();
        temp = temp->next;
    }
}

void Manager::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "[!] Cannot open file.\n";
        return;
    }

    while (!in.eof()) {
        Vehicle v;
        v.fromStream(in);
        if (in) addVehicle(v);
    }

    in.close();
    cout << "[+] Loaded vehicles from file.\n";
}

#endif
