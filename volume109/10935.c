#include <stdio.h>
#define QUEUE_SIZE 52
typedef struct {
    int a[QUEUE_SIZE];
    int front;
    int back;
    int count;
} Queue;

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->back = 0;
    queue->count = 0;
}

int empty(Queue *queue) {
    return queue->count == 0;
}

int count(Queue *queue) {
    return queue->count;
}

void push(Queue *queue, int value) {
    if(queue->front != queue->back || empty(queue)) {
        queue->a[queue->back] = value;
        queue->back = (queue->back + 1) % QUEUE_SIZE;
        queue->count++;
    }
}

int pop(Queue *queue) {
    if(!empty(queue)) {
        int value = queue->a[queue->front];
        queue->front = (queue->front + 1) % QUEUE_SIZE;
        queue->count -= 1;
        return value;
    }
    return -1;
}

int main() {
    int n, i, card[52], t, flag;
    Queue queue;
    while(scanf(" %d", &n) != EOF) {
        if(!n) {
            break;
        }
        initQueue(&queue);
        for(i = 1; i <= n; i++) {
            push(&queue, i);
        }
        flag = 0;
        printf("Discarded cards:");
        while(count(&queue) > 1) {
            if(flag) {
                printf(",");
            }
            printf(" %d", pop(&queue));
            t = pop(&queue);
            push(&queue, t);
            flag = 1;
        }
        printf("\nRemaining card: %d\n", pop(&queue));
    }
    return 0;
}