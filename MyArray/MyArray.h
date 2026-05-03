#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <memory> // Для std::uninitialized_copy и т.д.

template <typename T>
class MyArray {
private:
    T* arr;
    int capacity;
    int size;

    // Вспомогательная функция для уничтожения элементов в диапазоне [start, end)
    void destroyRange(T* start, T* end);

    // Вспомогательная функция для построения элементов из другого диапазона
    void constructFrom(const T* start, const T* end, T* dest);

public:
    // Конструктор
    MyArray(int initialCapacity = 10);

    // Деструктор
    ~MyArray();

    // Конструктор копирования
    MyArray(const MyArray& other);

    // Оператор присваивания копированием
    MyArray& operator=(const MyArray& other);

    // Добавить элемент в конце
    void add(const T& element);

    // Получить элемент по индексу
    T& get(int index);

    // Получить элемент по индексу (константная версия)
    const T& get(int index) const;

    // Установить элемент по индексу
    void set(int index, const T& value);

    // Удалить элемент по индексу
    void removeAt(int index);

    // Получить текущий размер
    int getSize() const;

    // Проверить, пуст ли массив
    bool isEmpty() const;

    // Напечатать все элементы
    void printAll() const;

    // Отсортировать элементы (по возрастанию)
    void sort();

    // Отфильтровать элементы по условию
    // Возвращает новый MyArray с элементами, соответствующими условию
    template <typename Predicate>
    MyArray<T> filter(Predicate condition) const;

    // Поддержка итераторов
    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
};

// Включить реализацию
#include "MyArray/MyArray.cpp"