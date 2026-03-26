#include<stdio.h>
const int m=1e5;
int main(){
    int mx,k;
    scanf("%d %d",&mx,&k);
    int a[m];
    for(int i=0;i<m;i++){
        a[i]=0;
    }
    a[k-1]=1;
    int i=k;
    for(;;i++){
        for(int j=i;j>=i-k;j--){
            a[i]+=a[j];
        }
        if(a[i]>mx) break;
    }
    for(int j=i-k;j<i;j++){
        if(j!=i-1) printf("%d ",a[j]);
        else printf("%d",a[j]);
    }
}