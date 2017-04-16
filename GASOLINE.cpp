#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		vector<vector< int > > graph(n,vector<int>(n,INT_MAX));
		while(m--)
		{
			int src,des,d;
			scanf("%d%d%d",&src,&des,&d);
			if(graph[src][des]>d)
				graph[src][des]=d;
			if(graph[des][src]>d)
				graph[des][src]=d;	
		}
		int dist[n][n], i, j, k;
	    for (i = 0; i < n; i++)
	        for (j = 0; j < n; j++)
	            dist[i][j] = graph[i][j];
	    for (k = 0; k < n; k++)
	    {
	        for (i = 0; i < n; i++)
	        {
	            for (j = 0; j < n; j++)
	            {
	                if ( dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
	             	       dist[i][j] = dist[i][k] + dist[k][j];
	            }
	        }
	    }
	    bool found=true;
	    int result=-1;
	    for(int i=0;i<n && found;i++)
	    {
	    	int ccal=-1;
	    	for(int j=0;j<n && found;j++)
	    	{ 
//	    		cout<<dist[i][j]<<" ";
	    		if(dist[i][j]==INT_MAX)
	    		{
	    			result=INT_MAX;
	    			found=false;
	    		}
	    		else if(i!=j && ccal<dist[i][j])
	    			ccal=dist[i][j];
	    	}
//	    	cout<<endl;
	    	if(result<ccal)
	    		result=ccal;
	    }
	    if(result==INT_MAX)
	    	result=-1;
	    printf("%d\n",result);
	}
	return 0;
}
