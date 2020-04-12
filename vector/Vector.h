//
// Created by Maxim Hnatiuk on 24.02.2020.
//

#ifndef VECTOR_LIST_VECTOR_H
#define VECTOR_LIST_VECTOR_H

#include <iostream>
#include <string>

template <typename T>
class Vector {
private:
    T* vectorPtr;
    int size;
public:
    explicit Vector(int size);
    Vector(Vector& a);
    Vector(T array[], int length);

    int getSize();
    int setSize(int newSize);
    T getElement(int index);
    T* getPtr();
    int setPtr(T* newPtr);

    std::string toString();

    int add(T element);
    int remove(int index);

    Vector& operator=(const Vector& vector);
    bool operator==(Vector& vector);

    Vector calculate(Vector& vector, char sign);
    int changeArray(T element, char sign);

    template <T> friend Vector<T> operator+(Vector<T>& first, Vector<T>& second);
    template <T> friend int operator+(Vector<T>& vector, T element);
    template <T> friend int operator+(T element, Vector<T>& vector);
    template <T> friend int operator+=(Vector<T>& vector, T element);

    template <T> friend Vector<T> operator-(Vector<T>& first, Vector<T>& second);
    template <T> friend int operator-(Vector<T>& vector, int index);
    template <T> friend int operator-=(Vector<T>& vector, T element);

    template <T> friend Vector<T> operator*(Vector<T>& first, Vector<T>& second);
    template <T> friend Vector<T> operator*(Vector<T>& vector, T element);
    template <T> friend Vector<T> operator*(T element, Vector<T>& vector);
    template <T> friend int operator*=(Vector<T>& vector, T element);

    template <T> friend Vector<T> operator/(Vector<T>& first, Vector<T>& second);
    template <T> friend int operator/=(Vector<T>& vector, T element);

    template <T> friend std::ostream& operator <<(std::ostream& output, Vector<T>& vector);
    template <T> friend std::istream& operator >>(std::istream& input, Vector<T>& vector);

    ~Vector();
};


#endif //VECTOR_LIST_VECTOR_H
