#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;
    node* pre;
};
struct douList {
    node* head;
    node* tail;
};
douList* createList(int x)
{
    douList* l = new douList;
    l->head = new node;
    l->head->data = x;
    l->head->next = NULL;
    l->head->pre = NULL;
    l->tail = l->head;
    return l;
}
douList* AddHead(douList* l, int x) {
    node* temp = new node;
    temp->data = x;
    temp->pre = NULL;
    temp->next = l->head;
    l->head->pre = temp;
    l->head = temp;
    return l;
}

douList* AddTail(douList* l, int x) {
    node* temp = new node;
    temp->data = x;
    temp->next = NULL;
    temp->pre = l->tail;
    l->tail->next = temp;
    l->tail = temp;
    return l;
}
douList* AddAt(douList* l, int k, int x) {
    node* p = l->head;
    for (int i = 0; i < k - 1; i++) {
        p = p->next;
    }
    node* temp = new node;
    temp->data = x;
    temp->pre = p;
    temp->next = p->next;
    p->next->pre = temp;
    p->next = temp;
    return l;
}
douList* deleteHead(douList* l) {
    node* p = l->head->next;
    node* temp = l->head;
    p->pre = NULL;
    l->head = p;
    delete(temp);
    return l;
}
douList* deleteTail(douList* l) {
    node* p = l->tail->pre;
    node* temp = l->tail;
    p->next = NULL;
    l->tail = p;
    delete(temp);
    return l;
}
douList* deleteAt(douList* l, int k) {
    node* p = l->head;
    for (int i = 0; i < k - 1; i++) {
        p = p->next;
    }
    node* temp = p->next;
    node* p2 = temp->next;
    p->next = p2;
    p2->pre = p;
    delete(temp);
    return l;
}
void PrintList(douList* l) {
    node* p = l->head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}
int dllist_main()
{
    douList* l = createList(3);
    AddHead(l, 10);
    AddHead(l, 10);
    AddHead(l, 10);
    cout << "Danh sach sau khi them vao dau: ";
    PrintList(l);

    AddTail(l, 9);
    AddTail(l, 9);
    cout << "\n\nDanh sach sau khi them vao dau: ";
    PrintList(l);

    AddAt(l, 3, 11);
    cout << "\n\nDanh sach sau khi them vao vi tri bat ki: ";
    PrintList(l);

    deleteHead(l);
    cout << "\n\nDanh sach sau khi xoa dau: ";
    PrintList(l);

    deleteTail(l);
    cout << "\n\nDanh sach sau khi xoa cuoi: ";
    PrintList(l);

    deleteAt(l, 3);
    cout << "\n\nDanh sach sau khi xoa vi tri bat ki: ";
    PrintList(l);
    return 0;
}