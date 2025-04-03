class MyCircularQueue {
private:
    int size = 0;
    ListNode* head;
    ListNode* tail;
    int limit = 0;
public:
    MyCircularQueue(int k) {
        limit = k;
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        
        ListNode* curr = new ListNode(value);

        if(isEmpty()){
            head = tail = curr;
            tail->next = head;
        }
        else{
            tail->next = curr;
            tail = curr;
            tail->next = head;
        }

        size++;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }

        if(head == tail){
            delete head;
            head = tail = nullptr;
        }
        else{
            head = head->next;
            tail->next = head;
        }
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }

        return head->val;
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return tail->val;
    }
    
    bool isEmpty() {
        return size ==0;
    }
    
    bool isFull() {
        return size == limit;
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