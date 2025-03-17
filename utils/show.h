#pragma once

#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <forward_list>
#include <map>
#include <unordered_map>
#include <concepts>

static int padding{ 1 };

namespace sh {
    template<typename T>
    concept STLContainer = requires(const T container) {
        typename T::value_type;
        container.begin();
        container.end();
    };

    template<typename T>
    bool IsSTLContainer(const T& container) {
        return STLContainer<T>;
    }

    template<STLContainer Container>
    void ShowContainer(const Container& c, int width = 0, int nest = 0);

    template<typename K, typename V>
    void ShowContainer(const std::map<K, V>& mp, int width = 0, int nest = 0);

    template<typename K, typename V>
    void ShowContainer(const std::unordered_map<K, V>& mp, int width = 0, int nest = 0);

    template<typename T>
    void ShowContainer(std::queue<T>& q, int width = 0, int nest = 0);
    
    template<typename T>
    void ShowContainer(std::stack<T>& st, int width = 0, int nest = 0);

    template<typename T>
    void ShowContainer(const T& value, int width = 0, int nest = 0);

    template<typename T, typename K>
    void ShowContainer(const std::pair<T, K>& value, int width = 0, int nest = 0);

    template<typename T>
    void Print(T smt);
}


template<sh::STLContainer Container>
void sh::ShowContainer(const Container& c, int width, int nest) {
    if (c.empty()) {
        std::cout << std::setw(width) << "";
        std::cout << "# [ Empty ] \n";
        return;
    }
    bool isNested = IsSTLContainer(*c.begin());
    std::cout << std::setw(width) << "";
    std::cout << "# ";
    if (isNested)
        std::cout << std::endl;
    for (auto it = std::begin(c); it != std::end(c); ++it) {
        if (std::next(it) == std::end(c)) {
            ShowContainer(*it, width + padding, nest + 1);
            if (nest == 0 or isNested == false)
                std::cout << std::endl;
            break;
        }
        ShowContainer(*it, width + padding, nest + 1);
        if (!isNested)
            std::cout << " ";
    }
}

template<typename K, typename V>
void sh::ShowContainer(const std::map<K, V>& mp, int width, int nest) {
    if (mp.empty()) {
        std::cout << "# [ Empty ] \n";
        return;
    }
    //std::cout << std::setw(width) << "";
    //std::cout << "|_________________" << std::endl;
    for (auto it = std::begin(mp); it != std::end(mp); ++it) {
        std::cout << std::setw(width) << "";
        std::cout << "";
        if (std::next(it) == std::end(mp)) {
            std::cout << "| " << it->first << " - " << it->second << std::endl;
            break;
        }
        std::cout << "| " << it->first << " - " << it->second << "\n";
    }
}

template<typename K, typename V>
void sh::ShowContainer(const std::unordered_map<K, V>& mp, int width, int nest) {
    if (mp.empty()) {
        std::cout << "# [ Empty ] \n";
        return;
    }
    for (auto it = std::begin(mp); it != std::end(mp); ++it) {
        std::cout << std::setw(width) << "";
        std::cout << "";
        if (std::next(it) == std::end(mp)) {
            std::cout << "| " << it->first << " - " << it->second << std::endl;
            break;
        }
        std::cout << "| " << it->first << " - " << it->second << "\n";
    }
}

template<typename T>
void sh::ShowContainer(std::queue<T>& q, int width, int nest) {
    if (q.empty()) {
        std::cout << "[ Empty ] \n";
        return;
    }
    std::cout << std::setw(width) << "";
    int sz(q.size());
    std::cout << "Queue : \n";
    while (sz--) {
        T curr = q.front();
        q.pop();
        sh::ShowContainer(curr);
        std::cout << " ";
        q.push(curr);
    }
    std::cout << std::endl;
}

template<typename T>
void sh::ShowContainer(const std::stack<T>& st, int width, int nest) {
    if (st.empty()) {
        std::cout << "[ Empty ] \n";
        return;
    }
    std::stack<T> tmp_st(st.size());
    std::cout << std::setw(width) << "";
    std::cout << "Stack : \n";
    while (!st.empty()) {
        T curr = st.top();
        st.pop();
        sh::ShowContainer(curr);
        tmp_st.push(curr);
    }
    while (!tmp_st.empty()){
        st.push(tmp_st.top());
        tmp_st.pop();   
    }
}

template<typename T>
void sh::ShowContainer(const T& value, int width, int nest) {
    std::cout << value;
}

template<typename T, typename K>
void sh::ShowContainer(const std::pair<T, K>& value, int width, int nest) {
    ShowContainer(value.first);
    std::cout <<  " - ";
    ShowContainer(value.second);
}

template <typename T>
void sh::Print(T smt) {
    std::cout << smt << std::endl;
};

