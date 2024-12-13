#pragma once

#include <iostream>
#include <chrono>
#include <string>

class Time
{
public:
    Time();
    Time(std::string m);
    ~Time();

    void End();
    std::chrono::duration<double> GetExcTime();
    void PrintExcTime(std::string m = "Execution time");
private:
    std::string message = "Execution time";
    std::chrono::time_point<std::chrono::high_resolution_clock> st;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
};