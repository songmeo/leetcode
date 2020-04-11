/*
 * Effort to solve https://leetcode.com/problems/longest-common-prefix/
 * using a Trie. 
 * 
 * Task:
 * Given a set of keys S = [S1, S2,..., Sn]
 * find the longest common prefix among a string q and S. 
 * 
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
	bool completeWord;
	unordered_map<char, Node*> children;
	Node() : completeWord(false) {};
};

class Trie {
public:
	Trie();
	void insert(string s);
	string longestCommonPrefix(string s);
private:
	Node* root;
	void insert(string s, Node* n);
};

Trie::Trie() {
	root = new Node();
}

void Trie::insert(string s) {
	insert(s, root);
}

void Trie::insert(string s, Node* n) {
	Node* tmp = n;
	for(char c : s) {
		auto &m = tmp->children;
		if(!m.count(c)) {
			Node* newNode = new Node();
			m.insert(pair<char,Node*>(c, newNode));
		}
		tmp = m[c];
	}
	tmp->completeWord = true;
}

string Trie::longestCommonPrefix(string s) {
	string re;
	Node* p = root;
	for(char c : s) {
		auto m = p->children;
		if(!m.count(c) || m.size() > 1 || p->completeWord) {
			return re;
		} else {
			re += c;
			p = m[c];
		}
	}
	return re;
}

int main() {
	Trie* t = new Trie();
	vector<string> ss{"leet", "leetcode", "leetc"};
	for(string s : ss) {
		t->insert(s);
	}
	cout << t->longestCommonPrefix("cat");
	return 0;
}
