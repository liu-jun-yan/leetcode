// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
//
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p=l1,*q=l2,*answer=NULL,*buffer=NULL,*temp=NULL;
        bool flag=false;
        int data;
        while(p!=NULL||q!=NULL){
            if(p==NULL){
                data=q->val;
                q=q->next;
            }
            else if(q==NULL){
                data=p->val;
                p=p->next;
            }
            else{
                data=p->val+q->val;
                p=p->next;
                q=q->next;
            }
            if(flag) data+=1;
            if(data>9){
                data-=10;
                flag=true;
            }
            else flag=false;
            buffer=new ListNode(data);
            if(answer==NULL){
                answer=buffer;
                temp=answer;
            }
            else{
                temp->next=buffer;
                temp=temp->next;
            }
        }
        if(flag){
            buffer=new ListNode(1);
            temp->next=buffer;
        }
        return answer;
    }
};
