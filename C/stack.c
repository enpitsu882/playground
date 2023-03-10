/* 逆ポーランド電卓 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long ELEM;
#define STACK_SIZE 100

ELEM stack[STACK_SIZE];
int n;

/* error */
void error(char *s){
    fprintf(stderr, s);
    exit(1);
}

/* init */
void init(){
    n = 0;
}

/* push */
void push(ELEM x){
    if (n >= STACK_SIZE)
        error("stack overflow\n");
    stack[n++] = x;
}

/* pop */
ELEM pop(){
    if (n <= 0)
        error("stack underflow\n");
    return stack[--n];
}

/* empty */
int empty(){
    return n == 0;
}

/*******************************************************/

/* 逆ポーランド電卓プログラム */

int main()
{
    int c;
    long x, a, b;

    init();
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            ungetc(c, stdin);
            scanf("%ld", &x);
            push(x);
        } else {
            switch (c)
            {
            case '+':
                b = pop();
                a = pop();
                push(a + b);
                break;
            case '-':
                b = pop();
                a = pop();
                push(a - b);
                break;
            case '*':
                b = pop();
                a = pop();
                push(a * b);
                break;
            case '/':
                b = pop();
                a = pop();
                push(a / b);
                break;
            case '\n':
                if (! empty())
                    printf("答えは%ldです\n", pop());
                init();
                break;
            case ' ':
            case '\t':
                /* 何もしないで読み飛ばす */
                break;
            default:
                printf("不正な文字がありました\n");
                printf("入力し直してください\n");
                while ((c = getchar()) != EOF && c != '\n')
                    ;
                break;
            }
        }
    }
}
