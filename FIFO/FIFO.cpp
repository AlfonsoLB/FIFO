#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node * p, * n;
    static Node* createNode(T data) {
        Node * node = (Node *) malloc(sizeof(node));
        node->data = data;
        node->p = node->n = NULL;
        return node;
    }
};

template<typename T>
class FIFO {
    // Properties
    Node<T>* first;
    Node<T>* last;
    int sizeQueue;

public:
    // Constructor
    FIFO () {
        first = last = NULL;
        sizeQueue = 0;
    }

    // Methods
    void push(T data);
    //T pop();
};

template <typename T>
void FIFO<T>::push(T data) {
    // Create a new node
    Node<T>* node = Node<T>::createNode(data);

    if (first == NULL) {
        first = last = NULL;
    } else {
        node->n = first;
        first->p = node;
        first = node;
    }

    sizeQueue++;
}

int main () {
    FIFO<int> f;
    cout << "Number five inserted" << endl;
    f.push(5);
}
