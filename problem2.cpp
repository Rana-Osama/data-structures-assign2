#include <iostream>

using namespace std;

//class to store a queue
class Queue
{
private:
    //array to store queue elements
    int *arr;
    //size of the queue
    int Count;
    //maximum capacity of the queue
    int capacity;
    //points to the front element in the queue (if any)
    int Front;
    //points to the last element in the queue
    int End;

public:
    //constructor
    Queue(int Size ){
        arr = new int [Size];
        Count = 0 ;
        capacity = Size ;
        Front = 0 ;
        End = -1 ;
    }
    // destructor (free memory allocated to the queue)
    ~Queue(){
        delete [] arr ;
    }

//function to add elements to the queue
    void enqueue(int element){
        //check if the queue is full
        if (isFull()){
            cout << "The queue is full , element can't be added" << endl;
        }
        else {
        //adding element to the end of the queue
        End = (End + 1) % capacity;
        arr[End] = element;
       // cout << "Element added successfully " << endl ;
        Count++;
        }
    }
//function to remove element from the queue
    int dequeue(){
        //check if the queue is empty
        if (isEmpty()){
            cout << "The queue is empty " << endl ;
        }
        else {
        //removing element from the beginning of the queue
        int element = arr [Front];
        Front = (Front + 1 ) % capacity;
        Count-- ;
       // cout << "The first element is removed " << endl ;

        return element;
        }
    }
//function to return the first element of the queue
    int Front_element (){
        //check if the queue is empty
        if (isEmpty()){
            cout << "The queue is empty " << endl;
        }
        else{
        return arr [Front];
        }
    }
//function to return the last element in the queue
    int Back(){
         //check if the queue is empty
        if (isEmpty()){
            cout << "The queue is empty " << endl;
        }
        else {
        return arr [End];
        }
    }
//function to return the size of the queue
    int Size(){
        return Count ;
    }
//function to check if the queue is empty or not
    bool isEmpty(){
        //returns true if size is zero
        return (Size() == 0);
    }
//function to check if the queue is full or not
    bool isFull(){
        //returns true is size is equal to capacity
        return (Size() == capacity);
    }


};

//function to Return the time taken for the person at position k to finish buying tickets
    int timeTaken(Queue tickets, int k) {
        int total_seconds = 0;
        int temp1 = 0;
        for (int i = 0;; i++) {
            //check if the first element is equal to zero (If a person does not have any tickets left to buy )
            if (tickets.Front_element() == 0) {
                //the person will leave the line
                tickets.dequeue();
                continue;
            }
            // person buy only 1 ticket at a time and go back to the end of the line
            temp1 = tickets.Front_element() - 1;
            tickets.dequeue();
            tickets.enqueue(temp1);
            total_seconds++;
            //check if the front of queue reached the person at position k
            if (i == k) {
                //check if the required person does not have any tickets left to buy
                if (temp1 == 0) {
                    break;
                }
                k = k + (tickets.Size());
            }
        }
        return total_seconds;
}

int main()
{

    // create a queue of capacity 5
    Queue q1(5);
    //adding elements to queue
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(2);
    cout << "The person at position 2 has successfully bought 2 tickets and it took "<<  timeTaken(q1 , 2) << " seconds"<< endl; //output 6
    cout << "---------------------------------------" << endl;

    // create a queue of capacity 4
    Queue q2 (4);
    //adding elements to queue
    q2.enqueue(5);
    q2.enqueue(1);
    q2.enqueue(1);
    q2.enqueue(1);
    cout << "The person at position 0 has successfully bought 5 tickets and it took " << timeTaken(q2 , 0) << " seconds"<< endl; //output 8
    cout << "---------------------------------------" << endl;

     // create a queue of capacity 4
    Queue q3 (4);
    //adding elements to queue
    q3.enqueue(8);
    q3.enqueue(2);
    q3.enqueue(3);
    q3.enqueue(5);
    cout << "The person at position 1 has successfully bought 2 tickets and it took "<<timeTaken(q3 , 1) << " seconds"<< endl; //output 6
    cout << "---------------------------------------" << endl;


     // create a queue of capacity 6
    Queue q4 (6);
    //adding elements to queue
    q4.enqueue(2);
    q4.enqueue(6);
    q4.enqueue(6);
    q4.enqueue(9);
    q4.enqueue(7);
    q4.enqueue(1);
    cout << "The person at position 4 has successfully bought 7 tickets and it took "<< timeTaken(q4 , 4) << " seconds"<< endl; //output 29
    cout << "---------------------------------------" << endl;

    // create a queue of capacity 8
    Queue q5(8);
    //adding elements to queue
    q5.enqueue(5);
    q5.enqueue(3);
    q5.enqueue(6);
    cout << "The person at position 1 has successfully bought 3 tickets and it took "<< timeTaken(q5 , 1) << " seconds"<< endl; //output 8
    cout << "---------------------------------------" << endl;








    return 0;
}

