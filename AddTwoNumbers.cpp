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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int count1=0,count2=0,flag=0,sum;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* newNode;
        ListNode* l3;
        ListNode* temp3;
        while(temp1!=NULL)
        {
            count1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            count2++;
            temp2=temp2->next;
        }
        temp1=l1;
        temp2=l2;
        while(temp1->next!=NULL)
        { 
            temp1=temp1->next;
        }
        while(temp2->next!=NULL)
        { 
            temp2=temp2->next;
        }
        if(count1>count2)
        {
            for(int i=1;i<=count1-count2;i++)
            {
                newNode=new ListNode();
                newNode->val=0;
                temp2->next=newNode;
                newNode->next=NULL;
                temp2=newNode;
            }
        }
        else
        {
            for(int i=1;i<=count2-count1;i++)
            {
                newNode=new ListNode();
                newNode->val=0;
                temp1->next=newNode;
                newNode->next=NULL;
                temp1=newNode;
            }
        }
        temp1=l1;
        temp2=l2;
        sum=flag+temp1->val+temp2->val;
        if(sum>=10)
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
        l3=new ListNode();
        l3->val=sum%10;
        temp1=temp1->next;
        temp2=temp2->next;
        temp3=l3;
        while(temp1 && temp2)
        {
            sum=flag+temp1->val+temp2->val;
            if(sum>=10)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
            newNode=new ListNode();
            newNode->val=sum%10;
            temp3->next=newNode;
            newNode->next=NULL;
            temp3=newNode;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(flag==1)
        {
            newNode=new ListNode();
            newNode->val=1;
            temp3->next=newNode;
            newNode->next=NULL;
            temp3=newNode;
        }
        return l3;
    }
};
