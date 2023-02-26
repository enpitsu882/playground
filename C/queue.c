/* queue */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long ELEM;
#define QUEUE_SIZE 100

ELEM queue[QUEUE_SIZE];
int front, rear;

#define next(a) (((a) + 1) % QUEUE_SIZE)

/* error */
void error(char *s){
    fprintf(stderr, s);
    exit(1);
}

/* init */
void init(){
    front = rear = 0;
}

/* enqueue */
void enqueue(ELEM x){
    if (next(rear) == front)
        error("queue overflow\n");
    queue[rear] = x;
    rear = next(rear);
}

/* dequeue */
ELEM dequeue(){
    ELEM x;

    if (front == rear)
        error("queue underflow\n");
    x = queue[front];
    front = next(front);
    return x;
}

/* empty */
int empty(){
    return front == rear;
}