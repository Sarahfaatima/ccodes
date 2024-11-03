#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define ELEMENT_SIZE 10 // Maximum size of each element (string)

char circular_queue[MAX][ELEMENT_SIZE];
int front = -1, rear = -1;

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return (rear + 1) % MAX == front;
}

void insertElement(char element[])
{
    if (isFull())
    {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    strcpy(circular_queue[rear], element);
}

void deleteElement()
{
    if (isEmpty())
    {
        printf("Circular Queue Underflow\n");
        return;
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%s ", circular_queue[i]);
        }
    }
    else
    {
        for (int i = front; i < MAX; i++)
        {
            printf("%s ", circular_queue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%s ", circular_queue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice;
    char element[ELEMENT_SIZE];
    do
    {
        printf("\n---- Circular Queue Menu ----\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Circular Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to be inserted: ");
            scanf("%s", element); // Read a string input
            insertElement(element);
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}