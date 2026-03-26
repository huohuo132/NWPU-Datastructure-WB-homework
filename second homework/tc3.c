#include<stdio.h>
#include<string.h>
#include <stdlib.h>
const int m=1e5;
int main(){
    int n;
    int a[m];
    int ptr=0;
    scanf("%d",&n);
    getchar();
    char line[10000];
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " \n");
    while (token != NULL) {
        a[ptr++] = atoi(token);
        token = strtok(NULL, " \n");
    }
    int tar;
    scanf("%d",&tar);
    int ptr1=0;
    for(int i=0;i<ptr;i++){
        if(a[i]==tar){
            ptr1=i+1;
        }
    }
    if(ptr>=n) printf("yes\n");
    for(int i=ptr1;i<ptr;i++){
        if(i!=ptr-1) printf("%d ",a[i]);
        else printf("%d\n",a[i]);
    }
    printf("%d",a[ptr1]);
}
/*测试输入：
5
3 4 6 2 7
4
预期输出：
yes
6 2 7
6
*/