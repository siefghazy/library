#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "book.h"
class linkedlist
{
    struct Node
    {
        book data;
        Node*next;
        Node*prev;
    };
    Node*head;
    Node*tail;
    int length;
public:
    linkedlist()
    {
        head=NULL;
        tail=NULL;
    }
    void setHead(Node*ptr)
    {
        head=ptr;
    }
    void setTail(Node*ptr)
    {
        tail=ptr;
    }
    void add(string t,string a,string c,int n)
    {
        Node*ptr=new Node;
        ptr->data.setAuthor(a);
        ptr->data.setCategory(c);
        ptr->data.setTitle(t);
        ptr->data.setPagenum(n);
        if(head==NULL)
        {
            head=tail=ptr;
            ptr->next=NULL;
            ptr->prev=NULL;
        }
        else
        {
            ptr->prev=tail;
            tail->next=ptr;
            tail=ptr;
            ptr->next=NULL;
        }
    }
    void display()
    {
        Node*ptr=head;
        while (ptr!=NULL)
        {
            cout<<ptr->data.getTitle()<<endl;
            cout<<ptr->data.getAuthor()<<endl;
            cout<<ptr->data.getNumofpages()<<endl;
            cout<<ptr->data.getCatorgety()<<endl;
            cout<<"----------------"<<endl;
            ptr=ptr->next;
        }

    }
    void displayAutor(string n)
    {
            Node*ptr=head;
            int i=0;
            while(ptr!=NULL){
                if(ptr->data.getAuthor()==n){
                    cout<<ptr->data.getTitle()<<endl;
                }
                else{
                    i++;
                    if(i==length){
                        cout<<n<<" is not available now"<<endl;
                    }
                }
                ptr=ptr->next;
            }

    }
    void displayCategory(string n)
    {
        Node*ptr=head;
        int i=1;
        try
        {
            while (ptr!=NULL)
            {
                if(ptr->data.getCatorgety()==n)
                {
                    cout<<ptr->data.getTitle()<<endl;
                }
                else
                {
                    i++;
                    if(i==length)
                    {
                        throw n;
                    }
                }
                ptr=ptr->next;
            }
        }
        catch(string n)
        {
            cout<<n<<" "<<"is not available"<<endl;
        }
    }
    void removeTitle(string n)
    {
        int i=1;
        try
        {
            if(head->data.getTitle()==n)
            {
                cout<<head->data.getTitle()<<endl;
                Node*ptr=head->next;
                delete head;
                head=ptr;
                head->prev=NULL;
                length--;
            }
            else if(tail->data.getTitle()==n)
            {
                cout<<tail->data.getTitle()<<endl;
                Node*ptr;
                ptr=tail->prev;
                delete tail;
                tail=ptr;
                tail->next=NULL;
                length--;
            }
            else
            {
                Node*curr=head;
                while(curr!=NULL)
                {
                    if(curr->data.getTitle()==n)
                    {
                        cout<<curr->data.getTitle()<<" is deleted"<<endl;
                        break;
                    }
                    else
                    {
                        i++;
                        if(i==length)
                        {
                            throw n;
                        }
                    }
                    curr=curr->next;
                }
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
                delete curr;
                length--;
            }
        }
        catch(string n)
        {
            cout<<n<<" "<<"is not available"<<endl;
        }
    }
    void removeAuthor(string n)
    {
        try
        {
            int i =0;
            Node*temp=head;
            while(temp!=NULL)
            {
                if(temp->data.getAuthor()!=n)
                {
                    i++;
                    if(i==length)
                    {
                        throw n;
                    }
                }
                temp=temp->next;
            }
        }
        catch(string n)
        {
            cout<<"No books for "<<n<<" now"<<endl;
        }
        Node*curr=head;
        Node*ptr;
        int counter=0;
        while(curr!=NULL)
        {
            if(curr->data.getAuthor()==n)
            {
                cout<<curr->data.getTitle()<<endl;
                if(curr==head)
                {
                    ptr=curr->next;
                    head=ptr;
                    ptr->prev=NULL;
                    delete curr;
                    curr=ptr;
                    length--;
                    counter++;
                }
                else if(curr==tail)
                {
                    ptr=tail->prev;
                    delete tail;
                    tail=ptr;
                    ptr->next=NULL;
                    curr=NULL;
                    length--;
                    counter++;
                }
                else
                {
                    ptr=curr->next;
                    curr->prev->next=curr->next;
                    curr->next->prev=curr->prev;
                    delete curr;
                    curr=ptr;
                    length--;
                    counter++;
                }
            }
            else
            {
                curr=curr->next;
            }
        }
        if(counter>0)
        {
            cout<<"the number of the deleted books are "<<counter<<endl;
        }
    }
    int getlength()
    {
        return length;
    }
    void setlength(int x)
    {
        length=x;
    }
    void sorting()
    {
        Node *current = head, *index = NULL;
        book temp;
        if(head == NULL)
        {
            return;
        }
        else
        {
            while(current != NULL)
            {
                index = current->next;
                while(index != NULL)
                {
                    if(current->data.getNumofpages() > index->data.getNumofpages())
                    {
                        temp.setTitle(current->data.getTitle());
                        temp.setCategory(current->data.getCatorgety());
                        temp.setPagenum(current->data.getNumofpages());
                        temp.setAuthor(current->data.getAuthor());
                        current->data.setTitle(index->data.getTitle());
                        current->data.setCategory(index->data.getCatorgety());
                        current->data.setPagenum(index->data.getNumofpages());
                        current->data.setAuthor(index->data.getAuthor());
                        index->data.setAuthor(temp.getAuthor());
                        index->data.setTitle(temp.getTitle());
                        index->data.setPagenum(temp.getNumofpages());
                        index->data.setCategory(temp.getCatorgety());
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
};

#endif // LINKEDLIST_H_INCLUDED
