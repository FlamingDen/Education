#include <compare>
#include <iostream>
#include <set>
#include <string>
 
class B;
class D;
struct Point
{
    int x;
    int y;
    auto operator<=>(const Point&) const = default;
    
    void printPoint(B obj);
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

    friend bool isEven(B obj);
    friend int comp(B obj, D obj_d);
    friend void Point::printPoint(B obj);
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

bool isEven(B obj){
    return !obj.b % 2;
}

int comp(B obj, D obj_d){
    return obj_d.d - obj.b;
}

void Point::printPoint(B obj){
    std:: cout << "Point : " << x << "\t" << y * obj.b << std::endl;
}

int main(int argc, char* argv[])
{
    std::cout << argv[0] << std::endl;

    std::cout << std::boolalpha <<  isEven(B(5)) << std::endl;
    std::cout << comp(B(67), D(34, 99)) << std::endl;
    Point(2,2).printPoint(B(2));

    return 0;
}
