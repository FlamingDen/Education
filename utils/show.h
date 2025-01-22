#pragma once

#include <iostream>
#include <vector>

namespace sh {
    template<typename T>
    void showContainer(const T& c);

    template<typename K, typename V>
    void showMap(std::map<K, V>& c);

    template<typename T>
    void showVecVec(const std::vector<std::vector<T>>& v);

    template<typename T>
    void print(T smt);
}


template<typename T>
void sh::showContainer(const T& c){
    if(c.empty()){
        std::cout << "[ Empty ] \n";
        return; 
    }
    std::cout << "[";
    for(auto it = std::begin(c); it != std::end(c); ++it){
        if(std::next(it) == std::end(c)){
            std::cout << *it << ']' <<  std::endl;
            break;
        }
        std::cout << *it << ", ";
    }
}

template<typename K, typename V>
void sh::showMap(std::map<K, V>& c){
    if(c.empty()){
        std::cout << "[ Empty ] \n";
        return; 
    }
    std::cout << "Map = [";
    for(auto it = std::begin(c); it != std::end(c); ++it){
        if(std::next(it) == std::end(c)){
            std::cout << it->first << " - " << it->second << ']'<<  std::endl;
            break;
        }
        std::cout << it->first << " - " << it->second << ", \n";
        std::cout.width(7);
        std::cout << "";
    }
}

template <typename T>
void sh::showVecVec(const std::vector<std::vector<T>> &v)
{
    if(v.empty()){
        std::cout << "[[ Empty ]] \n";
        return; 
    }
    std::cout <<'[' << std::endl;
    for (int i = 0; i < std::ssize(v); i++)
    {
        std::cout.width(4);
        if(i == std::ssize(v) - 1){
            showContainer(v[i]);
            std::cout << ']' << std::endl;
            break;
        }
        showContainer(v[i]);
    }
}

template <typename T>
void sh::print(T smt)
{
    std::cout << smt << std::endl;
};

