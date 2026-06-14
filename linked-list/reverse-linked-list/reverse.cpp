// Created by duongvct on 6/14/26.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev; // new h
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    if (!(cin >> n)) return 0;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ListNode* node = new ListNode(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    ListNode* rev = reverseList(head);

    for (ListNode* p = rev; p != nullptr; p = p->next) {
        cout << p->val;
        if (p->next) cout << ' ';
    }
    cout << '\n';

    return 0;
}
