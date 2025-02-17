#include "Sorting.hpp"


//=======================Samples================================================//
// std::vector<int> v{1,7,3,8,4,9};
// sh::showContainer(v);
// //HeapSort(v);
// //MergeSort(v);
// //QuickSort(v);
// //SelectionSort(v);
// //InsertionSort(v);
// //CombSort(v);
// //ShakerSort(v);
// //BubbleSort(v);
// sh::showContainer(v);

//==============================================================================//
void BubbleSort(vector<int> &values){
    for(size_t i(0); i + 1 < values.size(); ++i){
        for(size_t j(1); j < values.size() - i; ++j){
            if(values[j - 1] > values[j])
                swap(values[j - 1], values[j]);
        }
    }
}

void ShakerSort(vector<int> &values){
    if(values.empty())
        return;
    
    int l(0), r(values.size() - 1);
    while (l < r)
    {
        for(size_t i(l); i < r; ++i){
            if(values[i] > values[i + 1])
                swap(values[i], values[i + 1]);
        }
        --r;

        for(size_t i(r); i > 0; --i){
            if(values[i] < values[i - 1])
                swap(values[i], values[i - 1]);
        }
        ++l;
    }
}

void CombSort(vector<int> &values){
    const double factor = 1.247;
    int step = values.size() - 1;

    while (step >= 1){
        for(size_t i(0); i + step  < values.size(); ++i){
            if(values[i] > values[i + step])
                swap(values[i], values[i + step]);
        }
        step /= factor;
    }
}


//==============================================================================//
void InsertionSort(vector<int> &values){
    for(size_t i(1); i < values.size(); ++i){
        int j(i);
        int val(values[i]);
        while (j > 0 and val < values[j - 1]){   
            values[j] = values[j - 1];
            --j;
        }
        values[j] = val;
    }

}

void SelectionSort(vector<int> &values){
    for(auto it = std::begin(values); it != std::end(values); ++it){
        auto j = std::min_element(it, std::end(values));
        swap(*it, *j);
    }
}


//==============================================================================//
int Partition(vector<int> &values, int l, int r){
    int x = values[r];
    int less = l;

    for(size_t i(l); i < r; ++i){
        if(values[i] <= x)
            swap(values[i], values[less++]);
    }

    swap(values[less], values[r]);
    return less;
}
void QuickSortImpl(vector<int> &values, int l, int r){
    if(l < r){
        int m = Partition(values, l, r);
        QuickSortImpl(values, l, m - 1);
        QuickSortImpl(values, m + 1, r);
    }
}
void QuickSort(vector<int> &values){
    QuickSortImpl(values, 0, values.size() - 1);
}

void MergeSortImpl(vector<int> &values, vector<int> &buffer, int l, int r){
    if(l < r ){
        int m = (l + r) / 2;
        MergeSortImpl(values, buffer, l , m);
        MergeSortImpl(values, buffer, m + 1, r);

        int k = l;
        for(size_t i(l), j(m + 1); i <= m || j <= r ;){
            if(j > r or (i <= m and values[i] < values[j]))
                buffer[k++] = values[i++];
            else 
                buffer[k++] = values[j++];
        }
        copy(std::begin(buffer) + l, std::begin(buffer) + r + 1, std::begin(values) + l);
    }
}
void MergeSort(vector<int> &values){
    if(!values.empty()){
        vector<int> buffer(values.size());
        MergeSortImpl(values, buffer, 0 , values.size() - 1);
    }
}

void HeapSort(vector<int> &values){
    std::make_heap(values.begin(), values.end());
    for(auto i = values.end(); i != values.begin(); --i)
        std::pop_heap(values.begin(), i);
}
