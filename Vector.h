#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vector {
private:
    // Константа максимального розміру масиву (за вимогами методички)
    static const int MAX_SIZE = 100;

    int size;                  // Встановлений максимальний розмір для об'єкта
    int count;                 // Фактична кількість елементів у векторі
    int arr[MAX_SIZE];         // Статичний масив цілих чисел

public:
    // ================= КОНСТРУКТОРИ =================
    Vector();                                // Без параметрів
    Vector(int c, int initValue = 0);        // Ініціалізації (задана кількість і значення)
    Vector(const string& str);               // Ініціалізації літерним рядком
    Vector(const Vector& other);             // Копіювання
    ~Vector();                               // Деструктор

    // ================= МЕТОДИ ДОСТУПУ =================
    int getSize() const;                     // Отримати встановлену довжину
    int getCount() const;                    // Отримати фактичну кількість
    void setCount(int c);                    // Змінити фактичну кількість елементів

    // ================= БІЗНЕС-ЛОГІКА (Варіант 15) =================
    double norm() const;                     // Норма вектора (|max - min|)

    // ================= ПЕРЕВАНТАЖЕННЯ ОПЕРАЦІЙ (Методи класу) =================
    Vector& operator=(const Vector& other);  // Присвоєння
    operator string() const;                 // Приведення до рядка

    int& operator[](int index);              // Індексування (для запису: v[i] = 5)
    const int& operator[](int index) const;  // Індексування (для читання: x = v[i])

    // Інкремент/декремент (змінюють всі елементи вектора на 1)
    Vector& operator++();                    // Префіксний інкремент
    Vector& operator--();                    // Префіксний декремент
    Vector operator++(int);                  // Постфіксний інкремент
    Vector operator--(int);                  // Постфіксний декремент

    // ================= ДРУЖНІ ФУНКЦІЇ (Бінарні операції) =================

    // Скалярний добуток векторів
    friend int operator*(const Vector& a, const Vector& b);  // дружня функція, має доступ до private полів

    // Порівняння векторів (за їх нормами, або поелементно)
    friend bool operator==(const Vector& a, const Vector& b); // перевіряє, чи вектори ідентичні
    friend bool operator!=(const Vector& a, const Vector& b); // перевіряє, чи вектори відрізняються
    friend bool operator<(const Vector& a, const Vector& b);  // порівнює норми векторів
    friend bool operator>(const Vector& a, const Vector& b);  // порівнює норми векторів

    // Потокове введення/виведення
    friend ostream& operator<<(ostream& out, const Vector& v); // повертає потік out, щоб можна було писати cout << a << b
    friend istream& operator>>(istream& in, Vector& v);        // повертає потік in, щоб можна було писати cin >> a >> b
};