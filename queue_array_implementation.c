#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;//front element
    int r;//rear element
    int *arr;
};

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;    }
        else {
            return 0;
        }

}

int isEmpty(struct queue *q){
    if(q->r==q->f){
    return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){//q is pointer and is accessed through ->
    if(isFull(q))
 printf("Queue is full...");
 else {
    q->r++;
  q->arr[q->r]=val;
 }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q))
    printf("queue is empty");
    else {
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}


int main()
{
  struct queue q;
  q.size =100;
  q.f =q.r=-1;//structure is accesses through .
  q.arr=(int*)malloc(q.size*sizeof(int));

  //enque elements
  enqueue(&q, 4);//&q bcz its pointer ->taking its address
  enqueue(&q, 2);
printf("dequening elements %d", dequeue(&q));

}