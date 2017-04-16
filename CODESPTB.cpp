#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int mergesort(int *,int);
int _mergesort(int *,int *,int,int);
int merge(int *,int *,int,int,int);
int mergesort(int arr[],int n)
{
    int temp[n];
    return _mergesort(arr,temp,0,n-1);
}
int _mergesort(int arr[],int temp[],int left,int right)
{
    int mid,count=0;
    if(right>left)
    { 
      mid=(left+right)/2;
      count=_mergesort(arr,temp,left,mid);
      count+=_mergesort(arr,temp,mid+1,right);
      count+=merge(arr,temp,left,mid+1,right);
    }
    return count;
}

int merge(int arr[],int temp[],int left,int mid,int right)
{
  int i, j, k;
  int count = 0;
  i = left; 
  j = mid;  
  k = left; 
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      count = count + (mid - i);
    }
  }
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return count;
}

int main()
{
    int n,tc,i;
    cin>>tc;
    while(tc)
    {
      cin>>n;
      int arr[n];
      for(i=0;i<n;i++)
          cin>>arr[i];  
      cout<<mergesort(arr,n)<<endl;
      tc--;
    }
    return 0;   
}

