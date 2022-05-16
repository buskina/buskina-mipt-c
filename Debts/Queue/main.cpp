#include <iostream>

using namespace std;
struct Queue {
    int maxsize;
    int* arr;
    int fr = 0;
    int rear = 0;

    void alloc(int new_size) {
        arr = new int[maxsize = new_size];
    }

int peek() {
    return arr[fr];
}

bool isfull() {
    if (fr <= rear) {
        return rear - fr >=  maxsize - 1;
    }
    else {
        return fr - rear <= 1;
    }
}

bool isempty() {
    return fr == rear;
}

void enqueue(int data){
    if (isfull())
        return;
    arr[rear] = data;
    rear++;
    if (rear == maxsize)
        rear = 0;
    return;
}

int dequeue() {
    if (isempty())
        return 0;
    int ans = arr[fr];
    if (fr < maxsize - 1)
        fr++;
    else
        fr = 0;
    return ans;
}

void print(){
    if (isempty()) {
        cout<<"empty";}
    else {
        int i = fr;
        while (i!= rear) {
            cout<<arr[i]<<" ";
            i++;
            if (i == maxsize)
                i = 0;
        }
}
}
};


int main() {
    int n, a;
    cin >> n;
    Queue test;
    test.alloc(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a;
        test.enqueue(a);
    }
    test.print();
    cout<<"dequeue: "<<test.dequeue() << " \n";
    cout<< boolalpha<<test.isempty() << " ";
    test.print();
    return 0;
}
