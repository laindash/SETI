#include <iostream>
#include "Windows.h"

using namespace std;

extern "C" int MODIFY_ARRAY(int*, int);


int main() {
	// Установка кодировки ввода-вывода CHCP-1251, для поддержки кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout
		<< "****************************************************************************************************" << std::endl
		<< " Вычислительные системы, сети и телекоммуникации. Лабораторная работа #3." << std::endl
		<< " Тема: Использование внешних подпрограмм в проектах Microsoft Visual Studio C++ x86." << std::endl
		<< " Команды управления циклом и работы с массивами." << std::endl
		<< " Задача – в учебной программе поменять ручной ввод на заполнение элементов массива случайными целыми" << std::endl
		<< " значениями в диапазоне от - 50 до 50 с использованием внешней asm - подпрограммы," << std::endl
		<< " содержащей вызовы функций time, srand, rand." << std::endl
		<< "****************************************************************************************************" << std::endl
		<< " Работу выполнили: Семенков Даниил Ильич && Егорова Ксения Олеговна && Смирнова Светлана Алексеевна." << std::endl
		<< " Группа 425 | 2024 год." << std::endl
		<< "----------------------------------------------------------------------------------------------------" << std::endl;

	system("pause");
	system("cls");

	int* initialArray = nullptr;
	int i = 0, numberOfReplaces = 0, numberOfElements = 0;
	cout << "Количество элементов массива: ";
	cin >> numberOfElements;
	initialArray = new int[numberOfElements];

	for (i = 0; i < numberOfElements; i++) {
		cout << "[" << i + 1 << "] = ";
		cin >> initialArray[i];
	}

	cout << "Было: ";
	for (i = 0; i < numberOfElements; i++) {
		cout << initialArray[i] << " ";
	}
	cout << endl;

	numberOfReplaces = MODIFY_ARRAY(initialArray, numberOfElements);

	cout << "Стало: ";
	for (i = 0; i < numberOfElements; i++) {
		cout << initialArray[i] << " ";
	}
	cout << endl;

	cout << "Количество замен: " << numberOfReplaces << endl;

	delete[] (initialArray);
	initialArray = nullptr;
	system("pause");
}