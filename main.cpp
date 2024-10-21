#include <compare>
#include <iostream>
#include <set>
 
struct Point
{
    int x;
    int y;
    auto operator<=>(const Point&) const = default;
    /* non-comparison functions */
};
 
int main()
{
    Point pt1{1, 1}, pt2{1, 2};
    std::set<Point> s; // OK
    s.insert(pt1);     // OK
 
    // two-way comparison operator functions are not required to be explicitly defined:
    // operator== is implicitly declared (see below)
    // the overload resolutions of other candidates will select rewritten candidates 
    std::cout << std::boolalpha
        << (pt1 == pt2) << ' ' << std::endl  // false
        << (pt1 != pt2) << ' ' << std::endl  // true
        << (pt1 <  pt2) << ' ' << std::endl  // true
        << (pt1 <= pt2) << ' ' << std::endl  // true
        << (pt1 >  pt2) << ' ' << std::endl  // false
        << (pt1 >= pt2) << ' ' << std::endl; // false
}


// struct Point
// {
//     Point(int x, int y){
//         this->x =x;
//         this->y = y;
//     }

//     int x;
//     int y;
// };
 
// int main(){
//     std::cout<< "hello" << std::endl;
//     Point pt1{1, 1}, pt2{1, 2};
//     std::set<Point> s; // OK
//     std::cout << __cplusplus << std::endl;
//     return 0;
// }
