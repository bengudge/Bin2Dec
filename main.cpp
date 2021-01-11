#include <iostream>
#include <iomanip>
#include <math.h>

//Use gmp to make big integers unusable

using namespace std;

bool isBinary(int n) {
    int i = 0;

    while(n > 0) {
        i = n % 10;

        if((i != 0) && (i != 1)) {
            return false;
        }
        n /= 10;

        if(n == 0) {
            return true;
        }
    }
}

int digitLength(int n) {
    int length = 0;

    while(n != 0) {
        n /= 10;
        length++;
    }
    return length;
}

int power(int base, int exponent) {

    if(exponent == 0) {
        return 1;
    }
    int temp = power(base, exponent/2);

    if(exponent % 2 == 0){
        return temp * temp;
    } else {
        return (base * temp * temp);
    }
}

int binToDec(int b) {
    int j = 0, binIndex = j, sum = j;

    while(b > 0) {
        j = b % 10;

        if (j == 1) {
            sum += power(2, binIndex);
        }
        b /=  10;
        binIndex++;
    }
    return sum;
}

int main() {
    long num;
    string input;

    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    cout << setfill(' ') << setw(26) << "" << "Binary to Decimal Conversion" << endl;
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    cout << "Enter '0' to exit program." << endl;

    while(true) {
        cout << endl << "Enter any 8 bit number: " << endl;
        cin >> num;

        if(num == 0) {
            break;
        }

        if(digitLength(num) > 8) {
            cout << "Number is too large! Try again." << endl;
            continue;
        }

        if(!isBinary(num)) {
            cout << "A valid binary number must be entered!" << endl;
            continue;
        }

        cout << endl << "Decimal: " << binToDec(num) << endl;
    }
    return 0;
}
