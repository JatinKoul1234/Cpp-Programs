#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imaginary;
};

Complex add(Complex c1, Complex c2) {
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imaginary = c1.imaginary + c2.imaginary;
    return sum;
}

Complex subtract(Complex c1, Complex c2) {
    Complex diff;
    diff.real = c1.real - c2.real;
    diff.imaginary = c1.imaginary - c2.imaginary;
    return diff;
}

Complex multiply(Complex c1, Complex c2) {
    Complex product;
    product.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    product.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return product;
}

int main() {
    Complex num1, num2;

    cout << "Enter the first complex number:" << endl;
    cout << "Real part: ";
    cin >> num1.real;
    cout << "Imaginary part: ";
    cin >> num1.imaginary;

    cout << "Enter the second complex number:" << endl;
    cout << "Real part: ";
    cin >> num2.real;
    cout << "Imaginary part: ";
    cin >> num2.imaginary;

    Complex sum = add(num1, num2);
    Complex diff = subtract(num1, num2);
    Complex product = multiply(num1, num2);

    cout << "Sum: " << sum.real << " + " << sum.imaginary << "i" << endl;
    cout << "Difference: " << diff.real << " + " << diff.imaginary << "i" << endl;
    cout << "Product: " << product.real << " + " << product.imaginary << "i" << endl;

    return 0;
}

