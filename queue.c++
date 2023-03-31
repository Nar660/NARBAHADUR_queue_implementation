#include <iostream>
using namespace std;

#define MAX_SIZE 10 // Maximum size of the queue

class Queue {
  private:
    int arr[MAX_SIZE];
    int front, rear;

  public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool is_empty() {
        return (front == -1 && rear == -1);
    }

    bool is_full() {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    void enqueue(int x) {
        if (is_full()) {
            cout << "Queue is full." << endl;
            return;
        } else if (is_empty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int get_front() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    void print_queue() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);

    q.print_queue();

    q.enqueue(11);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.print_queue();

    cout << "Front element: " << q.get_front() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.print_queue();

    q.dequeue();

    cout << "Front element: " << q.get_front() << endl;

    return 0;
}
