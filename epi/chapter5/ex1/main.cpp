#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

/* naive version */
int numberOneBits_naive(long n) {
    int result = 0;
    while(n) {
        int rest = n % 2;
        if(rest) {
            ++result;
        }
        n /= 2;
    }
    return result;
}

/* naive parity */
int parity_naive(long s) {
    return (numberOneBits_naive(s) % 2) != 0 ? 1 : 0;

}

/* returns the number of bit with value 1 for v */
int numberOneBits(long n) {
    int result = 0;
    while(n) {
        ++result;
        n &= (n-1);
    }
   return result;
}

/* parity of a sequence is 1 if number has odd number of 1 bits, 0 otherwise */
int parity(long s) {
    return (numberOneBits(s) % 2) != 0 ? 1 : 0;

}

/* converts decimal to binary
 * use of unsigned long because pow returns a double and in order to convert
 * double to long we need unsigned long otherwise the positive values are too
 * small in long */
unsigned long decToBin(unsigned long v) {
    unsigned long result = 0;
    double powerTwoDouble= pow(2.0, 63.0); /* number of bytes * bits in a byte */
    unsigned long powerTwo = (unsigned long) powerTwoDouble;
    while(powerTwo){
        unsigned long isBitOne = v & powerTwo;
        result *= 10;
        if(isBitOne == powerTwo) {
            ++result;
        }
        powerTwo /= 2;
    }
    return result;
}

int main(int argc, char** argv) {
    if(argc != 2) {
        cout << "Please enter a number." << endl;
        return 0;
    }
    unsigned long number;
    stringstream(argv[1]) >> number;
    cout << decToBin(number) << endl;
    cout << parity(number) << endl;
    return 0;
}
