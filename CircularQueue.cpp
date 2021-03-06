/* 
Operations to be performed in the Queue are : 
Enqueue()
Dequeue()
IsEmpty()
IsFull()
count()
*/

#include<iostream>

using namespace std;

class CircularQueue
{
    private:
        int front;
        int rear;
        int arr[5];
        int ItemCount;
    public:
        CircularQueue()
        {
            front = -1;
            rear = -1;
            ItemCount = 0;
            for(int i = 0;i<5;i++)
            {
                arr[i] = 0;
            }
        }
        bool isEmpty()
        {
            if(front==-1 && rear==-1)
                return true;
            else
            {
                return false;
            }
        }
        bool isFull()
        {
            if((rear + 1)%5 == front)
                return true;
            else 
             return false;
        }
        void enqueue(int val)
        {
            if (isFull())
            {
                cout<<"The queue is full!"<<endl;
                return;
            }
            else if (isEmpty())
            {
                rear = 0;
                front = 0;
            }
            else
            {
                rear = (rear+1)%5;
            }
            arr[rear] = val;
            ItemCount++;
        }
        int dequeue()
        {
            int x;
            if(isEmpty())
            {
                cout<<"Queue is empty!"<<endl;
                return x;
            }
            else if (front == rear)
            {
                x = arr[front];
                arr[front] = 0;
                front = -1;
                rear = -1;
                ItemCount--;
                return x;
            }
            else
            {
                x = arr[front];
                arr[front] = 0;
                front = (front+1)%5;
                ItemCount--;
                return x;
            }
        }
        int count()
        {
            return ItemCount;
        }
        void display()
        {
            cout<<"All the values in the queue are : "<<endl;
            for (int i=0;i<5;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
};

int main()
{
  CircularQueue q1;
  int value, option;
 
  do {
    cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;
 
    cin >> option;
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
      cin >> value;
      q1.enqueue(value);
      break;
    case 2:
      cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
      break;
    case 3:
      if (q1.isEmpty())
        cout << "Queue is Empty" << endl;
      else
        cout << "Queue is not Empty" << endl;
      break;
    case 4:
      if (q1.isFull())
        cout << "Queue is Full" << endl;
      else
        cout << "Queue is not Full" << endl;
      break;
    case 5:
      cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
      break;
    case 6:
      cout << "Display Function Called - " << endl;
      q1.display();
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);

    return 0;
}