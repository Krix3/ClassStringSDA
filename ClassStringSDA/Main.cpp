#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

class String {
private:
    size_t length;  // Длина строки без учета нуль-терминатора
    char* str;      // Указатель на блок памяти, где хранится строка

public:
    // Конструктор с параметром-строкой (const char*)
    String(const char* s)
    {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Конструктор с параметром длина строки
    String(size_t len) : length(len)
    {
        str = new char[length + 1];
        str[0] = '\0';
    }

    // Конструктор копирования
    String(const String& other) : length(other.length)
    {
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // Оператор присваивания
    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Деструктор
    ~String()
    {
        delete[] str;
    }

    // Метод для вывода строки на экран
    void print() const
    {
        cout << str << endl;
    }

    // Сеттер, принимающий в качестве параметра строку (const char*)
    void setString(const char* s)
    {
        size_t newLength = strlen(s);
        if (newLength > length)
        {
            delete[] str;
            str = new char[newLength + 1];
            length = newLength;
        }
        strcpy(str, s);
    }

    // Метод для получения длины строки
    size_t getLength() const
    {
        return length;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Тестирование класса String
    String s1("Привет, Мир!");
    s1.print();  // Вывод: Hello, World!

    String s2(10);
    s2.setString("Короткий");
    s2.print();  // Вывод: Short

    s2.setString("Это более длинная строка");
    s2.print();  // Вывод: This is a longer string

    String s3 = s1;
    s3.print();  // Вывод: Hello, World!

    s3.setString("Новая строка");
    s3.print();  // Вывод: New string

    s1.print();  // Вывод: Hello, World! (проверка, что s1 не изменился)

    return 0;
}