#include <iostream>
using namespace std;

int main() {
    float a,b;
    char calc;

    cout << "Enter first number: "<<endl;
    cin >> a;
    cout << "Enter an operation (+, -, *, /): "<<endl;
    cin >> calc;
    cout << "Enter second number: "<<endl;
    cin >> b;

    switch (calc) {
        case '+':
            cout <<  " Addition of " <<a<<" and "<<b<<" is: "<<a + b << endl;
            break;
        case '-':
           cout <<  " Subtraction of " <<a<<" and "<<b<<" is: "<<a - b << endl;
            break;
        case '*':
            cout <<  " Multiplication of " <<a<<" and "<<b<<" is: "<<a * b << endl;
            break;
        case '/':
            if (b!= 0)
               cout <<  " Division of " <<a<<" and "<<b<<" is: "<<a / b << endl;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        default:
            cout << "Error: Invalid Operation!" << endl;
            break;
    }

    return 0;
}