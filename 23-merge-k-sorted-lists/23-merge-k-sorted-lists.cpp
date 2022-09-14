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
        int n = lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto a:lists){
            if(a!=NULL)
                pq.push({a->val,a});
        }
        
        ListNode *ans=new ListNode(0);
        ListNode *support=ans;
        pair<int,ListNode*>temp;
        while(pq.size()){
            temp=pq.top();
            pq.pop();
            support->next=new ListNode(temp.first);
            support=support->next;
            if(temp.second->next)
                pq.push({temp.second->next->val,temp.second->next});
            
        }
        
        return ans->next;
    }
};