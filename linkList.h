#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <iostream>
using namespace std;


class illegalInput{};
template <class elemType>
class linkList
{
    private:
        struct node
        {
            elemType data;
            node *next;
            node(const elemType &x,node *p = NULL)
            {
                data = x;
                next = p;
            }
            node(){next = NULL;}
            ~node(){};
        };
        node *head;
    public:
        void insert(int n,const elemType &x);
        void traverse()const;
        elemType visit(int i)const;
        void remove(int i);
        void clear();
        linkList();
        ~linkList(){clear();delete head;}

};
template <class elemType>
void linkList<elemType>::traverse()const
{
    node *p = head->next;
    while(p)
    {
        cout << p->data << " ";

        p = p->next;
    }
    cout << endl;
    return;
}
template <class elemType>
void linkList<elemType>::insert(int n,const elemType &x)
{
    if(n < 0)throw illegalInput();
    int count = -1;

    node *p = head;
    node *tmp = new node(x);
    while(p && n - 1 > count)
    {

        count++;
        p = p->next;

    }
    if(!p)throw illegalInput();
    tmp->next = p->next;
    p->next = tmp;

}
template <class elemType>
linkList<elemType>::linkList()
{
    head = new node;
}
template <class elemType>
void linkList<elemType>::clear()
{
    node *p = head;
    while(p)
    {
        node *q = p->next;
        delete p;
        p = q;
    }
    return;
}
template <class elemType>
void linkList<elemType>::remove(int i)
{
    return;
}
template <class elemType>
elemType linkList<elemType>::visit(int i)const
{
    node *p = head->next;
    int count = 0;
    while(p && count < i)
    {

        p = p->next;
        count++;
    }
    if(!p)return -1;
    return p->data;
}


#endif // LINKLIST_H_INCLUDED
