#ifndef MYMAP_H
#define MYMAP_H
#include <iostream>
#include <stdlib.h>

template <class Key, class Item> struct node
{
    Key key;
    Item item;
    struct node *parent;
    struct node *ls;
    struct node *rs;
    public:
    node(Key k,Item i): key(k), item(i), ls(NULL), rs(NULL), parent(NULL){}
    ~node()
    {
        parent=NULL;
        ls=NULL;
        rs=NULL;
    }
    node(const node &tmp)
    {
        key=tmp.key;
        item=tmp.item;
        parent=NULL;
        ls=NULL;
        rs=NULL;
    }
    node & operator=(const node *tmp)
    {
        key=tmp->key;
        item=tmp->item;
        parent=NULL;
        ls=NULL;
        rs=NULL;
    }
};

template <class Key, class Item> class myMap
{
    public:
    node<Key, Item>* getRoot(){return root;}
    node<Key, Item>* most_left(node<Key, Item> *start)
    {
      if(start->ls != NULL)
            return most_left(start->ls);
       else
            return start;
     }

    node<Key, Item>* searchKey(node<Key, Item>* start, Key key)
    {
       if (start->key==key) return start; //found
       else if (key<start->key && start->ls!= NULL) return searchKey(start->ls, key); //search in left direction
       else if (key>start->key && start->rs!=NULL) return searchKey(start->rs, key); //search in right direction
       return NULL;
     }

    node<Key, Item>* searchItem(node<Key, Item>* start, Item item)
    {
       if (start->item==item) return start; //found
       else if (item<start->item && start->ls!=NULL) return searchItem(start->ls, item); //search in left direction
       else if (item>start->item && start->rs!=NULL) return searchItem(start->rs, item); //search in right direction
       return NULL;
     }

    Key addNode(Key n, Item i, node<Key, Item>* start)
    {
      if (root==NULL) //adding the root
       {
            root=(node<Key, Item>*)malloc(sizeof *root);
            root->key=n;
            root->item=i;
            root->ls=NULL;
            root->rs=NULL;
            root->parent=NULL;
       }
      else if(n<start->key) //LEFT
       {
            if(start->ls!=NULL)
             {
                addNode(n, i, start->ls); //recursively
             }
             else //adding node
             {
                node<Key, Item>* newNode=(node<Key, Item>*)malloc(sizeof *root);
                newNode->key=n;
                newNode->item=i;
                newNode->ls=NULL;
                newNode->rs=NULL;
                newNode->parent=start;
                start->ls=newNode;
             }
        }
       else //RIGHT
        {
             if(start->rs!=NULL)
              {
                    addNode(n, i, start->rs); //RECURSIVELY
              }
             else //adding node
              {
                   node<Key, Item>* newNode = (node<Key, Item>*)malloc(sizeof *root);
                   newNode->key=n;
                   newNode->item=i;
                   newNode->ls=NULL;
                   newNode->rs=NULL;
                   newNode->parent=start;
                   start->rs=newNode;
              }
        }
      return 0;
     }

    void deleteNode(node<Key, Item>* start)
    {
      if(start==NULL) return;
      if(searchKey(start, start->key)==NULL) return;
      if(start->ls==NULL && start->rs==NULL) //no descendant
      {
           if(start->parent==NULL) //if root
           {
                root=NULL;
           }
           else if(start->parent->ls==start) //on the left
           {
                start->parent->ls=NULL; //delete left one
           }
           else //on the right
           {
                start->parent->rs=NULL; //delete right one
           }
           delete start;
      }
      else if(start->ls==NULL || start->rs==NULL) //one descendant
      {
           if(start->ls==NULL) //no left
           {
                if(start->parent==NULL) //if root
                {
                    root=start->rs;
                    start->rs->parent=NULL; ///maybe zle
                }
                else if(start->parent->ls==start) //on the left of parent
                {
                    start->parent->ls=start->rs;
                    start->rs->parent=start->parent;
                }
                else //on the right of parent
                {
                    start->parent->rs=start->rs;
                    start->rs->parent=start->parent;
                }
           }
           else //no right
           {
                if(start->parent==NULL) //if root
                {
                    root=start->ls;
                    start->ls->parent=NULL;
                }
                else if(start->parent->ls==start) //on the left of parent
                {
                    start->parent->ls=start->ls;
                    start->ls->parent=start->parent;
                }
                else //on the right of parent
                {
                    start->parent->rs=start->ls;
                    start->rs->parent=start->parent;
                }
           }
           delete start;
      }
      else //both descendants -> right node as start
      {
           node<Key, Item>* temp;
           temp=most_left(start->rs);
           start->key = temp->key;
           deleteNode(temp);
      }
    }

        myMap(){}
        ~myMap()
        {
            while(root)
            {
                deleteNode(most_left(root));
            }
        }
    private:
    node<Key, Item>* root=NULL;
};

    template <class Key, class Item> bool isKey(Key k, node<Key, Item>* start)
{
    if(start->ls != NULL)//jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
    if(isKey(k, start->ls)==true)return true;
    if(start->key==k){return true;}
    if(start->rs != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
    if(isKey(k, start->rs)==true)return true;
    return false;
};

#endif // MYMAP_H
