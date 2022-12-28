#include<iostream>
using namespace std;

struct NODE
{
    int data;
    NODE* next;
};

NODE* insertInAnEmptyList(NODE* last, int new_data)
{
    if (last != NULL)
        return last;

    NODE* temp = new NODE;
    temp->data = new_data;

    last = temp;
    last->next = last;

    return last;
};

NODE* insertAtBegin(NODE* last, int new_data)
{
    if (last == NULL)
        return insertInAnEmptyList(last, new_data);

    NODE* temp = new NODE;

    temp->data = new_data;
    temp->next = last->next;
    last->next = temp;

    return last;
}
NODE* insertAtEnd(NODE* last, int new_data)
{
    if (last == NULL)
        return insertInAnEmptyList(last, new_data);

    NODE* temp = new NODE;

    temp->data = new_data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

NODE* insertAfter(NODE* last, int new_data, int after_item)
{
    if (last == NULL)
        return NULL;

    NODE* temp, * p;
    p = last->next;
    do
    {
        if (p->data == after_item)
        {
            temp = new NODE;
            temp->data = new_data;
            temp->next = p->next;
            p->next = temp;

            if (p == last)
                last = temp;
            return last;
        }
        p = p->next;
    } while (p != last->next);

    cout << "Node " << after_item << " is not in list." << endl;
    return last;

}
void traverseList(struct NODE* last) 
{
    NODE* p;

    if (last == NULL) 
    {
        cout << "Circle list is empty." << endl;
        return;
    }
    p = last->next;

    do 
    {
        cout << p->data << " -> ";
        p = p->next;
    } while (p != last->next);
    if (p == last->next)
        cout << p->data;
    cout << "\n\n";
}

void deleteNode(NODE** head, int key)
{
    if (*head == NULL)
        return;

    if ((*head)->data == key && (*head)->next == *head) 
    {
        free(*head);
        *head = NULL;
    }
    NODE* last = *head, * d;

    if ((*head)->data == key) 
    {
        while (last->next != *head) 
            last = last->next;

        last->next = (*head)->next;
        free(*head);
        *head = last->next;
    }

    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }
    if (last->next->data == key) 
    {
        d = last->next;
        last->next = d->next;
        cout << "Delete node " << key << " from list" << endl;
        free(d);
        cout << endl;
    }
    else cout << "Node " << key << " not in list " << endl;
}

int clist_main()
{
    NODE* last = NULL;

    last = insertInAnEmptyList(last, 30);
    last = insertAtBegin(last, 120);
    last = insertAtEnd(last, 40);
    last = insertAfter(last, 150, 120);
    last = insertAfter(last, 50, 30);
    cout << "Circle list complete: ";
    traverseList(last);
    int option, input;\
    cout << "1. Insert at begin\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert after\n";
    cout << "4. Delete\n";\
    cout << "Your option: ";
    cin >> option;
    switch (option)
    {
        case 1:
        {
            cout << "Your input: ";
            cin >> input;
            insertAtBegin(last, input);
            cout << "Circle list complete: ";
            traverseList(last);
            break;
        }
        case 2:
        {
            cout << "Your input: ";
            cin >> input;
            insertAtEnd(last, input);
            cout << "Circle list complete: ";
            traverseList(last);
            break;
        }
        case 3:
        {
            int nodeafter;
            cout << "Your input: ";
            cin >> input;
            cout << "Node you want to insert after: ";
            cin >> nodeafter;
            insertAfter(last, input, nodeafter);
            cout << "Circle list complete: ";
            traverseList(last);
            break;
        }
        case 4:
        {
            cout << "Node delete: ";
            cin >> input;
            deleteNode(&last, input);
            cout << "Circle list complete: ";
            traverseList(last);
            break;
        }
        case 5:
            break;
    }
    return 0;
}