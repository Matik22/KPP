#include <stdexcept>
#include <utility> // Для std::move

template <typename T>
void MyArray<T>::destroyRange(T* start, T* end) {
    while (start != end) {
        --end;
        end->~T();
    }
}

template <typename T>
void MyArray<T>::constructFrom(const T* start, const T* end, T* dest) {
    while (start != end) {
        new (dest) T(*start);
        ++dest;
        ++start;
    }
}

template <typename T>
MyArray<T>::MyArray(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;
    arr = static_cast<T*>(::operator new[](capacity * sizeof(T)));
}

template <typename T>
MyArray<T>::~MyArray() {
    // Уничтожить все построенные элементы
    destroyRange(arr, arr + size);
    // Освободить память
    ::operator delete[](arr);
}

template <typename T>
MyArray<T>::MyArray(const MyArray& other) {
    capacity = other.capacity;
    size = other.size;
    arr = static_cast<T*>(::operator new[](capacity * sizeof(T)));
    constructFrom(other.arr, other.arr + other.size, arr);
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray& other) {
    if (this != &other) {
        // Уничтожить существующие элементы
        destroyRange(arr, arr + size);
        ::operator delete[](arr);

        // Скопировать из other
        capacity = other.capacity;
        size = other.size;
        arr = static_cast<T*>(::operator new[](capacity * sizeof(T)));
        constructFrom(other.arr, other.arr + other.size, arr);
    }
    return *this;
}

template <typename T>
void MyArray<T>::add(const T& element) {
    if (size >= capacity) {
        // Удвоить ёмкость
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newArr = static_cast<T*>(::operator new[](newCapacity * sizeof(T)));

        // Скопировать существующие элементы в новый массив
        constructFrom(arr, arr + size, newArr);

        // Уничтожить старые элементы и освободить память
        destroyRange(arr, arr + size);
        ::operator delete[](arr);

        arr = newArr;
        capacity = newCapacity;
    }

    // Построить новый элемент в конце
    new (&arr[size]) T(element);
    size++;
}

template <typename T>
T& MyArray<T>::get(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    return arr[index];
}

template <typename T>
const T& MyArray<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    return arr[index];
}

template <typename T>
void MyArray<T>::set(int index, const T& value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    arr[index] = value;
}

template <typename T>
void MyArray<T>::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс вне диапазона");
    }

    // Уничтожить элемент по индексу
    arr[index].~T();

    // Сдвинуть элементы влево
    for (int i = index; i < size - 1; i++) {
        arr[i] = std::move(arr[i + 1]);
    }

    size--;
}

template <typename T>
int MyArray<T>::getSize() const {
    return size;
}

template <typename T>
bool MyArray<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
void MyArray<T>::printAll() const {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MyArray<T>::sort() {
    std::sort(arr, arr + size);
}

template <typename T>
template <typename Predicate>
MyArray<T> MyArray<T>::filter(Predicate condition) const {
    MyArray<T> result;
    for (int i = 0; i < size; i++) {
        if (condition(arr[i])) {
            result.add(arr[i]);
        }
    }
    return result;
}

template <typename T>
T* MyArray<T>::begin() {
    return arr;
}

template <typename T>
T* MyArray<T>::end() {
    return arr + size;
}

template <typename T>
const T* MyArray<T>::begin() const {
    return arr;
}

template <typename T>
const T* MyArray<T>::end() const {
    return arr + size;
}