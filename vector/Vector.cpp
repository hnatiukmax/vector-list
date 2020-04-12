//
// Created by Maxim Hnatiuk on 24.02.2020.
//

#include "Vector.h"

template <typename T>
Vector<T>::Vector(int size) {
    this->size = size > 0 ? size : 5;
    this->vectorPtr = new T[this->size];

    for (int i = 0; i < this->size; i++) {
        this->vectorPtr[i] = 0;
    }
}

template <typename T>
Vector<T>::Vector(Vector& vector) {
    this->size = vector.size;
    for (int i = 0; i < vector.size; i++) {
        this->vectorPtr[i] = vector.vectorPtr[i];
    }
}

template <typename T>
Vector<T>::Vector(T array[], int length) {
    this->size = length;
    this->vectorPtr = new T[length];

    for (int i = 0; i < this->size; i++) {
        this->vectorPtr[i] = array[i];
    }
}

template <typename T>
int Vector<T>::getSize() {
    return this->size;
}

template <typename T>
int Vector<T>::setSize(int newSize) {
    T* newVectorPtr = new T[newSize];
    for (int i = 0; i < newSize; i++) {
        newVectorPtr[i] = i > this->size ? 0 : vectorPtr[i];
    }

    this->size = newSize;
    this->vectorPtr = newVectorPtr;

    return 1;
}

template <typename T>
T Vector<T>::getElement(int index) {
    if (this->size < index) {
        return 0;
    }
    return this->vectorPtr[index];
}

template <typename T>
T* Vector<T>::getPtr() {
    return this->vectorPtr;
}

template <typename T>
int Vector<T>::setPtr(T* newPtr) {
    if (newPtr == nullptr) {
        return -1;
    }

    for (int i = 0; i < this->size; i++) {
        this->vectorPtr[i] = newPtr[i];
    }
    this->vectorPtr = newPtr;

    return 1;
}

template <typename T>
std::string Vector<T>::toString() {
    std::string result = "[";
    for (int i = 0; i < this->size; i++) {
        result += std::to_string(this->vectorPtr[i]) + ((i == size - 1) ? "" : ", ");
    }
    result += "]";
    return result;
}

template <typename T>
int Vector<T>::add(T element) {
    T* newVectorPtr = new T[this->size + 1];
    for (int i = 0; i < this->size; i++) {
        newVectorPtr[i] = vectorPtr[i];
    }
    newVectorPtr[this->size] = element;

    this->size += 1;

    delete this->vectorPtr;
    this->vectorPtr = newVectorPtr;

    return 1;
}

template <typename T>
int Vector<T>::remove(int index) {
    if (this->size == 0 || this->size <= index) {
        return -1;
    }

    T* newVectorPtr = new T[this->size - 1];
    bool less = false;
    for (int i = 0; i < this->size; i++) {
        if (i == index) {
            less = true;
            continue;
        }
        newVectorPtr[less ? i - 1 : i] = vectorPtr[i];
    }

    this->size -= 1;
    this->vectorPtr = newVectorPtr;

    return 1;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& vector) {
    if (this == &vector) {
        return *this;
    }

    this->size = vector.size;

    for (int i = 0; i < vector.size; i++) {
        this->vectorPtr[i] = vector.vectorPtr[i];
    }

    return *this;
}

template <typename T>
bool Vector<T>::operator==(Vector& vector_list) {
    if (this->vectorPtr == vector_list.vectorPtr) {
        return true;
    } else if (this->size == vector_list.size) {
        for (int i = 0; i < vector_list.size; i++) {
            if (this->vectorPtr[i] != vector_list.vectorPtr[i]) {
                return false;
            }
        }
    } else {
        return false;
    }

    return true;
}

template <typename T>
Vector<T> operator +(Vector<T>& first, Vector<T>& second) {
    return first.calculate(second, '+');
}

template <typename T>
int operator +(T element, Vector<T>& vector) {
    return vector.add(element);
}

template <typename T>
int operator +(Vector<T>& vector, T element) {
    return vector.add(element);
}

template <typename T>
int operator +=(Vector<T>& vector, T element) {
    return vector + element;
}

template <typename T>
Vector<T> operator -(Vector<T>& first, Vector<T>& second) {
    return first.calculate(second, '-');
}

template <typename T>
int operator -(Vector<T>& vector, int index) {
    return vector.remove(index);
}

template <typename T>
int operator -=(Vector<T>& vector, T index) {
    return vector.remove(index);
}

template <typename T>
Vector<T> operator *(Vector<T>& first, Vector<T>& second) {
    return first.calculate(second, '*');
}

template <typename T>
Vector<T> operator *(T element, Vector<T>& vector) {
    T* ptr = new T[vector.getSize()];

    for (int i = 0; i < vector.getSize(); i++) {
        ptr[i] = vector.getElement(i) * element;
    }

    Vector<T> result(vector.getSize());
    result.setPtr(ptr);

    return result;

}

template <typename T>
Vector<T> operator *(Vector<T>& vector, T element) {
    return element * vector;
}

template <typename T>
int operator *=(Vector<T>& vector, T element) {
    return vector.changeArray(element, '*');
}

template <typename T>
Vector<T> operator /(Vector<T>& first, Vector<T>& second) {
    return first.calculate(second, '/');
}

template <typename T>
int operator /=(Vector<T>& vector, T element) {
    return vector.changeArray(element, '/');
}

template <typename T>
std::ostream& operator <<(std::ostream& output, Vector<T>& vector) {
    output << vector.toString();
    return output;
}

template <typename T>
std::istream& operator >>(std::istream& input, Vector<T>& vector) {
    T* inputPtr = new T[vector.getSize()];
    for (int i = 0; i < vector.getSize(); i++) {
        input >> inputPtr[i];
    }

    vector.setPtr(inputPtr);

    return input;
}

template <typename T>
Vector<T>::~Vector() {
    delete [] this->vectorPtr;
}

template <typename T>
int Vector<T>::changeArray(T element, char sign) {
    if (this->size <= 0) {
        return -1;
    }

    for (int i = 0; i < this->size; i++) {
        switch (sign) {
            case '*':
                this->vectorPtr[i] *= element;
                break;
            case '/':
                this->vectorPtr[i] /= element;
                break;
            default:
                break;
        }
    }

    return 1;
}

template <typename T>
Vector<T> Vector<T>::calculate(Vector<T>& vector, char sign) {
    int newSize = __min(this->size, vector.size);
    T* ptr = new T[newSize];

    for (int i = 0; i < newSize; i++) {
        switch (sign) {
            case '+':
                ptr[i] = this->vectorPtr[i] + vector.vectorPtr[i];
                break;
            case '-':
                ptr[i] = this->vectorPtr[i] - vector.vectorPtr[i];
                break;
            case '*':
                ptr[i] = this->vectorPtr[i] * vector.vectorPtr[i];
                break;
            case '/':
                ptr[i] = this->vectorPtr[i] / vector.vectorPtr[i];
                break;
            default:
                ptr[i] = this->vectorPtr[i];
                break;
        }
    }

    Vector result = Vector(newSize);
    result.vectorPtr = ptr;

    return result;
}
