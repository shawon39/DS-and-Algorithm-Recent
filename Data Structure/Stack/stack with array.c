#include <stdio.h>
int stack[5];
int top=-1;

void push(int data)
{
    if(top>=4) {
        printf("Stack is Full\n");
    }
    else {
        top++;
        stack[top]=data;
    }
}
void pop()
{
    if(top<0) {
        printf("Stack is Empty!\n");
    }
    else {
        top--;
    }
}

void print()
{
    int i;
    printf("Number is: ");
    for(i=0; i<=top; i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main()
{

    push(1); print();
    push(2); print();
    push(3); print();
    push(4); print();
    push(5); print();
    push(6); print();

    return 0;
}

