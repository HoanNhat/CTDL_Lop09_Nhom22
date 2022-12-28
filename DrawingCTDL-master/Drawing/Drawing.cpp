#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

class CircleList
{
    void CreateNode(int x, int y)
    {
        //width = 125
        for (int i = 0; i <= 150; i = i + 10)
        {
            rectangle(50 + x, 50 + y, x, 0 + y);
            line(x, y, 50 + x, y);
            line(x, 50 + y, x, y);
            line(x, 50 + y, 50 + x, 50 + y);

            line(-25 + x, 25 + y, x, 25 + y);
            line(80 + x, 25 + y, 100 + x, 25 + y);

            rectangle(80 + x, 51 + y, 50 + x, y);
            setcolor(9);
            circle(64 + x, 25 + y, 25);

            setcolor(4);

            line(x - 10, 15 + y, x, 25 + y);
            line(x - 10, 35 + y, x, 25 + y);
        }
    }
    void CreateLink(int soNode, int x, int y)
    {
        setcolor(4);
        int X = x - 23;
        int Y = y + 75;
        int W = 125 * soNode;
        line(X, -50 + Y, X, Y);
        for (int i = 1;i <= soNode;i++)
        {
            line(X, Y, 125 * i, Y);
        }
        line(W + X, -50 + Y, W + X, Y);
    }
    void NullNode(int x, int y)
    {
        setcolor(4);
        rectangle(30 + x, 0 + y, 110 + x, 50 + y);
        drawText(255 + x, 180 + y, "Null");
    }
    void CreateCircleList(int soNode)
    {
        int a = 0;
        for (int i = 0;i < soNode;i++)
        {
            CreateNode(30 + a, 125);
            a += 125;
        }
        NullNode((soNode - 1) * 125, 30);
        line((soNode - 1) * 125 + 60, 50, (soNode - 1) * 125 + 60, 150);
    }
    void InsertInAnEmptyList()
    {
        cout << "INSERT NODE IN AN EMPTY LIST";
        int i = 0, a = 0;
        for (i;i <= 100;i++)
        {
            NullNode(0, 0);
            CreateNode(30, 200 - 2 * i);
            CreateLink(1, 30, 200 - 2 * i);
            line(60, 20, 60, 20 + 2 * i);
            if (i == 50)
                break;
            system("cls");
        }
    }
    void InsertAtBegin()
    {
        int i, j = 0;
        int a = 0, soNode;
        cout << "INSERT NODE AT BEGIN OF LIST";
        cout << "\nNhap so node ban dau: ";
        cin >> soNode;

        int W = 125 * soNode;

        for (int i = 1;i <= 125;i++, j += 3)
        {
            system("cls");
            CreateCircleList(soNode);
            line(0 - j, -50 + 200, 0 - j, 200);
            line(0 - j, 200, 127 * soNode, 200);
            line(W + 7, -50 + 200, W + 7, 200);
            CreateNode(-95, 245 - j);
            if (j == 120)
                break;
        }
    }
    void InsertAfter()
    {
        int i, j = 0, pos;
        int soNode;

        cout << "INSERT NODE IN BETWEEN LIST";
        cout << "\nNhap so node ban dau: ";
        cin >> soNode;

        cout << "Nhap vi tri can them: ";
        cin >> pos;

        int W = 125 * soNode;


        for (i = 1;i <= 125;i++, j += 3)
        {
            int a = 0;

            for (int z = 1;z <= pos;z++)
            {
                CreateNode(30 + a, 125);
                a += 125;
                if (j == pos)
                    break;
            }
            for (int z = 1;z <= soNode - pos;z++)
            {
                CreateNode(30 + a + j, 125);
                a += 125;
            }

            line(5, -50 + 200, 5, 200);
            line(0, 200, 127 * soNode + j, 200);
            line(W + 7 + j, -50 + 200, W + 7 + j, 200);

            CreateNode(30 + pos * 125, 245 - j);

            NullNode(soNode * 125, 30);
            line(soNode * 125 + 60, 50, (soNode * 125 - 60) + j, 150);

            if (j == 120)
                break;
            system("cls");
        }
    }
    void InsertAtEnd()
    {
        int i, j = 0, a = 0, soNode;
        cout << "INSERT NODE AT THE END OF THE LIST";
        cout << "\nNhap so node ban dau: ";
        cin >> soNode;

        int W = 125 * soNode;

        for (int i = 1;i <= 125;i++, j += 3)
        {
            int a = 0;
            for (int z = 1;z <= soNode;z++)
            {
                CreateNode(30 + a, 125);
                a += 125;
                if (j == soNode)
                    break;
            }

            line(0, 200, 127 * soNode + j, 200);
            line(0, -50 + 200, 0, 200);
            line(W + 7 + j, -50 + 200, W + 7 + j, 200);

            CreateNode(soNode * 125 + 30, 245 - j);

            NullNode(soNode * 125, 30);
            line(soNode * 125 + 60, 50, (soNode * 125 - 60) + j, 150);
            if (j == 120)
                break;
            system("cls");
        }
    }
    void Delete()
    {
        int i, j = 0, pos;
        int soNode;

        cout << "INSERT NODE IN BETWEEN LIST";
        cout << "\nNhap so node ban dau: ";
        cin >> soNode;

        cout << "Nhap vi tri node can xoa: ";
        cin >> pos;

        int W = 125 * soNode;

        for (i = 1;i <= 125;i++, j += 3)
        {
            system("cls");
            int a = 0;
            for (int z = 1;z < pos;z++)
            {
                CreateNode(30 + a, 125);
                a += 125;
            }

            CreateNode(30 + ((pos - 1) * 125), 125 - j);

            for (int z = pos;z < soNode;z++)
            {
                CreateNode(((25 + a) + 125) - j, 125);
                a += 125;
            }

            line(5, -50 + 200, 5, 200);
            line(0, 200, 127 * soNode - j, 200);
            line(W + 7 - j, -50 + 200, W + 7 - j, 200);

            NullNode(soNode * 125 - (j - 1), 30);
            line(soNode * 125 + 60 - (j - 1), 50, (soNode * 125 - 60) - j, 150);

            if (j == 120)
                break;
        }
    }

    public: void A()
    {
        initgraph();
        SetXY();
        int option;
        do {

            cout << "1. Insert node in an empty list\n";
            cout << "2. Insert node at begin of list\n";
            cout << "3. Insert node at the end of list\n";
            cout << "4. Insert node after other node of list\n";
            cout << "5. Delete node in list\n";
            cout << "6. Return\n";
            cout << "Your select: ";
            cin >> option;
            system("cls");
            switch (option)
            {
            case 1:
                InsertInAnEmptyList();
                break;
            case 2:
                InsertAtBegin();
                break;
            case 3:
                InsertAtEnd();
                break;
            case 4:
                InsertAfter();
                break;
            case 5:
                Delete();
                break;
            default:
                break;
            }
        } while (option != 6);
    }
};

class Deque
{
    void node(int x, int y)
    {
        for (int i = 0; i <= 150; i = i + 10)
        {
            rectangle(x, 200 + y, 50 + x, 120 + y);
        }
    }

    void nodedequeuexx(int x, int y)
    {
        for (int i = 0; i <= 150; i = i + 10)
        {
            rectangle(450 - x, 200 + y, 500 - x, 120 + y);
        }
    }

    void insertback()
    {
        int sonode;
        cout << "Nhap so node can insert: ";
        cin >> sonode;
        int pos = 0, count = 0;
        for (int b = 1; b <= sonode; b++)
        {
            for (int i = 1; i <= 200; i += 5)
            {
                int a = 0;
                system("cls");
                setcolor(9);
                line(30, 110, 450, 110);
                line(30, 210, 450, 210);
                setcolor(8);
                nodedequeuexx(i, 0);
                if (i == 200) break;
                for (int y = 1; y <= count; y++)
                {
                    nodedequeuexx(400 + a, 0);
                    a -= 60;
                }
            }
            pos += -60, count++;
        }
    }

    void insertfront()
    {
        int sonode;
        cout << "Nhap so node can insert: ";
        cin >> sonode;
        int pos = 0, count = 0;
        for (int b = 1; b <= sonode; b++)
        {
            for (int i = 1; i <= 200; i += 5)
            {
                int a = 0;
                system("cls");
                setcolor(9);
                line(30, 110, 450, 110);
                line(30, 210, 450, 210);
                setcolor(8);
                node(i, 0);
                if (i == 200) break;
                for (int y = 1; y <= count; y++)
                {
                    node(400 + a, 0);
                    a -= 60;
                }
            }
            pos += -60, count++;
        }
    }

    void deleteback()
    {
        int sonode, option;
        cout << "Nhap so node ban dau: ";
        cin >> sonode;
        do
        {
            cout << "Ban co muon xoa node (1:co/0:khong): ";
            cin >> option;
            if (option == 0)
            {
                break;
            }
            for (int i = 1; i <= 250; i += 5)
            {
                int a = 0;
                setcolor(9);
                line(30, 110, 450, 110);
                line(30, 210, 450, 210);
                setcolor(8);
                for (int y = 1; y < sonode; y++)
                {
                    nodedequeuexx(400 + a, 0);
                    a -= 60;
                }
                nodedequeuexx(200 + a - i, 0);
                if (i == 250) break;
                system("cls");
            }
            sonode--;
            system("cls");
        } while (option == 1);
    }

    void deletefront()
    {
        int sonode, option;
        cout << "Nhap so node ban dau: ";
        cin >> sonode;
        do
        {
            cout << "Ban co muon xoa node (1:co/0:khong): ";
            cin >> option;
            if (option == 0)
            {
                break;
            }
            for (int i = 1; i <= 250; i += 5)
            {
                int a = 0;
                setcolor(9);
                line(30, 110, 450, 110);
                line(30, 210, 450, 210);
                setcolor(8);
                for (int y = 1; y < sonode; y++)
                {
                    node(400 + a, 0);
                    a -= 60;
                }
                node(200 + a - i, 0);
                if (i == 250) break;
                system("cls");
            }
            sonode--;
            system("cls");
        } while (option == 1);
    }

    public: void B()
    {
        initgraph();
        SetXY();

        int option;
        do {

            cout << "1. Insert front of deque\n";
            cout << "2. Delete front of deque\n";
            cout << "3. Insert back of deque\n";
            cout << "4. Delete back of deque\n";
            cout << "5. Return\n";
            cout << "Your select: ";
            cin >> option;
            system("cls");
            switch (option)
            {
            case 1:
                insertfront();
                break;
            case 2:
                deletefront();
                break;
            case 3:
                insertback();
                break;
            case 4:
                deleteback();
                break;
            default:
                break;
            }
        } while (option != 5);
    }
};

class LinkList
{

    void TaoNode(int x, int y)
    {
        //width = 125
        int i, j = 0;
        for (i = 0; i <= 150; i = i + 10, j++)
        {

            rectangle(50 + x, 50 + y, x, 0 + y);
            line(x, y, 50 + x, y);
            line(x, 50 + y, x, y);
            line(x, 50 + y, 50 + x, 50 + y);

            line(-60 + x, 25 + y, x, 25 + y);

            rectangle(80 + x, 51 + y, 50 + x, y);
            setcolor(9);
            circle(64 + x, 25 + y, 25);

            setcolor(4);

            line(x - 10, 15 + y, x, 25 + y);
            line(x - 10, 35 + y, x, 25 + y);
        }
    }

    void TaoLink(int soNode, int x, int y)
    {
        setcolor(4);
        int X = x - 23;
        int Y = y + 75;
        int W = 125 * soNode;
        line(X, -50 + Y, X, Y);
        for (int i = 1;i <= soNode;i++)
        {
            line(X, Y, 125 * i + 10, Y);
        }
        line(W + X, -50 + Y, W + X, Y);
    }

    void Node(int x, int y)
    {
        setcolor(4);
        rectangle(30 + x, 0 + y, 110 + x, 50 + y);
        rectangle(-100, 125, -30, 175);
    }

    void CreateLinkList(int soNode)
    {
        int a = 0;
        for (int i = 0;i < soNode;i++)
        {
            TaoNode(30 + a, 125);
            a += 125;
        }
        Node((soNode - 1) * 125, 30);
        line((soNode - 1) * 125 + 60, 50, (soNode - 1) * 125 + 60, 150);
    }

    void ThemVaoDSRong()
    {
        cout << "INSERT NODE IN AN EMPTY LIST";
        int i = 0, a = 0;
        for (i;i <= 100;i++)
        {
            Node(0, 0);
            TaoNode(30, 200 - 2 * i);
            TaoLink(1, 30, 200 - 2 * i);
            line(60, 20, 60, 30 + 2 * i);
            if (i == 50)
                break;
            system("cls");
        }
    }

    void ThemVaoDau()
    {
        int i, j = 0;
        int a = 0, soNode;
        cout << "INSERT NODE AT BEGIN OF LIST";
        cout << "\nNhap so node ban dau: ";
        cin >> soNode;

        int W = 125 * soNode;

        for (int i = 1;i <= 125;i++, j += 3)
        {
            CreateLinkList(soNode);
            rectangle(-100 - j, 125, -30 - j, 175);
            TaoNode(-95, 245 - j);
            if (j == 120)
                break;
            system("cls");
        }
    }

    void ThemVaoSau()
    {
        int i, j = 0, pos;
        int soNode;

        cout << "INSERT NODE IN BETWEEN LIST";
        cout << "\nNhap so node ban dau: ";
        cin >> soNode;

        cout << "Nhap vi tri can them: ";
        cin >> pos;

        int W = 125 * soNode;

        for (i = 1;i <= 125;i++, j += 3)
        {
            int a = 0;
            Node(soNode * 125, 30);
            TaoNode(30 + pos * 125, 245 - j);
            system("cls");
            for (int z = 1;z <= pos;z++)
            {
                TaoNode(30 + a, 125);
                a += 125;
                if (j == pos)
                    break;
            }
            for (int z = 1;z <= soNode - pos;z++)
            {
                TaoNode(30 + a + j, 125);
                a += 125;
            }

            line(soNode * 125 + 60, 50, (soNode * 125 - 60) + j, 150);

            if (j == 120)
                break;
        }
    }

    void ThemVaoCuoi()
    {
        int i, j = 0, a = 0, soNode;
        cout << "INSERT NODE AT THE END OF THE LIST";
        cout << "\nNhap so node ban dau: ";
        cin >> soNode;

        int W = 125 * soNode;

        for (int i = 1;i <= 125;i++, j += 3)
        {
            system("cls");
            int a = 0;
            for (int z = 1;z <= soNode;z++)
            {
                TaoNode(30 + a, 125);
                a += 125;
                if (j == soNode)
                    break;
            }
            TaoNode(soNode * 125 + 30, 245 - j);

            Node(soNode * 125, 30);
            line(soNode * 125 + 60, 50, (soNode * 125 - 60) + j, 150);
            if (j == 120)
                break;
        }
    }

    void Xoa()
    {
        int i, j = 0, pos;
        int soNode;

        cout << "INSERT NODE IN BETWEEN LIST";
        cout << "\nNhap so node ban dau: ";
        cin >> soNode;

        cout << "Nhap vi tri node can xoa: ";
        cin >> pos;

        int W = 125 * soNode;

        for (i = 1;i <= 125;i++, j += 3)
        {
            int a = 0;
            for (int z = 1;z < pos;z++)
            {
                TaoNode(30 + a, 125);
                a += 125;
            }

            TaoNode(30 + ((pos - 1) * 125), 125 - j);

            for (int z = pos;z < soNode;z++)
            {
                TaoNode(((25 + a) + 125) - j, 125);
                a += 125;
            }


            Node(soNode * 125 - (j - 1), 30);
            line(soNode * 125 + 60 - (j - 1), 50, (soNode * 125 - 60) - j, 150);

            if (j == 120)
                break;
            system("cls");
        }
    }

    public: void C()
    {
        initgraph();
        SetXY();

        int option;
        do {

            cout << "1. Insert node in an emty list\n";
            cout << "2. Insert node at begin of list\n";
            cout << "3. Insert node at the end of list\n";
            cout << "4. Insert node after other node of list\n";
            cout << "5. Delete node in list\n";
            cout << "6. Return\n";
            cout << "Your select: ";
            cin >> option;
            system("cls");
            switch (option)
            {
            case 1:
                ThemVaoDSRong();
                break;
            case 2:
                ThemVaoDau();
                break;
            case 3:
                ThemVaoCuoi();
                break;
            case 4:
                ThemVaoSau();
                break;
            case 5:
                Xoa();
                break;
            default:
                break;
            }
        } while (option != 6);
    }
};

class Queue
{

    int sonode = 0;
    void nodequeue(int x, int y)
    {
        for (int i = 0; i <= 150; i = i + 10)
        {
            rectangle(x, 200 + y, 50 + x, 120 + y);
        }
    }

    void queueinsert()
    {
        changex(200);
        changey(200);
        cout << "Nhap so node can insert: ";
        cin >> sonode;
        int pos = 0, count = 0;
        for (int b = 1; b <= sonode; b++)
        {
            for (int i = 1; i <= sonode * 60 - 60 * count; i += 5)
            {
                int a = 0;
                system("cls");
                drawText(190 + sonode * 60, 230, " front ");
                drawText(230, 230, " rear ");
                setcolor(9);
                line(sonode * 60 + 60, 110, 0, 110);
                line(sonode * 60 + 60, 210, 0, 210);
                setcolor(8);
                nodequeue(i, 0);
                for (int y = 1; y <= count; y++)
                {
                    nodequeue(sonode * 60 + a, 0);
                    a -= 60;
                }
                if (i == sonode * 60 - 60 * count) break;
            }
            count++;
        }
    }

    void queuedelete()
    {
        changex(200);
        changey(200);
        int option;
        do
        {
            if (sonode == 0)
            {
                cout << "Queue is empty\n";
                break;
            }
            cout << "Ban co muon xoa node (1:co/0:khong): ";
            cin >> option;
            if (option == 0)
            {
                break;
            }
            for (int i = 1; i <= 250; i += 5)
            {
                int a = 0;
                setcolor(9);
                drawText(540, 230, " front ");
                drawText(220, 230, " rear ");
                line(20, 110, 400, 110);
                line(20, 210, 400, 210);
                setcolor(8);
                for (int y = 1; y < sonode; y++)
                {
                    nodequeue(30 + a, 0);
                    a += 60;
                }
                nodequeue(sonode * 65 + i, 0);
                if (i == 250) break;
                system("cls");
            }
            sonode--;
            system("cls");
        } while (option == 1);
    }

    public: void D()
    {
        initgraph();
        system("cls");
        int option;
        do {

            cout << "1. Enqueue\n";
            cout << "2. Dequeue\n";
            cout << "3. Return\n";
            cout << "Your select: ";
            cin >> option;
            system("cls");
            switch (option)
            {
            case 1:
                queueinsert();
                break;
            case 2:
                queuedelete();
                break;
                break;
            default:
                break;
            }
        } while (option != 3);
    }
};

class Stack
{

    int soNode = 0;
    void NodeStack(int x, int y)
    {
        for (int i = 0; i <= 150; i = i + 10)
        {
            rectangle(x, 250 + y, 80 + x, 200 + y);
        }
    }

    void StackInsert()
    {
        changex(200);
        changey(150);
        cout << "Nhap so node can insert: ";
        cin >> soNode;
        int pos = 0, count = 0;
        for (int b = 1; b <= soNode; b++)
        {
            for (int i = 1; i <= 125; i += 5)
            {
                int a = 0;
                system("cls");
                drawText(300, 90, "Top");
                setcolor(9);
                line(-10, 380, -10, 10);
                line(-10, 380, 100 + -10, 380);
                line(100 + -10, 380, 100 + -10, 10);
                setcolor(8);
                NodeStack(0, pos + i);
                if (i == 120) break;
                for (int y = 1; y <= count; y++)
                {
                    NodeStack(0, 125 + a);
                    a -= 55;
                }
            }
            pos += -55, count++;
        }
    }

    void StackDelete()
    {
        changex(200);
        changey(150);
        int option;
        do
        {
            if (soNode == 0)
            {
                cout << "Stack is empty\n";
                break;
            }
            cout << "Ban co muon xoa node (1:Co/0:Khong): ";
            cin >> option;
            if (option == 0)
            {
                break;
            }
            for (int i = 1; i <= 250; i += 5)
            {
                int a = 0;
                setcolor(9);
                line(-10, 380, -10, 380 - soNode * 60);
                line(-10, 380, 100 + -10, 380);
                line(100 + -10, 380, 100 + -10, 380 - soNode * 60);
                setcolor(8);
                for (int y = 1; y < soNode; y++)
                {
                    NodeStack(0, 125 + a);
                    a -= 55;
                }
                NodeStack(0, 125 + a - i);
                if (i == 250) break;
                system("cls");
            }
            soNode--;
        } while (option == 1);
    }

    public: void E()
    {
        initgraph();
        system("cls");
        int option;
        do {

            cout << "1. Insert stack (Push)\n";
            cout << "2. Delete stack (Pop)\n";
            cout << "3. Return\n";
            cout << "Your select: ";
            cin >> option;
            system("cls");
            switch (option)
            {
                case 1:
                    StackInsert();
                    break;
                case 2:
                    StackDelete();
                    break;
                default:
                    break;
            }
        } while (option != 3);
    }
};

int main()
{
    CircleList clist;
    Deque deque;
    LinkList llist;
    Queue queue;
    Stack stack;
    int option;
    do {

        cout << "1. Stack\n";
        cout << "2. Queue\n";
        cout << "3. Deque\n";
        cout << "4. Link list\n";
        cout << "5. Circle list\n";
        cout << "6. Exit\n";
        cout << "Your select: ";
        cin >> option;
        system("cls");
        switch (option)
        {
            case 1:
                stack.E();
                break;
            case 2:
                queue.D();
                break;
            case 3:
                deque.B();
                break;
            case 4:
                llist.C();
                break;
            case 5:
                clist.A();
                break;
            default:
                break;
        }
    } while (option != 6);
    return 0;
}
