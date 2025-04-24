#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int num)
{
    if (rear < MAX - 1)
    {
        rear++;
        queue[rear] = num;
    }
    else
        printf("Queue is full\n");
}

int firstNonRepeating()
{
    for (int i = front; i <= rear; i++)
    {
        int count = 0;
        for (int j = front; j <= rear; j++)
        {
            if (queue[i] == queue[j])
                count++;
        }
        if (count == 1)
            return queue[i];
    }
    return -1;
}

int main()
{
    enqueue(4);
    enqueue(5);
    enqueue(4);
    enqueue(7);
    enqueue(5);
    enqueue(8);

    int result = firstNonRepeating();
    if (result != -1)
        printf("The first non-repeating number in the queue is: %d\n", result);
    else
        printf("No non-repeating number found in the queue\n");
}
