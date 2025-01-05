#include <iostream>
#include <limits> // Required for numeric_limits
#include <iomanip> // For setting precision

using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Simple Calculator\n";

    while (true) { // Main loop for multiple calculations
        cout << "Enter the first number: ";
        if (!(cin >> num1)) {
            cerr << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Go to the next iteration of the loop
        }

        cout << "Enter the second number: ";
        if (!(cin >> num2)) {
            cerr << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter an operator (+, -, *, /): ";
        cin >> operation;

        // Input validation for operator
        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            cerr << "Invalid operator. Please enter +, -, *, or /.\n";
            continue;
        }

        cout << fixed << setprecision(2); // Set output precision to 2 decimal places

        switch (operation) {
            case '+':
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 == 0) {
                    cerr << "Error: Division by zero is not allowed.\n";
                } else {
                    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                }
                break;
        }
        char continueCalc;
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueCalc;
        if (continueCalc != 'y' && continueCalc != 'Y')
        {
            break;
        }
    }
    cout << "Calculator Closed" << endl;
    return 0;
}