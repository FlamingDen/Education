#include <iostream>
#include <vector>
#include <unordered_map>

/*
------Sample------
DSU dsu(6);
dsu.UnionSets(0, 1);
dsu.UnionSets(2, 1);
dsu.UnionSets(4, 5);
dsu.UnionSets(1, 4);
dsu.PrintDSU();
*/

class DSU
{
private:
    std::vector<int> p;
    std::vector<int> weight;
public:
    DSU(int n);

    int FindSet(int v);

    void UnionSets(int a, int b);

    std::unordered_map<int , std::vector<int>> GetDSU();

    void PrintDSU();
};



