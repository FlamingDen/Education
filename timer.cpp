#include "timer.h"

Time::Time(){
    st = std::chrono::high_resolution_clock::now();
    end = st;
}

Time::Time(std::string m): message(m) {
    st = std::chrono::high_resolution_clock::now();
}

Time::~Time(){
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::endl;
    std::cout << message << "(all) = { "  << std::chrono::duration<double>(end -st) << " }\n";
}

void Time::End(){
    end = std::chrono::high_resolution_clock::now(); 
}

std::chrono::duration<double> Time::GetExcTime()
{
    return std::chrono::duration<double>(end-st);
}

void Time::PrintExcTime(std::string m)
{
    if(st  != end){
        std::cout << std::endl;
        std::cout << m << " = { "  << std::chrono::duration<double>(end -st) << " }\n";
    }
}
