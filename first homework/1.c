#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int vec[1000];
    for(int i=0;i<n;i++) scanf("%d",&vec[i]);
    int x;scanf("%d",&x);
    int pos=0;
    while(pos<n&&vec[pos]<x){
        pos++;
    }
    for(int i=n;i>pos;i--){
        vec[i]=vec[i-1];
    }
    vec[pos]=x;
    for(int i=0;i<=n;i++){
        printf("%d ",vec[i]);
    }
    printf("\n");
}