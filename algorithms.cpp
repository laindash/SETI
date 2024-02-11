#include "input.h"
#include "work_info.h"
#include <iostream>


void calculationAndOutput(const std::string& sign, int& x, int& y) {
    int result{}, remainder{}, first_op = x, second_op = y;

    if (sign == "+") {
        _asm {
            MOV EAX, first_op
            MOV EBX, second_op
            ADD EAX, EBX
            MOV result, EAX
        }
    }

    if (sign == "-") {
        _asm {
            MOV EAX, first_op
            MOV EBX, second_op
            SUB EAX, EBX
            MOV result, EAX
        }
    }

    if (sign == "*") {
        _asm {
            MOV EAX, first_op
            IMUL EAX, second_op
            MOV result, EAX
        }
    }

    if (sign == "/") {
        _asm {
            MOV EAX, first_op
            CDQ  // (Convert Doubleword to Quadword) расширяет знак числа в регистре EAX до 64 бит, помещая результат в EDX:EAX
            IDIV second_op
            MOV result, EAX
            MOV remainder, EDX
        }
    }

    if (sign != "/") {
        std::cout
            << "-----------------------------------------------------------------------" << std::endl
            << "Результат: " << x << ' ' << sign << ' ' << y << " = " << result << std::endl
            << "-----------------------------------------------------------------------" << std::endl;
    }
    else {
        std::cout
            << "-----------------------------------------------------------------------" << std::endl
            << "Результат: " << x << ' ' << sign << ' ' << y << " = " << result << ' ' << "остаток: " << remainder << std::endl
            << "-----------------------------------------------------------------------" << std::endl;
    }
}


void startProgram() {
    int user_choice{}, x{}, y{}; // Выбор пользователя и переменные для расчёта
    std::string sign{};
    
    // Вызов приветственного меню
    showInfo();
    
    // Вызов меню действий с переменными
    showMenu();
        
    // Бесконечный цикл работы программы
    for (;;) {
        // Ввод данных пользователем
        std::cout 
            << std::endl
            << "Введите первый операнд: ";
        x = getInt();

        std::cout << "Введите знак действия (+ - * /):  ";
        getSign(std::cin, sign);

        std::cout << "Введите второй операнд: ";
        
        if (sign != "/") {
            y = getInt();
        }
        else {
            do {
                y = getInt();
                
                if (y == 0) {
                    std::cout
                        << "Делить на 0 нельзя! Введите другое значение." << std::endl
                        << std::endl
                        << "Введите второй операнд: ";
                }
            } 
            while (y == 0);
        }

        // Вывод результатов расчёта
        calculationAndOutput(sign, x, y);


        // Вывод опции для перезапуска программы или завершения
        std::cout 
            << std::endl
            << "Нажмите 1, чтобы продолжить ввод. ESC - Завершить работу программы." << std::endl;
        user_choice = getKey(Reset, Reset);
    }
}