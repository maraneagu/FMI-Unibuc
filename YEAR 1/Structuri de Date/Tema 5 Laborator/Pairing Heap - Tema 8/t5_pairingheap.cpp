#include <iostream>
#include <cstdlib>
using namespace std;

// NODUL UNUI HEAP
struct HeapNode{

    int key;
    HeapNode *leftChild;
    HeapNode *nextSibling;

    // INITIALIZARE - COPIL,FRATE NULL
    HeapNode():leftChild(NULL),nextSibling(NULL){}

    // CREARE NOU NOD
    HeapNode(int hKey, HeapNode *hLeftChild, HeapNode *hNextSibling):
        key(hKey),leftChild(hLeftChild),nextSibling(hNextSibling){}

    // ADAUGARE COPIL/FRATE UNUI NOD
    void addChild(HeapNode *node) {
        if(leftChild == NULL)leftChild = node;
        else
        {
            node->nextSibling = leftChild;
            leftChild = node;
        }
    }
};

// VERIFICARE RADACINA NULL
bool Empty(HeapNode *node)
{
    return (node == NULL);
}

// MERGE DOUA HEAP-URI
HeapNode *Merge(HeapNode *A, HeapNode *B)
{
    // DACA UNUL ESTE NULL, SE RETURNEAZA CELALALT
    if(A == NULL) return B;
    if(B == NULL) return A;

    // VALOARE MAI MICA DEVINE PARINTELE
    if(A->key < B->key)
    {
        A->addChild(B);
        return A;
    }
    else
    {
        B->addChild(A);
        return B;
    }
}

// RADACINA
int Top(HeapNode *node)
{
    return node->key;
}

// INSERAREA UNUI NOU NOD CU VALOAREA = KEY IN HEAP-UL NODE
HeapNode *Insert(HeapNode *node, int key)
{
    return Merge(node, new HeapNode(key, NULL, NULL));
}

// STERGEREA RADACINII
HeapNode *TwoPassMerge(HeapNode *node) {

    // DACA ESTE NULL/FRATELE ESTE NULL, PRIN ELIMINIARE => NULL
    if(node == NULL || node->nextSibling == NULL)
        return node;
    else
    {
        HeapNode *A, *B, *newNode;
        A = node;
        B = node->nextSibling;
        newNode = node->nextSibling->nextSibling;

        A->nextSibling = NULL;
        B->nextSibling = NULL;

        return Merge(Merge(A, B), TwoPassMerge(newNode));
    }
}

// STERGEREA RADACINII
HeapNode *Delete(HeapNode *node) {
    return TwoPassMerge(node->leftChild);
}

struct PairingHeap {
    HeapNode *root;

    // INITIALIZARE - RADACINA ESTE NULA
    PairingHeap():root(NULL){}

    // VERIFICARE PAIRING HEAP NULL
    bool Empty()
    {
        return ::Empty(root);
    }

    // RADACINA
    int Top()
    {
        return ::Top(root);
    }

    // INSERARE NOD CU VALOAREA = KEY
    void Insert(int key)
    {
        root=::Insert(root, key);
    }

    // STERGERE RADACINA
    void Delete()
    {
        root = ::Delete(root);
    }

    // PAIR HEAP
    void Join(PairingHeap other)
    {
        root = ::Merge(root, other.root);
    }

};
int main()
{
    PairingHeap heap1, heap2;
    heap2.Insert(5);
    heap2.Insert(2);

    heap2.Insert(6);
    heap1.Insert(1);
    heap1.Insert(3);
    heap1.Insert(4);

    heap1.Join(heap2);

    cout << heap1.Top() << endl;
    heap1.Delete();

    cout << heap1.Top() << endl;
    return 0;
}
