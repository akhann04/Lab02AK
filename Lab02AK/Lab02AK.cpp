#include <iostream>
#include "Functions.h" 
using namespace std;


int main() {
    char userChoice;

    do {
        cout << "MENU OPTIONS" << endl;
        cout << "----------------" << endl;
        cout << "a. Convert from Binary to Decimal" << endl;
        cout << "b. Convert from Binary to Another Base" << endl;
        cout << "c. Convert Decimal Number to Binary" << endl;
        cout << "d. Convert from another base to Binary" << endl;
        cout << "e. Exit" << endl;
        cout << "Choose your option (a-e): " << endl;
        cin >> userChoice;

        if (userChoice == 'a') {
            string binary;
            cout << "Enter a Binary Number: " << endl;
            cin >> binary;
            int decimal = binaryToDecimal(binary);
            if (decimal != -1) {
                cout << "Original Binary Value: " << binary << endl; // Added
                cout << "Decimal Value: " << decimal << endl;
            }
        }
        else if (userChoice == 'b') {
            string binary;
            int base;
            cout << "Enter a Binary Number: ";
            cin >> binary;
            cout << "Enter the base to convert to: ";
            cin >> base;
            if (base < 2 || base>16) {
                cout << "Base not in range" << endl;
            }
            else {
                cout << "Original Binary Value: " << binary << endl; // Added
                string result = binaryToBase(binary, base);
                cout << "Value in base: " << base << ":" << result << endl;
            }
        }
        else if (userChoice == 'c') {
            int decimal;
            cout << "Enter a decimal number: ";
            cin >> decimal;
            if (decimal < 0) {
                cout << "Invalid decimal number" << endl;
            }
            else {
                string binary = decimalToBinary(decimal);
                cout << "Original Decimal Value: " << decimal << endl; // Added
                cout << "Binary Value: " << binary << endl;
            }
        }
        else if (userChoice == 'd') {
            string value;
            int base;
            cout << "Enter the value: ";
            cin >> value;
            cout << "Enter the base of the value (2-16): ";
            cin >> base;
            if (base < 2 || base>16) {
                cout << "Base not in range" << endl;
            }
            else {
                string binary = baseToBinary(value, base);
                cout << "Original Value: " << value << endl; // Added
                cout << "Binary Value:" << binary << endl;
            }
        }
        else if (userChoice == 'e') {
            cout << "Exiting Program" << endl;
        }
        else {
            cout << "Not a choice. Pick another option" << endl;
        }

        cout << endl;

    } while (userChoice != 'e'); // Loop until the user chooses 'e' to exit

    return 0;
}