#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
class MyArray {
private:
    T* data;
    int capacity;
    int size;

    void resize() {
        int newCap = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[newCap];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    MyArray(int initCap = 10) : capacity(initCap), size(0) {
        data = new T[capacity];
    }

    ~MyArray() {
        delete[] data;
    }

    void add(const T& item) {
        if (size >= capacity)
            resize();
        data[size++] = item;
    }

    T& get(int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& get(int index) const {
        if(index < 0 || index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
        for (int i = index; i < size - 1; ++i) data[i] = data[i + 1];
        --size;
    }

    int getSize() const {return size;}
    bool isEmpty() const {return size == 0;}

    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (data[i].isLessThan(data[j])) std::swap(data[i], data[j]);
            }
        }
    }

    T& operator[](int index) {return get(index);}
    const T& operator[](int index) const {return get(index);}

    T* begin() {return data;}
    T* end() {return data + size;}
};