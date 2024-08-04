#include<bits/stdc++.h>
using namespace std;

struct Node {
	Node * links[26];
	int val;
};
 
Node * new_node() {
	Node * temp = new Node();
	temp -> val = 0;
	for(int i=0; i<26; i++){
        temp -> links[i] = NULL;
    }
	return temp;
}
 
struct Trie {
	 Node * root = new_node();
	
		void insert(string s) {
			Node * node = root;
			for(int i = 0; i < s.size(); i++) {
				char bit = s[i]-'a';
				node -> val ++;
				if(node -> links[bit] == NULL) {
					node -> links[bit] = new_node();
				}
				node = node -> links[bit];
			}
			node -> val ++;
		}
		
		void remove(string s) {
			Node * node = root;
			for(int i = 0; i < s.size(); i++) {
				node -> val --;
				int bit = s[i]-'a';
				node = node -> links[bit];
			}
			node -> val --;
		}
		
		bool is_present(string s) {
			Node * node = root;
			for(int i = 0; i < s.size(); i++) {
				int bit = s[i]-'a';
				if(node -> links[bit] == NULL) {
					return false;
				}
				node = node -> links[bit];
			}
			return node -> val > 0;
		}

};
 
int main(){
    Trie trie;           

    return 0;
}