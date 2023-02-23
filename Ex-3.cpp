#include <iostream>
using namespace std;

struct Numbers {
    int num1;
    int num2;
};

int main() {
    Numbers nums;

    cout << "Enter two numbers:" << endl;
    cin >> nums.num1 >> nums.num2;

    cout << "Sum: " << nums.num1 + nums.num2 << endl;
    cout << "Difference: " << nums.num1 - nums.num2 << endl;
    cout << "Product: " << nums.num1 * nums.num2 << endl;

    if (nums.num2 != 0) {
        cout << "Quotient: " << nums.num1 / nums.num2 << endl;
        cout << "Remainder: " << nums.num1 % nums.num2 << endl;
    }
    else {
        cout << "Cannot divide by zero." << endl;
    }

    return 0;
}

