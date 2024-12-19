#include "timer.h"

Timer::Timer(std::string m, std::ostream& out):
    st(std::chrono::high_resolution_clock::now()),
    message(m),
    out(out)
{}

Timer::~Timer(){
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::endl;
    std::cout << message << "(end) = { "  << std::chrono::duration<double>(end -st) << " }\n";
}

void Timer::SetIntermediatePoint(const std::string& m) const
{  
    std::chrono::duration<double> res = std::chrono::high_resolution_clock::now() - st;
    std::cout << std::endl;
    std::cout << message <<'(' << m << ')' << " = { "  << res << " }\n";
}

void Timer::End(){
    this->~Timer();
    st = std::chrono::high_resolution_clock::now();
}


