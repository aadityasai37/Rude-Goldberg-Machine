// Binary Tree in C++
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

// ! -------------------------------QUEUE PART-------------------------------

struct Node
{
    string fname;
    string sname;
    int age;
    int dob;
    Node *next;
};

Node *top = NULL;
Node *start = NULL;
Node *front = NULL;
Node *rear = NULL;

Node *Create_LL(string fname, string sname, int age, int dob)
{
    Node *temp;
    temp = new Node(); //! Creates a single node.
    temp->fname = fname;
    temp->sname = sname;
    temp->age = age;
    temp->dob = dob;
    temp->next = NULL;

    return temp;
}

void insert_LL(string fname, string sname, int age, int dob)
{

    Node *temp, *t;
    temp = Create_LL(fname, sname, age, dob);

    if (start == NULL) //! Insert the single node.
    {
        start = temp;
        start->next = NULL;
    }

    else
    {
        t = start;
        while (t->next != NULL)
        {
            t = t->next;
        }

        t->next = temp;
    }
}
void traverse_LL(Node *np)
{
    cout << "\n \n Your Linked List is : \n \n ";

    while (np != NULL) //! Traverse Linked List function.
    {
        cout << np->fname << " " << np->sname << " " << np->age << " " << np->dob << " -> ";
        np = np->next;
    }
    cout << "NULL";
    cout << "\n";
    cout << "\n";
}

void Insert(string fname, string sname, int age, int dob)
{
    Node *temp;

    temp = Create_LL(fname, sname, age, dob);

    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
    }
    else
    {

        rear->next = temp;
        rear = temp;
    }
}
Node *Dequeue()
{
    Node *temp;
    Node *temp1;
    temp = front;
    if (front == NULL)
    {
        cout << "Underflow" << endl; //! Dequeue function.
        exit;
    }
    else if (front == rear)
    {
        return front;
        front = rear = NULL;
    }
    else
    {
        temp = front;
        front = front->next;

        return temp;
        free(temp);
    }
    return temp;
}

void Display()
{
    Node *temp;
    temp = front;
    if ((front == NULL) && (rear == NULL))
    {
        cout << "Queue is empty" << endl; //! Display queue function.
    }
    cout << "Queue elements are: " << endl;
    while (temp != NULL)
    {
        cout << temp->fname << " " << temp->sname << " " << temp->age << " " << temp->dob << " "
             << "--->>";

        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

//!----------------------STACK AND QUEUE-------------------------
void Stack_Push(string fname, string sname, int age, int dob)
{
    Node *temp;
    Node *var;
    temp = Create_LL(fname, sname, age, dob);

    temp->next = top;
    top = temp;
}

void Stack_display()
{
    Node *temp;
    temp = top;
    if (top == NULL)
    {
        cout << "\nStack Underflow\n"; //! Satck Functions
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->fname << " " << temp->sname << " " << temp->age << " " << temp->dob << " "
                 << "--->>";

            temp = temp->next;
        }
        cout << "NULL";
    }
}

//!---------------------BINARY TREE FORMATION------------------------
struct node
{

    string fname;
    string sname;
    int age;
    int dob;
    node *left;
    node *right;
};
node *create()
{
    Node *hello;
    int num;
    node *newNode;
    newNode = new node();
    cout << "\nEnter choice => 1 for Insertion OR -1 for no node \n";
    cin >> num;
    if (num == -1)
    {
        return 0;
    }
    hello = Dequeue();
    newNode->fname = hello->fname;
    newNode->sname = hello->sname;
    newNode->age = hello->age;
    newNode->dob = hello->dob;

    cout << "\nEnter left child\n";
    newNode->left = create();

    cout << "\nEnter right child\n";
    newNode->right = create();

    return newNode;
}

// Traverse Preorder
void traversePreOrder(struct node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->fname << " " << temp->sname << " " << temp->age << " " << temp->dob << " " << endl;

        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}

// Traverse Inorder
void traverseInOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traverseInOrder(temp->left);
        insert_LL(temp->fname, temp->sname, temp->age, temp->dob);
        traverseInOrder(temp->right);
    }
}

// Traverse Postorder
void traversePostOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << " " << temp->fname << " " << temp->sname << " " << temp->age << " " << temp->dob << " "
             << "-->>";
    }
}

//!------------------------------QUICKSORT----------------------
void display(Node **head)
{

    Node *tem = *head;

    while (tem != NULL)
    {

        if (tem->next != NULL)
            cout << tem->fname << " " << tem->sname << " " << tem->age << " " << tem->dob << " ->";
        else
            cout << tem->fname << " " << tem->sname << " " << tem->age << " " << tem->dob;

        tem = tem->next;
    }

    cout << endl;
}
Node *getTail(Node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;

    return cur;
}

Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (cur->age < pivot->age)
        {

            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {

            if (prev)
                prev->next = cur->next;

            Node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

Node *quickSortRecur(Node *head, Node *end)
{

    if (!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;

    Node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {

        Node *tmp = newHead;

        while (tmp->next != pivot)
            tmp = tmp->next;

        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

void option()
{
}

int main()
{
    system("clear");

    cout << "Press enter to read the contents from the text file......" << endl;
    fflush(stdin);
    getchar();

    ifstream inFile;
    inFile.open("abc.txt");

    cout << "Press enter to display the contents from the queue......" << endl;
    fflush(stdin);
    getchar();

    string fname, sname;
    int age, dob;
    if (inFile.is_open())
    {
        while (inFile >> fname >> sname >> age >> dob)
        {

            Insert(fname, sname, age, dob);
            Stack_Push(fname, sname, age, dob);
        }
    }
    inFile.close();
    Display();

    cout << endl;

    cout << "Press enter to display elements in Queue in Reverse Order......" << endl;
    fflush(stdin);
    getchar();
    cout << endl;
    Stack_display();
    cout << endl;

    node *root;

    cout << endl;

    cout << "Press enter for insertion of elements in Binary Tree......" << endl;
    fflush(stdin);
    getchar();

    root = create();

    cout << "\nPress Enter to print PreOrder.....\n";
    fflush(stdin);
    getchar();

    traversePreOrder(root);

    cout << "\nPress Enter to continue.....\n";
    fflush(stdin);
    getchar();

    cout << "\nPostorder traversal: ";
    traversePostOrder(root);
    cout << "NULL" << endl
         << endl;

    cout << "Press enter to display Inorder Linked List ......" << endl;
    fflush(stdin);
    getchar();

    cout << endl;
    cout << endl;

    cout << "\nInorder LInked List traversal: ";
    traverseInOrder(root);
    traverse_LL(start);

    cout << "\nPress Enter to see the Sorted List.....\n";
    fflush(stdin);
    getchar();
    quickSort(&start);
    display(&start);

    int option;

    cout << "\nDo you want to add stuff? Press 1 for yes\n";
    cin >> option;
    if (option == 1)
    {
        cout << "\nEnter first name?\n";
        fflush(stdin);
        getline(cin, fname);
        cout << "\nEnter sur name?\n";
        fflush(stdin);
        getline(cin, sname);
        cout << "\nEnter age?\n";
        cin >> age;
        cout << "\nEnter Date Of Birth?\n";
        cin >> age;

        Insert(fname, sname, age, dob);
        Display();
    }
    return 0;
}