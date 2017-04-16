#include<bits/stdc++.h>
#define ld long double
#define pi 3.14159265358979323846264338327950
using namespace std;
bool pos(ld vol[],int n,int f,ld m)
{
    for(int i=0;i<n;i++)
    {
        int q=floor(vol[i]/m);
        f-=q;
        if(f<=0)
            return true;
    }
    return false;
}
void binarysearch(ld vol[],int n,int f)
{
    ld l=0;
    ld r=vol[n-1];
    ld result=0;
    while((r-l)>=1e-6)
    {
        ld m=(l+r)/2;
        if(pos(vol,n,f,m))
        {
            if((result-m)<0)
                result=m;
            l=m;
        }
        else
            r=m;
    }
    printf("%.4Lf\n",result);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,f;
        scanf("%d%d",&n,&f);
        ld vol[n];
        f+=1;
        ld r=0;
        for(int i=0;i<n;i++)
        {
            cin>>vol[i];
            vol[i]=pi*vol[i]*vol[i];
            r+=vol[i];
        }
        sort(vol,vol+n);
        binarysearch(vol,n,f);
    }
    return 0;
}
