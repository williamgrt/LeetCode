#include "list_node.h"

/*
* （1）遍历l1和l2中的每一位数字，将两数相加，并用一个变量addOne标识是否需要进位。直到到达l1的末尾或者l2的末尾。
* （2）
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        
        ListNode *result = new ListNode(0);
        ListNode *currNode = result;
        bool addOne = false;
        while (l1 != nullptr && l2 != nullptr) {
            int first = l1->val;
            int second = l2->val;
            int sum = first + second + addOne;
            addOne = false;
            if (sum >= 10) {
                sum -= 10;
                addOne = true;
            }
            currNode->next = new ListNode(sum);
            currNode = currNode->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        currNode->next = (l1 == nullptr ? l2: l1);
        ListNode *prevNode = currNode;
        if (currNode->next != nullptr) {
            currNode = currNode->next;    
            while (currNode != nullptr && addOne) {
                currNode->val = (currNode->val + addOne) % 10;
                if (currNode->val != 0)
                    addOne = false;
                prevNode = currNode;
                currNode = currNode->next;
            }
        }
        if (addOne) {
            prevNode->next = new ListNode(1);
        }
        
        return result->next;
    }
};