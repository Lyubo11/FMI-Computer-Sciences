#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

void coordinates(int& x1, int& y1, int& width1, int& height1, int& x2, int& y2, int& width2, int& height2) {
    cout << "Enter the x coordinate of the first rectangle: ";
    cin >> x1;
    cout << "Enter the y coordinate of the first rectangle: ";
    cin >> y1;
    cout << "Enter the width of the first rectangle: ";
    cin >> width1;
    cout << "Enter the height of the first rectangle: ";
    cin >> height1;

    cout << "\nEnter the x coordinate of the second rectangle: ";
    cin >> x2;
    cout << "Enter the y coordinate of the second rectangle: ";
    cin >> y2;
    cout << "Enter the width of the second rectangle: ";
    cin >> width2;
    cout << "Enter the height of the second rectangle: ";
    cin >> height2;
}

void calculateAndPrintCommonPartArea(int& top, int& bottom, int& right, int& left) {
    if ((top > bottom) && (right > left))
    {
        int commonPartArea = (top - bottom) * (right - left);
        cout << "\nThe area of the common part is: " << commonPartArea << endl;
    }
    else
    {
        cout << "\nThe rectangles have no common part, but may have a common point!\nThe area is 0" << endl;
    }
}

int main() {
    int x1, y1, width1, height1, x2, y2, width2, height2;
    coordinates(x1, y1, width1, height1, x2, y2, width2, height2);

    int top = min(y1 + height1, y2 + height2);
    int bottom = max(y1, y2);
    int right = min(x1 + width1, x2 + width2);
    int left = max(x1, x2);

    calculateAndPrintCommonPartArea(top, bottom, right, left);
}
