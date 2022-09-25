class MyCircularQueue {
public:
    int front=0,rear=0;
    int q[100000];
    int n;
    MyCircularQueue(int k) {
        n=k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        q[rear%n]=value;
        rear++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front++;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return q[front%n];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return q[(rear-1)%n];
    }
    
    bool isEmpty() {
        return front==rear;
    }
    
    bool isFull() {
        int sz=rear-front;
        return sz==n;
    }
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */