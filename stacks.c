#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

typedef struct node
{
    double value;
    struct node *next;
}node;

node *top=NULL;
int overflow = 0;
int underflow=0;
int dividebyzero=0;
int invalidInput=0;


void push(double element)
{
    node* bufferP = malloc(sizeof(node*));
    bufferP->value=element;
    bufferP->next=top;
    top=bufferP;

}

void printStack()
{
    node *temp = top;
    while(temp!=NULL)
    {
    printf("%f\n",temp->value);
    temp = temp->next;
    }
}

double pop()
{   
    node *bufferP= top;
    if(top == NULL)
    {
        underflow++;
        return 0;
    }
    else
    {
        double poppedElement=top->value;
        top=top->next;
        free(bufferP);
        return poppedElement;
    }
  
}

void add()
{
    push(pop()+pop());
}

void multiply()
{
    push(pop()*pop());
}

void subtract()
{
    push(pop()-pop());
}

void divide()
{
    double x1 = pop();
    double x2 = pop();
    if((int)x2!=0)
    {
        push(x1/x2);
    }
    else
    {
        dividebyzero++;
    }
}

void negate()
{
    push(-pop());
}

void square()
{
    double x1 = pop();
    push(x1*x1);
}

void pi()
{
    push(3.14159);
}

void dup()
{
    double x =pop();
    push(x);
    push(x);
}

int isNum(char * string)
{
    int x;
    int y = strlen(string)-1;
    int count=0;
    for(x=0;x<y;x++)
    {
        if(isdigit(string[x]))
        {
            count++;

        }
        else if(string[x]=='-')
        {
            count++;
        }
    }
    if(y==count)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void lower(char (*string)[])
{
    int x=0;
    for(x=0;x<strlen(*string);x++)
    {
        (*string)[x]=tolower((*string)[x]);
    }
}

void strip(char (*string)[])
{
    int len = strlen(*string);
    if((*string)[len-1]=='\n')
    {
        (*string)[len-1]='\0';
    }
}

int main()
{
    push(0);
    char buffer[255];
    char adds[]="add";
    char subtracts[]="subtract";
    char sqaures[]="square";
    char multiplies[]="multiply";
    char divides[]="divide";
    char negates[]="negate";
    char pis[]="pi";
    char dups[]="dup";
    double d;
    FILE * file = fopen("sums.txt","r");
    while(fgets(buffer, 255, file)!=NULL)
    {
        lower(&buffer);
        strip(&buffer);
        if(isalpha(buffer[0]))
        {
            if (strcmp(buffer,adds)==0)
            {
                add();
            }
            else if (strcmp(buffer,subtracts)==0)
            {
                subtract();
            }
            else if (strcmp(buffer,multiplies)==0)
            {
                multiply();
            }                      
            else if (strcmp(buffer,divides)==0)
            {
                divide();
            }   
            else if (strcmp(buffer,sqaures)==0)
            {
                square();
            }            
            else if (strcmp(buffer,negates)==0)
            {
                negate();
            }
            else if (strcmp(buffer,pis)==0)
            {
                pi();
            }
            else if (strcmp(buffer,dups)==0)
            {
                dup();
            }
            else
            {
                invalidInput++;
            }              
            
        }
        else if(isNum(buffer))
        {
            sscanf(buffer, "%lf",&d);
            push(d);
        }
        else
        {
            invalidInput++;
        }
    }
    if(invalidInput!=0)
    {
        printf("ERROR: INVALID INPUT");
    }
    else if(dividebyzero!=0)
    {
        printf("ERROR: DIVIDE BY ZERO");
    }
    else if(underflow!=0)
    {
        printf("ERROR: STACK EMPTY");
    }
    else
    {
        printf("%f",top->value);
    }
}