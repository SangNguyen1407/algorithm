/* Linked list
 *  This is a single-linked list.
 *  The single-linked list contains nodes that only pointer to the next node.
 *  The node has two parts: the data part and the next part. The data part 
 *  contains the stored data and the next part provides the address of the next
 *  node.
 *  The first node of a linked list is called the head, and the last node of a 
 *  linked list is called the tail.
 */
#include<iostream>
#include<string>

using namespace std;

/* List node contains
 *   int val
 *   the next node
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int printListNode(ListNode *node)
{
    ListNode *temp = node;
    while (temp != NULL){
        cout << temp->val << "   ";
        temp = temp->next;
    }
    return 0;
}

/* add new Node into exsisted linked list node
 * input: 
 *       ListNode*   the header of the linked list
 *       int         data in Node
 * output:
 *       ListNode*
 *       return      1: success
 *                   0: list node is null
 */
int addNode(ListNode *lNode, int val){
    if (lNode){
        return 0;
    }
    // create new node 
    ListNode *node = new ListNode(val);
    // node -> next (lNode) 
    // the head of list Node is new node
    node->next = lNode;
    lNode = node;

    return 1;
}

/* add new Node into exsisted linked list node
 * input: 
 *       ListNode*   the header of the linked list
 *       int         data in Node
 * output:
 *       ListNode*
 *       return      1: success
 *                   0: list node is null
 */
int addNode(ListNode *lNode, int *arr, int len){
    if (arr == NULL){
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
    temp->next = NULL;
    cout << endl;
    return 1;
}

/* insert new node into link list with position 
 * input: 
 *       ListNode*   the header of the linked list
 *       int         data in Node
 *       int         Node of position in linked List
 * output:
 *       ListNode*
 *       return      1: success
 *                   0: list node is null
 */
int insertNode(ListNode *lNode, int pos, int num){
    if (!lNode){
        return 0;
    }

    // increase number and stop it when i equal position
    int i = 0; 
    // create new node with input data
    // using temp Node for searching  position instead of
    // using ListNode which contains LinkedList header
    ListNode *temp = lNode;
    ListNode *node = new ListNode(num);

    // while function working util finding position node
    while (1){
        // with the last node, add new node and break
        if (temp == NULL){
            temp = node;
            break;
        }
        // add new node into ListNode
        // temp -> newNode -> temp->next
        if (i == pos){
            ListNode *temp1  = temp->next;
            temp->next = node;
            node->next = temp1;
            break;
        }
        temp = temp->next;
        i++;
    }

    return 1;
}

/* delete node into link list with position 
 * input: 
 *       ListNode*   the header of the linked list
 *       int         data in Node
 *       int         Node of position in linked List
 * output:
 *       ListNode*
 *       return      1: success
 *                   0: list node is null
 */
int deleteNode(ListNode *lNode, int pos){
    if (!lNode){
        return 0;
    }

    // increase number and stop it when i equal position
    int i = 0; 
    // create new node with input data
    // using temp Node for searching  position instead of
    // using ListNode which contains LinkedList header
    ListNode *beforeDelNode = lNode;
    // the first and the tail node is a node
    if (beforeDelNode == NULL || beforeDelNode->next == NULL){
        delete(beforeDelNode);
    }

    // while function working util finding position node
    while (1){
        // next node is delete node postion
        // beforeDelNode -> (delNode) -> beforeDelNode->next->next
        if (i+1 == pos){
            // the next DelNode  is null
            if (beforeDelNode->next->next == NULL){
                delete(beforeDelNode->next);
                beforeDelNode->next = NULL;
            }
            else{
                // the next DelNode  is not null
                ListNode *delNode = beforeDelNode->next;
                beforeDelNode->next = beforeDelNode->next->next;
                delete(delNode);
            }
            break;
        }
        beforeDelNode = beforeDelNode->next;
        i++;
    }

    return 1;
}

int main ()
{
    int arr[] = {1, 2, 3, 4, 3, 2, 1};
    ListNode *node;

    int len = sizeof(arr)/sizeof(arr[0]); 
    
    // create list node into linked list
    addNode(node, arr, len);
    cout << "add list node:" << endl;
    printListNode(node);
    cout << endl;
    
    // insert new node into linked list
    insertNode(node, 6, 7);
    cout << "insert node(3) in pos 5 list node:" << endl;
    printListNode(node);
    cout << endl;

    // insert new node into linked list
    deleteNode(node, 5);
    cout << "delete node5 in list node:" << endl;
    printListNode(node);
    cout << endl;

    return 0;    
}
