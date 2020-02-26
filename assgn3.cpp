#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node*lf,*rt;
	bool lthread,rthread;

};
class TBT
{
	node *root,*cn;
public:
	TBT()
{
		root=new node;
		root->lf=root->rt=NULL;
        root->lthread=root->rthread=0;
}
	void insertnode(node *parent,int LR);
	void createTBT();
	node* leftmost(node* cn);
	void inorder(node* root);
        void preorder(node*);
        node* presucessor(node*);
	node* GETROOT()
	{
		return root;
	}
};
node* TBT::leftmost(node*cn)
{
	while(cn->lthread==1)
		cn=cn->lf;
	return cn;
}

node* TBT::presucessor(node* cn)
{
        if(cn->lthread==1)
	{
	     cn=cn->lf;
	     return cn;
	}
	if(cn->rthread==1)
	{
	   return cn->rt;
	}
	else
	{
	while(cn->rthread==0 &&cn->rt!=root)
	       {
                   cn=cn->rt;
               }
	       return cn->rt;
	}

}




void TBT::preorder(node* cn)
{
       cout<<"\n I am Preorder Function";
       cn=root->lf;
       while(cn!=root)
      {
         cout<<" "<<cn->data;
         cn=presucessor(cn);
      }
}




void TBT::inorder(node*root)
{
	cout<<"\n I AM IN INORDER FUNCTION";
        cn=root->lf;

	while(cn!=root)
	{
               cn=leftmost(cn);
		cout<<" "<<cn->data;
		while(cn->rthread==0 && cn->rt!=root)
		{
			cn=cn->rt;

			cout<<" "<<cn->data;
		}
		cn=cn->rt;


	}
}



void TBT::insertnode(node*parent,int LR)
{
	node*nn;
	int d;

	cout<<"\n Enter Child !(If you dont want to enter data enter -100)";
	cin>>d;
	if(d==-100)
	{
		return ;
	}
	nn=new node;
	nn->data=d;

	if(LR==1)
	{
		nn->lf=parent->lf;
		nn->lthread=parent->lthread;
		nn->rt=parent;
		nn->rthread=0;
		parent->lf=nn;
		parent->lthread=1;
	}
	if(LR==0)
	{
		nn->lf=parent;
		nn->lthread=0;
		nn->rt=parent->rt;
		nn->rthread=parent->rthread;
		parent->rt=nn;
		parent->rthread=1;
	}
   cout<<"\n Enter left child of "<<nn->data;
   insertnode(nn,1);
   cout<<"\n Enter right child of "<<nn->data;
   insertnode(nn,0);
}


void TBT::createTBT()
	{

		insertnode(root,1);

	}

int main()
{
    TBT obj;
    obj.createTBT();
    obj.inorder(obj.GETROOT());
    obj.preorder(obj.GETROOT());
	return 0;
}
