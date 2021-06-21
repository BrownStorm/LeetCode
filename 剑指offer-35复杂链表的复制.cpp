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
        if (!head) return nullptr;
        map<Node*, Node*> m;
        Node *newHead = new Node(head->val), *preNewNode = newHead;
        Node *prenode = head, *node = head->next;
        m.insert({head, newHead});
        Node* newNode;
        while (node) {
            Node* newNode = new Node(node->val);
            preNewNode->next = newNode;
            m.insert({node, newNode});
            node = node->next;
            preNewNode = newNode;
        }

        node = head;
        newNode = newHead;
        while (node) {
            newNode->random = m[node->random];
            node = node->next;
            newNode = newNode->next;
        }
        return newHead;

    }
};