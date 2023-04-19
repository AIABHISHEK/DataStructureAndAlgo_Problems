#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
// check if x exists in an array 
int a[] = {3, 6,9,90};
bool result = binary_search(a, a+sizeof(a), 90);
cout<<result;
//lower_bound points to element if occurs else next greater element if that that also not exists points at end
//  - a of to get index
int x = lower_bound(a, a+4, 3) - a; // points at 3
int y = lower_bound(a, a+4, 8) - a; //points at 9
int z = lower_bound(a, a+4, 100) - a; //points at end of array
int *p = lower_bound(a, a+4, 3);
cout<<*p;
vector<int> b = {1,2,2,3};
// vector<int>::iterator q;
// auto q = lower_bound(b.begin(), b.end(), 2);
 int index = lower_bound(b.begin(), b.end(), 2) - b.begin();
cout<<index;
// upper_bound points to next greater element
// time complexity log(n)
return 0;
}