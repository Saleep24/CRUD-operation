//Name: Saleep Shrestha
//ID: w10167735
//Program purpose: Design to implement the CRUD (Create, Read, Update, Delete) operations on a linked list-based data structure. Allows user to add, find, edit, remove, and display elements in the list.

//This structure is effective for dynamic data handling where data elements are inserted or removed frequently.

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* nextPtr;

    Node(string value) : data(value), nextPtr(nullptr) {}
};

class DataStream {
private:
    Node* headPtr;

public:
    DataStream() : headPtr(nullptr) {}

    void insertData(string value) {
        Node* newNode = new Node(value);
        if (!headPtr) {
            headPtr = newNode;
        } else {
            Node* temp = headPtr;
            while (temp->nextPtr) {
                temp = temp->nextPtr;
            }
            temp->nextPtr = newNode;
        }
        cout << "Added \"" << value << "\" to the list.\n";
    }

    bool searchData(string value) {
        Node* temp = headPtr;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->nextPtr;
        }
        return false;
    }

    bool updateData(string oldValue, string newValue) {
        Node* temp = headPtr;
        while (temp) {
            if (temp->data == oldValue) {
                temp->data = newValue;
                cout << "Updated \"" << oldValue << "\" to \"" << newValue << "\".\n";
                return true;
            }
            temp = temp->nextPtr;
        }
        return false;
    }

    bool deleteData(string value) {
        if (!headPtr) return false;

        if (headPtr->data == value) {
            Node* temp = headPtr;
            headPtr = headPtr->nextPtr;
            delete temp;
            cout << "Removed \"" << value << "\" from the list.\n";
            return true;
        }

        Node* current = headPtr;
        while (current->nextPtr && current->nextPtr->data != value) {
            current = current->nextPtr;
        }

        if (current->nextPtr) {
            Node* temp = current->nextPtr;
            current->nextPtr = temp->nextPtr;
            delete temp;
            cout << "Removed \"" << value << "\" from the list.\n";
            return true;
        }
        return false;
    }

    void displayStream() {
        Node* temp = headPtr;
        cout << "Current List: ";
        while (temp) {
            cout << "\"" << temp->data << "\" -> ";
            temp = temp->nextPtr;
        }
        cout << "NULL\n";
    }
};

void runMenu() {
    DataStream dataStream;
    int choice;
    string value, newValue;

    do {
        cout << "\nList Operations:\n";
        cout << "1. Add Item\n";
        cout << "2. Find Item\n";
        cout << "3. Edit Item\n";
        cout << "4. Remove Item\n";
        cout << "5. Show All Items\n";
        cout << "6. Quit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter item to add: ";
                getline(cin, value);
                dataStream.insertData(value);
                break;
            case 2:
                cout << "Enter item to find: ";
                getline(cin, value);
                if (dataStream.searchData(value)) cout << "\"" << value << "\" is in the list.\n";
                else cout << "\"" << value << "\" is not in the list.\n";
                break;
            case 3:
                cout << "Enter item to edit: ";
                getline(cin, value);
                cout << "Enter new value: ";
                getline(cin, newValue);
                if (dataStream.updateData(value, newValue)) cout << "Item updated.\n";
                else cout << "Item not found in the list.\n";
                break;
            case 4:
                cout << "Enter item to remove: ";
                getline(cin, value);
                if (dataStream.deleteData(value)) cout << "Item removed.\n";
                else cout << "Item not found in the list.\n";
                break;
            case 5:
                dataStream.displayStream();
                break;
            case 6:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 6);
}

int main() {
    runMenu();
    return 0;
}
