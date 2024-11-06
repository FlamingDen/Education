#include <compare>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "point.h"

class B;
class D1;
class D2;
class D3;

 
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
};

class D1: virtual public B{
    int d1;
public:
    D1(): B(), d1(0) {
        std::cout << "Конструктор D1()" << std::endl;
    }
    D1(int b, int d): B(b), d1(d){
        std::cout << "Конструктор D1()" << std::endl;
    }
    ~D1(){
        std::cout << "Декструткор ~D1()" << std::endl;
    }
    int get_d1() const{
        return this->d1;
    };
    void show() override {
        std:: cout << "D : " << this->get_b() << "\t" << d1 << std::endl;
    }

    int mul() const {
        return d1 * get_b();
    };
};

class D2: virtual public B{
    int d2;
public:
    D2(): B(), d2(0) {
        std::cout << "Конструктор D2()" << std::endl;
    }
    D2(int b, int d): B(b), d2(d){
        std::cout << "Конструктор D2()" << std::endl;
    }
    ~D2(){
        std::cout << "Декструткор ~D2()" << std::endl;
    }
    int get_d2() const{
        return this->d2;
    };
    void show() override {
        std:: cout << "D : " << this->get_b() << "\t" << d2 << std::endl;
    }

    int mul() const {
        return d2 * get_b();
    };
};

class D3: public D1, public D2{
    int d3;
public:
    D3(): d3(0) {
        std::cout << "Конструктор D3()" << std::endl;
    }
    D3(int b, int d): d3(d){
        std::cout << "Конструктор D3()" << std::endl;
    }
    ~D3(){
        std::cout << "Декструткор ~D3()" << std::endl;
    }
    int get_d3() const{
        return this->d3;
    };
    void show() override {
        std:: cout << "D3 : " << "\t" << this->get_d1()<< "\t" << this->get_d2() << "\t" << d3 << std::endl;
    }
};




int main(int argc, char* argv[])
{
    std::cout << argv[0] << std::endl;


    // 8.3
    std::cout.fill('&');
    std::cout.width(13);
    std::cout << "hi!" <<std::endl;

    std::cout.fill('&');
    std::cout.width(13);
    std::cout.setf(std::iostream::left);
    std::cout << "hi!" <<std::endl;
    
    std::cout.fill('-');
    std::cout.width(13);
    std::cout.precision(10);
    std::cout.setf(std::iostream::right);
    std::cout << 123.123<<std::endl;
    

    // 8.4
    std::cout << std::setw(10) << std::setfill('@') << 100 <<std::endl;
    

    // 8.5
    Point p(11,22);
    std::cout << p;


    // 8.6
    Point point;
    std::cin >> point;
    std::cout << point;


    return 0;
}
