#include<bits/stdc++.h>
using namespace std;
int inceil(int tail[],int l,int r,int k)
{
	while(r-l>1)
	{
		int m=l+(r-l)/2;
		if(tail[m]>=k)
			r=m;
		else
			l=m;
	}
	return r;
}
void increasing(int arr[],int lis[],int n)
{
	int tail[n];
	memset(tail,0,sizeof(tail));
	tail[0]=arr[0];
	lis[0]=1;
	int len=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]<tail[0])
			tail[0]=arr[i];
		else if(arr[i]>tail[len-1])
			tail[len++]=arr[i];
		else
			tail[inceil(tail,-1,len-1,arr[i])]=arr[i];
		lis[i]=len;
	}
}
int main()
{
	char s[1000001];
	scanf("%s",s);
	int len=strlen(s);
	int oc=0,ec=0,zc=0,sc=0;
	int oi,ei,zi,si;
	int ou=-1,eu=-1,zu=-1,su=-1;
	for(int i=0;i<len;i++)
	{
		switch(s[i])
		{
			case '1':
				{
					oc++;
					if(oc==1)
						oi=i;
					ou=i;
					break;
				}
			case '8':
				{
					ec++;
					if(ec==1)
						ei=i;
					eu=i;
					break;
				}
			case '0':
				{
					zc++;
					if(zc==1)
						zi=i;
					zu=i;
					break;
				}
			case '7':
				{
					sc++;
					if(sc==1)
						si=i;
					su=i;
				}
		}
	}
	if(oc!=0 && ec!=0 && zc!=0 && sc!=0 && oi<eu && ei<zu && zi<su)
	{
//		cout<<oc<<" "<<ec<<" "<<zc<<" "<<sc<<endl;
		int t=ec;
		ec=oc+1;
		int t1=zc;
		zc=ec+t;
		sc=zc+t1;
		oc=1;
//		cout<<oc<<" "<<ec<<" "<<zc<<" "<<sc<<endl;
		int arr[len];
		for(int i=0;i<len;i++)
		{
			if(s[i]=='1')
				arr[i]=oc++;
			if(s[i]=='8')
				arr[i]=ec++;
			if(s[i]=='0')
				arr[i]=zc++;
			if(s[i]=='7')
				arr[i]=sc++;
//			cout<<arr[i]<<" ";
		}
		int larray[len];
		increasing(arr,larray,len);
		int result=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='7' && result<larray[i])
				result=larray[i];
		}
		printf("%d",result);
	}
	else
		printf("0");
	return 0;
}
