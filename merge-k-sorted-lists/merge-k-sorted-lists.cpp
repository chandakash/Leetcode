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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *temp = new ListNode(0);
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto head : lists)
        {
            while(head)
            {
                pq.push(head->val);
                head = head->next;
            }
        }
        
        ListNode *res = temp;
        while(!pq.empty())
        {
            temp->next = new ListNode(pq.top());
            pq.pop();            
            temp = temp->next;
        }
    return res->next;
    }
};