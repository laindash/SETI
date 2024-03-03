#include <iostream>

int firstFunc(int x) {
    int result = 0;
    result = (x - 0x20) * 5 / 9;
    return result;
}

int secondFunc(int a, int b) {
    a = a + b;
    return a;
}

void thirdFunc() {
    int a, b;

    a = firstFunc(0x64);
    b = secondFunc(0x8, 0x10);
}

int main() {
    thirdFunc();

    system("pause");
    return 0;
}