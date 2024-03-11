// OOPLab2Tpl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"


/// @brief 
/// @return 

void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Examples of problems using bitwise operations \n";
    cout << "    6.  Exit \n";
}
int task1(int a, int b, int c, int d) {
    int a, b, c, d;

    std::cout << "Enter values for a, b, c, and d: ";
    std::cin >> a >> b >> c >> d;

    int result = 0;

    // Обчислення a * 34
    result += (a << 5) + (a << 1);

    // Обчислення (13 * a + 12 * c) / 64
    result += ((a << 3) + (a << 2) + (c << 3)) >> 6;

    // Обчислення b * 2560
    result -= (b << 8) + (b << 6);

    // Обчислення d * 127
    result += (d << 7) - d;

    // Обчислення c * 18
    result -= (c << 4) + (c << 1);

    std::cout << "Result: " << result << std::endl;

    return result;
}

void task2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations  \n";

}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields \n";
}


void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

}


int main()
{
    cout << "OOP. Template for laboratory work #2.\n";

    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = cin.get();
        
        cin.get();

        switch (ch) {
        case '1': task1();   break;
        case '2': task2();   break;
        case '3': task3();   break;
        case '4': task4();   break;
		case '5':  Examples(); break;
		case '6': return 0;
	    }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '6');

    return 0;
}

