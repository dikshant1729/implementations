#include<bits/stdc++.h>
using namespace std;

struct Node {
	Node * links[2];
	int val;
};
 
Node * new_node() {
	Node * temp = new Node();
	temp -> val = 0;
	temp -> links[0] = NULL;
	temp -> links[1] = NULL;
	return temp;
}
 
struct Trie {
	 Node * root = new_node();
	
		void insert(int num) {
			Node * node = root;
			for(int i = 30; i >= 0; i --) {
				int bit = (num >> i) & 1;
				node -> val ++;
				if(node -> links[bit] == NULL) {
					node -> links[bit] = new_node();
				}
				node = node -> links[bit];
			}
			node -> val ++;
		}
		
		void remove(int num) {
			Node * node = root;
			for(int i = 30; i >= 0; i --) {
				node -> val --;
				int bit = (num >> i) & 1;
				node = node -> links[bit];
			}
			node -> val --;
		}
		
		int maxxor(int num) {
			int res = 0;
			Node * node = root;
			for(int i = 30; i >= 0; i --) {
				int bit = (num >> i) & 1;
				if(node -> links[!bit] && node -> links[!bit] -> val) {
					res |= (1 << i);
					node = node -> links[!bit];
				}
				else if(node -> links[bit] && node -> links[bit] -> val) node = node -> links[bit];
			}
			return res;
		}

        int minxor(int num) {
            int res = 0;
            Node * node = root;
            for(int i = 31; i >= 0; i --) {
                int bit = (num >> i) & 1;
                if(node -> links[bit] && node -> links[bit] -> val) {
                    node = node -> links[bit];
                }
                else if(node -> links[!bit] && node -> links[!bit] -> val) {
                    res |= (1 << i);
                    node = node -> links[!bit];
                }
            }
            return res;
        }

};
 
int main(){
    Trie trie;

    trie.insert(5);
    trie.insert(10);
    trie.insert(15);
    trie.insert(20);
    
    int x = 25; 
    
    int maxXor = trie.maxxor(x);
    
    cout << "Maximum XOR of " << x << " with a number from the trie: " << maxXor << endl;

    return 0;
}