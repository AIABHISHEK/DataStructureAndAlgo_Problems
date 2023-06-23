#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//Implementation of ListNode interface
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} 
    ListNode(int x) : val(x), next(nullptr){}
};
//----------------------------------------------------------------


class Solution
{
public:
    // Insertion sort on singly linked list
    ListNode *insertionSortList(ListNode *head)
    {
        if (head->next == NULL)
            return head;
        ListNode *ans = new ListNode(0);
        ans->next = head;
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *start = head;

        while (curr != NULL)
        {
            if (curr->val < prev->val)
            {
                ListNode *temp = ans;
                while (true)
                {
                    if (temp->next->val > curr->val)
                        break;
                    temp = temp->next;
                }
                ListNode *n = curr->next;
                ListNode *m = temp->next;
                temp->next = curr;
                temp->next->next = m;
                prev->next = n;
                if (n != NULL)
                    curr = n;
                else
                    break;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return ans->next;
    }
};

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

return 0;
}