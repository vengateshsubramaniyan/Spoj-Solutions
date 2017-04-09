#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct trie
{
	struct trie* arr[26];
	ll count;
};
trie* create()
{
	struct trie *root=NULL;
	root=(trie *)malloc(sizeof(struct trie));
	for(int i=0;i<26;i++)
		root->arr[i]=NULL;
	root->count=0;
	return root;
}
void add(trie *root,string s)
{
	ll len=s.length();
	if(len==0)
		return ;
	ll index=0;
	for(index=0;index<len;index++)
	{
		if(root->arr[s[index]-'a']==NULL)
		{
			root->arr[s[index]-'a']=create();
		}
		root=root->arr[s[index]-'a'];
		root->count++;
	}
}
ll find(trie *root,string s)
{
	ll len=s.length();
	if(len==0)
		return 0;
	ll index;
	for(index=0;index<len;index++)
	{
		if(root->arr[s[index]-'a']==NULL)
			return 0;
		root=root->arr[s[index]-'a'];
	}
	return root->count;
}
int main()
{
	ll n,q;
	scanf("%lld%lld",&n,&q);
	trie *root=create();
	while(n--)
	{
		string s;
		cin>>s;
		ll len=s.length();
		if(len>=1)
		{
			add(root,s);
		}
	}
	while(q--)
	{
		string s;
		cin>>s;
		printf("%lld\n",find(root,s));
	}
	return 0;
}
