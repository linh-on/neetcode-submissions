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
        unordered_map<Node*, Node*> hashMap;
        hashMap[nullptr] = nullptr;
        
        for (Node * p = head; p != nullptr; p=p->next){
            Node * newNode = new Node(p->val);
            hashMap[p] = newNode;
        }

        for (Node * p = head; p != nullptr; p=p->next){
            hashMap[p]->next = hashMap[p->next];
            hashMap[p]->random = hashMap[p->random];
        }

        return hashMap[head];
        

        


        
    }
};
