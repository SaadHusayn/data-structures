#include<iostream>
#include<vector>
#include<priority_queue>
using namespace std;

class Heap{
    public:
    vector<int> heap;
    bool isMax;

    void Heapify_Up(int index){
        while(index > 0){
            int Parrent = (index-1)/2;
            if((isMax && heap[index] > heap[Parrent]) || (!isMax && heap[Parrent] > heap[index])){
                swap(heap[Parrent], heap[index]);
                index = Parrent;
            }else break;
        }
    }

    void Heapify_Down(int index){
        int l = index*2 +1;
        int r = index*2 + 2;
        int toSwap = index;

        if(isMax){
            if(l < heap.size() && heap[l] > heap[toSwap]){
                toSwap = l;
            }
            if(r < heap.size() && heap[r] > heap[toSwap]){
                toSwap = r;
            }
        }
        else{
            if(l < heap.size() && heap[l] < heap[toSwap]){
                toSwap = l;
            }
            if(r < heap.size() && heap[r] < heap[toSwap]){
                toSwap = r;
            }
        }

        if(toSwap != index){
            swap(heap[toSwap], heap[index]);
            Heapify_Down(toSwap);
        }
    }

    Heap(vector<int> Heaps, bool argue){
        isMax = argue;
        for(int i=0; i<Heaps.size(); i++){
            heap.push_back(Heaps[i]);
        }

        for(int i= heap.size()/2 - 1 ; i>=0; i--){
            Heapify_Down(i);
        }
    }

    void print(){
        for(int i=0; i< heap.size(); i++){
            cout << heap[i] << " "  ;
        }
    }

    void insert(int key){
        heap.push_back(key);
        Heapify_Up(heap.size()-1);
    }

    void deleteHeap(int key){
        for(int i=0; i< heap.size(); i++){
            if(key == heap[i]){
                heap[i] = heap[heap.size() - 1];
                heap.pop_back();
                Heapify_Down(i);
                break;
            }
        }
    }

};


void heapSort(vector<int> &p){
    Heap h(p, 1);
    int i=p.size()-1;
    while(h.heap.size()>0){
        p[i] = h.heap[0];
        h.deleteHeap(h.heap[0]);
        i--;
    }
}


int main(){
    vector<int> h= {0, 5, 20, 6, 12, 65, 1, 4, 93};
    // Heap h1(h, 1);
    // h1.print();
    // cout << endl;
    // h1.insert(13);
    // h1.print();
    // cout << endl;
    // h1.deleteHeap(93);
    // h1.print();

    for(auto i: h) cout<<i<<" ";
    cout<<endl;

    heapSort(h);

    for(auto i: h) cout<<i<<" ";
    cout<<endl;

}