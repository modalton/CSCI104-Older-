
#ifndef HSORT_H
#define HSORT_H
#include <vector>

template<typename T, class Comparator>
void heapify(int idx, std::vector<T>& start, Comparator comp)
{
    if(  (2*idx) >= start.size() && (2*idx+1) >= start.size()) return;
    int smallerChild = 2*idx; // start w/ left
    if( (smallerChild+1) < start.size()) {
        int rChild = smallerChild+1;
        if(comp(start.at(rChild-1), start.at(smallerChild-1))){
            smallerChild = rChild;
        } }
    if( comp(start.at(smallerChild-1), start.at(idx-1))){
        T temp = start.at(idx-1);
        start.at(idx-1) = start.at(smallerChild-1);
        start.at(smallerChild-1) = temp;
        heapify(smallerChild, start, comp);
    }
}

template<typename T, class Comparator>
void heapsort(std::vector<T>& input, Comparator comp){
    std::vector<T> proxy = input;
    for (int i= (proxy.size()/2) ; i!=0; i--) {
        heapify(i, proxy, comp);
    }

    for(int i = 0; i< input.size(); i++){
        input.at(i)= proxy.at(0);
        proxy.at(0) = proxy.back();
        heapify(1, proxy, comp);
        proxy.pop_back();

    }

}



#endif
