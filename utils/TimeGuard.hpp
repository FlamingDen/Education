#pragma onces

#include <iostream>
#include <string>
#include <chrono>

class TimeGuard {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> st{ std::chrono::high_resolution_clock::now() };
    std::ostream& out;
    std::string message;

public:
    TimeGuard(std::string str, std::ostream& out = std::cout);

    ~TimeGuard();

    template<typename Func, typename... Args>
    static void TimingFunc(Func func, Args... args);
};

template<typename Func, typename... Args>
inline void TimeGuard::TimingFunc(Func func, Args... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(args...);
    std::cout << std::endl;
    std::cout << __FUNCTION__ << "(processing time) = { " << std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start) << " }\n";
}


