#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int maxSize;
    int count;
    int front;
    int rear;
    int *QueueElement;
} queue;

int isIntegerQueueEmpty(queue *q);
int isIntegerQueueFull(queue *q);
int freeIntegerQueue(queue *q);

void initQueue(queue *q, int size) {
    q->maxSize = size + 1;
    q->front = 0;
    q->count =0;
    q->rear = 0;
    q->QueueElement = (int *)malloc(q->maxSize * sizeof(int));
}

void createintegerQueue(queue **q_ptr, int size) {
    if (size <= 0) {
        *q_ptr = NULL;
        return;
    }
    
    *q_ptr = (queue *)malloc(sizeof(queue));
    if (*q_ptr == NULL) {
        return;
    }
    
    initQueue(*q_ptr, size);
    if ((*q_ptr)->QueueElement == NULL) {
        free(*q_ptr);
        *q_ptr = NULL;
    }
}

int enqueueInteger(queue *q, int value) {
    if (q == NULL) {
        return 0;
    }
    
    if (q->count == q->maxSize -1) {
        return 0; 
    }
    
    q->rear = (q->rear + 1) % q->maxSize;
    q->QueueElement[q->rear] = value;
    q->count++;
    return 1;
}

int dequeueInteger(queue *q, int *value) {
    if (q == NULL) {
        return 0;
    }
    
    if (isIntegerQueueEmpty(q)) {
        return 0; 
    }
    
    q->front = (q->front + 1) % q->maxSize;
    *value = q->QueueElement[q->front];
    q->count--;
    return 1;
}

void printQueue(queue *q) {
    if (q == NULL) {
        return;
    }
    
    if (0 == q->count) {
        printf("Queue is empty\n");
        return;
    }
    printf(" max size of queue  %d <-> number of ele in queue %d \n", q->maxSize -1 , q->count);
    int i ;
    for( i = 1; i <= q->count; i++)
    {
        int index = (i + q->front) % q->maxSize;
        printf(" value %d at index %d\n", q->QueueElement[index], index);
    }
    printf("\n");
}

int freeIntegerQueue(queue *q) {
    if (q == NULL) {
        return 0;
    }
    
    if (q->QueueElement != NULL) {
        free(q->QueueElement);
        q->QueueElement = NULL;
    }
    
    free(q);
    return 1;
}

int isIntegerQueueEmpty(queue *q) {
    if (q == NULL) {
        return 1;
    }
    if(0 == q->count)
        return 1;

        else 
        return 0;
}

int isIntegerQueueFull(queue *q) {
    if (q == NULL) {
        return 0;
    }
    if ( q->count == q->maxSize -1)
    return 1;

    return 0;
}

void menuofqueue(queue* q) {
    int choice;
    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue  2. Dequeue  3. Print Queue  4. Check if Queue is Empty  \n \n 5. Check if Queue is Full  6. Free Queue and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (enqueueInteger(q, value)) {
                    printf("Enqueued %d successfully.\n", value);
                } else {
                    printf("Enqueue failed.\n");
                }
                break;
            }
            case 2: {
                int value;
                if (dequeueInteger(q, &value)) {
                    printf("Dequeued value: %d\n", value);
                } else {
                    printf("Dequeue failed.\n");
                }
                break;
            }
            case 3:
                printQueue(q);
                break;
            case 4:
                if (isIntegerQueueEmpty(q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                if (isIntegerQueueFull(q)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 6:
                freeIntegerQueue(q);
                printf("Queue freed. Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
}

int main() {
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    queue *q = NULL;
    createintegerQueue(&q, size);
    
    if (q == NULL) {
        printf("Failed to create queue. Exiting.\n");
        return 1;
    }
    
    menuofqueue(q);
    
    return 0;
}