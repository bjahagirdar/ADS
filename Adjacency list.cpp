#include<iostream>
#include<stack>
#include<queue>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE;


class G_list
{
    NODE *head[10];
    int nV,visited[10];
public:
    G_list();
    void read_Graph();
    void add_Node(int, int);
    void display_Graph();
    void init();
    void DFS(int);
    void BFS(int);
};

//------------------------------------
G_list :: G_list()
{
    nV=0;
    for(int i=0;i<10;i++)
    {
        head[i]=NULL;
        visited[i]=0;
    }
}

//--------------------------------------------
void G_list :: read_Graph()
{
    void check_list();

    int nE;
    cout<<"Enter number of vertices of the graph : ";
    cin>>nV;
    cout<<"Enter number of edges of the graph : ";
    cin>>nE;
    cout<<endl;

    int i,j,initial,terminal;

    for(i=1; i<=nE; i++)
    {
        cout<<"Enter initial vertex : ";
        cin>>initial;
        cout<<"Enter end vertex : ";
        cin>>terminal;

        cout<<endl;

        add_Node(initial, terminal);
        add_Node(terminal, initial);
    }
}

//-----------------------------------------------------------
void G_list :: add_Node(int m, int n)
{
    NODE *nn, *cn;
    nn = new NODE;
    nn->next = NULL;
    nn->data = n;


    if(head[m] == NULL)
        {head[m]=nn;}
    else
    {
        for(cn=head[m]; cn->next!=NULL; cn=cn->next);
        cn->next=nn;
    }

}

//---------------------------------------------------------------
void G_list :: init()
{
    for(int i=0;i<10;i++)
        visited[i]=0;
}

//--------------------------------------------------------------
void G_list :: display_Graph()
{
    int i;
    NODE *cn;
    for(i=1; i<=nV; i++)
    {
        cout<<" ("<<i<<") -> ";
        for(cn=head[i]; cn!=NULL; cn=cn->next)
        {
              cout<<cn->data<<" -> ";
        }
        cout<<endl;
    }
    cout<<endl;

}

//------------------------------------------------------------
void G_list :: DFS(int v)
{
    NODE *cn;
    cout<<v<<" -> ";
    visited[v-1]=1;
    int i;

    for(cn=head[v]; cn!=NULL; cn=cn->next)
    {
        i=cn->data;
        if((visited[i-1]==0) )
            DFS(i);
    }
}

//-----------------------------------------------------------------------
void G_list :: BFS(int v)
{
    queue<int> q;
    int visited[nV];
    int w,i;
    NODE *cn;

    for(i=0;i<nV;i++)
        visited[i]=0;

    q.push(v);
    while(!q.empty())
    {
        w=q.front();
        q.pop();

        if(visited[w-1] == 0)
        {
            visited[w-1]=1;
            cout<<w<<" -> ";

            for(cn=head[w]; cn!=NULL; cn=cn->next)
            {
                i=cn->data;
                if(visited[i-1]==0)
                    q.push(i);
            }
        }
    }
    cout<<endl;
}

//---------------------------------------------------------------
int main()
{
    G_list G1;
    int ch, iV;
    bool done=false;

    cout<<"Welcome to Graph operations : "<<endl;
    cout<<"1. Enter graph details."<<endl;
    cout<<"2. Display adjacency list."<<endl;
    cout<<"3. DFS traversal(Recursive)."<<endl;
    cout<<"4. BFS traversal."<<endl;

    cout<<"6. Exit."<<endl;



    do
    {
        cout<<"Enter your choice : ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1 : G1.read_Graph();
                     break;

            case 2 : G1.display_Graph();
                     break;

            case 3 :
                     cout<<"Enter initial vertex for traversal : ";
                     cin>>iV;
                     G1.init();
                     G1.DFS(iV);
                     cout<<endl<<endl;
                     break;

             case 4 :
                     cout<<"Enter initial vertex for traversal : ";
                     cin>>iV;
                     G1.BFS(iV);
                     cout<<endl<<endl;
                     break;

            case 6 : done=true;
                     break;

            default : cout<<"Please enter a valid option."<<endl;break;
        }

    }while(!done);










return 0;


}
