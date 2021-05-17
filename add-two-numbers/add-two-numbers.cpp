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
    // ListNode* reverse(ListNode* head)
    // {
    //     ListNode *curr = head,*next=NULL,*prev=NULL;
    //     while(curr!=NULL)
    //     {
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = prev;
    //     }
    // return prev;
    // }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *res = new ListNode();
        ListNode *curr = res;
        
        int sum=0,carry=0;
        
        while(l1!=NULL || l2!=NULL)
        {
            sum = carry;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            carry = sum/10;
        }
        
        if(carry>=1)
        {
            curr->next = new ListNode(carry);
        }
        
    return res->next;
        // l1 = reverse(l1);
        // l2 = reverse(l2);
        
//         ListNode *temp = l1;
//         int carry =0;
//         while(l1!=NULL||l2!=NULL)
//         {
//             l1->val = l1->val + l2->val + carry;
//             carry = 0;
//             if(l1->val>9)
//             {
//                 l1->val = l1->val%10;
//                 carry = 1;
//             }
//             l1=l1->next;
//             l2=l2->next;
//         }
//     ListNode *temp2 = temp;
//     if(carry == 1)
//     {
//         while(temp->next!=NULL)
//             temp = temp->next;
        
//          ListNode *newData = new ListNode(1);
//         temp->next = newData;
//     }
//     // temp2 = reverse(temp2);
//     return temp2;
    }
};