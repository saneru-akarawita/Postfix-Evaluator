#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 100

int top=-1;
char stack[size];
char ch;

void push(char ch) {
	
	if(top>size-1) {
		printf("\tStack Overflow\n");
		exit(0);
	}
	else {
		top=top+1;
		stack[top]=ch;
	}	
}

char pop() {
	char op;
	
	if(top==-1) {
		printf("\tStack Underflow\n");
		exit(0);
	}
	else {
		op=stack[top];
		top=top-1;
	}
	return op;
}

void print(char A, char B, char C, char D) {
	
	if(B>='0'&& B<='9')	{
		printf("\tLD\tTemp%c\n",B);
	}
	else
        printf("\tLD\t%c\n",B);
                	
    if(A>='0'&& A<='9')	{
        printf("\t%c%c\tTemp%c\n",C,D,A);
	}
	else
		printf("\t%c%c\t%c\n",C,D,A);          
}

void EvalPostfix(char exp[]) {
	char A,B;
	char count='0';
	int len = strlen(exp);
	int i;
	
	for (i=0;i<len;i++) {
		ch=exp[i];
	
		if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z')) {
			push(exp[i]);
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			A=pop();
			B=pop();
			count++;
			
			switch (ch) {	
					
            case '+':
            	print(A,B,'A','D');
            	push(count);
            	printf("\tST\tTemp%c\n",count);
                break;
                
            case '-':
                print(A,B,'S','B');
                push(count);
                printf("\tST\tTemp%c\n",count);
                break;
                
            case '*':
                print(A,B,'M','L');
                push(count);
                printf("\tST\tTemp%c\n",count);
                break;
                
            case '/':
                print(A,B,'D','V');
                push(count);
                printf("\tST\tTemp%c\n",count);
                break;
			}	
		}
	}	
}

int main() {
    char exp[size];

    printf("\n\tPlease enter the postfix expression : ");
	gets(exp);
	printf("\n");
	
    EvalPostfix(exp);

    return 0;
}

