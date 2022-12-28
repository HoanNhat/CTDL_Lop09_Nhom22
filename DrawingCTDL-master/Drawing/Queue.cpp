#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

struct queue {
	node* front;
	node* rear;
};

void init(queue& q) {
	q.front = NULL;
	q.rear = NULL;
}

bool isEmpty(queue& q) {
	return q.front == NULL;
}

bool isFull(queue& q) {
	node* p = new node;
	if (p == NULL) return true;
	delete p;
	return false;
}

void Insert(queue& q, int x) {
	node* p = new node;
	p->data = x;
	p->next = NULL;
	if (q.front == NULL) {
		q.front = p;
		q.rear = p;
	}
	else {
		q.rear->next = p;
		q.rear = p;
	}
}

int Remove(queue& q) {
	int x;
	node* p = NULL;
	if (q.front != NULL) {
		p = q.front;
		x = p->data;
		q.front = q.front->next;
		delete p;
		if (q.front == NULL) {
			q.rear = NULL;
		}
	}
	return x;
}

int Front(queue& q) {
	return q.front->data;
}

int Back(queue& q) {
	return q.rear->data;
}

void Print(queue& q) {
	node* p = q.front;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int queue_main()
{
	queue q;
	init(q);
	int x, option;
	Insert(q, 1);
	Insert(q, 8);
	Insert(q, 5);
	Insert(q, 7);
	Insert(q, 6);
	Insert(q, 2);
	cout << "Cac phan tu trong queue "; Print(q);
	cout << endl;
	do {
		cout << "1. Them vao queue" << endl;
		cout << "2. Xoa node dau khoi queue" << endl;
		cout << "3. Kiem tra queue rong" << endl;
		cout << "4. Kiem tra queue day" << endl;
		cout << "5. Lay phan tu dau tien" << endl;
		cout << "6. Lay phan tu cuoi cung" << endl;
		cout << "7. In ra phan tu trong queue" << endl;
		cout << "8. Thoat" << endl;
		cout << "Nhap lua chon: ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << " nhap so can them: ";
			cin >> x;
			Insert(q, x);
			break;
		case 2:
			x = Remove(q);
			cout << "Phan tu da xoa: " << x << endl;
			break;
		case 3:
			if (isEmpty(q)) {
				cout << "Queue rong" << endl;
			}
			else {
				cout << "Co phan tu trong queue" << endl;
			}
			break;
		case 4:
			if (isFull(q)) {
				cout << "Queue day" << endl;
			}
			else {
				cout << "Queue chua day" << endl;
			}
			break;
		case 5:
			cout << "Phan tu dau tien: " << Front(q) << endl;
			break;
		case 6:
			cout << "Phan tu cuoi cung: " << Back(q) << endl;
			break;
		case 7:
			Print(q);
			break;
		default:
			break;
		}
	} while (option != 8);
	return 0;
}