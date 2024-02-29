#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Item structure
struct Item {
    string name;
    int amount;
};

// Structure of all items
struct GroupOfItems {
    vector<Item> listOfNumbers;

    // Function of adding item
    void addItem(const Item& newItem) {
        listOfNumbers.push_back(newItem);
    }

    // function for deleting item
    void removeItem(int index) {
        if (index > 0 && index <= static_cast<int>(listOfNumbers.size())) {
            listOfNumbers.erase(listOfNumbers.begin() + (index - 1));
        } else {
            cerr << "Incorrect item index\n";
        }
    }

    // function for displaying all items
    void displayList() {
        int numer = 1;
        for (const auto& item : listOfNumbers) {
            cout << numer << ". Name: " << item.name << ", Amount: " << item.amount << endl;
            numer += 1;
        }
    }
};

int main() {

    GroupOfItems items;
    char option;
    ofstream Myfile;
    // Displaying menu
    do {
        cout << "\nMENU\n";
        cout << "1: Add item\n";
        cout << "2: Display items\n";
        cout << "3: Remove item\n";
        cout << "4: END CODE\n";
        cout << "OPTION: ";
        cin >> option;

        switch (option) {
            case '1': {
                Item newItem;
                cout << "Name: ";
                cin >> newItem.name;
                cout << "Amount: ";
                cin >> newItem.amount;
                items.addItem(newItem);
                break;
            }
            case '2': {
                items.displayList();
                break;
            }
            case '3': {
                int index;
                cout << "Index of item you wish to delete: ";
                cin >> index;
                items.removeItem(index);
                break;
            }

            default: {
                cout << "Error Incorrect option\n";
            }
        }
    } while (option != '4');
}