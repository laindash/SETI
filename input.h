#ifndef INPUT_H
#define INPUT_H

#include <conio.h> // �������� ������� getch
#include <string>

constexpr auto KEY_ESC = 0x1B; // ����������� �� ����� ���������� ��� ������, ���������� ����������, ��� ������� ESC
constexpr auto KEY_1 = 0x31; // ����������� �� ����� ���������� ��� ������, ���������� ����������, ��� ������� 1


enum BoolMenu {
    Reset = KEY_1,
    Quit = KEY_ESC
};


/// <summary>
/// ������� ��� ��������� �������������� ����� �� ������������.
/// </summary>
int getInt();

/// <summary>
/// ������� ��� ��������� ���������� ����� � �������� ���������.
/// </summary>
int getKey(int key_min, int key_max);

/// <summary>
/// ������� ��� ��������� ����� ���������� �������� ��� ����������.
/// </summary>
std::string getSign(std::istream& input, std::string& line);

#endif