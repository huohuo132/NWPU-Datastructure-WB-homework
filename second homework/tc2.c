#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 100

typedef struct { char data[MAX_SIZE]; int top; } Stack;
void init(Stack *s) { s->top = -1; }
int empty(Stack *s) { return s->top == -1; }
void push(Stack *s, char c) { if (s->top < MAX_SIZE-1) s->data[++(s->top)] = c; }
char pop(Stack *s) { return empty(s) ? -1 : s->data[(s->top)--]; }
char top(Stack *s) { return empty(s) ? -1 : s->data[s->top]; }

int priority(char op, int inStack) {
    if (inStack) {
        switch(op) { case '+': case '-': return 2; case '*': case '/': return 3; case '(': return 0; }
    } else {
        switch(op) { case '+': case '-': return 1; case '*': case '/': return 2; case '(': return 4; }
    }
    return -1;
}

void infixToPostfix(char *in, char *out) {
    Stack s; init(&s);
    int i=0, j=0;
    while (in[i]) {
        char c = in[i++];
        if (c==' ') continue;
        if (isalnum(c)) out[j++] = c;
        else if (c=='(') push(&s, c);
        else if (c==')') {
            while (!empty(&s) && top(&s)!='(') out[j++] = pop(&s);
            pop(&s);
        } else {
            while (!empty(&s) && top(&s)!='(' && priority(top(&s),1)>=priority(c,0))
                out[j++] = pop(&s);
            push(&s, c);
        }
    }
    while (!empty(&s)) out[j++] = pop(&s);
    out[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    scanf("%s", infix);
    char postfix[MAX_SIZE];
    infixToPostfix(infix, postfix);
    printf("%s",postfix);
    return 0;
}