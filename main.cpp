#include <compare>
#include <iostream>
#include <set>
#include <string>
 
struct Point
{
    int x;
    int y;
    auto operator<=>(const Point&) const = default;
    /* non-comparison functions */
};

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
};

template<typename T>
void print(T curr){
    std::cout << "print()" << std::endl;
}

D input(){
    D temp(4,4);
    return D(6,6);
}

B inputB(){
    B temp(4);
    return B(1);
}

int main(int argc, char* argv[])
{
    std::cout << argv[0] << std::endl;

    // D x = input();
    // x.show();

    B y;
    y = inputB();
    y.show();

    return 0;
}
