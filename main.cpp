#include <compare>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "point.h"

class B;
class D;

class MyClass{
public:
    MyClass(): a(0), b(0){};
    MyClass(int a, int b) : a(a), b(b){};
    ~MyClass(){}
    
    int a;
    int b;
};
 

class B{
    int b;
public:
    B(): b(0){
        std::cout << "Конструктор B()" << std::endl;
    }
    B(const B &other){
        if(this == &other)
            return;
        this->b = other.b;
        std::cout << "Вызывался конструктор копирования B(B &other)" << std::endl;
    }
    B(int b): b(b){
        std::cout << "Конструктор B()" << std::endl;
    }
    ~B(){
        std::cout << "Деструктор ~B()" << std::endl;
    }

    int get_b() const{
        return b;
    };

    virtual void show(){
        std::cout << "B : " << get_b() << std::endl;
    }

    friend int comp(B obj, D obj_d);
};

class D: public B{
    int d;
public:
    D(): d(0) {
        std::cout << "Конструктор D()" << std::endl;
    }
    D(int b, int d): B(b), d(d){
        std::cout << "Конструктор D()" << std::endl;
    }
    ~D(){
        std::cout << "Декструткор ~D()" << std::endl;
    }
    int get_d() const{
        return this->d;
    };
    void show() override {
        std:: cout << "D : " << this->get_b() << "\t" << d << std::endl;
    }

    int mul() const {
        return d * get_b();
    };

    friend int comp(B obj, D obj_d);
};

int comp(B obj, D obj_d)
{
    return obj_d.d - obj.b;
}


int main(int argc, char* argv[])
{
    std::cout << argv[0] << std::endl;

    // 6.1 - 6.5
    Point a(1,1);
    Point b = a++;
    Point c(a + b);

    std::cout << a[1] << ", " << a[2] << std::endl;
    b.show();
    c.show();

    std::cout << "------------------------------------" << std::endl; 
    a = c;
    std::cout << "------------------------------------" << std::endl;

    std::cout << "------------------------------------" << std::endl; 
    c = (c - b);
    std::cout << "------------------------------------" << std::endl;
    c.show();

    return 0;
}
