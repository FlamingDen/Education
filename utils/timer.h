#pragma once

#include <iostream>
#include <chrono>
#include <string>

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> st;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    std::ostream& out;
    std::string message;
    
public:
    Timer(std::string m = "Execution time", std::ostream& out = std::cout);
    ~Timer();

    void SetIntermediatePoint(const std::string& m) const;

    void End();
};