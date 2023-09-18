/**
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         // define parameter
         ListNode *l3 = nullptr;
         ListNode **node = &l3;
         int sum = 0;
         int odd = 0;
         
         // Handle
         while (l1 != nullptr || l2 != nullptr)
         {
             if(l1 != nullptr)
             {
                 sum += l1->val;
                 l1   = l1->next;
             }
             
             if(l2 != nullptr)
             {
                 sum += l2->val;
                 l2   = l2->next;
             }
             
             (*node) = new ListNode(sum%10);
             sum = sum / 10; // (sum > 10) -> next_node +1
             node = &((*node)->next);
         }
         
         if (sum)
         {
             (*node) = new ListNode(sum);
              node = &((*node)->next);
         }
         
         return l3;
    }

    int addNode(ListNode *lNode, int *arr, int len){
        if (arr == nullptr){
            return 0;
        }

        // the first node
        if (!lNode){
            ListNode *node = new ListNode(arr[0]);
            lNode = node;
        }
        else{
            lNode->val = arr[0];
        }

        // add node 
        ListNode *temp = lNode;
        for (int i = 1; i < len; i++){
            ListNode *node = new ListNode(arr[i]);
            temp->next = node;
            temp = temp->next;
        }
        // the last node
        temp->next = nullptr;


        return 1;
    }

    int printListNode(ListNode *node){
        ListNode *temp = node;
        while (temp != NULL){
            cout << temp->val << "   ";
            temp = temp->next;
        }
        return 0;
    }

};

int main (){
    Solution s;
    ListNode *l1 = (ListNode*) malloc(sizeof( ListNode* ));
    ListNode *l2 = (ListNode*) malloc(sizeof( ListNode* ));
    ListNode *l3 = (ListNode*) malloc(sizeof( ListNode* ));
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 7};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    s.addNode( l1, arr1, size1 );
    cout << "l1 : ";
    s.printListNode( l1 );
    cout << endl;
    s.addNode( l2, arr2, size2 );
    cout << "l2 : ";
    s.printListNode( l2 );
    cout << endl;
    
    l3 = s.addTwoNumbers(l1, l2);
    cout << "sum: ";
    s.printListNode( l3 );
    cout << endl;

}