#include <compare>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <regex>
#include <new>

#include <typeinfo>

#include "TimeGuard.hpp"
#include "show.h"

#include "point.h"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <shared_mutex>

class B;
class D1;
class D2;
class D3;

//==============================================================================//
class B {
    int b;
public:
    B() : b(0) {
        std::cout << "Конструктор B()" << std::endl;
    }
    B(const B& other) {
        if (this == &other)
            return;
        this->b = other.b;
        std::cout << "Вызывался конструктор копирования B(B &other)" << std::endl;
    }
    B(int b) : b(b) {
        std::cout << "Конструктор B()" << std::endl;
    }
    virtual ~B() {
        std::cout << "Деструктор ~B()" << std::endl;
    }
    int get_b() const {
        return b;
    };
    virtual void show() {
        std::cout << "B : " << get_b() << std::endl;
    }
};

class D1 : virtual public B {
    int d1;
public:
    D1() : B(), d1(0) {
        std::cout << "Конструктор D1()" << std::endl;
    }
    D1(int b, int d) : B(b), d1(d) {
        std::cout << "Конструктор D1()" << std::endl;
    }
    ~D1() {
        std::cout << "Декструткор ~D1()" << std::endl;
    }
    int get_d1() const {
        return this->d1;
    };
    void show() override {
        std::cout << "D : " << this->get_b() << "\t" << d1 << std::endl;
    }
    int mul() const {
        return d1 * get_b();
    };
};

class D2 : virtual public B {
    int d2;
public:
    D2() : B(), d2(0) {
        std::cout << "Конструктор D2()" << std::endl;
    }
    D2(int b, int d) : B(b), d2(d) {
        std::cout << "Конструктор D2()" << std::endl;
    }
    ~D2() {
        std::cout << "Декструткор ~D2()" << std::endl;
    }
    int get_d2() const {
        return this->d2;
    };
    void show() override {
        std::cout << "D : " << this->get_b() << "\t" << d2 << std::endl;
    }

    int mul() const {
        return d2 * get_b();
    };
};

class D3 : public D1, public D2 {
    int d3;
public:
    D3() : d3(0) {
        std::cout << "Конструктор D3()" << std::endl;
    }
    D3(int b, int d) : d3(d) {
        std::cout << "Конструктор D3()" << std::endl;
    }
    ~D3() {
        std::cout << "Декструткор ~D3()" << std::endl;
    }
    int get_d3() const {
        return this->d3;
    };
    void show() override {
        std::cout << "D3 : " << "\t" << this->get_b() << "\t" << this->get_d1() << "\t" << this->get_d2() << "\t" << d3 << std::endl;
    }
};

//==============================================================================//
class Base {
    int a, b;
public:
    Base() : a(0), b(0) {
        std::cout << "Base()" << std::endl;
    }
    Base(int a) : a(a), b(0) {
        std::cout << "Base()" << std::endl;
    }
    virtual ~Base() {
        std::cout << "~Base()" << std::endl;
    }
    int getA() { return a; }
    int getB() { return b; }
    virtual void show() = 0;
};

class Child final : public  Base
{
    //Timer t{"Field in Child"};
public:
    Child() {
        std::cout << "Child()" << std::endl;
    }
    ~Child() {
        std::cout << "~Child()" << std::endl;
    }
    virtual void show() override {
        std::cout << getB() * getA() << std::endl;
    }
};

//==============================================================================//
std::istream& manip(std::istream& out) {
    out.width(20);
    out.precision(5);
    out.fill('-');
    return out;
}

void check_status(std::ostream& in) {
    std::iostream::iostate i = in.rdstate();
    bool a = i & std::_S_goodbit;
    a = i & std::iostream::badbit;
    a = i & std::iostream::failbit;
    a = i & std::iostream::eofbit;
    if (i == std::iostream::badbit) {
        std::cout << "Fatal!";
    }
    if (i == std::iostream::failbit) {
        std::cout << "No fatal!";
    }
    if (i == std::_S_goodbit) {
        std::cout << "Все хорошо!";
    }
    if (i == std::iostream::eofbit) {
        std::cout << "End!";
    }
}

template<typename T>
T sum(T a, T b) {
    return a + b;
}

double divide(double a, double b) {
    try
    {
        if (!b) throw b;
    }
    catch (...)
    {
        std::cerr << "Дление на 0" << '\n';
        exit(1);
    }
    return a / b;
}

template<typename T>
class G {
    T x;
};

//==============================================================================//
// свой new
// void* operator new(size_t count){
//     std::cout << "new: allocate " << count << " bytes" << std::endl;
//     if(auto ptr = std::malloc(count); ptr != nullptr)
//         return ptr;
//     throw std::bad_alloc();
// }

// void* operator new[](size_t count){
//     std::cout << "new[] -> ";
//     return ::operator new(count);
// }

// N* b = new N;
// N* barr = new N[1];
class N {
    int b;
public:
    N() : b(0) {
        std::cout << "N()" << std::endl;
    }
    ~N() {
        std::cout << "~N()" << std::endl;
    }
};

//==============================================================================//
// интересный случай с move семантикой
// float a = 1.1f;
// int b = 2;
// std::cout << "      For rvalue : " << std::endl;
// std::cout << "  float 1.1f : " << std::endl;
// test(1.1f);
// std::cout << "  int 2 : " << std::endl;
// test(2);
// std::cout << std::endl << std::endl;
// std::cout << "      For lvalue : " << std::endl;
// std::cout << "  float 1.1f : " << std::endl;
// test(a);
// std::cout << "  int 2 : " << std::endl;
// test(b);
void func(float&& a) {
    std::cout << "f&& " << a << std::endl;
}

void func(int&& a) {
    std::cout << "i&& " << a << std::endl;
}

void func(float& a) {
    std::cout << "f& " << a << std::endl;
}

void func(int& a) {
    std::cout << "i& " << a << std::endl;
}

template <typename T>
void test(T&& v) {
    std::cout << "Common -> ";
    func(v);
    std::cout << "std::move -> ";
    func(std::move(v));
    std::cout << "std::forward<T> -> ";
    func(std::forward<T&&>(v));
}

//==============================================================================//
// свой std::move()

void foo(int& v) { std::cout << "int&  " << v << std::endl; }
void foo(int&& v) { std::cout << "int&& " << v << std::endl; }

template<typename T>
std::remove_reference_t<T>&& custom_move(T&& value) {
    return static_cast<std::remove_reference_t<T>&&>(value);
}

template<typename T>
T&& custom_forward(std::remove_reference_t<T>& value) {
    return static_cast<T&&>(value);
}

template<typename T>
T&& custom_forward(std::remove_reference_t<T>&& value) {
    static_assert(!std::is_lvalue_reference_v<T>);
    return static_cast<T&&>(value);
}

//==============================================================================//
std::mutex mt;
int counter{ 0 };
std::condition_variable cv;

void processing() {
    int c;
    {
        std::unique_lock<std::mutex> lk{ mt };
        cv.wait(lk, [] { return counter > 0;});
        c = counter;
    }
    std::cout << "-";
}

void prepare() {
    {
        std::lock_guard<std::mutex> lk{ mt };
        ++counter;
        cv.notify_all();
    }
    std::cout << "+";
}

//==============================================================================//
int main() {
    TimeGuard timer("Main.cpp");


}

