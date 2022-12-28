#include<iostream>
#include<stdio.h>
using namespace std;
#define SIZE 8

void insert_front(int*, int, int*, int*);
void insert_rear(int*, int, int*, int*);
int remove_front(int*, int*, int*);
int remove_rear(int*, int*, int*);
void print(int*);
int count_element(int*);
void insert_front(int* a, int data, int* front, int* rear) {
    int i, c, k;
    if (*front == 0 && *rear == SIZE - 1)
    {
        cout << "\n da day";
        return;
    }
    if (*front == -1)
    {
        *front = *rear;
        a[*front] = data;
        return;
    }

    if (*rear != SIZE - 1)
    {
        c = count_element(a);
        k = *rear + 1;
        for (i = 1; i <= c; i++)
        {
            a[k] = a[k - 1];
            k--;
        }
        a[k] = data;
        *front = k;
        (*rear)++;
    }
    else {
        (*front--);
        a[*front] = data;
    }
}

void insert_rear(int* a, int data, int* front, int* rear) {
    int i, k;
    if (*front == 0 && *rear == SIZE - 1)
    {
        cout << "da day";
        return;
    }
    if (*front == -1)
    {
        *rear = *front = 0;
        a[*rear] = data;
        return;
    }
    if (*rear == SIZE - 1)
    {
        k = *front - 1;
        for (i = *front - 1; i < *rear; i++)
        {
            k = i;
            if (k == SIZE - 1)
            {
                a[k] = 0;
            }
            else
                a[k] = a[i + 1];
        }
        (*rear)--;
        (*front)--;
    }
    (*rear)++;
    a[*rear] = data;
}
int remove_front(int* a, int* front, int* rear)
{
    int data;
    if (*front == -1)
    {
        cout << "Hang doi rong";
        return 0;
    }
    data = a[*front];
    a[*front] = 0;
    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else
        (*front)++;
    return data;
}
int remove_rear(int* a, int* front, int* rear) {
    int data;
    if (*front == -1)
    {
        cout << "Hang doi rong";
        return 0;
    }
    data = a[*rear];
    a[*rear] = 0;
    (*rear)--;
    if (*rear == -1) {
        *front = -1;
    }
    return data;
}
void print(int* a) {
    for (int i = 0; i < SIZE; i++)
    {
        cout << a[i] << " ";
    }
}
int count_element(int* a) {
    int k = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (a[i] != 0)
            k++;
    }
    return k;
}

int deque_main()
{
    int a[SIZE];
    int front, rear, i, number;

    front = rear = -1;
    for (i = 0; i < SIZE; i++)
        a[i] = 0;
    insert_rear(a, 3, &front, &rear);
    insert_front(a, 5, &front, &rear);
    insert_rear(a, 7, &front, &rear);
    insert_front(a, 9, &front, &rear);
    insert_rear(a, 11, &front, &rear);

    cout << "Phan tu trong han doi la: ";
    print(a);
    cout << endl;

    i = remove_front(a, &front, &rear);
    cout << "\nPhan tu da duoc xoa: "; cout << i << endl;
    cout << "Sau khi xoa phia truoc: "; print(a);

    i = remove_rear(a, &front, &rear);
    cout << "\n\nPhan tu da duoc xoa: "; cout << i << endl;
    cout << "Sau khi xoa phia sau: "; print(a);

    number = count_element(a);
    cout << "\n\nso phan tu trong hang doi la: " << number;

    return 0;
}
