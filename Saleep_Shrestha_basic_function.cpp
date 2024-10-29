
//Name: Saleep Shrestha
//ID: w10167735
//Program purpose: Design to implement the CRUD (Create, Read, Update, Delete) operations on a linked list based data strucutre. Allows user to insert, search, update, delete and view elements in the list.

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
        cout << "Inserted \"" << value << "\" into the DataStream.\n";
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
            cout << "Deleted \"" << value << "\" from the DataStream.\n";
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
            cout << "Deleted \"" << value << "\" from the DataStream.\n";
            return true;
        }
        return false;
    }

    void displayStream() {
        Node* temp = headPtr;
        cout << "Current DataStream: ";
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
        cout << "\nDataStream Operations:\n";
        cout << "1. Insert Data\n";
        cout << "2. Search Data\n";
        cout << "3. Update Data\n";
        cout << "4. Delete Data\n";
        cout << "5. Display DataStream\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                getline(cin, value);
                dataStream.insertData(value);
                break;
            case 2:
                cout << "Enter value to search: ";
                getline(cin, value);
                if (dataStream.searchData(value)) cout << "\"" << value << "\" found in the DataStream.\n";
                else cout << "\"" << value << "\" not found in the DataStream.\n";
                break;
            case 3:
                cout << "Enter the old value to update: ";
                getline(cin, value);
                cout << "Enter the new value: ";
                getline(cin, newValue);
                if (dataStream.updateData(value, newValue)) cout << "Data updated.\n";
                else cout << "Data not found in the DataStream.\n";
                break;
            case 4:
                cout << "Enter value to delete: ";
                getline(cin, value);
                if (dataStream.deleteData(value)) cout << "Data deleted.\n";
                else cout << "Data not found in the DataStream.\n";
                break;
            case 5:
                dataStream.displayStream();
                break;
            case 6:
                cout << "Exiting...\nHave a good day\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}

int main() {
    runMenu();
    return 0;
}
