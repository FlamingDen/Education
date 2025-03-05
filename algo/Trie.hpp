#pragma once

#include <unordered_map>
#include <string>


/* 
    ------Sample-------
    Trie* trie = new Trie(); 
    trie->Insert("apple"); 
    std::cout << std::boolalpha;
    sh::print(trie->Search("apple")); // возвращает True 
    sh::print(trie->Search("app")); // возвращает False 
    sh::print(trie->StartsWith("app")); // возвращает True 
    trie->Insert("app"); 
    trie->Search("app");
*/
class Trie {
    struct Vertex
    {
        std::unordered_map<char ,Vertex*> to;
        bool terminal = {false};
    };
    
    Vertex* root;
public:
    Trie();
    
    void Insert(std::string word);
    
    bool Search(std::string word);
    
    bool StartsWith(std::string prefix);
};