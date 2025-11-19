// shortest unique prefix
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map <char, Node*> children;
    bool endOfWord; // T or F
    int freq;  // Frequency
    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1;
    }

    void insert(string key) { //O(L)
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if (temp->children.count(key[i]) == 0 ) {
                temp->children[key[i]] =  new Node();  // insert
                temp->children[key[i]]->freq = 1;
            } else {
                temp->children[key[i]]->freq++;
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    string getPrefix(string key) { // O(L)
        Node* temp = root;
        string prefix = "";

        for(int i=0; i<key.size(); i++) {
            prefix += key[i];
            if(temp->children[key[i]]->freq == 1) {
                break;
            }
            temp = temp->children[key[i]];
        }

        return prefix;
    }
};

void prefixProblem(vector<string> words) { //O(n*L)
    Trie trie;
    for(int i=0; i<words.size(); i++) {
        trie.insert(words[i]);
    }

    for(int i=0; i<words.size(); i++) {
        cout << trie.getPrefix(words[i]) << endl;
    }
}

int main() {
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    // vector<string> ans = {"z", "dog", "du", "dov"};

    prefixProblem(words);

    return 0;
}