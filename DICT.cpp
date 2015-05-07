#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct tNode{
	char c;
	tNode* links[26];
	string word;
};

tNode* getNewNode(char c){
	tNode* t = new tNode();
	t->c = c;
	for(int i=0; i<26; i++){
		t->links[i] = NULL;
	}
	t->word = "";
	return t;
}

void addWord(tNode* dict, char word[]){
	int len = strlen(word);
	tNode* temp = dict;
	for(int i=0; i<len; i++){
		int ind = (int) (word[i] - 'a');
		if(temp->links[ind] == NULL){
			tNode* t = getNewNode(word[i]);
			temp->links[ind] = t;
		}
		temp = temp->links[ind];
	}
	temp->word = string(word);
}

bool hasPrefix(tNode* dict, char prefix[]){
	tNode* t = dict;
	int len = strlen(prefix);
	for(int i=0; i<len; i++){
		int ind = (int) (prefix[i] - 'a');
		if(t->links[ind] == NULL)
			return false;
		t = t->links[ind];
	}
	return true;
}

void printAllWords(tNode* dict){
	if(dict == NULL)
		return;

	if(dict->word != ""){
		printf("%s\n", dict->word.c_str());
	}
	for(int i=0; i<26; i++){
		printAllWords(dict->links[i]);
	}
}

void printWithPrefix(tNode* dict, char prefix[]){
	tNode* t = dict;
	int len = strlen(prefix);
	for(int i=0; i<len; i++){
		int ind = (int) (prefix[i] - 'a');
		if(t->links[ind] == NULL)
			return;
		t = t->links[ind];
	}
	for(int i=0; i<26; i++)
		printAllWords(t->links[i]);
}

int main() {
	tNode* dict = getNewNode('0');
	
	int N;
	scanf("%d", &N);
	char word[20];
	for(int i=0; i<N; i++){
		scanf("%s", word);
		addWord(dict, word);
	}
	
	int M;
	scanf("%d", &M);
	char prefix[20];
	for(int i=0; i<M; i++){
		scanf("%s", prefix);
		cout << "Case #" << i+1 << ":" << endl;
		if(hasPrefix(dict, prefix)){
			printWithPrefix(dict, prefix);
		}
		else{
			cout << "No match." << endl;
		}
	}
	return 0;
}