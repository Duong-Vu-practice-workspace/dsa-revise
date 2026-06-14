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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    ListNode* pointerA;
    ListNode* pointerB;
    pointerA = headA;
    pointerB = headB;
    while (pointerA != pointerB)
    {
        if (pointerA != nullptr)
        {
            pointerA = pointerA->next;
        } else
        {
            pointerA = headB;
        }

        if (pointerB != nullptr)
        {
            pointerB = pointerB->next;
        } else
        {
            pointerB = headA;
        }
    }
    return pointerA;
}
    int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, intersectIdx;
        cin >> a >> b >> intersectIdx;
        // intersectIdx: -1 means no intersection, 0-based index in list A where B starts sharing
        
        vector<ListNode*> nodesA;
        ListNode* nodeA = nullptr;
        ListNode* tailA = nullptr;

        for (int i = 0; i < a; ++i) {
            int x; cin >> x;
            ListNode* node = new ListNode(x);
            if (!nodeA)
            {
                nodeA = node;
                tailA = node;
            }
            else
            {
                tailA->next = node;
                tailA = tailA->next;
            }
            nodesA.push_back(node);
        }

        ListNode* nodeB = nullptr;
        ListNode* tailB = nullptr;
        for (int i = 0; i < b; ++i) {
            int x; cin >> x;
            ListNode* node = new ListNode(x);
            if (!nodeB)
            {
                nodeB = node;
                tailB = node;
            }
            else
            {
                tailB->next = node;
                tailB = tailB->next;
            }
        }

        // Create intersection: connect tail of B to a node in A
        if (intersectIdx >= 0 && intersectIdx < nodesA.size() && tailB != nullptr) {
            tailB->next = nodesA[intersectIdx];
        }

        ListNode* rev = getIntersectionNode(nodeA, nodeB);

        if (rev != nullptr)
        {
            cout << rev->val;
        } else
        {
            cout << "-1";
        }
        cout << '\n';
    }


    return 0;
}
