#include<bits/stdc++.h>
using namespace std;
struct trie
{
	struct trie* arr[10];
	bool end;
};
trie* create()
{
	trie *root=(trie *)malloc(sizeof(trie));
	for(int i=0;i<10;i++)
		root->arr[i]=NULL;
	root->end=false;
	return root;
}
bool add(trie *root,string s)
{
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(root->arr[s[i]-'0']!=NULL)
		{
			root=root->arr[s[i]-'0'];
		}
		else
		{
			root->arr[s[i]-'0']=create();
			root=root->arr[s[i]-'0'];
		}
		if(root->end==true)
			return false;
	}
	root->end=true;
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		struct trie *root=create();
		int n;
		scanf("%d",&n);
		bool result=true;
		vector<string> phone(n);
		for(int i=0;i<n;i++)
			cin>>phone[i];
		sort(phone.begin(),phone.end());
		for(int i=0;i<n;i++)
		{
			if(!add(root,phone[i]))
			{
				result=false;
				break;
			}
		}
		delete root;
		result?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
