#include <iostream>
#include <Windows.h>
#include "Vector.h"

using namespace std;

// Структура для демонстрації #pragma pack(1)
#pragma pack(push, 1)
class VectorPacked {
    int size;
    int count;
    int arr[100];
};
#pragma pack(pop)

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "Розмір класу Vector без #pragma pack(1): " << sizeof(Vector) << " байт" << endl;
    cout << "Розмір класу з #pragma pack(1): " << sizeof(VectorPacked) << " байт" << endl;
    cout << "-------------------------------------------------" << endl;

    // Демонстрація конструкторів
    Vector v1;                          // За умовчанням
    Vector v2(3, 5);                    // 3 елементи, кожен = 5
    Vector v3("10 20 30 40");           // З літерного рядка
    Vector v4 = v3;                     // Копіювання

    cout << "v1 (за умовчанням)   : " << v1 << endl;
    cout << "v2 (ініціалізації)   : " << v2 << endl;
    cout << "v3 (з рядка)         : " << v3 << endl;
    cout << "v4 (копія v3)        : " << v4 << endl;
    cout << "-------------------------------------------------" << endl;

    // Демонстрація бізнес-логіки (Норма та скалярний добуток)
    Vector v5("2 8 4 10");
    cout << "Вектор v5: " << v5 << endl;
    cout << "Норма вектора v5 (|max - min| = |10 - 2|): " << v5.norm() << endl;

    Vector a("1 2 3");
    Vector b("4 5 6");
    cout << "Вектор a: " << a << ", Вектор b: " << b << endl;
    cout << "Скалярний добуток (a * b) = " << (a * b) << "  // 1*4 + 2*5 + 3*6" << endl;
    cout << "-------------------------------------------------" << endl;

    // Демонстрація порівнянь
    cout << "Порівняння векторів a та b:" << endl;
    cout << "a == b : " << (a == b ? "Так" : "Ні") << endl;
    cout << "a < b (за нормою) : " << (a < b ? "Так" : "Ні") << endl;
    cout << "-------------------------------------------------" << endl;

    // Індексування та інкремент
    a[0] = 99;
    cout << "Вектор 'a' після зміни a[0] = 99: " << a << endl;
    cout << "++a (збільшення всіх елементів): " << ++a << endl;
    cout << "-------------------------------------------------" << endl;

    // Демонстрація масиву об'єктів (введення)
    Vector arrVectors[2];
    cout << "Створення масиву векторів:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Вектор [" << i << "]:" << endl;
        cin >> arrVectors[i];
    }

    cout << "\nВаш масив векторів:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "arrVectors[" << i << "] = " << arrVectors[i] << endl;
    }

    return 0;
}