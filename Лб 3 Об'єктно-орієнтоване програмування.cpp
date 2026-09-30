#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <clocale>

using namespace std;

class Angle
{
private:
    int degrees;
    int minutes;

    int totalMinutes() const
    {
        return degrees * 60 + minutes;
    }

    void normalize()
    {
        int total = totalMinutes();
        const int fullCircle = 360 * 60;

        total %= fullCircle;

        if (total < 0)
            total += fullCircle;

        degrees = total / 60;
        minutes = total % 60;
    }

public:

    // 1. Конструктор за замовчуванням
    Angle()
    {
        degrees = 0;
        minutes = 0;

        cout << "Викликано конструктор за замовчуванням."
            << endl;
    }

    // 2. Конструктор з параметрами
    Angle(int d, int m)
    {
        degrees = d;
        minutes = m;

        normalize();

        cout << "Викликано конструктор з параметрами."
            << endl;
    }

    // 3. Конструктор копіювання
    Angle(const Angle& other)
    {
        degrees = other.degrees;
        minutes = other.minutes;

        cout << "Викликано конструктор копіювання."
            << endl;
    }

    // Деструктор
    ~Angle()
    {
        cout << "Викликано деструктор Angle."
            << endl;
    }

    // Ініціалізація об'єкта
    void Init(int d = 0, int m = 0)
    {
        degrees = d;
        minutes = m;

        normalize();
    }

    // Введення даних
    void Read()
    {
        cout << "Введіть градуси: ";
        cin >> degrees;

        cout << "Введіть хвилини: ";
        cin >> minutes;

        normalize();
    }

    // Виведення даних
    void Display() const
    {
        cout << degrees << "° "
            << minutes << "'" << endl;
    }

    // Перетворення в рядок
    string toString() const
    {
        ostringstream out;

        out << degrees << "° "
            << minutes << "'";

        return out.str();
    }

    // Переведення у радіани
    double toRadians() const
    {
        const double PI = 3.14159265358979323846;

        double angleInDegrees =
            degrees + minutes / 60.0;

        return angleInDegrees * PI / 180.0;
    }

    // Нормалізація кута
    void normalizeAngle()
    {
        normalize();
    }

    // Збільшення кута
    void increase(int d, int m)
    {
        int total =
            totalMinutes() + d * 60 + m;

        degrees = total / 60;
        minutes = total % 60;

        normalize();
    }

    // Зменшення кута
    void decrease(int d, int m)
    {
        int total =
            totalMinutes() - d * 60 - m;

        degrees = total / 60;
        minutes = total % 60;

        normalize();
    }

    // Обчислення синуса
    double sine() const
    {
        return sin(toRadians());
    }

    // Порівняння двох кутів
    int compare(const Angle& other) const
    {
        int thisAngle = totalMinutes();
        int otherAngle = other.totalMinutes();

        if (thisAngle < otherAngle)
            return -1;

        if (thisAngle > otherAngle)
            return 1;

        return 0;
    }

    // Оператор ==
    bool operator==(const Angle& other) const
    {
        return compare(other) == 0;
    }

    // Оператор <
    bool operator<(const Angle& other) const
    {
        return compare(other) < 0;
    }

    // Оператор >
    bool operator>(const Angle& other) const
    {
        return compare(other) > 0;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    cout << "=== Перевірка конструктора за замовчуванням ==="
        << endl;

    Angle angle1;

    cout << "angle1 = ";
    angle1.Display();

    cout << endl;

    cout << "=== Перевірка конструктора з параметрами ==="
        << endl;

    Angle angle2(120, 30);

    cout << "angle2 = ";
    angle2.Display();

    cout << endl;

    cout << "=== Перевірка конструктора копіювання ==="
        << endl;

    Angle angle3(angle2);

    cout << "angle3 = ";
    angle3.Display();

    cout << endl;

    cout << "=== Введення першого кута ==="
        << endl;

    angle1.Read();

    cout << endl;

    cout << "Перший кут: ";
    angle1.Display();

    cout << fixed << setprecision(6);

    cout << "Радіани: "
        << angle1.toRadians()
        << endl;

    cout << "Синус: "
        << angle1.sine()
        << endl;

    cout << endl;

    cout << "=== Операції з першим кутом ==="
        << endl;

    angle1.increase(10, 30);

    cout << "Після збільшення на 10° 30': ";
    angle1.Display();

    angle1.decrease(5, 15);

    cout << "Після зменшення на 5° 15': ";
    angle1.Display();

    cout << endl;

    cout << "=== Введення другого кута ==="
        << endl;

    Angle angle4;

    angle4.Read();

    cout << "Другий кут: ";
    angle4.Display();

    cout << endl;

    cout << "=== Порівняння кутів ==="
        << endl;

    if (angle1 == angle4)
    {
        cout << "Кути рівні." << endl;
    }
    else if (angle1 > angle4)
    {
        cout << "Перший кут більший за другий."
            << endl;
    }
    else
    {
        cout << "Перший кут менший за другий."
            << endl;
    }

    cout << endl;

    cout << "Результат toString() для першого кута: "
        << angle1.toString()
        << endl;

    cout << endl;

    cout << "=== Завершення роботи програми ==="
        << endl;

    return 0;
}