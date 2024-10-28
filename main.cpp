#include <compare>
#include <iostream>
#include <set>
#include <string>
 
class B;
class D;
struct Point
{
    int x = 0;
    int y = 0;

    auto operator<=>(const Point&) const = default;
    
    Point(){
        std::cout << "Point() "  << std::endl;
    }
    Point(int x) : x(x){
        std::cout << "Point() "  << std::endl;
    }
    Point(int x, int y) : x(x), y(y){
        std::cout << "Point() "  << std::endl;
    }
    ~Point(){ 
         std::cout << "~Point() "  << std::endl;
    }

    void show(){
        std::cout << "Point : " << x <<" \t " << y << std::endl; 
    };
    void printPoint(B obj);
    void increase(int &add){
        x += add;
        y += add;
    }
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

void f(Point &p){
    p.show();
}

int x_gl;
int& foo(){
    return x_gl;
}


int main(int argc, char* argv[])
{
    // std::cout << argv[0] << std::endl;
    // // 4.4 - 4.5
    // Point *p = new Point [3];
    // for(int i(0); i < 3; i++){
    //     *(p+i) = {i+2,i+2};
    // } 
    // for(int i(0); i < 3; i++){
    //     (p+i)->show();
    // }
    // delete[] p;

    // // 4.6
    // Point x(1,1);
    // int add(44);
    // x.increase(add);
    // x.show();

    // 4.7
    Point y(7,7);
    f(y);

    // 4.8
    foo() = 20;
    std::cout << x_gl << std::endl;

    


    return 0;
}
