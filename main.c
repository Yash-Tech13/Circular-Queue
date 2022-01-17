#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull() 
{
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) 
    return 1;

  return 0;
}

int isEmpty() 
{
  if (front == -1) 
    return 1;
  
  return 0;
}

void enQueue(int element) 
{
  if (isFull())
    printf("\n Queue is full!! \n");
  else 
  {
    if (front == -1) 
      front = 0;
    
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d\n", element);
  }
}

int deQueue() 
{
  int element;
  if (isEmpty()) 
  {
    printf("\n Queue is empty !! \n");
    return (-1);
  } 
  else 
  {
    element = items[front];
    if (front == rear) 
    {
      front = -1;
      rear = -1;
    } 
    else 
    {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

void display() 
{
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else 
  {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) 
    {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main()  
{  
  int choice,x;
      
  do
  {
    printf("Menu\n");  
    printf("Press 1: Insert an element\n");  
    printf("Press 2: Delete an element\n");  
    printf("Press 3: Display the element\n");
    printf("Press 4: Exit\n");  
    printf("Enter your choice: ");  
    scanf("%d", &choice);  
      
    switch(choice)  
    {      
      case 1:
      printf("Enter the element which is to be inserted: ");  
      scanf("%d", &x);  
      enQueue(x);  
      break;

      case 2:  
      deQueue();  
      break;

      case 3:  
      display();
      break;

      case 4:
      printf("Good Bye!!\n");
      break;

      default:
      printf("Enter valid number.\n");  
    }
  }while(choice != 4);  
  return 0;  
}
