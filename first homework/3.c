#include<stdio.h>
int main(){
    int m,n,p;
    scanf("%d %d %d",&m,&n,&p);
    int a[1000],b[1000],c[1000],used[1000];
    for(int i=0;i<m;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        used[b[i]]++;
    }
    for(int i=0;i<p;i++){
        scanf("%d",&c[i]);
        used[c[i]]++;
    }
    for(int i=0;i<m;i++){
        if(used[a[i]]<2) printf("%d ",a[i]);
    }
}