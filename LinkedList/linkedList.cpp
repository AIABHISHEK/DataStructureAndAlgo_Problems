#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
template<class T>
struct ListNode
{
    T val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(T x) : val(x), next(nullptr) {}
};

template <class T>
class LinkedList
{
    ListNode<T> *firstNode;//first node pointer
    ListNode<T> *lastNode;

    int size;//size of the list
    //constructor
    //copy constructor
    //destructor

    public:
        // LinkedList() : size(0);
        LinkedList();
        LinkedList(const ListNode<T> *list);
        ~LinkedList(){};

};

template <class T>
LinkedList<T>::LinkedList(){
    cout<<"LinkedList"<<endl;
}
//copy constructor for a linked list class
template <class T>
LinkedList<T>::LinkedList(const ListNode<T> *list){

}
//copy elements 
template <class iterator>
void copy(iterator begin, iterator end, iterator to){
    while(begin != end){
        *to = *begin;
        begin++;
        to++;
    }
}

    main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    ListNode<int> *node = new ListNode<int>(9);
    cout << node->val << endl;
    LinkedList<int> *list = new LinkedList<int>();
    return 0;
}