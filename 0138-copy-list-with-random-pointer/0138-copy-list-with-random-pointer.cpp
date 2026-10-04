/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // USING HASH MAP APPROACH
        Node* temp=head;
        unordered_map<Node*,Node*> mp;
        while(temp!=NULL){
            Node* newnode=new Node(temp->val);
            mp[temp]=newnode;
            temp=temp->next;
        }
        Node*temp1=head;
        while(temp1!=NULL){
            Node* copynode=mp[temp1];
            copynode->next=mp[temp1->next];
            copynode->random=mp[temp1->random]  ;
            temp1=temp1->next;
        }
        return mp[head];

        
        
    }
};