// count unique substrings
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map <char, Node*> children;
    bool endOfWord; // T or F
    Node() {
        endOfWord = false;
    }
};


class Trie {
    Node* root;
    int count;
public:
    Trie() {
        root = new Node();
        count = 0;
    }

    void insertSuffixes(string str) {
        for (int i = 0; i < str.size(); i++) {
            insert(str.substr(i));
        }
    }

    void insert(string key) { //O(L)
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if (temp->children.count(key[i]) == 0 ) {
                temp->children[key[i]] =  new Node();  // insert
                count++;
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key) {    //O(L)
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if (temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }
        return temp->endOfWord;
    }

    int getUniqueSubstringCount() {
        return count+1;
    }

};



int main() {
    string str = "ababa";

    Trie trie;
    trie.insertSuffixes(str);
    cout << "Total unique substrings: " << trie.getUniqueSubstringCount() << endl;
    return 0;

}