#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class G_matrix {
		int G[10][10], nV, visited[10];
	public:
		G_matrix();
		void init();
		void read_Graph();
		void display_Graph();
		void DFS(int);
		void IDFS(int);
		void BFS(int);
};

//------------------------------------
G_matrix :: G_matrix() {
	nV=0;
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			G[i][j]=0;
		}
	}

}

//-------------------------------------
void G_matrix :: read_Graph() {
	int nE;
	cout<<"Enter number of vertices of the graph : ";
	cin>>nV;
	cout<<"Enter number of edges of the graph : ";
	cin>>nE;
	cout<<endl;

	int i,j,initial,terminal;

	for(i=1; i<=nE; i++) {
		cout<<"Enter initial vertex : ";
		cin>>initial;
		cout<<"Enter end vertex : ";
		cin>>terminal;

		cout<<endl;

		G[initial][terminal] = 1;
		G[terminal][initial] = 1;
	}
}

//-----------------------------------------------------------
void G_matrix :: display_Graph() {
	int i,j;
	cout<<"The adjacency graph is : "<<endl;
	for(i=1; i<=nV; i++) {
		for(j=1; j<=nV; j++) {
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

}
//------------------------------------------------------------
void G_matrix :: init() {
	for(int i=0; i<10; i++)
		visited[i]=0;
}


//------------------------------------------------------------
void G_matrix :: DFS(int v) {
	int i;
	cout<<v<<" -> ";
	visited[v-1]=1;

	for(i=1; i<=nV; i++) {
		if( (G[v][i]==1) && (visited[i-1]==0) )
			DFS(i);
	}
}

//----------------------------------------------------------------
void G_matrix :: IDFS(int v) {
	stack<int> s;
	int i,w;

	for(i=0; i<nV; i++)
		visited[i]=0;

	s.push(v);
	while(!s.empty()) {
		w=s.top();
		if(visited[w-1]==0)
			cout<<w<<" -> ";
		s.pop();
		visited[w-1]=1;

		for(i=nV; i>=1; i--) {
			if( (G[w][i]==1) && (visited[i-1]==0) )
				s.push(i);
		}
	}
	cout<<endl;
}

//-----------------------------------------------------------------------
void G_matrix :: BFS(int v) {
	queue<int> q;
	int w,i;

	for(i=0; i<nV; i++)
		visited[i]=0;

	q.push(v);
	while(!q.empty()) {
		w=q.front();
		q.pop();

		if(visited[w-1] == 0) {
			visited[w-1]=1;
			cout<<w<<" -> ";

			for(i=1; i<=nV; i++) {
				if(G[w][i]==1 && visited[i-1]==0)
					q.push(i);
			}
		}
	}
	cout<<endl;
}

//---------------------------------------------------------------
int main() {
	G_matrix G1;
	int ch, iV;
	bool done=false;

	cout<<"Welcome to Graph operations : "<<endl;
	cout<<"1. Enter graph details."<<endl;
	cout<<"2. Display graph matrix."<<endl;
	cout<<"3. DFS traversal(Recursive)."<<endl;
	cout<<"4. DFS traversal(Non - Recursive)."<<endl;
	cout<<"5. BFS traversal."<<endl;

	cout<<"6. Exit."<<endl;



	do {
		cout<<"Enter your choice : ";
		cin>>ch;
		cout<<endl;
		switch(ch) {
			case 1 :
				G1.read_Graph();
				break;

			case 2 :
				G1.display_Graph();
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
				G1.IDFS(iV);
				cout<<endl<<endl;
				break;

			case 5 :
				cout<<"Enter initial vertex for traversal : ";
				cin>>iV;
				G1.BFS(iV);
				cout<<endl<<endl;
				break;





			case 6 :
				done=true;
				break;

			default :
				cout<<"Please enter a valid option."<<endl;
				break;
		}

	} while(!done);










	return 0;








}
