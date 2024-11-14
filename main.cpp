#include <compare>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>


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
    virtual ~B(){
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
        std:: cout << "D3 : " << "\t" << this->get_b() << "\t" << this->get_d1()<< "\t" << this->get_d2() << "\t" << d3 << std::endl;
    }
};

class Base{
    int a, b;
public:
    Base(): a(0), b(0) {}
    Base(int a) : a(a), b(0){}
    virtual ~Base(){}
    int getA(){ return a; }
    int getB(){ return b; }
    virtual void show() = 0;
};

class Child final: public  Base 
{
public:
    Child(){}
    ~Child(){}
    void show() override {
        std::cout << getB() * getA()  << std::endl;
    }
};





std::istream& manip(std::istream &out){ 
    out.width(20);
    out.precision(5);
    out.fill('-');
    return out;
}

void check_status(std::ostream &in){
    std::iostream::iostate i = in.rdstate();
    bool a = i & std::_S_goodbit;
    a = i & std::iostream::badbit;
    a = i & std::iostream::failbit;
    a = i & std::iostream::eofbit;
    if(i == std::iostream::badbit){
        std::cout << "Fatal!";
    }
    if(i == std::iostream::failbit){
        std::cout << "No fatal!";
    }
    if(i == std::_S_goodbit){
        std::cout << "Все хорошо!";
    }
    if(i == std::iostream::eofbit){
        std::cout << "End!";
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL,"ru");
    
    Base* b = new Child();
    b->show();
    delete b;
    


    return 0;
}
