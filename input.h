#ifndef INPUT_H
#define INPUT_H

#include <conio.h> // Содержит функцию getch
#include <string>

constexpr auto KEY_ESC = 0x1B; // Вычисляемый на этапе компиляции тип данных, являющийся константой, для клавиши ESC
constexpr auto KEY_1 = 0x31; // Вычисляемый на этапе компиляции тип данных, являющийся константой, для клавиши 1


enum BoolMenu {
    Reset = KEY_1,
    Quit = KEY_ESC
};


/// <summary>
/// Функция для получения целочисленного ввода от пользователя.
/// </summary>
int getInt();

/// <summary>
/// Функция для получения клавишного ввода в заданном диапазоне.
/// </summary>
int getKey(int key_min, int key_max);

/// <summary>
/// Функция для получения знака выполнения действия над операндами.
/// </summary>
std::string getSign(std::istream& input, std::string& line);

#endif