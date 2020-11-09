// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <algorithm>
#include <cassert>
using namespace std;

class ArrayInt {
private:
    int m_length;
    int* m_data;
public:
    ArrayInt() : m_length(0), m_data(nullptr) {}
    ArrayInt(int length) : m_length(length) {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
        //Дополним класс заполнением нулями, иначе элементы массива будут мусором.
        for (int i = 0; i < length; i++) {
            *(m_data + i) = 0;
        }

    }
    ~ArrayInt() { delete [] m_data; }
    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() const { return m_length; }
    int& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void resize(int newLength) {
        if (newLength == m_length) return;
        if (newLength <= 0) {
            erase();
            return;
        }
        int* data = new int[newLength];
        if (m_length > 0) {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            for (int i = 0; i < elementsToCopy; ++i) {
                data[i] = m_data[i];
            }
            for (int i = elementsToCopy; i < newLength; ++i) {
                *(data+i) = 0;
            }
            delete[] m_data;
            m_data = data;
            m_length = newLength;
        }
    }
    void pop_back() {
        resize(m_length - 1);
    }
    void pop_front() {
        int* data = new int[m_length-1];
        for (int i = 1; i < m_length; ++i) {
            data[i - 1] = m_data[i];
        }
        delete[] m_data;
        m_data = data;
        m_length--;
    }

    void print() {
        for (int i = 0; i < m_length; i++) {
            cout << m_data[i] << " ";
        }
        cout << endl;
    }

    void sort() { //Пузырьком
        int temp;
        for (int i = m_length - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (*(m_data + j) > * (m_data + j + 1)) {
                    temp = *(m_data + j + 1);
                    *(m_data + j + 1) = *(m_data + j);
                    *(m_data + j) = temp;
                }
            }
        }
    }

};

int main()
{

    ArrayInt array(5);
    array.resize(10);

    for (int i = 0; i < 10; i++) {
        array[i] = i + 1;
    }

    array.print();

    array.pop_back();
    array.print();
    array.pop_front();
    array.print();

    array.resize(10);
    array.print();

    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 10 +1;
    }

    array.print();
    array.sort();
    array.print();



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
