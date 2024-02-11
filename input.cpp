#include "input.h"
#include <iostream>
#include <string>


int getInt() {
    int input{};

    // Ввод значения с клавиатуры
    std::cin >> input;

    // Проверка наличия ошибок ввода
    do {
        // Если ввод не является целым числом
        if (std::cin.fail()) {
            // Вывод сообщения об ошибке
            std::cout << "Неверный ввод, повторите попытку!" << std::endl;

            // Сброс флага ошибки ввода
            std::cin.clear();

            // Очистка буфера ввода до символа новой строки
            // Первый аргумент - количество игнорируемых символов, второй - разделитель между игнорируемыми символами
            std::cin.ignore(INT_MAX, '\n');

            // Повторный ввод значения
            std::cin >> input;
        }
    } 
    while (std::cin.fail()); // Повторять, пока ввод содержит ошибку

    // Очистка буфера ввода после успешного ввода значения
    std::cin.ignore(INT_MAX, '\n');

    // Возвращение полученного целочисленного значения
    return input;
}


int getKey(int key_min, int key_max) {
    int key = 0;

    // Повторять, пока не будет введена клавиша в заданном диапазоне
    do {
        // Получение клавишного ввода без ожидания нажатия Enter (или другого символа)
        key = _getch();

        // Если нажата клавиша ESC, возвращаем ее значение без ожидания остального ввода
        if (key == KEY_ESC) {
            std::cout << "Выполнение программы было прервано при нажатии ESC" << std::endl;
            exit(EXIT_SUCCESS);
        }
    } 
    while ((key < key_min) || (key > key_max)); // Повторять, пока введенная клавиша не находится в заданном диапазоне

    return key;
}


std::string getSign(std::istream &input, std::string &line) {
    bool valid_input = true;

    // Цикл повторяется, пока не будет введена корректная строка
    do {
        std::getline(input, line);

        // Проверка на наличие ошибок ввода
        do {
            if (std::cin.fail()) {
                // Сброс флага ошибки ввода
                input.clear();

                // Очистка буфера ввода до символа новой строки
                // Первый аргумент - количество игнорируемых символов, второй - разделитель между игнорируемыми символами
                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Некорректный ввод, повторите попытку!" << std::endl;
                std::getline(input, line);
            }
        } 
        while (std::cin.fail()); // Повторять, пока ввод содержит ошибку

   
        if (line.empty()) {
            std::cout << "Вводимое значение не должно быть пустым!" << std::endl;
            valid_input = false;
            continue;
        }

        int space_position(0);
        int character_position(0);

        // Проверка на отсутствие непечатных символов и начало строки с пробела
        for (const unsigned char c : line) {
            // Проверка является ли символ непечатным, используются "широкие" символы, т.к. необходима кириллица
            if (!iswprint(c)) {
                valid_input = false;
                std::cout << "Вводимое значение не должно содержать непечатные символы!" << std::endl;
                break;
            }

            if (c == ' ') {
                space_position++;
            }

            if (c != ' ') {
                character_position++;
            }

            if (space_position > character_position) {
                valid_input = false;
                std::cout << "Вводимое значение не должно начинаться с пробела!" << std::endl;
                break;
            }

            if (!(c == '*' || c == '/' || c == '-' || c == '+')) {
                valid_input = false;
                std::cout << "Вводимое значение и должно быть одним из знаков + - * /!" << std::endl;
                break;
            }
            else {
                valid_input = true;
            }
        }
    } 
    while (!valid_input);

    // Возвращение полученной строки
    return line;
}