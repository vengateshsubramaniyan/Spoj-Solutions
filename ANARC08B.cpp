#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	vector< int > val(128,0);
	val[10]=1,val[93]=2,val[79]=3,val[106]=4,val[103]=5,val[119]=6,val[11]=7;val[127]=8,val[107]=9;
	vector< string > digit(10);
	digit[0]="063",digit[1]="010",digit[2]="093",digit[3]="079",digit[4]="106",digit[5]="103",digit[6]="119",digit[7]="011",digit[8]="127",digit[9]="107"; 
	char arr[100000];
	scanf("%s",arr);
	ll len=strlen(arr);
	while(len!=3 || strcmp(arr,"BYE")!=0)
	{
		ll n1=0,n2=0,d=0;
		ll i=len-2;
		while(i>=0)
		{
			if(arr[i]=='+')
			{
				n2=n1;
				n1=0;
				d=0;
				i--;
			}
			else
			{
				int d1=(arr[i]-'0')+(10*(arr[i-1]-'0'))+(100*(arr[i-2]-'0'));
				n1+=(pow(10,d)*val[d1]);
				i-=3;
				d++;
			}
		}
		n1+=n2;
		string result="";
		do
		{
			result=digit[n1%10]+result;
			n1/=10;
		}while(n1);
		printf("%s",arr);
		cout<<result<<endl;
		scanf("%s",arr);
		len=strlen(arr);
	}
	return 0;
}
