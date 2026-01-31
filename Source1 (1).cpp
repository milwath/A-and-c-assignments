#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter first integer: ";
    cin >> a;
    cout << "Enter second integer: ";
    cin >> b;

    cout << "\nSum: " << (a + b);
    cout << "\nDifference: " << (a - b);
    cout << "\nProduct: " << (a * b);

    cout << "\n\nDivisors of " << a << ": ";
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0)
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
