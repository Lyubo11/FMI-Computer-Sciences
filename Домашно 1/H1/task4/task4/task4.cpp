#include <iostream>
#include <cmath>

using namespace std;

int generateSecretNumber() {
    int secretNumber = 0;
    int digits[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 4; ++i) {
        int index = rand() % (9 - i);
        secretNumber = secretNumber * 10 + digits[index];
        swap(digits[index], digits[8 - i]);
    }

    return secretNumber;
}

void checkGuess(int secretNumber, int guess, int& bulls, int& cows) {
    bulls = 0;
    cows = 0;

    int tempSecretNumber = secretNumber, secretNumber2 = secretNumber;

    for (int i = 0; i < 4; ++i) {
        int secretDigit = tempSecretNumber % 10;
        tempSecretNumber = tempSecretNumber / 10;
        int guessDigit = guess % 10;
        guess = guess / 10;

        if (secretDigit == guessDigit) {
            ++bulls;
        }
        else {
            secretNumber2 = secretNumber;
            int tempSecretDigit = secretNumber2 % 10;
            while (tempSecretDigit != 0)
            {
                if (tempSecretDigit == guessDigit)
                {
                    ++cows;
                    break;
                }
                else {
                    secretNumber2 /= 10;
                    tempSecretDigit = secretNumber2 % 10;
                }
            }
        }
    }
}

int main() {
    srand(time(nullptr));
    const int maxAttempts = 10;
    int secretNumber = generateSecretNumber();
    int attemptCount = 0;

    cout << "Welcome to the Bulls and Cows Game!" << endl;
    cout << "Try to guess the secret 4-digit number!" << endl;

    while (attemptCount < maxAttempts) {
        int guess;
        cout << "Try #" << attemptCount + 1 << ": ";

        while (!(cin >> guess) || guess < 1000 || guess > 9999) {
            cout << "Invalid attempt! Please enter a 4-digit number: ";
        }

        int bulls, cows;
        checkGuess(secretNumber, guess, bulls, cows);

        cout << bulls << " bull";
        if (bulls != 1) {
            cout << "s";
        }
        cout << " and " << cows << " cow";
        if (cows != 1) {
            cout << "s";
        }
        cout << "." << endl;

        if (bulls == 4) {
            cout << "Congratulations! You guessed the secret number!" << endl;
            break;
        }

        ++attemptCount;
    }

    if (attemptCount == maxAttempts) {
        cout << "Sorry, but you have exhausted all attempts. The secret number was: " << secretNumber << endl;
    }

    return 0;
}
