#include <bits/stdc++.h>
using  namespace std;

int printList();

// 构建一个链表
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

int _size = 0;
ListNode* _dummyhead = new ListNode(0);

void addAtHead(int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = _dummyhead->next;
    _dummyhead->next = newNode;
    _size++;

}

void addAtTail(int val) {
    ListNode* newNode = new ListNode(val);
    ListNode* cur = _dummyhead;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = newNode;
    _size++;
}

int addAtIndex(int index, int val) {
    /*
    @Brief: 在第index个节点前，插入值为val的节点，其中索引值从1开始计数。
    */
    if (index > _size || index <= 0) {
        return -1;
    }
    ListNode* insertNode = new ListNode(val);
    ListNode* cur = _dummyhead;
    index--;
    while (index--) {
        cur = cur->next;
    }
    insertNode->next = cur->next;
    cur->next = insertNode;
    return 0;

}

int deleteAtIndex(int index) {
    /*
    @Brief: 按照索引值删除元素，索引值从1开始计数
    */

    if (index > _size || index <= 0) {
        return -1;
    }

    ListNode* cur = _dummyhead;
    index--;
    while (index--) {
        cur = cur->next;
    }
    ListNode * tmpNode = cur->next;
    cur->next = cur->next->next;
    // 不仅要释放空间，还要将指针置为nullptr，防止悬空指针
    delete tmpNode;
    tmpNode = nullptr;

    --_size;
    return 0;
}

ListNode* getAtIndex(int index) {
    if (index > _size || index <= 0) {
        return nullptr;
    }
    ListNode* cur = _dummyhead;
    while (index--) {
        cur = cur->next;
    }
    return cur;
}

int printList() {
    ListNode* cur = _dummyhead;
    if (cur->next == nullptr) return -1;
    while (cur->next) {
        cout << cur->next->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}

int main(){
    int n; //读入节点总数
    cin >> n;
    int a; // 读入每个节点的val;
    ListNode* head = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> a;
        addAtHead(a);
    }
    int nOperation; //读入执行操作的总数
    cin >> nOperation;
    while (nOperation--) {
        string s;
        cin >> s;
        if (s == "show") {
            if (printList() == -1) cout << "Link List is empty" << endl;
        }

        if (s == "delete") {
            int indexDelete;
            cin >> indexDelete;
            if (deleteAtIndex(indexDelete) == -1) cout << "delete fail" << endl;
            else cout << "delete OK" << endl;
        }

        if (s == "insert") {
            int indexInsert;
            cin >> indexInsert;
            int valInsert;
            cin >> valInsert;
            if (addAtIndex(indexInsert, valInsert) == -1) cout << "insert fail" << endl;
            else cout << "insert OK" << endl;
        }

        if (s == "get") {
            int getIndex;
            cin >> getIndex;
            ListNode* p = getAtIndex(getIndex);
            if (p == nullptr) cout << "get fail" << endl;
            else cout << p->val << endl;
        }
 
    }
    return 0;
}

