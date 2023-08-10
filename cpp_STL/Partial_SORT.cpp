#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
//partial sort

// used for sorting the elements present within a container. One of the variants of this is

// std::partial_sort

// , which is used for sorting not the entire range, but only a sub-part of it. It rearranges the elements in the range [first, last), in such a way that the elements before middle are sorted in ascending order, whereas the elements after middle are left without any specific order. It can be used in two ways as shown below:
// vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//give array in unsorted
vector<int> v = {2, 1, 9, 5, 4, 3, 8, 7, 6, };
// partial_sort(v.begin(), v.begin() + 5, v.end());
for(auto i : v){
cout<<i<<" ";
}
cout << endl;
nth_element(v.begin(), v.begin() + 4, v.end());
for(auto i : v){
cout<<i<<" ";
}

return 0;
}