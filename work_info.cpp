﻿#include <iostream>
#include <limits>


void showInfo() {
	std::cout
		<< "***********************************************************************" << std::endl
		<< " Вычислительные системы, сети и телекоммуникации. Лабораторная работа #1." << std::endl
		<< " Тема: Использование встроенного ассемблера в проектах Microsoft Visual Studio C++ x86." << std::endl
		<< " Вычисление простейших арифметических выражений." << std::endl
		<< " Задача: разработать asm-вставку для подсчета суммы, разности, произведения," << std::endl
		<< " целой части частного и остатка от целочисленного деления двух целочисленных значений." << std::endl
		<< "***********************************************************************" << std::endl
		<< " Работу выполнили: Семенков Даниил Ильич && Егорова Ксения Олеговна && Смирнова Светлана Алексеевна." << std::endl
		<< " Группа 425 | 2024 год." << std::endl
		<< "-----------------------------------------------------------------------" << std::endl;

	system("pause");
	system("cls");
}

void showMenu() {
	std::cout
		<< "Введите данные. Пример ввода представлен ниже." << std::endl
		<< "Пример:" << std::endl
		<< "Введите первый операнд: 425" << std::endl
		<< "Введите знак действия (+ - * /): *" << std::endl
		<< "Введите второй операнд: 10" << std::endl
		<< "-----------------------------------------------------------------------" << std::endl
		<< "Результат: 425 * 10 = 4250" << std::endl
		<< "-----------------------------------------------------------------------" << std::endl
		<< "В случае умножения рекомендуется вводить небольшие множители, т.к. если их произведение превысит " << std::endl
		<< std::numeric_limits<int>::max() << " , то оно будет расчитано неверно, из-за ограничений типа int." << std::endl
		<< "После получения результата вы можете нажать ESC для выхода или продолжить ввод." << std::endl;
}