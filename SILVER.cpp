#include<iostream>
using namespace std;
int main(){
int i,j,k,l,a,t,n,s;
while(1){
cin>>n;
if(n==0) break;
s=1;a=0;
while(s<=n){
 s*=2;a++;
 }
cout<<a-1<<'\n';
}
 
return 0;}
