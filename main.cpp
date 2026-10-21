// Лабораторна робота № 5.1 (варіант 10)
#include <iostream> // підключення бібліотеки вводу та виводу (cin, cout)
#include <cmath>    // підключення математичної бібліотеки (sin, pow)
using namespace std; // використання стандартного простору імен

double f(const double a, const double b, const double c); // прототип функції f(a, b, c)
double calc(const double s, const double t);               // прототип функції обчислення виразу

#ifndef UNIT_TEST // якщо це не тест, компілюємо main (у тесті свій main)
int main() // головна функція програми
{
    double s, t; // дійсні змінні s і t, задані за умовою
    cout << "s = "; cin >> s; // виводимо підказку та зчитуємо s з клавіатури
    cout << "t = "; cin >> t; // виводимо підказку та зчитуємо t з клавіатури
    cout << "c = " << calc(s, t) << endl; // обчислюємо вираз і виводимо результат
    return 0; // успішне завершення програми
}
#endif // кінець блоку умовної компіляції

// f(a,b,c) = (a+b+c) / (sin^2(ab) + c^2)
double f(const double a, const double b, const double c) // визначення функції f
{
    return (a + b + c) / (pow(sin(a * b), 2) + c * c); // чисельник ділимо на sin^2(ab) + c^2
}

// c = (f(t,s,2) + f(1,s+t,t-s)) / (1 + f^2(1,1,t^2+s^2))
double calc(const double s, const double t) // визначення функції обчислення виразу
{
    // у чисельнику сума двох викликів f, у знаменнику 1 плюс квадрат третього виклику f
    return (f(t, s, 2) + f(1, s + t, t - s)) / (1 + pow(f(1, 1, t * t + s * s), 2));
}
