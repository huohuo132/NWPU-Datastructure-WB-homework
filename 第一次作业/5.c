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
// Node*add(Node* A,Node*B){
//     Node *C=(Node*)malloc(sizeof(Node));
//     C->next=NULL;
//     Node *pa=A->next,*pb=B->next,*q;
//     while(pa&&pb){
//         if(pa->a<=pb->a){
//             q=pa;
//             pa=pa->next;
//         }
//         else{
//             q=pb;
//             pb=pb->next;
//         }
//         q->next=C->next;
//         C->next=q;
//     }
//     while(pa){
//         q=pa;
//         pa=pa->next;
//         q->next=C->next;
//         C->next=q;
//     }
//     while(pb){
//         q=pb;
//         pb=pb->next;
//         q->next=C->next;
//         C->next=q;
//     }
//     return C;
// }
int main(){
    int m,n,p;
    scanf("%d %d %d",&m,&n,&p);
    int a[1000],b[1000],c[1000],used[1000];
    for(int i=0;i<m;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<p;i++) scanf("%d",&c[i]);
    Node *A=create(a,m),*B=create(b,n),*C=create(c,p);
    Node *q=C->next;
    while(q){
        used[q->a]++;
        q=q->next;
    }
    q=B->next;
    while(q){
        used[q->a]++;
        q=q->next;
    }
    q=A->next;
    while(q){
        if(used[q->a]<2) printf("%d ",q->a);
        q=q->next;
    }
    printf("\n");
}