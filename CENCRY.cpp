#include<bits/stdc++.h>
using namespace std;
int main()
{
	int cpos[256];
	cpos['a']=1,cpos['e']=2,cpos['i']=3,cpos['o']=4,cpos['u']=5;
	cpos['b']=1,cpos['c']=2,cpos['d']=3,cpos['f']=4,cpos['g']=5,cpos['h']=6,cpos['j']=7,cpos['k']=8,cpos['l']=9,cpos['m']=10,cpos['n']=11;
	cpos['p']=12,cpos['q']=13,cpos['r']=14,cpos['s']=15,cpos['t']=16,cpos['v']=17,cpos['w']=18,cpos['x']=19,cpos['y']=20,cpos['z']=21;
	char vchar[]={'0','a','e','i','o','u'};
	char cchar[]={'0','b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector < int > occr(26,0);
		char arr[50001];
		scanf("%s",arr);
		string result;
		for(int i=0;arr[i]!='\0';i++)
		{
			occr[arr[i]-'a']++;
			int c=occr[arr[i]-'a'];
			if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u')
			{
				c=cpos[arr[i]]+((c-1)*5);
				if(c>21)
					c=c%21;
				if(c==0)
					c=21;
				result.push_back(cchar[c]);
			}
			else
			{
				c=cpos[arr[i]]+((c-1)*21);
				if(c>5)
					c=c%5;
				if(c==0)
					c=5;
				result.push_back(vchar[c]);
			}
		}
		cout<<result<<endl;
	}
	return 0;	
}
