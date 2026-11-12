#include "Vector.h"
#include <sstream>
#include <cmath>
#include <algorithm>

// Конструктор за умовчанням
Vector::Vector() : size(MAX_SIZE), count(0) {
    for (int i = 0; i < size; i++) arr[i] = 0; // очищуємо масив
}

// Конструктор ініціалізації із заданою кількістю
Vector::Vector(int c, int initValue) : size(MAX_SIZE) {
    setCount(c);                               // встановлюємо фактичну кількість
    for (int i = 0; i < count; i++) {
        arr[i] = initValue;                    // заповнюємо масив
    }
}

// Конструктор ініціалізації з літерного рядка ("1 2 3 4")
Vector::Vector(const string& str) : size(MAX_SIZE), count(0) {
    stringstream ss(str);
    int val;
    while (ss >> val && count < size) {
        arr[count++] = val;                    // зчитуємо числа з рядка
    }
}

// Конструктор копіювання
Vector::Vector(const Vector& other) {
    size = other.size;
    count = other.count;
    for (int i = 0; i < count; i++) {
        arr[i] = other.arr[i];                 // копіюємо кожен елемент
    }
}

// Деструктор (порожній, бо масив статичний)
Vector::~Vector() {}

// Гетери
int Vector::getSize() const { return size; }
int Vector::getCount() const { return count; }

// Сетер з перевіркою виходу за межі
void Vector::setCount(int c) {
    if (c >= 0 && c <= size) count = c;
    else count = 0;                            // захист від некоректного розміру
}

// Обчислення норми вектора: |максимальний - мінімальний елемент|
double Vector::norm() const {
    if (count == 0) return 0.0;
    int maxVal = arr[0], minVal = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];  // шукаємо максимум
        if (arr[i] < minVal) minVal = arr[i];  // шукаємо мінімум
    }
    return std::abs(maxVal - minVal);          // модуль різниці
}

// Оператор присвоєння
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        count = other.count;
        for (int i = 0; i < count; i++) {
            arr[i] = other.arr[i];             // копіюємо дані
        }
    }
    return *this;
}

// Перетворення вектора в рядок
Vector::operator string() const {
    stringstream ss;
    ss << "[ ";
    for (int i = 0; i < count; i++) ss << arr[i] << " ";
    ss << "]";
    return ss.str();
}

// Оператор індексування (читання/запис)
int& Vector::operator[](int index) {
    if (index < 0 || index >= count) index = 0; // примітивний захист
    return arr[index];
}

// Оператор індексування (тільки читання)
const int& Vector::operator[](int index) const {
    if (index < 0 || index >= count) index = 0; // примітивний захист
    return arr[index];
}

// Префіксний інкремент (збільшує всі елементи на 1)
Vector& Vector::operator++() {
    for (int i = 0; i < count; i++) ++arr[i];
    return *this;
}

// Префіксний декремент
Vector& Vector::operator--() {
    for (int i = 0; i < count; i++) --arr[i];
    return *this;
}

// Постфіксний інкремент
Vector Vector::operator++(int) {
    Vector temp(*this);                         // копія старого стану
    ++(*this);                                  // викликаємо префіксний
    return temp;                                // повертаємо старий стан
}

// Постфіксний декремент
Vector Vector::operator--(int) {
    Vector temp(*this);                         // копія старого стану
    --(*this);                                  // викликаємо префіксний
    return temp;                                // повертаємо старий стан
}

// Скалярний добуток векторів (сума добутків відповідних координат)
int operator*(const Vector& a, const Vector& b) {
    int sum = 0;
    int limit = min(a.count, b.count);          // множимо до найменшого розміру
    for (int i = 0; i < limit; i++) {
        sum += a.arr[i] * b.arr[i];             // a[i] * b[i]
    }
    return sum;
}

// Порівняння: чи рівні вектори
bool operator==(const Vector& a, const Vector& b) {
    if (a.count != b.count) return false;       // різна кількість - не рівні
    for (int i = 0; i < a.count; i++) {
        if (a.arr[i] != b.arr[i]) return false; // знайшли відмінність
    }
    return true;
}

// Порівняння: чи не рівні
bool operator!=(const Vector& a, const Vector& b) {
    return !(a == b);
}

// Порівняння за нормою: менше
bool operator<(const Vector& a, const Vector& b) {
    return a.norm() < b.norm();
}

// Порівняння за нормою: більше
bool operator>(const Vector& a, const Vector& b) {
    return a.norm() > b.norm();
}

// Виведення вектора
ostream& operator<<(ostream& out, const Vector& v) {
    out << string(v);
    return out;
}

// Введення вектора
istream& operator>>(istream& in, Vector& v) {
    cout << " Введіть кількість елементів: ";
    int c; in >> c;
    v.setCount(c);
    cout << " Введіть " << v.getCount() << " елементів: ";
    for (int i = 0; i < v.getCount(); i++) {
        in >> v[i];                             // зчитуємо значення
    }
    return in;
}