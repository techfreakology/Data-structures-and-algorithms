#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int value;
	Node *left,*right;
	char character;
};

struct cmp
{
	bool operator () (const Node* a,const Node* b)
	{
		return a->value > b->value;
	}
};


Node* getNewNode(char character,int freq,Node* left,Node* right)
{
	Node* node = new Node();
	node->value = freq;
	node->character = character;
	node->left = left;
	node->right = right;
	return node;
}

void traverse(Node *root,string s,int height)
{
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->character<<"\t\t\t"<<root->value<<"\t\t\t"<<height<<"\t\t\t"<<s<<"\n";
		return;
	}
	traverse(root->left,s+"0",height+1);
	traverse(root->right,s+"1",height+1);
}

int main()
{
	char character[] = {'a','b','c','d','e','f'};	//characters
	int frequency[] = {45,13,12,16,9,5};				//and their respective frequencies
	int n = 6;										//size of array

	priority_queue<Node*,vector<Node*>,cmp> pq;

	for(int i=0;i<n;i++)
	{
		Node *node = getNewNode(character[i],frequency[i],NULL,NULL);
		pq.push(node);
	}

	while(pq.size()>1)
	{
		Node *right,*left;
		left = pq.top();pq.pop();
		right = pq.top();pq.pop();
		Node *node = getNewNode('!',left->value + right->value,left,right);	// '!' for non leaf nodes 
		pq.push(node);
	}

	Node* root = pq.top();
	pq.pop();

	string code="";
	int height = 0;
	cout<<"Character\tfrequency\tHeight\t\tCode\n";
	traverse(root,code,height);

	return 0;
}