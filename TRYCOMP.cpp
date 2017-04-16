#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct trie
{
	trie *arr[26];
	char ra[15];
	ll rc;
	bool isleaf;
	ll count;
};
trie* create()
{
	trie *root=(trie*)malloc(sizeof(trie));
	for(int i=0;i<26;i++)
	{
		root->arr[i]=NULL;
	}
	root->count=0;
	root->rc=0;
	root->isleaf=false;
	return root;
}
ll add(trie *root,char a[],int i)
{
	if(a[i]=='\0')
	{
		root->count++;
		root->isleaf=true;
		if(root->rc==0)
		{
			strcpy(root->ra,a);
			root->rc=1;
		}
		else if(root->rc<=root->count)
		{
			if(root->rc==root->count)
			{
				if(strcmp(a,root->ra)<0)
					strcpy(root->ra,a);
			}
			else
			{
				root->rc=root->count;
				strcpy(root->ra,a);
			}
		}
		return root->count;
	}
	if(root->arr[a[i]-'a']==NULL)
		root->arr[a[i]-'a']=create();
	ll rr=add(root->arr[a[i]-'a'],a,i+1);
	if(root->rc==0)
	{
		strcpy(root->ra,a);
		root->rc=1;
	}
	else if(root->rc<=rr)
	{
		if(root->rc==rr)
		{
			if(strcmp(a,root->ra)<0)
				strcpy(root->ra,a);
		}
		else
		{
			root->rc=rr;
			strcpy(root->ra,a);
		}
	}
	return rr;
}
void find(trie *root,char r1[],char result[],ll &cc)
{
	int i=0;
	while(r1[i]!='\0')
	{
		if(root->arr[r1[i]-'a']==NULL)
			return;
		root=root->arr[r1[i]-'a'];
		i++;
	}
	strcpy(result,root->ra);
	cc=root->rc;
}

int main()
{
	ll n,q;
	scanf("%lld",&n);
	trie *root=create();
	while(n--)
	{
		char a[15];
		scanf("%s",a);
		add(root,a,0);
	}
	scanf("%lld",&q);
	while(q--)
	{
		ll cc=-1;
		char a[15];
		char result[15];
		scanf("%s",a);
		find(root,a,result,cc);
		if(cc==-1)
			printf("-1\n");
		else
			printf("%s %lld\n",result,cc);
	}
	return 0;
}
