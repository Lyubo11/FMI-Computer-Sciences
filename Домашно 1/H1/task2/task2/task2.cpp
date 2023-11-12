#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void closedIntervalBetween(int& a, int& b) {
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
}

int countDivisors(int num) {
    int count = 0;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            ++count;
        }
    }
    return count;
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int a, b;
    closedIntervalBetween(a, b);

    int count = 0;
    for (int i = a + 1; i < b; ++i) {
        int divisorCount = countDivisors(i);
        if (isPrime(divisorCount)) {
            ++count;
        }
    }

    cout << "The count is : " << count << endl;

    return 0;
}
