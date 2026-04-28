class MyCircularQueue {
    int *arr;
    int size;
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        this->size = k;
        arr = new int[size];
        rear = front = -1;
    }
    
    bool enQueue(int value) {
        if( front == (rear+1)%size ) return false;
        else{
            rear = (rear+1)%size ;
            arr[rear] = value;
            if(front==-1) front = 0;
        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        else{

            if(front==rear) {
                front = rear = -1;
            }
            else{
                front = (front+1)%size ;
            }
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return rear==-1;
    }
    
    bool isFull() {
        return front == (rear+1)%size;
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