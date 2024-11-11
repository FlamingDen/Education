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
    std::cout << argv[0] << std::endl;

    // // 9.1
    // std::cout.fill('-');
    // std::cout.width(13);
    // std::cout.precision(10);
    // std::cout << 123.123<<std::endl; // =
    // std::cout << manip <<  123.123<<std::endl;
    
    // 9.2
    std::ofstream out;
    std::ifstream in;

    //out.open("file.txt");
    //in.open("file.txt");
    
    std::cout << std::fstream::app << std::endl;    // добавление в конец и только
    std::cout << std::fstream::ate << std::endl;    // сразу утсановлен курсон в конце, но можно писать в любом месте
    std::cout << std::fstream::binary << std::endl;  // открыват в довичном режиме
    std::cout << std::fstream::in << std::endl;     // открыт для ввода
    std::cout << std::fstream::out << std::endl;    // открыт для вывода
    std::cout << std::fstream::trunc << std::endl;  // удаляет все что было

    // 9.3
    check_status(std::cout);
    
    return 0;
}
