#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class linkedList{
    private:
        ListNode *head;
        ListNode *tail;
    public:
        linkedList(){
            head = NULL;
            tail = NULL;
        }
        int push(int );
        int pop();
        int display();
};

/* add new node into linked list
 */
int linkedList::push(int val){
    ListNode *newNode  = new ListNode(val);
    if (head == NULL){
        head = newNode;
        tail = head;
        return 0;
    }

    newNode->next = head;
    head = newNode;
    return 1;
}


/* get the head node and get head node out from linked list
 */
int linkedList::pop(){
    if (head == NULL){
        return 0;
    }

    ListNode* delNode = head;
    if (head == tail) {
        head = NULL;
    }
    else {
        head = head->next;
    }
    delete(delNode);

    return 1;
}

/* show linked list data
 */
int linkedList::display()
{
    ListNode *temp = head;
    while (temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
    return 1;
}

int main ()
{
    int arr[] = {1, 2, 3, 4, 3, 2, 7};
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    int i = 0;

    linkedList list; 
    cout << "push: " << endl;
    while (i < size_arr){
        list.push(arr[i]);
        i++;
    }
    list.display();

    cout << "pop: " << endl;
    list.pop();
    list.display();

    return 0;    
}