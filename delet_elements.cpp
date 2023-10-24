#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h> 

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 10;
    vector<int> arr(n);

    // Initialize the array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << '\t';
    }

    ofstream fout("OneDimensionalArray.dat", ios::binary);
    if (!fout.is_open()) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    fout.write((char*)arr.data(), n * sizeof(int));
    fout.close(); // Close the file

    int choice;
    cout << "Choose an action:\n1 - Edit element\n2 - Delete element\n";
    cin >> choice;

    if (choice == 1) {
        // Edit an element
        int indexToEdit, newValue;
        cout << "Enter the index of the element to edit: ";
        cin >> indexToEdit;
        cout << "Enter the new value for the element: ";
        cin >> newValue;

        if (indexToEdit >= 0 && indexToEdit < n) {
            arr[indexToEdit] = newValue;

            // Update the file by overwriting the entire vector
            ofstream updatedFile("OneDimensionalArray.dat", ios::binary);
            if (!updatedFile.is open()) {
                cout << "Error opening the file for updating!" << endl;
                return 1;
            }
            updatedFile.write((char*)arr.data(), n * sizeof(int));
            updatedFile.close(); // Close the file
        }
        else {
            cout << "Invalid index for editing." << endl;
        }
    }
    else if (choice == 2) {
        // Delete an element
        int indexToDelete;
        cout << "Enter the index of the element to delete: ";
        cin >> indexToDelete;

        if (indexToDelete >= 0 && indexToDelete < n) {
            arr.erase(arr.begin() + indexToDelete);

            // Update the file by overwriting the entire vector
            ofstream updatedFile("OneDimensionalArray.dat", ios::binary);
            if (!updatedFile.is_open()) {
                cout << "Error opening the file for updating!" << endl;
                return 1;
            }
            updatedFile.write((char*)arr.data(), arr.size() * sizeof(int));
            updatedFile.close(); // Close the file
        }
        else {
            cout << "Invalid index for deletion." << endl;
        }
    }
    else {
        cout << "Invalid choice of action." << endl;
    }

    // Display the updated array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << '\t';
    }
    cout << endl;

    return 0;
}