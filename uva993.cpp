//UVA 993
//Catagory: Mathematics/Prime Numbers

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

void digPro (long int n) {
    int c2 = 0, c3 = 0, c5 = 0, c7 = 0; // 4 counters to hold the appearance of 2, 3, 5 and 7 respectively
    int m2, m3, m5, m7; // to store the multiplied form of 2, 3, 5 and 7 respectively
    if (n <= 9) { // If the number is 1-9 then don't need to multiply 2 numbers to get one of this
        cout << n << endl;
    }
    else { // Prime-factorizing part
        int A[30]; // It's guessed maximum range
        int x = 0;
        if (n % 2 == 0) { // Finding number of 2's
            while (n % 2 == 0) {
                c2++;
                n /= 2;
            }
        }
        if (n % 3 == 0) { // Finding number of 3's
            while (n % 3 == 0) {
                c3++;
                n /= 3;
            }
        }
        if (n % 5 == 0) { // Finding number of 5's
            while (n % 5 == 0) {
                c5++;
                n /= 5;
            }
        }
        if (n % 7 == 0) { // Finding number of 7's
            while (n % 7 == 0) {
                c7++;
                n /= 7;
            }
        }
        if (n != 1) { // If there is prime-factor larger than 7, then the number can't be represented into required form
            cout << "-1" << endl;
        }
        else {
            m2 = pow(2,c2); // Storing mutiplied form of 2's
            m3 = pow(3,c3); // Storing mutiplied form of 3's
            m5 = pow(5,c5); // Storing mutiplied form of 5's
            m7 = pow(7,c7); // Storing mutiplied form of 7's

            if (m2 >= 8) {
                while (m2 % 8 == 0) { // Finding the number of 8's means 2^3's
                    A[x] = 8;
                    x++;
                    m2 /= 8;
                }
            }
            if (m3 >= 9) { // Finding the number of 9's means 3^2's
                while (m3 % 9 == 0) {
                    A[x] = 9;
                    x++;
                    m3 /= 9;
                }
            }
            if (m3 == 3) { // Reduce from 3*2*2 into 6*2 and 3*2 to 6
                if (m2 == 2) {
                    A[x] = 6;
                    x++;
                }
                else if (m2 == 4) {
                    A[x] = 2;
                    x++;
                    A[x] = 6;
                    x++;
                }
                else {
                    A[x] = m3;
                    x++;
                }
            }
            else {
                A[x] = m2;
                x++;
            }
            if (m5 > 5) { // Finding the number of 5's means 5^1's
                while (m5 % 5 == 0) {
                    A[x] = 5;
                    x++;
                    m5 /= 5;
                }
            }
            else {
                A[x] = m5;
                x++;
            }
            if (m7 > 7) { // Finding the number of 7's means 7^1's
                while (m7 % 7 == 0) {
                    A[x] = 7;
                    x++;
                    m7 /= 7;
                }
            }
            else {
                A[x] = m7;
                x++;
            }
            sort(A, A+x); // Sotring thing number from small to big
            for (int z = 0; z < x; z++) {
                if (A[z] != 1) { // We don't nedd 1s' because 1*something = something
                    cout << A[z];
                }
            }
            cout << endl;
        }
    }
}

int main() {
    long int n;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        digPro(n); // Calling the function
    }
    return 0;
}
