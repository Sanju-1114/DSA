//leetCode 146
#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;

class LRUCache{
public:

    class Node {
    public:
        int key , val;
        Node* prev;
        Node* next;

        Node(int k , int v){
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int, Node*> m;

    int limit;    

    void addNode(Node* newNode){  //O(1)
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode){  //O(1)
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity){
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){  // O(1)
        if(m.find(key) == m.end()){
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        m.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int value){  //O(1)
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }
        if(m.size() == limit){
            // delete LRU data
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key , value);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main(){

    // Your LRUCache object will be instantiated and called as such:
    LRUCache* lRUCache = new LRUCache(2);

    lRUCache->put(1, 1);                 // cache is {1=1}
    lRUCache->put(2, 2);                 // cache is {1=1, 2=2}
   
    cout << lRUCache->get(1) << endl;    // return 1
   
    lRUCache->put(3, 3);                 // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
   
    cout << lRUCache->get(2) << endl;    // returns -1 (not found)
   
    lRUCache->put(4, 4);                 // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
   
    cout << lRUCache->get(1) << endl;    // return -1 (not found)
    cout << lRUCache->get(3) << endl;    // return 3
    cout << lRUCache->get(4) << endl;    // return 4

    return 0;
}