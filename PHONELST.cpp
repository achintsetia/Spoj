#include <iostream>
#include <stdio.h>
using namespace std;

class tNode{
	private:
		int v;
		tNode* links[10];

	public:
		tNode(int _v);
		int getV();
		bool hasLink(int i);
		bool isTerminal();
		tNode* getLink(int i);
		void setLink(tNode* node);
};

tNode::tNode(int _v){
	v = _v;
	for(int i=0; i<10; i++)
		links[i] = NULL;
}

int tNode::getV(){
	return v;
}
		
bool tNode::hasLink(int i){
	if(links[i] != NULL && links[i]->v >= 0)
		return true;
	return false;
}

bool tNode::isTerminal(){
	for(int i=0; i<10; i++)
		if(links[i] != NULL && links[i]->v != -1)
			return false;
	return true;
}

tNode* tNode::getLink(int i){
	if(links[i] != NULL && links[i]->v >= 0)
		return links[i];
	return NULL;
}
		
void tNode::setLink(tNode* node){
	if(node->getV() != -1){
		links[node->getV()] = node;
	}
}

class trie{
	private:
		tNode* T;
	public:
		trie();
		bool checkPrefix(string num);
		void addString(string num);
};

trie::trie(){
	T = new tNode(-1);
}

bool trie::checkPrefix(string num){
	int len = num.size();
	int i=0;
	tNode* temp = T;
	while(i<len && temp->hasLink((int)(num[i] - '0'))){
		temp = temp->getLink((int)(num[i] - '0'));
		if(temp->isTerminal())
			return true;
		i++;
	}
	
	if(i==len)
		return true;
		
	return false;
}

void trie::addString(string num){
	int len = num.size();
	tNode* temp = T;
	for(int i=0; i<len; i++){
		int c = (int) (num[i] - '0');
		if(temp->hasLink(c)){
			temp = temp->getLink(c);
			continue;
		}
		tNode* newNode = new tNode(c);
		temp->setLink(newNode);
		temp = newNode;
	}
}

int main() {
	int T;
	cin >> T;
	while(T--){
		trie t;
		int N;
		cin >> N;
		bool ans = true;
		for(int i=0; i<N; i++){
			string num;
			cin >> num;
			if(t.checkPrefix(num)){
				ans = false;
			}
			if(ans){
				t.addString(num);
			}
		}
		
		if(ans){
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}