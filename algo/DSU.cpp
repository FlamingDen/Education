#include <DSU.hpp>

#include "show.h"

DSU::DSU(int n)
{
    p.reserve(n);
    weight.reserve(n);

    for(size_t i(0); i != n; ++i){
        p.push_back(i);
        weight.push_back(1);
    }
}

int DSU::FindSet(int v){
    return p[v] == v ? v : p[v] = FindSet(p[v]);
}

void DSU::UnionSets(int a, int b)
{
    a = FindSet(a);
    b = FindSet(b);
    if (weight[a] > weight[b])
        std::swap(a, b);
    weight[b] += weight[a];
    p[a] = b;
}

std::unordered_map<int, std::vector<int>> DSU::GetDSU()
{
    std::unordered_map<int, std::vector<int>> res;
    for(size_t i(0); i != p.size(); ++i){
        res[FindSet(i)].push_back(i);
    }
    return res;
}

void DSU::PrintDSU(){
    auto m = GetDSU();
    for(auto it = std::begin(m); it != std::end(m); ++it){
        std::cout << it->first << " : ";
        sh::showContainer(it->second);
    }
}
