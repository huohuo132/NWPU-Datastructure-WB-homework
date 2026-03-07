#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int a;
    struct Node *next;
}Node;
Node *create(int a[],int n){
    Node* head=(Node*) malloc(sizeof(Node));
    head->next=NULL;
    Node* tail=head;
    for(int i=0;i<n;i++){
        Node *p=(Node*) malloc(sizeof(Node));
        p->a=a[i];
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
    return head;
}
Node*add(Node* A,Node*B){
    Node *C=(Node*)malloc(sizeof(Node));
    C->next=NULL;
    Node *pa=A->next,*pb=B->next,*q;
    while(pa&&pb){
        if(pa->a<=pb->a){
            q=pa;
            pa=pa->next;
        }
        else{
            q=pb;
            pb=pb->next;
        }
        q->next=C->next;
        C->next=q;
    }
    while(pa){
        q=pa;
        pa=pa->next;
        q->next=C->next;
        C->next=q;
    }
    while(pb){
        q=pb;
        pb=pb->next;
        q->next=C->next;
        C->next=q;
    }
    return C;
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int a[1000],b[1000];
    for(int i=0;i<m;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    Node *A=create(a,m),*B=create(b,n),*c=add(A,B);
    Node *p=c->next;
    while(p){
        printf("%d ",p->a);
        p=p->next;
    }
    printf("\n");
}