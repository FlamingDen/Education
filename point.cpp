#include "point.h"

int Point::operator[](const int &i) const
{
    return i == 1 ? this->x : i == 2? this->y : -1;
}

Point Point::operator+(const Point& p){
    return {x + p.x, y + p.y};
}

Point Point::operator++()
{   
    x++;
    y++;
    return *this;
}

Point Point::operator++(int)
{
    return {x++, y++};
}

Point& Point::operator=(const Point &other)
{
    x = other.x;
    y = other.y;
    std::cout << "operator=()" << std::endl;
    return *this;
}

void Point::show(){
    std::cout << "Point : " << x <<" \t " << y << std::endl; 
};

void Point::increase(int &add)
{
    x += add;
    y += add;
}

Point operator-(Point &a, Point &b){
    return {a.x - b.x, a.y - b.y};
}

Point operator--(Point &obj){
    obj.x--;
    obj.y--;
    return obj;
}

Point operator--(Point &obj, int){
    obj.x--;
    obj.y--;
    return {obj.x - 1, obj.y - 1};
}

Point operator>>(Point &ob, int a)
{
    ob.x = ob.x >> a;
    ob.y = ob.y >> a;
    return ob;
}

Point operator<<(Point &ob, int a)
{
    ob.x = ob.x << a;
    ob.y = ob.y << a;
    return ob;
}
