#include<iostream>
using namespace std;
#define inf 999
 
class graph
{
    int g[10][10];
    int visited[10];
    int from[10];
    int distance[10];
    int nV,nE;

public:

    graph()
    {
        for(int i=0;i<10;i++)
        {
            visited[i]=0;
            from[i]=0;
            distance[i]=inf;
            
            for(int j=0;j<10;j++)            
            {
                g[i][j]=inf;
            
            }       
        }
    }

    void read()
    {
        int m,n,cost;
        cout<<"\nEnter no. of vertices : ";
        cin>>nV;
        
        cout<<"\nEnter no. of edges : ";
        cin>>nE;
        
        cout<<endl;    
        
		cout<<"\n (Start vertex from 0) \n\n";
		  
        for(int i=0;i<nE;i++)
        {
            cout<<"Enter first vertex , second vertex and cost : ";
			cin>>m>>n>>cost;
			g[m][n]=cost;
			g[n][m]=cost;
        
        }
    
    }

  

    void prims()
    {
    int minCost=0,min,vertex;
    
	cout<<"\n\n Minimum Spanning tree is: ";
	
	for(int i=0;i<nV;i++)
	{
		distance[i]=g[0][i];
		from[i]=0;
		visited[i]=0;
	}
	visited[0]=1;
	
	for(int i=0;i<nV-1;i++)
	{
		min=inf;
		for(int j=1;j<nV;j++)
		{
			if(min>distance[j])
			{
				min=distance[j];
				vertex=j;

			}
		}
		visited[vertex]=1;
		cout<<"\n Edge: "<<from[vertex]<<"-"<<vertex<<"\n ";
		minCost=minCost+distance[vertex];
		distance[vertex]=inf;
		for(int j=1;j<=nV;j++)
		{
			if(!visited[j]&& g[vertex][j]<distance[j])
			{
				distance[j]=g[vertex][j];
				from[j]=vertex;
			}
		}
	}
	cout<<"\n\n Cost of Minimum Spanning tree : "<<minCost<<endl;
    }

};


int main()
{
graph g;
g.read();
g.prims();



return 0;
}
