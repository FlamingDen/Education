#include "Trie.hpp"

Trie::Trie() : root(new Vertex()) {}

void Trie::Insert(std::string word)
{
    auto currVertex = root;
    for(const auto c : word){
        if(!currVertex->to.contains(c)){
            Vertex* newVer = new Vertex();
            currVertex->to.insert({c, newVer});
        }
        currVertex = currVertex->to[c];
    }
    currVertex->terminal = true; 
}

bool Trie::Search(std::string word)
{
    auto currVertex = root;
    for(const auto c : word){
        if(!currVertex->to.contains(c)){
            return false;
        }
        currVertex = currVertex->to[c];
    }
    return currVertex->terminal;
}

bool Trie::StartsWith(std::string prefix)
{
    auto currVertex = root;
    for(const auto c : prefix){
        if(!currVertex->to.contains(c)){
            return false;
        }
        currVertex = currVertex->to[c];
    }
    return true;
}
