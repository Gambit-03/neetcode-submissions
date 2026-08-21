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
        unordered_map<Node*,Node*> copys;
        copys[NULL] = NULL;

        Node* cur = head;
        while(cur != NULL){
            Node* copy = new Node(cur->val);
            copys[cur] = copy;
            cur = cur->next;
        }

        cur = head;
        while(cur!= NULL){
            Node* copy = copys[cur];
            copy->next = copys[cur->next];
            copy->random = copys[cur->random];
            cur = cur->next;
        }
        return copys[head];
    }
};
