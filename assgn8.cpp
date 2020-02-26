#include<iostream>
#include<fstream>
using namespace std;

class student
{
        int rno;
        char address[50];
        char name[30];
        char div;
public:
        bool flag;
        void accept()
        {
                cout<<"\nEnter Roll no of student : ";
                cin>>rno;
                cout<<"Enter Name of student : ";
                cin.ignore();                                //inputbuffer clear
                cin.getline(name,30);
                cout<<"Enter Division of student : ";
                cin>>div;
                cout<<"Enter address of student : ";
                cin>>ws;                                      //inputbuffer clear
                cin.getline(address,50);
        }

        void display()
        {
                cout<<"\n\nRoll no of student : "<<rno;
                cout<<"\nName of student : "<<name;
                cout<<"\nDivision of student : "<<div;
                cout<<"\nEnter address of student : "<<address;
        }
        
        int getrollno() {return rno;}
};




void addnewrecord()
{
        ofstream out;
        student obj;
        obj.accept();
        out.open("file.txt",ios::binary|ios::app);
        obj.flag=1;
        out.write((char*)&obj,sizeof(obj));
        out.close();
}


void displayfile()
{
        ifstream in;
        student obj;
        in.open("file.txt");
        while(1)
        {
                in.read((char*)&obj,sizeof(obj));
                if(in.eof()!=0) 
                break;
                if(obj.flag==1)   
                obj.display();
        }
        in.close();
        cout<<"\n\nRecord Added successfully!!";

}

void delet()
{
        fstream f;
        student obj;
        int flag,x;
        f.open("file.txt",ios::binary|ios::in|ios::out);
        cout<<"Enter Roll No. you want to delete : ";
        cin>>x;
        while(1)
        {
                f.read((char*)&obj,sizeof(obj));
                if(x==obj.getrollno())
                {
                        flag=1;
                        f.seekp((-1*sizeof(obj)),ios::cur);
                        obj.flag=0;
                        f.write((char*)&obj,sizeof(obj));
                        cout<<"\n\nRecord Deleted successfully!!";
                        break;
                }
                if(f.eof()!=0) 
                break;
                
        }
        if(flag==0)
        cout<<"\nRecord not found..\n";
        f.close();
}

void update()
{
        fstream f;
        student obj;
        int flag,x;
        f.open("file.txt",ios::binary|ios::in|ios::out);
        cout<<"\nEnter Roll No. of record you want to update : ";
        cin>>x;
        while(1)
        {
                f.read((char*)&obj,sizeof(obj));
                if(x==obj.getrollno())
                {
                        cout<<"\nRecord found\n\nEnter updated details :\n";
                        flag=1;
                        f.seekp((-1*sizeof(obj)),ios::cur);
                        obj.accept();
                        f.write((char*)&obj,sizeof(obj));
                        cout<<"\n\nRecord Updated successfully!!";
                        break;
                }
                if(f.eof()!=0) 
                break;
                
        }
        if(flag==0)
        cout<<"\nRecord not found..\n";
        f.close();
}

void search()
{
        fstream f;
        student obj;
        int flag,x;
        f.open("file.txt",ios::binary|ios::in|ios::out);
        cout<<"Enter Roll No. of record you want to search : ";
        cin>>x;
        while(1)
        {
                f.read((char*)&obj,sizeof(obj));
                if(x==obj.getrollno())
                {
                        flag=1;
                        cout<<"\nRecord found...\n\nDetails are :\n";
                        obj.display();
                        break;
                }
                if(f.eof()!=0) 
                break;
                
        }
        if(flag==0)
        cout<<"\nRecord not found..\n";
        f.close();
}

int main()
{
        int ch;
   do
   {
        cout<<"\n\nMENU\n";
        cout<<"\n1 : Accept new record.";
        cout<<"\n2 : Display record.";
        cout<<"\n3 : Delete record.";
        cout<<"\n4 : Update record.";
        cout<<"\n5 : Search record.";
        cout<<"\n6 : EXIT.";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
                case 1 : addnewrecord();
                         break;
        
                case 2 : displayfile();
                         break;
                         
                case 3 : delet();
                         break;
                         
                case 4 : update();
                         break;
                         
                case 5 : search();
                         break;         
                
                case 6 : cout<<"\nExitted...!\n";
                         break;
                       
                default : cout<<"\nInvalid option";
        
        }  
   }while(ch!=6);    

   return 0;
}
