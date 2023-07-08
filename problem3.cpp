#include <iostream>
#include<queue>

using namespace std;

class Stack{
public :
    queue<int> Queue ;

//function returns the top element of the stack
    int top (){
        //check if the queue is empty
        if (Queue.empty()){
            cout << "the stack is empty "<< endl;
        }
         //if it is not empty return the top element
        else {
            return Queue.front();
        }
    }

//function removes the top element of the stack
    void pop(){
        //check if the queue is empty
        if (Queue.empty()){
            cout << "the stack is empty "<< endl;
        }
        //if it is not empty remove the top element
        else{
        Queue.pop();
        }
    }

//function adds an element to the top of the stack.
    void push(int num){

        int Size ;
        //getting size of queue
        Size = Queue.size();
        //adding the required number to the end of queue
        Queue.push(num);

        //removing all the previous elements of the queue and put them after the added element
        //add 4 to 1 2 3 => 1 2 3 4 => 2 3 4 1 => 3 4 1 2 => 4 1 2 3
        for (int i = 0 ; i < Size ; i++){
            //adding the first element in queue in the end
            Queue.push(Queue.front());
            //removing first element
            Queue.pop();
        }
    }


};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.top() << endl ; //5
    s.pop();
    cout << s.top() << endl ;//4
    s.pop();
    s.pop();
    cout << s.top() << endl ; //2


    return 0 ;
}
