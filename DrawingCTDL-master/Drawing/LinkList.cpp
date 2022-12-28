#include<iostream>
using namespace std;
//khai báo cấu trúc node
struct node {
    int data;
    struct node* pNext;
};
typedef struct node NODE;

//khai báo cấu trúc danh sách liên kết đơn
struct list
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct list LIST;

void KhoiTao(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE* KhoiTaoNODE(int x)
{
    NODE* p = new NODE;
    if (p == NULL)
    {
        cout << "Khong du bo nho de cap phat!";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

//Thêm phần tử vào đầu danh sách
void ThemVaoDau(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

//Thêm phần tử vào cuối danh dách
void ThemVaoCuoi(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

//Thêm phần tử vào vị trí truoc gia trị bất kì bất kì trong danh sách
void ThemVaoViTriTruoc(LIST& l, NODE* p)
{
    int x;
    cout << "Nhap gia tri vi tri muon them vao:  ";
    cin >> x;
    NODE* q = KhoiTaoNODE(x);
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
    {
        ThemVaoDau(l, p);
    }
    else
    {
        NODE* g = new NODE;
        for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        {
            if (q->data == k->data)
            {
                p->pNext = k;
                g->pNext = p;
            }
            g = k;
        }
    }
}

//Thêm phần tử vào vị trí sau gia trị bất kì bất kì trong danh sách
void ThemVaoViTriSau(LIST& l, NODE* p)
{
    int x;
    cout << "Nhap gia tri vi tri muon them vao:  ";
    cin >> x;
    NODE* q = KhoiTaoNODE(x);
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
    {
        ThemVaoCuoi(l, p);
    }
    else
    {
        for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        {
            if (q->data == k->data)
            {
                NODE* h = KhoiTaoNODE(p->data);
                NODE* g = k->pNext;
                h->pNext = g;
                k->pNext = h;
            }
        }
    }
}

//Thêm vào vị trí bất kì
void ThemVaoBatKi(LIST& l, NODE* p, int vt, int n)
{

    if (l.pHead == NULL || vt == 1)
    {
        ThemVaoDau(l, p);
    }
    else if (vt == n + 1)
    {
        ThemVaoCuoi(l, p);
    }
    else {
        int dem = 0;
        NODE* g = new NODE;
        for (NODE* k = l.pHead; k != NULL; k = k->pNext)
        {
            dem++;
            if (dem == vt)
            {
                NODE* h = KhoiTaoNODE(p->data);
                h->pNext = k;
                g->pNext = h;
                break;
            }
            g = k;
        }
    }
}


//Xóa đầu
void XoaDau(LIST& l)
{
    if (l.pHead == NULL)
    {
        return;
    }
    NODE* p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
}

//Xóa Cuối
void XoaCuoi(LIST& l)
{
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->pNext == l.pTail)
        {
            delete l.pTail;
            k->pNext = NULL;
            l.pTail = k;
            return;
        }
    }
}

//Xóa vị trí bất kì
void XoaBatKi(LIST& l, int x)
{
    if (l.pHead->data == x)
    {
        XoaDau(l);
    }
    if (l.pTail->data == x)
    {
        XoaCuoi(l);
        return;
    }

    NODE* g = new NODE;
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->data == x)
        {
            // NODE *h = k->pNext;
            g->pNext = k->pNext;
            delete k;
            return;
        }
        g = k;
    }
}
//Hàm xuất danh sách liên kết đơn;
void XuatDanhSach(LIST l)
{
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << k->data << " ";
    }
    cout << endl;
}


void Menu(LIST& l)
{
    int luachon;
    while (true)
    {
        cout << "\n\t***********MENU*****************";
        cout << "\n\t1. Them node vao dau danh sach";
        cout << "\n\t2. Them node vao cuoi danh sach";
        cout << "\n\t3. Them node vao vi tri truoc gia tri bat ki";
        cout << "\n\t4. Them node vao vi tri sau gia tri bat ki";
        cout << "\n\t5. Them node vao vi tri sau gia tri bat ki";
        cout << "\n\t6. Xoa phan tu dau";
        cout << "\n\t7. Xoa phan tu cuoi";
        cout << "\n\t8. Xoa phan tu bat ki";
        cout << "\n\t9. xuat danh sach lien ket don";
        cout << "\n\t0. Thoat";
        cout << "\n\t********************************";
        cout << "\nNhap lua chon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 9)
        {
            cout << "Khong hop le!";
            system("pause");
        }
        if (luachon == 1)
        {
            int x;
            cout << "\n Nhap gia tri so nguyen: ";
            cin >> x;
            NODE* p = KhoiTaoNODE(x);
            ThemVaoDau(l, p);
        }
        else if (luachon == 2)
        {
            int x;
            cout << "\n Nhap gia tri so nguyen: ";
            cin >> x;
            NODE* p = KhoiTaoNODE(x);
            ThemVaoCuoi(l, p);
        }
        else if (luachon == 3)
        {
            int x;
            cout << "\n Nhap gia tri node can them sau: ";
            cin >> x;
            NODE* p = KhoiTaoNODE(x);
            ThemVaoViTriTruoc(l, p);
        }
        else if (luachon == 4)
        {
            int x;
            cout << "\n Nhap gia tri node can them sau: ";
            cin >> x;
            NODE* p = KhoiTaoNODE(x);
            ThemVaoViTriSau(l, p);
        }
        else if (luachon == 5)
        {
            int n = 0;
            for (NODE* k = l.pHead; k != NULL; k = k->pNext)
            {
                n++;
            }

            int x;
            cout << "\n Nhap gia tri node can them: ";
            cin >> x;
            NODE* p = KhoiTaoNODE(x);

            int vt;
            do
            {
                cout << "Nhap vi tri muon them: ";
                cin >> vt;
                if (vt < 1 || vt > n + 1)
                {
                    cout << "Loi, vi tri can them phai nam trong doan [1; " << n + 1 << "]";
                    system("pause");
                }
            } while (vt < 1 || vt > n + 1);

            ThemVaoBatKi(l, p, vt, n + 1);
        }
        else if (luachon == 6)
        {
            XoaDau(l);
        }
        else if (luachon == 7)
        {
            XoaCuoi(l);
        }
        else if (luachon == 8)
        {
            int x;
            cout << "Nhap node can xoa: ";
            cin >> x;
            XoaBatKi(l, x);
        }
        else if (luachon == 9)
        {
            XuatDanhSach(l);
            system("pause");
        }
        else
        {
            break;
        }
    }
}
int llist_main()
{
    LIST l;
    KhoiTao(l);
    Menu(l);
    return 0;
}