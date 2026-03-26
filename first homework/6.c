#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int a;
    struct node *next;
    struct node *prior;
    int rt;
} node;
node *create(char a[],int n){
    if(n==0)return NULL;
    node *head=(node*)malloc(sizeof(node));
    head->a=a[0];
    head->next=head;
    head->prior=head;
    head->rt=0;
    node *tail=head;
    for(int i=1;i<n;i++){
        node *new_node=(node*)malloc(sizeof(node));
        new_node->a=a[i];
        new_node->next=head;
        new_node->prior=tail;
        new_node->rt=0;
        tail->next=new_node;
        tail=new_node;
    }
    if(n>1) head->prior=tail;
    return head;
}
void locate(node **head,char x){
    node *p=*head,*found=NULL;
    do{
        if(p->a==x){
            found=p;
            p->rt++;
            break;
        }
        p=p->next;
    }while(p!=*head);
    found->prior->next=found->next;
    found->next->prior=found->prior;
    if(found==*head){
        found->next->prior=found->prior;
        found->prior->next=found->next;
        (*head)=found->next;
        if(found==*head) *head=NULL;
    }
    if(*head==NULL){
        found->next=found;
        found->prior=found;
        *head=found;
        return;
    }
    node *q=*head,*start=*head;
    int is_found=0;
    do{
        if(q->rt<found->rt){
            is_found=1;
            break;
        }
        q=q->next;
    }while(q!=start);
    if(is_found){
        found->next=q;
        found->prior=q->prior;
        q->prior=found;
        found->prior->next=found;;
        if(q==*head) *head=found;
    }
    else{
        found->next=*head;
        found->prior=(*head)->prior;
        (*head)->prior->next=found;
        (*head)->prior=found;
    }

}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    char a[m];
    for(int i=0;i<m;i++) scanf(" %c",&a[i]);
    node *head=create(a,m);
    for(int i=0;i<n;i++){
        char x;
        scanf(" %c",&x);
        locate(&head,x);
    }
    node *p=head;
    printf("%c",p->a);
    p=p->next;
    while(p!=head){
        printf(" %c",p->a);
        p=p->next;
    }
    printf("\n");
}
// 测试输入：
// 7 1
// a b c d e f g
// d
// 预期输出：
// d a b c e f g