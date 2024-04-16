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
	// Шифрування тексту
	auto encrypt = [](const string& plaintext) -> string {
		string encrypted_text;
		for (char c : plaintext) {
			// Визначення номеру рядка та позиції букви
			int row = (encrypted_text.size() / 16) % 4;
			int position = encrypted_text.size() % 16;

			// Отримання ASCII-коду букви та біт парності
			int ascii_code = static_cast<int>(c);
			int parity_bit = 0;
			for (int i = 0; i < 7; ++i) {
				parity_bit ^= (ascii_code >> i) & 1;
			}

			// Закодування байтів
			int byte1 = (row << 6) | (position << 2) | (parity_bit << 1) | (ascii_code >> 7);
			int byte2 = ((ascii_code & 0x7F) << 1) | parity_bit;

			// Додавання закодованих байтів до результуючого тексту
			encrypted_text += static_cast<char>(byte1);
			encrypted_text += static_cast<char>(byte2);
		}
		return encrypted_text;
		};

	// Функція для розшифрування тексту
	auto decrypt = [](const string& encrypted_text) -> string {
		string decrypted_text;
		for (int i = 0; i < encrypted_text.size(); i += 2) {
			// Отримання байтів
			int byte1 = static_cast<int>(encrypted_text[i]);
			int byte2 = static_cast<int>(encrypted_text[i + 1]);

			// Розкодування номеру рядка, позиції букви та ASCII-коду
			int row = (byte1 >> 6) & 0x03;
			int position = (byte1 >> 2) & 0x0F;
			int ascii_code = ((byte1 & 0x03) << 7) | (byte2 >> 1);

			// Перевірка біту парності
			int calculated_parity_bit = 0;
			for (int j = 0; j < 7; ++j) {
				calculated_parity_bit ^= (byte1 >> j) & 1;
			}
			calculated_parity_bit ^= (byte2 & 1);

			// Перевірка біту парності
			int received_parity_bit = (byte2 & 1);

			// Якщо біти парності співпадають, додаємо символ до результуючого тексту
			if (calculated_parity_bit == received_parity_bit) {
				decrypted_text += static_cast<char>(ascii_code);
			}
			else {
				// Якщо біти парності не співпадають, виводимо помилку та виходимо
				cout << "Помилка розшифрування. Неправильний біт парності." << endl;
				return "";
			}
		}
		return decrypted_text;
		};

	string plaintext = "Hello, world!"; // Початковий текст
	string encrypted_text = encrypt(plaintext); // Шифрування тексту
	cout << "Зашифрований текст: " << encrypted_text << endl;

	string decrypted_text = decrypt(encrypted_text); // Розшифрування тексту
	if (!decrypted_text.empty()) {
		cout << "Розшифрований текст: " << decrypted_text << endl;
	}

}

void task3()
{

}


void task4()
{   
	int a, b;
	std::cout << "Введіть ціле число a: ";
	std::cin >> a;
	std::cout << "Введіть ціле число b: ";
	std::cin >> b;

	int result = 0;
	while (b != 0) {
		// Перевірка найменшого біта b
		if (b & 1) {
			// Додавання до результату a, якщо відповідний біт в b встановлений
			result += a;
		}
		// Зсув b на 1 біт вправо та зсув a наліво (еквівалент множення на 2)
		a <<= 1;
		b >>= 1;
	}
	
	std::cout << "Добуток чисел " << a << " та " << b << " дорівнює " << result << std::endl;
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

