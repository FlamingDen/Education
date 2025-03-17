#include "TimeGuard.hpp"


TimeGuard::TimeGuard(std::string str, std::ostream& out) : message(str), out(out) {}

TimeGuard::~TimeGuard() {
    std::cout << std::endl;
    std::cout << message << "(end) = { " << std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - st) << " }\n";
}