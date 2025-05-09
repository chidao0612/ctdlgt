#include "manager.h"

void showMenu() {
    cout << "\n====== VEHICLE MANAGER ======" << endl;
    cout << "1. Add Vehicle\n2. Delete Vehicle\n3. Update Vehicle\n";
    cout << "4. Search Vehicle\n5. Sort by Year\n6. Load from File\n";
    cout << "7. Display All\n0. Exit\nChoose: ";
}

int main() {
    Manager mng;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string id, type, brand, status;
                int year;
                cout << "ID: "; cin >> id;
                cout << "Type: "; cin >> type;
                cout << "Brand: "; cin >> brand;
                cout << "Year: "; cin >> year;
                cout << "Status: "; cin >> status;
                mng.addVehicle(Vehicle(id, type, brand, year, status));
                break;
            }
            case 2: {
                string id;
                cout << "Enter ID to delete: ";
                cin >> id;
                mng.deleteVehicle(id);
                break;
            }
            case 3: {
                string id;
                cout << "Enter ID to update: ";
                cin >> id;
                mng.updateVehicle(id);
                break;
            }
            case 4: {
                string keyword;
                cout << "Enter keyword to search: ";
                cin >> keyword;
                mng.searchVehicle(keyword);
                break;
            }
            case 5:
                mng.sortByYear();
                break;
            case 6: {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                mng.loadFromFile(filename);
                break;
            }
            case 7:
                mng.displayAll();
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "[!] Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
