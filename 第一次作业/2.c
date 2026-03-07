#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int a;
    struct Node*next;
}Node;
Node* create(int a[], int n) {
    if(n==0) return NULL;
    Node *head=NULL;
    for(int i=0;i<n;i++){
        Node *new=(Node*)malloc(sizeof(Node));
        new->a=a[i];
        new->next=head;
        head=new;
    }
    return head;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", a[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
    Node *head=create(a,n);
    Node *p=head;
    while(p!=NULL){
        printf("%d",p->a);
        if (p->next) printf(" ");
        p=p->next;
    }
    printf("\n");
}