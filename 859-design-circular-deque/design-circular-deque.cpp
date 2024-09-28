class MyCircularDeque {

public:
vector<int>q;
int front;
int currsize;


    MyCircularDeque(int k) {
     q=vector<int>(k,-1);
     front=0;
     currsize=0;   
    }
    
    bool insertFront(int value) {
         if(isFull()){
            return false;
         }
         else{
            front=(front-1+q.size())%q.size();

         }
         q[front]=value;
         currsize++;
return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }

        q[(front+currsize)%q.size()]=value;
        currsize++;
        return true;
    }
    
    bool deleteFront() {

        if(isEmpty()){
            return false;
        }
              q[front]=-1;
        front=(front+1)%q.size();
        currsize--;
        return true;
        
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }

        q[(front+currsize-1)%q.size()]=-1;
        currsize--;
        return true;
    }
    
    int getFront() {
        return q[front];
    }
    
    int getRear() {
        return q[(front+currsize-1)%q.size()];
    }
    
    bool isEmpty() {
        return currsize==0;
    }
    
    bool isFull() {
      return currsize==q.size();  
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */