#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

class String {
private:
    size_t length;  // ����� ������ ��� ����� ����-�����������
    char* str;      // ��������� �� ���� ������, ��� �������� ������

public:
    // ����������� � ����������-������� (const char*)
    String(const char* s)
    {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // ����������� � ���������� ����� ������
    String(size_t len) : length(len)
    {
        str = new char[length + 1];
        str[0] = '\0';
    }

    // ����������� �����������
    String(const String& other) : length(other.length)
    {
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // �������� ������������
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

    // ����������
    ~String()
    {
        delete[] str;
    }

    // ����� ��� ������ ������ �� �����
    void print() const
    {
        cout << str << endl;
    }

    // ������, ����������� � �������� ��������� ������ (const char*)
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

    // ����� ��� ��������� ����� ������
    size_t getLength() const
    {
        return length;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // ������������ ������ String
    String s1("������, ���!");
    s1.print();  // �����: Hello, World!

    String s2(10);
    s2.setString("��������");
    s2.print();  // �����: Short

    s2.setString("��� ����� ������� ������");
    s2.print();  // �����: This is a longer string

    String s3 = s1;
    s3.print();  // �����: Hello, World!

    s3.setString("����� ������");
    s3.print();  // �����: New string

    s1.print();  // �����: Hello, World! (��������, ��� s1 �� ���������)

    return 0;
}