#pragma once

#include <iostream>

struct Point
{
    int x = 0;
    int y = 0;

    //auto operator<=>(const Point&) const = default;

    Point()
    {
        std::cout << "Point() " << std::endl;
    }
    Point(int x) : x(x)
    {
        std::cout << "Point() " << std::endl;
    }
    Point(int x, int y) : x(x), y(y)
    {
        std::cout << "Point() " << std::endl;
    }
    Point(const Point& other)
    {
        if (this == &other)
            return;
        this->x = other.x;
        this->y = other.y;
        std::cout << "copy Point() " << std::endl;
    }
    ~Point()
    {
        std::cout << "~Point() " << std::endl;
    }
    int operator[](const int& i) const;
    Point operator+(const Point& p);
    Point operator++();
    Point operator++(int);
    Point& operator=(const Point& other);


    void show();
    void increase(int& add);

    friend Point operator-(Point& a, Point& b);
    friend Point operator--(Point& obj);
    friend Point operator--(Point& obj, int);
    friend Point operator>>(Point& ob, int a);
    friend Point operator<<(Point& ob, int a);
    friend std::ostream& operator<<(std::ostream& stream, const Point& ob);
    friend std::istream& operator>>(std::istream& stream, Point& ob);

};
