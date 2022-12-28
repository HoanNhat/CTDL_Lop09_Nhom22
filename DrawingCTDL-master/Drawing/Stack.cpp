#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
typedef struct Node* stack;

struct Stack {
	Node* head;
	Node* tail;
};

Node* CreateNode(int x) {
	Node* p = new Node();
	if (p == NULL) {
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

bool isEmpty(stack s) {
	return s == NULL;
}

void Push(stack& s, int x) {
	Node* p = CreateNode(x);
	if (isEmpty(s)) {
		s = p;
	}
	else {
		p->next = s;
		s = p;
	}
}

int Pop(stack& s) {
	if (!isEmpty(s)) {
		int data = s->data;
		Node* x = s;
		s = s->next;
		delete(x);
		cout << "xoa thanh cong ";
		return data;
	}
	else {
		cout << "stack is empty" << endl;
	}
}

void Print(stack s) {
	if (!isEmpty(s)) {
		while (s != NULL) {
			cout << s->data << " ";
			s = s->next;
		}
		cout << endl;
	}
	else {
		cout << "stack is empty" << endl;
	}
}

int Top(stack s) {
	if (!isEmpty(s)) {
		return s->data;
	}
	else {
		cout << "stack is empty" << endl;
	}
}

int stack_main()
{
	stack s;
	int x, option;
	Push(s, 5);
	Push(s, 8);
	Push(s, 9);
	Push(s, 4);
	Push(s, 7);
	Push(s, 3);
	cout << "Cac phan tu trong stack: 3 7 4 9 8 5" << endl;
	do {
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Top" << endl;
		cout << "4. IsEmpty" << endl;
		cout << "5. Print" << endl;
		cout << "6. Exit" << endl;
		cout << "Nhap option: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter x: ";
			cin >> x;
			Push(s, x);
			break;
		case 2:
			cout << Pop(s) << endl;
			break;
		case 3:
			cout << "Top: " << Top(s) << endl;
			break;
		case 4:
			if (isEmpty(s)) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout << "Stack is not empty" << endl;
			}
			break;
		case 5:
			cout << "Print: ";
			Print(s);
			break;
		default:
			break;
		}
	} while (option != 6);
	return 0;
}