#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;

typedef struct node
{
    char data;
    node *lf,*rt;
}NODE;
//-----------------------------------------

class ExpTree
{
    char exp[50];
    NODE *root;
public:
    ExpTree(){root=NULL;}
	void getExp();
    void buildTree();
    int priority(char);
    void BFS_display();
    void nonRecPreorder();
    void nonRecInorder();
    void nonRecPostorder();
};

//--------------------------------------
void ExpTree::getExp()
{
	cout<<"Enter expression to build tree : ";
	cin>>exp;
}
//--------------------------------------
int ExpTree::priority(char a)
{
    if(a=='+' || a=='-')
        return 1;
    else if(a=='*' || a=='/')
        return 2;
}

//-----------------------------------
void ExpTree::buildTree()
{
    stack<NODE*> s1,s2;
    int i;
    NODE* nn, *cn, *opr, *op1, *op2;

    for(i=strlen(exp)-1 ; i>=0; i--)
    {
        if(exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' )
        {
            nn = new NODE;
            nn->data = exp[i];
            nn->lf = nn-> rt = NULL;
            s1.push(nn);
        }
        else
        {
            if(s2.empty())
            {
                nn = new NODE;
                nn->data = exp[i];
                nn->lf = nn-> rt = NULL;
                s2.push(nn);
            }
            else
            {
                cn=s2.top();
                while(priority(cn->data) > priority(exp[i]))
                {
                    opr = s2.top();
                    s2.pop();
                    op1 = s1.top();
                    s1.pop();
                    op2 = s1.top();
                    s1.pop();
                     opr->lf = op1;
                    opr->rt = op2;
                    s1.push(opr);
                    if(s2.empty())
                        break;
                    cn=s2.top();
                }

                nn = new NODE;
                nn->data = exp[i];
                nn->lf = nn-> rt = NULL;
                s2.push(nn);

            }
        }

        /*if(!s1.empty())
        {cn=s1.top();
        cout<<"S1-top : "<<cn->data<<" ";
        }

        if(!s2.empty())
        {
        cn=s2.top();
        cout<<"S2-top : "<<cn->data;
        }
        cout<<endl<<endl;*/

    }

    while(!s2.empty())
    {
        opr = s2.top();
        s2.pop();
        op1 = s1.top();
        s1.pop();
        op2 = s1.top();
        s1.pop();
        opr->lf = op1;
        opr->rt = op2;
        s1.push(opr);
    }

    root=s1.top();
    s1.pop();

    cout<<"Build Done!"<<endl;
}

//---------------------------------------------------------------
void ExpTree::BFS_display()
{
    queue<NODE*> q;
    NODE *cn;

    q.push(root);
    while(!q.empty())
    {
        cn=q.front();
        cout<<cn->data<<" ";
        q.pop();

        if(cn->lf != NULL)
            q.push(cn->lf);
        if(cn->rt != NULL)
            q.push(cn->rt);
    }
    cout<<endl;
}

//-------------------------------------------------------------
void ExpTree::nonRecPreorder()
{
    NODE *cn=root;
    stack<NODE*>s;
    if(root == NULL)
        return;
    else
        s.push(cn);

    while(!s.empty())
    {
        cn=s.top();
        cout<<cn->data<<" ";
        s.pop();
        if(cn->rt != NULL)
            s.push(cn->rt);
        if(cn->lf != NULL)
            s.push(cn->lf);
    }
    cout<<endl;
}

//---------------------------------------------------------------
void ExpTree::nonRecInorder()
{
    NODE *cn=root;
    stack<NODE*>s;

    while(1)
    {
        while(cn != NULL)
        {
            s.push(cn);
            cn=cn->lf;
        }
        
        
        {
            if(!s.empty())
            {
                cn=s.top();
                s.pop();
                cout<<cn->data<<" ";
                cn=cn->rt;
            }
            else
                break;

        }
    }

    cout<<endl;
}

//-----------------------------------------------------
void ExpTree::nonRecPostorder()
{
    NODE *cn=root;
    stack<NODE*>s1,s2;

    if(cn != NULL)
        s1.push(cn);

    while(!s1.empty())
    {
        cn=s1.top();
        s1.pop();
        s2.push(cn);
        if(cn->lf != NULL)
            s1.push(cn->lf);
        if(cn->rt != NULL)
            s1.push(cn->rt);
    }

    while(!s2.empty())
    {
        cn=s2.top();
        s2.pop();
        cout<<cn->data<<" ";
    }

    cout<<endl;
}

//---------------------------------------------------------------
int main()
{
    ExpTree t;
    int ch;
    bool done=false;
	cout<<"Welcome to Expression Tree : "<<endl;
    cout<<"1. Enter expression."<<endl;
    cout<<"2. Build expression tree."<<endl;
    cout<<"3. Display using Breadth First Traversal."<<endl;
    cout<<"4. Pre-order traversal."<<endl;
    cout<<"5. In-order traversal."<<endl;
    cout<<"6. Post-order traversal."<<endl;
    cout<<"7. Exit."<<endl;

    do
    {
        cout<<"\nEnter choice : ";
        cin>>ch;
        cin.ignore(256, '\n');

        switch(ch)
        {
            case 1 : t.getExp();
                     break;

            case 2 : t.buildTree();
                     break;

            case 3 : t.BFS_display();
                     break;

            case 4 : t.nonRecPreorder();
                     break;

            case 5 : t.nonRecInorder();
                     break;

            case 6 : t.nonRecPostorder();
                     break;

            case 7 : done=true;
                     break;

			default : cout<<"Please enter a valid choice."<<endl;
                      break;
        }

    }while(done==false);

return 0;
}
