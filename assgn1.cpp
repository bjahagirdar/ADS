#include<iostream>
#include<cstring>
using namespace std;

typedef struct node
{
    string key,meaning;
    node *lf,*rt;
}NODE;
//-----------------------------------------

class BST
{
    NODE *root;
public:
    BST(){root=NULL;}
    NODE* addNode();
    void preOrder(NODE*);
    void inOrder(NODE*);
    void postOrder(NODE*);
    void dsearch(string);
    void dupdate(string);
};

//-----------------------------------
NODE* BST::addNode()
{
    NODE *nn,*cn,*parent;
    int flag=0;
    nn=new NODE;
    nn->lf=NULL;
    nn->rt=NULL;

    //cin>>ws;
    cout<<"Enter keyword : ";
    //cin>>nn->key;
    getline(cin, nn->key);
    cout<<"Enter its meaning: ";
    getline(cin, nn->meaning);
    //cin>>nn->meaning;

    if(root == NULL)
        root=nn;
    else
    {
        cn=root;
        while(cn != NULL)
        {
            parent=cn;
            if(nn->key <= cn->key)
            {
                flag=0;
                cn=cn->lf;
            }
            else
            {
                flag=1;
                cn=cn->rt;
            }
        }

        if(flag == 0)
            parent->lf=nn;
        else
            parent->rt=nn;
    }

    return root;

}

//----------------------------------------------
void BST::preOrder(NODE *cn)
{
    if(cn != NULL)
    {
        cout<<cn->key<<" ";
        preOrder(cn->lf);
        preOrder(cn->rt);
    }

}

//------------------------------------------------
void BST::inOrder(NODE *cn)
{
    if(cn != NULL)
    {
        inOrder(cn->lf);
        cout<<cn->key<<" ";
        inOrder(cn->rt);
    }
}

//----------------------------------------------------
void BST::postOrder(NODE *cn)
{
    if(cn != NULL)
    {
        postOrder(cn->lf);
        postOrder(cn->rt);
        cout<<cn->key<<" ";
    }
}

//-----------------------------------------------------
void BST::dsearch(string s_key)
{
    NODE *cn=root;
    int flag=0;

    do
    {

        if(s_key < cn->key)
            cn=cn->lf;
        else if(s_key > cn->key)
            cn=cn->rt;
        else
            {
                flag=1;
                break;
            }

    }while(cn != NULL);

    if(flag == 0)
        cout<<"Word not found!"<<endl;
    else
        cout<<"Word found!"<<endl;
        cout<<cn->key<<" : "<<cn->meaning<<endl;

}

//-------------------------------------------------------
void BST::dupdate(string s_key)
{
    NODE *cn=root;
    int flag=0;
    string u_meaning;

    do
    {

        if(s_key < cn->key)
            cn=cn->lf;
        else if(s_key > cn->key)
            cn=cn->rt;
        else
            {
                flag=1;
                break;
            }

    }while(cn != NULL);

    if(flag == 0)
        cout<<"Node not found!"<<endl;
    else
    {
        cout<<"Word found!"<<endl;
        cout<<"Enter new meaning : ";
        //cin>>u_meaning;
        getline(cin, u_meaning);
        cn->meaning = u_meaning;
        cout<<"Data updated!"<<endl;

    }

}

//-------------------------------------------------------
int main()
{
    BST t1;
    NODE *r;
    int ch;
    string key;
    bool done=false;

    cout<<"Welcome to Dictionary!"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"1. Add word."<<endl;
    cout<<"2. Pre-order traversal."<<endl;
    cout<<"3. In-order traversal."<<endl;
    cout<<"4. Post-order traversal."<<endl;
    cout<<"5. Search for a word."<<endl;
    cout<<"6. Update meaning of a word."<<endl;
    cout<<"7. Exit."<<endl;

    do
    {
        cout<<"\nEnter choice : ";
        cin>>ch;
        cin.ignore(256, '\n');

        switch(ch)
        {
            case 1 : r=t1.addNode();
                     break;

            case 2 : t1.preOrder(r);
                     cout<<endl;
                     break;

            case 3 : t1.inOrder(r);
                     cout<<endl;
                     break;

            case 4 : t1.postOrder(r);
                     cout<<endl;
                     break;

            case 5 : cout<<"Enter word to be searched : ";
                     //cin>>key;
                     getline(cin, key);
                     t1.dsearch(key);
                     break;

            case 6 : cout<<"Enter word to be updated : ";
                     //cin>>key;
                     getline(cin, key);
                     t1.dupdate(key);
                     break;


            case 7 : done=true;
                     break;
        }

    }while(done==false);


return 0;
}
