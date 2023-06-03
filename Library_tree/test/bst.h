#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include "book.h"
class BST
{
    struct node
    {
        book data;
        node*right;
        node*left;
    };
    node*root;
    int numberOfbooks;
public:
    BST()
    {
        root=NULL;
        numberOfbooks=0;
    }
    node*insert(node*r,string t,string a,string c,int num )
    {
        if(r==NULL)
        {
            node*newNode=new node;
            r=newNode;
            newNode->data.setTitle(t);
            newNode->data.setAuthor(a);
            newNode->data.setCategory(c);
            newNode->data.setPagenum(num);
            r->right=NULL;
            r->left=NULL;
            numberOfbooks++;
        }
        else
        {
            if(t<r->data.getTitle())
            {
                r->left=insert(r->left,t, a, c, num);
            }
            else if(t>r->data.getTitle())
            {
                r->right=insert(r->right, t, a, c, num);
            }
        }
        return r;
    }
    void insert(string t, string a,string c,int num)
    {
        root=insert(root,t,a,c,num);
    }
    node*searchTitle(node*r,string key)
    {
        if(r==NULL)
        {
            return r ;
        }
        else if( r->data.getTitle()==key)
        {
            return r;
        }
        else if(key<r->data.getTitle())
        {
            return searchTitle(r->left,key);
        }
        else
        {
            return searchTitle(r->right,key);
        }
    }
    bool searchTitle(string item )
    {

        if(searchTitle(root,item)==NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void inorder(node*r)
    {
        if(r==NULL)
        {
            return  ;
        }
        inorder(r->left);
        r->data.display();
        inorder(r->right);

    }
    node*findMax(node*r)
    {
        if(r==NULL)
        {
            return NULL;
        }
        else if(r->right==NULL)
        {
            return r;
        }
        else
        {
            return findMax(r->right);
        }
    }
    void traverseASC()
    {
        inorder(root);
    }

    node*Deletes(node*r,string key)
    {

        if(r==NULL)
        {
            return NULL;
        }
        if(key<r->data.getTitle())
        {
            r->left=Deletes(r->left,key);
        }
        else if(key>r->data.getTitle())
        {
            r->right=Deletes(r->right,key);
        }
        else
        {
            if(r->left==NULL&&r->right==NULL)
            {
                r=NULL;
            }
            else if (r->left!=NULL&&r->right==NULL)
            {
                r->data.setTitle(r->left->data.getTitle());
                r->data.setAuthor(r->left->data.getAuthor());
                r->data.setCategory(r->left->data.getCatorgety());
                r->data.setPagenum(r->left->data.getNumofpages());
                delete r->left;
                r->left=NULL;
            }
            else if(r->left==NULL&&r->right!=NULL)
            {
                r->data.setTitle(r->right->data.getTitle());
                r->data.setAuthor(r->right->data.getAuthor());
                r->data.setCategory(r->right->data.getCatorgety());
                r->data.setPagenum(r->right->data.getNumofpages());
                delete r->right;
                r->right=NULL;
            }
            else
            {
                node*max=findMax(r->left);
                r->data.setTitle(max->data.getTitle());
                r->data.setAuthor(max->data.getAuthor());
                r->data.setCategory(max->data.getCatorgety());
                r->data.setPagenum(max->data.getNumofpages());
                r->left=Deletes(r->left,max->data.getTitle());
            }
        }
        return r;
    }
    void Delete(string x)
    {
        Deletes(root,x);
    }
    void findmax()
    {
        findMax(root)->data.display();
    }
    void searchCategory(node*r,string key)
    {
        if(r==NULL)
        {
            return ;
        }
        searchCategory(r->left,key);
        if(r->data.getCatorgety()==key)
        {
            r->data.display();
        }
        searchCategory(r->right,key);
    }
    void searchCategory(string item)
    {
        searchCategory(root,item);
    }
    void searchAuthor(node*r,string key)
    {
        if(r==NULL)
        {
            return ;
        }
        searchAuthor(r->left,key);
        if(r->data.getAuthor()==key)
        {
            r->data.display();
        }
        searchAuthor(r->right,key);
    }
    void searchAuthor(string item)
    {
        searchAuthor(root,item);
    }
    void postorder(node*r)
    {
        if(r==NULL)
        {
            return  ;
        }
        postorder(r->right);
        r->data.display();
        postorder(r->left);
    }
    void traverseDSC()
    {
        postorder(root);
    }
};

#endif // BST_H_INCLUDED
