#include <stdexcept>
#include <utility>
#include <iostream>

#pragma region helpers

void MyArray::destroyRange(Photo* start, Photo* end) {
    while (start != end) { --end; end->~Photo(); }
}

void MyArray::constructFrom(const Photo* start, const Photo* end, Photo* dest) {
    while (start != end) {
        new (dest) Photo(*start);
        ++dest; ++start;
    }
}

#pragma endregion


#pragma region constructors_destructor

MyArray::MyArray(int initialCapacity)
    : m_capacity(initialCapacity), m_size(0),
      m_arr(static_cast<Photo*>(::operator new[](initialCapacity * sizeof(Photo)))) {}

MyArray::MyArray(const MyArray& other)
    : m_capacity(other.m_capacity), m_size(other.m_size),
      m_arr(static_cast<Photo*>(::operator new[](other.m_capacity * sizeof(Photo)))) {
    constructFrom(other.m_arr, other.m_arr + other.m_size, m_arr);
}

MyArray& MyArray::operator=(const MyArray& other) {
    if (this != &other) {
        destroyRange(m_arr, m_arr + m_size);
        ::operator delete[](m_arr);
        m_capacity = other.m_capacity;
        m_size     = other.m_size;
        m_arr      = static_cast<Photo*>(::operator new[](m_capacity * sizeof(Photo)));
        constructFrom(other.m_arr, other.m_arr + other.m_size, m_arr);
    }
    return *this;
}

MyArray::~MyArray() {
    destroyRange(m_arr, m_arr + m_size);
    ::operator delete[](m_arr);
}

#pragma endregion


#pragma region operators

Photo& MyArray::operator[](int index) {
    if (index < 0 || index >= m_size) throw std::out_of_range("Индекс вне диапазона");
    return m_arr[index];
}

const Photo& MyArray::operator[](int index) const {
    if (index < 0 || index >= m_size) throw std::out_of_range("Индекс вне диапазона");
    return m_arr[index];
}

std::ostream& operator<<(std::ostream& out, const MyArray& obj) {
    for (int i = 0; i < obj.m_size; ++i) {
        out << "[" << i << "] "
            << obj.m_arr[i].getTitle() << " | "
            << obj.m_arr[i].getDate()  << " | "
            << obj.m_arr[i].getAuthor() << "\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, MyArray& obj) {
    int n;
    std::cout << "Введите количество фото -> ";
    in >> n; in.ignore();
    for (int i = 0; i < n; ++i) {
        std::string t, d, a;
        std::cout << "Фото [" << i << "] название -> "; std::getline(in, t);
        std::cout << "Фото [" << i << "] дата     -> "; std::getline(in, d);
        std::cout << "Фото [" << i << "] автор    -> "; std::getline(in, a);
        obj.add(Photo(t, d, a));
    }
    return in;
}

#pragma endregion


#pragma region methods

void MyArray::add(const Photo& element) {
    if (m_size >= m_capacity) {
        int newCap = (m_capacity == 0) ? 1 : m_capacity * 2;
        Photo* newArr = static_cast<Photo*>(::operator new[](newCap * sizeof(Photo)));
        constructFrom(m_arr, m_arr + m_size, newArr);
        destroyRange(m_arr, m_arr + m_size);
        ::operator delete[](m_arr);
        m_arr      = newArr;
        m_capacity = newCap;
    }
    new (&m_arr[m_size]) Photo(element);
    ++m_size;
}

Photo& MyArray::get(int index) {
    if (index < 0 || index >= m_size) throw std::out_of_range("Индекс вне диапазона");
    return m_arr[index];
}

const Photo& MyArray::get(int index) const {
    if (index < 0 || index >= m_size) throw std::out_of_range("Индекс вне диапазона");
    return m_arr[index];
}

void MyArray::set(int index, const Photo& value) {
    if (index < 0 || index >= m_size) throw std::out_of_range("Индекс вне диапазона");
    m_arr[index] = value;
}

void MyArray::removeAt(int index) {
    if (index < 0 || index >= m_size) throw std::out_of_range("Индекс вне диапазона");
    m_arr[index].~Photo();
    for (int i = index; i < m_size - 1; ++i)
        m_arr[i] = std::move(m_arr[i + 1]);
    --m_size;
}

void MyArray::sort() {
    std::sort(m_arr, m_arr + m_size, [](const Photo& a, const Photo& b) {
        return a.getTitle() < b.getTitle();
    });
}

int  MyArray::getSize()     const { return m_size; }
int  MyArray::getCapacity() const { return m_capacity; }
bool MyArray::isEmpty()     const { return m_size == 0; }

#pragma endregion


#pragma region iterators

MyArray::iterator MyArray::begin() { return iterator(m_arr); }
MyArray::iterator MyArray::end()   { return iterator(m_arr + m_size); }

#pragma endregion
