#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void variables(float& x, int& n) {
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;
}

double factorial(int i) {
    if (i <= 1)
    {
        return 1;
    }
    return (i * factorial(i - 1));
}

double pow(float num, int power) {
    if (power < 1)
    {
        return 1;
    }
    return num * pow(num, power - 1);
}

int main()
{
    float x;
    int n;

    variables(x, n);

    double sumFromZeroToN = 0;

    for (int i = 0; i <= n; i++)
    {
        sumFromZeroToN += pow(-1, n) * (pow(x, 2 * i + 1) / factorial(2 * i + 1));
    }

    cout << "The sum from 0 to " << n << " is " << sumFromZeroToN << endl;

    return 0;
}
