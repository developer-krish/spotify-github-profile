#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int Top;
    int size;
    char *arr;
};
int isEmpty(struct stack * ptr)
{
    if (ptr->Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->Top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, char x)
{
    if (isFull(ptr))
    {
        printf("Stack is full\n");
    }
    else
    {
         ptr->Top++;
         ptr->arr[ptr->Top] = x;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty");
    }
    else
    {
       char x = ptr->arr[ptr->Top];
       ptr->Top--;
       return x;
    }
}
void display(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty");
    }
    else
    {
        for (ptr->Top ; ptr->Top != -1 ; ptr->Top--)
        {
            printf("%d ",ptr->arr[ptr->Top]);
        }
        printf("\n");
    }
}
int peek(struct stack *ptr, int i)
{
    if (ptr->Top - i + 1 < 0)
    {
        printf("Not a valid position.\n");
    }
    else
    {
        return ptr->arr[ptr->Top - i + 1];
    }
}
int parenthrsisMatch(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->Top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0 ; exp[i] != '\0' ; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int main()
{  
    char *exp = "(a + b) * (b + c))))"; 
    if (parenthrsisMatch(exp))
    {
        printf("Parenthesis Matched.\n");
    }
    else
    {
        printf("Parenthesis Not Matched.\n");
    }

}
    
    
