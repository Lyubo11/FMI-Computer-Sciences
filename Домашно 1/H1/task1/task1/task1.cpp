#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

// Задача 1 (1,00 т.):
// Дадена е декартова координатна система.Всеки правоъгълник със страни успоредни
// на координатните оси в нея може да се определи с четири числа с плаваща точка :
// координатите на долния ляв ъгъл(х, у), ширината и височината си.
// Напишете програма, която прочита от стандартния вход данни за два правоъгълника и
// извежда лицето на общата им част. Ако правоъгълниците нямат обща част, приемаме лицето за нула.
// Пример:
// Вход:		|	Вход:
//	0  0 2 2	|	0 0 5 3
// -1 -1 1 1	|	4 1 3 3
// Изход:		|	Изход:
// 0			|	2

void coordinates(int &x1, int &y1, int &height1, int &width1, int &x2, int &y2, int &height2, int &width2) {
	cout << "Enter the x coordinate of the first rectangle: ";
    cin >> x1;
    cout << "Enter the y coordinate of the first rectangle: ";
    cin >> y1;
    cout << "Enter the height of the first rectangle: ";
    cin >> height1;
    cout << "Enter the width of the first rectangle: ";
    cin >> width1;

    cout << "\nEnter the x coordinate of the second rectangle: ";
    cin >> x2;
    cout << "Enter the y coordinate of the second rectangle: ";
    cin >> y2;
    cout << "Enter the height of the second rectangle: ";
    cin >> height2;
    cout << "Enter the width of the second rectangle: ";
    cin >> width2;
}

int main() {
	int x1, y1, height1, width1, x2, y2, height2, width2, commonPartArea;
	coordinates(x1, y1, height1, width1, x2, y2, height2, width2);

    int top = min(y1 + height1, y2 + height2);
    int bottom = max(y1, y2);
    int right = min(x1 + width1, x2 + width2);
    int left = max(x1, x2);
    
    if ((top > bottom) && (right > left))
    {
        commonPartArea = (top - bottom) * (right - left);
        cout << "\nThe area of the common part is: " << commonPartArea << endl;
    }
    else 
    {
        cout << "\nThe rectangles have no common part, but may have a common point!\nThe area is 0" << endl;
    }
}