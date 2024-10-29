#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>


int abs(const int &a){ 
    return a >= 0 ? a : -a;
}

std::vector<int> sort_arr1(const std::vector<int>& arr){
    std::vector<int> ans;
    ans.reserve(arr.size());

    int pos_ind = arr.size();
    int neg_ind;
    for (size_t i(0); i < arr.size(); i++)
    {
        if(arr[i] >= 0){
            pos_ind = i;
            break; 
        }
    }
    neg_ind = pos_ind - 1;
    for (size_t i(0); i < arr.size(); i++)
    {
        if(pos_ind >= arr.size()){
            ans.push_back(arr[neg_ind] * arr[neg_ind]);
            neg_ind--;
            continue;
        }
        if(neg_ind < 0){
            ans.push_back(arr[pos_ind] * arr[pos_ind]);
            pos_ind++;
            continue;
        }
        if(arr[pos_ind] >= -arr[neg_ind]){
            ans.push_back(arr[neg_ind]* arr[neg_ind]);
            neg_ind--;
            continue;
        }
        ans.push_back(arr[pos_ind] * arr[pos_ind]);
        pos_ind++;
    }
    return ans;
}


std::vector<int> sort_arr(std::vector<int>& arr){
    std::vector<int> ans;
    ans.reserve(arr.size());
    for(auto x : arr){
        ans.push_back(x * x);
    }

    std::ranges::sort(ans);
    return ans;
}

void printArr(const std::vector<int>& arr){
    for(auto a : arr){
        std::cout << a << ", ";
    }
    std::cout << std::endl;
}


int main(){
    srand(static_cast<unsigned int>(time(0)));
    std::vector<int> arr;
    arr.reserve(10);
    for (size_t i = 0; i < 10; i++)
    {
        arr.push_back(rand() % (10 + 10 +1) - 10);
    }
    std::ranges::sort(arr);
    printArr(arr);

    auto begin = std::chrono::steady_clock::now();
    sort_arr(arr);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";

    begin = std::chrono::steady_clock::now();
    arr = sort_arr1(arr);
    end = std::chrono::steady_clock::now();
    printArr(arr);
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() <<  " ms\n";
     
    
    return 0;
}