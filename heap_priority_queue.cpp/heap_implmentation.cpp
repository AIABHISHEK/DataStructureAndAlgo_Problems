#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

class MaxHeap{
public:
    vector<int> heap;
    int size;
    MaxHeap()
    {
        heap.push_back(0); // we do not put any element at 0 index
        size = 0;
    }
    /**
     * Inserts an element into the heap.
     *
     * @param x the element to be inserted
     *
     * @throws None
     */
    void insert(int x){
        // insert at position size + 1;
        heap.push_back(x);
        heapify(size + 1);
        size++;
    }
    /**
     * Heapify the element at index i in the heap.
     *
     * @param i the index of the element to heapify
     *
     * @throws None
     */
    void heapify(int i){
        while(i > 1){
            if(heap[i] > heap[i/2]){
                swap(heap[i], heap[i/2]);
                i = i/2;
            }
            else{
                break;
            }
        }
    }
    /**
     * Remove the first element from the heap and return it.
     *
     * @return the first element from the heap
     */
    int pop_front(){
        // remove the first element from the heap and return it
        int ans = heap[1];
        // to remove the element we put it at last index and remove it
        int i = 1;
        while(i < size){
            if(heap[2*i] > heap[2*i+1]){
                swap(heap[i], heap[2*i]);
                i = 2*i;
            }
            else{
                swap(heap[i], heap[2 * i + 1]);
                i = 2 * i + 1;
            }
        }
        size--;
        heap.pop_back();
        return ans;
    }
    /**
     * Get the top element of the heap.
     *
     * @return The top element of the heap.
     */
    int top(){
        //get top element of heap
        return heap[1];
    }
    /**
     * Checks if the container is empty.
     *
     * @return true if the container is empty, false otherwise.
     */
    bool empty(){
        return size==0;
    }
    /**
     * Retrieves the length of the object.
     *
     * @return the size of the object
     */
    int len(){
        return size;
    }
};

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
MaxHeap h;
h.insert(6);
h.insert(5);
h.insert(4);
h.insert(30);
h.pop_front();
cout << h.empty() << endl;
cout << h.len() << endl;
cout<<h.top()<<endl;

return 0;
}