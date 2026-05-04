#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include "../Photo/Photo.h"

#pragma region ArrayIterator

class ArrayIterator {
    friend class MyArray;
public:
    ArrayIterator(const ArrayIterator& other) : m_ptr(other.m_ptr) {}

    bool operator==(const ArrayIterator& other) const { return m_ptr == other.m_ptr; }
    bool operator!=(const ArrayIterator& other) const { return m_ptr != other.m_ptr; }

    ArrayIterator& operator++() { ++m_ptr; return *this; }
    ArrayIterator  operator++(int) { ArrayIterator tmp(*this); ++m_ptr; return tmp; }

    Photo& operator*()  const { return *m_ptr; }
    Photo* operator->() const { return  m_ptr; }

private:
    Photo* m_ptr;
    explicit ArrayIterator(Photo* ptr) : m_ptr(ptr) {}
};

#pragma endregion


#pragma region class_MyArray

class MyArray {
public:
    typedef ArrayIterator iterator;

    MyArray(int initialCapacity = 10);
    MyArray(const MyArray& other);
    MyArray& operator=(const MyArray& other);
    ~MyArray();

    Photo&       operator[](int index);
    const Photo& operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& out, const MyArray& obj);
    friend std::istream& operator>>(std::istream& in,  MyArray& obj);

    void         add(const Photo& element);
    Photo&       get(int index);
    const Photo& get(int index) const;
    void         set(int index, const Photo& value);
    void         removeAt(int index);
    void         sort();

    int  getSize()     const;
    int  getCapacity() const;
    bool isEmpty()     const;

    iterator begin();
    iterator end();

private:
    int    m_capacity;
    int    m_size;
    Photo* m_arr;

    void destroyRange(Photo* start, Photo* end);
    void constructFrom(const Photo* start, const Photo* end, Photo* dest);
};

#pragma endregion

#include "MyArray.cpp"
