#include<bits/stdc++.h>
using namespace std;
struct trie
{
	struct trie *arr[26];
	char st[200];
	bool leaf;
};
trie* create()
{
	trie *root=new trie;
	for(int i=0;i<26;i++)
		root->arr[i]=NULL;
	root->leaf=false;
	return root;
}
void addtrie(trie *root,char s[])
{
	for(int i=0;s[i]!='\0';i++)
	{
		int in=s[i]-'a';
		if(root->arr[in]==NULL)
			root->arr[in]=create();
		root=root->arr[in];
	}
	strcpy(root->st,s);
	root->leaf=true;
}
void print(trie *root)
{
	if(root->leaf)
	{
		printf("%s\n",root->st);
	}
	for(int i=0;i<26;i++)
	{
		if(root->arr[i]!=NULL)
		{
			print(root->arr[i]);
		}
	}
}
bool find(trie *root,char s[])
{
	int i=0;
	for(;s[i]!='\0';i++)
	{
		int in=s[i]-'a';
		if(root->arr[in]==NULL)
			return false;
		root=root->arr[in];
	}
	bool pr=true;
	for(int i=0;i<26;i++)
	{
		if(root->arr[i]!=NULL)
		{
			print(root->arr[i]);
			pr=false;
		}
	}
	if(pr)
		return false;
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	char s[100];
	trie *root=create();
	while(n--)
	{
		scanf("%s",s);
		addtrie(root,s);
	}
	int k;
	scanf("%d",&k);
	map<string,bool> m;
	int j=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%s",s);
//		if(m.find(s)==m.end())
//		{
			printf("Case #%d:\n",i);
			m[s]=true;
			if(!find(root,s))
				printf("No match.\n");
//		}
	}
	return 0;
}
