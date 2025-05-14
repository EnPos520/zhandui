#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
typedef int ElemType;
//栈的顺序结构实现
typedef struct {
    ElemType data[Maxsize];
    int top;
}stack1;
void initStack(stack1 *s) {
    s->top = -1;
}
int isStackEmpty(stack1 *s) {
    if (s->top == -1) {
        printf("stack is empty\n");
        return 0;
    }else {
        return 1;
    }
}
int push(stack1 *s, ElemType x) {
    if (s->top == Maxsize-1) {
        printf("stack is full\n");
        return 0;
    }s->top++;
    s->data[s->top] = x;
    return 1;
}
int pop(stack1 *s, ElemType *x) {
    if (s->top == -1) {
        printf("stack is empty\n");
        return 0;
    }
    *x = s->data[s->top];
    s->top--;
    return 1;
}
int topOfStack(stack1 *s, ElemType *x) {
    if (s->top == -1) {
        printf("stack is empty\n");
        return 0;
    }
    *x = s->data[s->top];
    return 1;
}

//栈的顺序结构初始化-动态分配内存
typedef struct Stack{
    ElemType *data;
    int top;
} Stack;
Stack* InitStack() {
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = (ElemType *)malloc(sizeof(ElemType) * Maxsize);
    p->top = -1;
    return p;
}
//栈的链式结构实现
typedef struct stack {
    ElemType *data;
    struct stack *next;
}stack;
stack* InitStack2() {
    stack *s = (stack *)malloc(sizeof(stack));
    s->next = NULL;
    return s;
}
int isStackEmpty2(stack *s) {
    if(s->next == NULL) {
        printf("stack is empty\n");
        return 1;
    }else {
        return 0;
    }
}
int Push2(stack *s, ElemType x) {
    stack *p = (stack *)malloc(sizeof(stack));
    p->data = x;
    p->next = s->next;
    s->next = p;
    return 1;
}
int pop2(stack *s, ElemType *x) {
    if (s->next == NULL) {
        printf("stack is empty\n");
        return 0;
    }else {
        *x = s->next->data;
        stack *p = s->next;
        s->next = p->next;
        free(p);
        return 1;
    }
}
int topOfStack2(stack *s, ElemType *x) {
    if (s->next == NULL) {
        printf("stack is empty\n");
        return 0;
    }else {
        *x = s->next->data;
        return 1;
    }
}
//顺序结构初始化
typedef int ElemType;
typedef struct Queue {
    int front;
    int tail;
    ElemType data[Maxsize];
}Queue1;
void InitQueue1(Queue1 *q) {
    q->front = 0;
    q->tail = 0;
}
int isQueueEmpty1(Queue1 *q) {
    if (q->front == 0 && q->tail ==0) {
        printf("queue is empty\n");
        return 1;
    }
    return 0;
}
//队列的顺序结构-循环队列
typedef struct {
    int *data;
    int front;
    int tail;
}Queue;
Queue* InitQueue() {
    Queue* p = (Queue*)malloc(sizeof(Queue));
    if (p == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    p->data = (int *)malloc(sizeof(int) * Maxsize);
    if (p->data == NULL) {
        printf("内存分配失败\n");
        free(p);
        return NULL;
    }
    p->front = 0;
    p->tail = 0;
    return p;
}
int isQueueEmpty(Queue *q) {
    if (q->front == q->tail) {
        printf("queue is empty\n");
        return 1;
    }else {
        return 0;
    }
}
//队尾：(q->tail+1)%Maxsize
//满队列：(q->tail+1)%Maxsize==q->front
void initQueue(Queue *q) {
    q->data = (int*)malloc(sizeof(int) * Maxsize);
    q->front = 0;
    q->tail = 0;
}
// 入队操作
int enQueue(Queue *q, int value) {
    if ((q->tail + 1) % Maxsize == q->front) {
        printf("队列已满，无法入队！\n");
        return 0;
    }
    q->data[q->tail] = value;
    q->tail = (q->tail + 1) % Maxsize;
    return 1;
}
// 出队操作
int deQueue(Queue *q, int *value) {
    if (q->front == q->tail) {
        printf("队列已空，无法出队！\n");
        return 0;
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % Maxsize;
    return 1;
}

int main() {
    Queue *q=InitQueue();
    if (!q) {
        printf("队列初始化失败\n");
        return -1;
    }
    int element;
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    if (deQueue(q, &element)) {
        printf("出队元素: %d\n", element);
    }
    return 0;
}
//队列的链式结构
typedef struct QueueNode{
    ElemType data;
    struct QueueNode *next;
}QueueNode;
typedef struct {
    QueueNode *front;
    QueueNode *tail;
}Queue2;
Queue2* InitQueue2() {
    Queue2 *q = (Queue2 *)malloc(sizeof(Queue2));
    if (!q) {
        printf("内存分配失败\n");
        return NULL;
    }
    q->front = NULL;
    q->tail = NULL;
    return q;
}
int enQueue2(Queue2 *q, ElemType x) {
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
        if (!node) return 0;
    node->data = x;
    node->next = NULL;
    if (q->tail == NULL) {
        q->front = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;//更新tail
    }
    return 1;
}
int deQueue2(Queue2 *q, ElemType *val) {
    if (q->front == NULL) {
        printf("队列为空，无法出队\n");
        return 0;
    }
    QueueNode *temp = q->front;
    *val = temp->data;
    q->front = temp->next;
    if (q->front == NULL) {
        q->tail = NULL;
    }
    free(temp);
    return 1;
}
int isQueueEmpty2(Queue2 *q) {
    return q->front == NULL;
}
int main() {
    Queue2 *q = InitQueue2();
    if (!q) return -1;

    enQueue2(q, 10);
    enQueue2(q, 20);
    enQueue2(q, 30);

    ElemType val;
    while (deQueue2(q, &val)) {
        printf("出队元素: %d\n", val);
    }
    free(q);
    return 0;
}
//递归1到n的和
int fun(int n) {
    if(n == 1) {
        return 1;
    }else {
        return fun(n-1)+n;
    }
}
//斐波那契数列第n项值
//非递归方式
int fabinaqie(int n) {
    int sum1=1;
    int sum2=1;
    int result=0;
    for(int i=1;i<=n;i++) {
        result = sum1 + sum2;
        sum1 = sum2;
        sum2 = result;
    }
}
//递归方式
int feibonaqie(int n) {
    if(n==1||n==2) {
        return 1;

    }else {
        return feibonaqie(n-1)+feibonaqie(n-2);
    }
}
//后缀表达式计算
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define Stack_Size 50
typedef int ElemType;

typedef struct {
    ElemType elem[Stack_Size];
    int top;
} Stack;

// 初始化栈
void init_stack(Stack *S) {
    S->top = -1;
}

// 入栈
bool push(Stack *S, ElemType x) {
    if (S->top >= Stack_Size - 1) return false;
    S->elem[++(S->top)] = x;
    return true;
}

// 出栈
bool pop(Stack *S, ElemType *x) {
    if (S->top < 0) return false;
    *x = S->elem[(S->top)--];
    return true;
}

// 是否是运算符
bool is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

// 计算两个数的结果
int calc(int x, int y, char op) {
    switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;  // 假设不除以0
        case '%': return x % y;
        default: return 0;       // 不会发生
    }
}

// 主函数：计算后缀表达式
int compute_reverse_polish_notation(char *str) {
    Stack S;
    init_stack(&S);

    char *token = strtok(str, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // 是数字（包括负数）
            int num = atoi(token);
            push(&S, num);
        } else if (is_operator(token[0]) && strlen(token) == 1) {
            int y, x;
            if (!pop(&S, &y) || !pop(&S, &x)) {
                printf("错误：操作数不足\n");
                return 0;
            }
            int result = calc(x, y, token[0]);
            push(&S, result);
        } else {
            printf("无效的标记：%s\n", token);
            return 0;
        }
        token = strtok(NULL, " ");
    }

    int final_result;
    if (!pop(&S, &final_result)) {
        printf("错误：栈为空\n");
        return 0;
    }

    // 栈中不应再有其他数据
    if (S.top != -1) {
        printf("错误：表达式不规范\n");
        return 0;
    }

    return final_result;
}
int a=0;