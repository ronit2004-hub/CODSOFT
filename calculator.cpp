#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2, result;

    // Display welcome message
    cout << "Simple Calculator Program" << endl;
    cout << "-------------------------" << endl;

    // Get user input
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Display operation options
    cout << "\nChoose an operation:" << endl;
    cout << "+ for Addition" << endl;
    cout << "- for Subtraction" << endl;
    cout << "* for Multiplication" << endl;
    cout << "/ for Division" << endl;
    cout << "Operation: ";
    cin >> operation;

    // Perform calculation based on user's choice
    switch(operation) {
        case '+':
            result = num1 + num2;
            cout << "\nResult: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "\nResult: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "\nResult: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "\nResult: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "\nError: Division by zero is not allowed!" << endl;
            }
            break;
        default:
            cout << "\nError: Invalid operation selected!" << endl;
            break;
    }

    return 0;
}