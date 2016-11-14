#include<stdio.h>  
#include<malloc.h>        //������malloc����  
/* 
 *ѭ�����У�������ʵ�� 
 */  
//���нṹ�嶨��  
typedef struct Queue  
{  
    int * pBase;    //���ڶ�̬�����ڴ�,pBase����������׵�ַ  
    int front;      //ָ��ͷ���  
    int rear;       //ָ�����һ��Ԫ�ص���һ���  
} QUEUE;  
//��������  
void initQueue(QUEUE * pQueue);                 //���г�ʼ���ĺ���  
bool isEmpty(QUEUE * pQueue);                   //�ж϶����Ƿ�Ϊ�յĺ���  
bool isFull(QUEUE * pQueue);                    //�ж϶����Ƿ����ĺ���  
bool enQueue(QUEUE * pQueue, int value);        //��ӵĺ���   
bool outQueue(QUEUE * pQueue, int * pValue);    //���ӵĺ���,ͬʱ������ӵ�Ԫ��  
void traverseQueue(QUEUE * pQueue);             //�������еĺ���  
/* 
 *������ 
 */  
int main(void)  
{  
    int value;          //���ڱ�����ӵ�Ԫ��  
    //�������ж���  
    QUEUE queue;  
    //���ó�ʼ�����еĺ���  
    initQueue(&queue);  
    //���ó��Ӻ���  
    enQueue(&queue, 1);  
    enQueue(&queue, 2);  
    enQueue(&queue, 3);  
    enQueue(&queue, 4);  
    enQueue(&queue, 5);  
    enQueue(&queue, 6);  
    enQueue(&queue, 7);  
    enQueue(&queue, 8);  
    //���ñ������еĺ���  
    traverseQueue(&queue);  
    //���ó��Ӻ���  
    if(outQueue(&queue, &value))  
    {  
        printf("����һ�Σ�Ԫ��Ϊ��%d\n", value);  
    }  
    traverseQueue(&queue);  
    if(outQueue(&queue, &value))  
    {  
        printf("����һ�Σ�Ԫ��Ϊ��%d\n", value);  
    }  
    traverseQueue(&queue);  
    getchar();  
    return 0;  
}  
/* 
 *��ʼ��������ʵ�� 
 */  
void initQueue(QUEUE * pQueue)  
{  
    //�����ڴ�  
    pQueue->pBase = (int *)malloc(sizeof(int) * 6);          //����6��int����ռ�Ŀռ�  
    pQueue->front = 0;       //��ʼ��ʱ��front��rearֵ��Ϊ0  
    pQueue->rear = 0;  
    return;  
}  
/* 
 *��Ӻ�����ʵ�� 
 */  
bool enQueue(QUEUE * pQueue, int value)  
{  
    if(isFull(pQueue))  
    {  
        printf("��������,�����ٲ���Ԫ����!\n");  
        return false;  
    }  
    else  
    {  
        //������������Ԫ��  
        pQueue->pBase[pQueue->rear] = value;  
        //��rear�����µĺ��ʵ�ֵ  
        pQueue->rear = (pQueue->rear+1) % 6;  
        return true;  
    }  
}  
/* 
 *���Ӻ�����ʵ�� 
 */  
bool outQueue(QUEUE * pQueue, int * pValue)  
{  
    //�������Ϊ��,�򷵻�false  
    if(isEmpty(pQueue))  
    {  
        printf("����Ϊ�գ�����ʧ��!\n");  
        return false;  
    }  
    else  
    {  
        *pValue = pQueue->pBase[pQueue->front];       //�Ƚ��ȳ�  
        pQueue->front = (pQueue->front+1) % 6;      //�Ƶ���һλ��  
        return true;  
    }  
}  
/* 
 *�������еĺ���ʵ�� 
 */  
void traverseQueue(QUEUE * pQueue)  
{  
    int i = pQueue->front;           //��ͷ��ʼ����  
    printf("�������У�\n");  
    while(i != pQueue->rear)     //���û�е���rearλ�ã���ѭ��  
    {  
        printf("%d  ", pQueue->pBase[i]);  
        i = (i+1) % 6;              //�Ƶ���һλ��  
    }     
    printf("\n");  
    return;  
}  
/* 
 *�ж϶����Ƿ����ĺ�����ʵ�� 
 */  
bool isFull(QUEUE * pQueue)  
{  
    if((pQueue->rear+1) % 6 == pQueue->front)     //������  
        return true;  
    else  
        return false;  
}  
/* 
 *�ж϶����Ƿ�Ϊ�պ�����ʵ�� 
 */  
bool isEmpty(QUEUE * pQueue)  
{  
    if(pQueue->front == pQueue->rear)  
        return true;  
    else  
        return false;  
}
