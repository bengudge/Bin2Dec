#include <iostream>
#include <math.h>

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

int numberLength(int n) {
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
    int binIndex, sum, j = 0;
    int i = numberLength(b)-1;

    while(b > 0) {
        j = b % 10;

        if (j == 1) {
            sum += power(2, i);
        }
        b /=  10;
        i--;
    }
    return sum;
}

int main() {
    int num;
    string input;

    cout << "+----------------------------------------------------------------------------------------+" << endl <<
            " Binary to Decimal Conversion" << endl <<
            "+----------------------------------------------------------------------------------------+" << endl;
    cout << "Enter '0' to exit program." << endl;

    while(true) {
        cout << endl << "Enter any 8 bit number: " << endl;
        cin >> num;

        if(num == 0) {
            break;
        }

        if(num > 1111111111) {
            cout << "Number is too large! Sorry." << endl;
            break;
        }

        if(!isBinary(num)) {
            cout << "A valid binary number must be entered!" << endl;
            continue;
        }

        cout << endl << "Decimal: " << binToDec(num) << endl;
    }
    return 0;
}
