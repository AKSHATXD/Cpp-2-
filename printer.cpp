#include <iostream> 
#include<stdlib.h>
using namespace std; 
  
struct Node { 
    int data; 
    Node* next = NULL; 
}; 
  
struct Queue { 
    Node *front= NULL, *rear = NULL;
	void enQueue(int x) 
    { 

        Node* temp = new Node;
        temp->data = x;
        if (rear == NULL) { 
            front = rear = temp; 
            return; 
        } 
        rear->next = temp; 
        rear = temp; 
    } 

    void deQueue() 
    { 
        if (front == NULL) 
            return; 
  
        Node* temp = front; 
        front = front->next; 
        if (front == NULL) 
            rear = NULL; 
  
    	free(temp); 
    } 
};

void display(Node * p)
{
    
    while(p!=NULL)
    {
        printf("Printing the document of person with user id = %d\n",p->data);
        p=p->next;
    }
}

int main() 
{ 
  
    Queue q; 
    int x;
	int choice;
    do{
        printf("enter your id (integer)\n");
        scanf("%d",&x);
        q.enQueue(x);
        printf("\nDo you want to use the printer?1: YES \n");
        scanf("%d",&choice);
    }while(1==choice);
    
    display((q.front));
}

