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
    T pop();
};

template <typename T>
void FIFO<T>::push(T data) {
    // Create a new node
    Node<T>* node = Node<T>::createNode(data);

    if (first == NULL) {
        first = last = node;
    } else {
        node->n = first;
        first->p = node;
        first = node;
    }

    sizeQueue++;
}

template <typename T>
T FIFO<T>::pop() {
    if (first == NULL) {
        cout << "FIFO is empty" << endl;
        return NULL;
    } else {
        Node<T>* temp = last;
        T data = last->data;
        last = last->p;

        if (last == NULL)
            first = NULL;
        else
            last->n = NULL;

        free(temp);
        sizeQueue--;

        return data;
    }
}

int main () {
    FIFO<int> f;
    cout << "Number 5 inserted" << endl;
    f.push(5);
    cout << "Number 6 inserted" << endl;
    f.push(6);
    cout << "Number 7 inserted" << endl;
    f.push(7);
    cout << "Number 8 inserted" << endl;
    f.push(8);

    cout << "Number " << f.pop() << " extracted" << endl;
    cout << "Number " << f.pop() << " extracted" << endl;
    cout << "Number " << f.pop() << " extracted" << endl;

    cout << "Number 9 inserted" << endl;
    f.push(9);
    cout << "Number 10 inserted" << endl;
    f.push(10);


    cout << "Number " << f.pop() << " extracted" << endl;
    cout << "Number " << f.pop() << " extracted" << endl;
    cout << "Number " << f.pop() << " extracted" << endl;
    cout << "Number " << f.pop() << " extracted" << endl;
}
