#include <iostream>
#include <set>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node(const int &d) : val(d),next(NULL) {}
};

// Time: O(n), Space: O(n)
bool hasCycleWithSet(Node * head) {
    if(head == nullptr) {
        return false;
    }
    std::set<Node *> tmp;
    Node *p = head;
    while(p != NULL) {
        if(tmp.find(p) != tmp.end()) {  //find it
            return true;
        }
        tmp.insert(p);
        p = p->next;
    }
    return false;
}
// Time: O(n), Space: O(1)
bool hasCycleWithTwoPointer(Node * head) {
    if(head == nullptr) {
        return false;
    }
    Node *fast = head;
    Node *low = head;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        low = low->next;
        if(fast == low) {
            return true;
        }
    }
    return false;
}

int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    bool res = hasCycleWithSet(node1);
    std::cout << res << std::endl;  //1表示有环
    bool res1 = hasCycleWithTwoPointer(node1);
    std::cout << res1 << std::endl;  //1表示有环
    delete(node1);
    delete(node2);
    delete(node3);
    return 0;
}