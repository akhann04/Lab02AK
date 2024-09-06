#include <iostream>
#include "Functions.h"
#include <cmath>
using namespace std;

int binaryToDecimal(const string& binary) {

    int decimal = 0;
    int power = 1;
    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += power;

        }
        else if (binary[i] != '0') {
            cout << "Not a binary number" << endl;
            return -1;

        }
        power *= 2;
    }
    return decimal;



}

string decimalToBinary(int decimal) {
    if (decimal == 0) return "0"; // Return "0" for decimal 0

    string binary;
    while (decimal > 0) {
        if (decimal % 2 == 0) {
            binary = '0' + binary;
        }
        else {
            binary = '1' + binary;
        }
        decimal /= 2;
    }
    return binary;

}

string binaryToBase(const string& binary, int base) {

    int decimal = binaryToDecimal(binary);
    if (decimal == -1) return" ";

    string result;
    while (decimal > 0) {
        int remainder = decimal % base;
        if (remainder < 10) {
            result = to_string(remainder) + result;
        }
        else {
            result = string(1, 'A' + (remainder - 10)) + result;
        }
        decimal /= base; // Update decimal for the next iteration
    }
    return result.empty() ? "0" : result;


}

string baseToBinary(const string& value, int base) {
    int decimal = 0;
    for (char c : value) {
        int digitValue = (c >= '0' && c <= '9') ? (c - '0') : (c - 'A' + 10);
        if (digitValue >= base) {
            cout << "Invalid digit for base" << base;
            return " ";
        }
        decimal = decimal * base + digitValue;
    }
    return decimalToBinary(decimal);
}