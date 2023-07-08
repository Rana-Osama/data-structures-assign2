# Data-structures-assign2

Problem 2:- Queue

In this problem, you should develop a queue class similar to that provided in the
C++ STL. You cannot use any of the C++ STL classes in this problem.
There are n people in a line queuing to buy tickets, where the 0th person is at the
front of the line and the (n - 1)th person is at the back of the line.
You are given a 0-indexed integer array of tickets of length n where the number of
tickets that the ith person would like to buy is tickets[i].
Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket
at a time and has to go back to the end of the line (which happens instantaneously)
in order to buy more tickets. If a person does not have any tickets left to buy, the
person will leave the line.
Return the time taken for the person at position k (0-indexed) to finish buying
tickets.

Example 1:

● Input: tickets = [2,3,2], k = 2

● Output: 6

● Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [1,
2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes
[0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 =
6 seconds.
   
Example 2:

● Input: tickets = [5,1,1,1], k = 0

● Output: 8

● Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [4,
0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at position 0 has successfully bought 5 tickets and it took 4 + 1 +
1 + 1 + 1 = 8 seconds.

  #############################################################################################

Problem 3:- Queue

In this problem, you must use your queue. Reimplement part of the stack data
structure using only one queue as an underlying data structure. Reimplement the
class for ‘int’ data type only and with the following functions only:

int top() – returns the top element. 

void pop() – removes the top element. 

void push(int value) – adds an element to the top of the stack. 

Write a main function to test .


  #############################################################################################

Problem 10:- Tree

Given a binary search tree and an integer k, our task is to implement a method to
find out the sum of all the elements which is less or equal to the kth smallest
element in the binary search tree.

For example, for given below binary search tree and k=3:

                         54
                      /      \ 
                     51       75
                   /   \     /   \
                 49    52   74   85
Explanation: so here in above example k th smallest element is 52 and sum of all
the elements which is less or equal to 52 is 152.

- Implement your algorithm as a function
  
- Calculating the sum

- Write five test cases for your application and run them correctly 
