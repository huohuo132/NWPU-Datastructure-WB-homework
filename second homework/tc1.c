#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int mx=1000000;
int main()
{
    int a[mx];
    for(int i=0;i<mx;i++){
        a[i]=-1;
    }
    int ptr1=0;
    char b[1000];
    scanf("%s",b);
    int n = (int)strlen(b);
    for(int i=0;i<n;i++){
        if(b[i]=='('){
            a[ptr1]=1;
            ptr1++;
        }
        else if(b[i]=='['){
            a[ptr1]=2;
            ptr1++;
        }
        else if(b[i]=='{'){
            a[ptr1]=3;
            ptr1++;
        }
        else if(b[i]==')'){
            if(ptr1==0){
                printf("no\n");
                return 0;
            }
            if(a[ptr1-1]!=1){
                printf("no\n");
                return 0;
            }
            else{
                a[ptr1-1]=0;
                ptr1--;
            }
        }
        else if(b[i]==']'){
            if(ptr1==0){
                printf("no\n");
                return 0;
            }
            if(a[ptr1-1]!=2){
                printf("no\n");
                return 0;
            }
            else{
                a[ptr1-1]=0;
                ptr1--;
            }
        }
        else if(b[i]=='}'){
            if(ptr1==0){
                printf("no\n");
                return 0;
            }
            if(a[ptr1-1]!=3){
                printf("no\n");
                return 0;
            }
            else{
                a[ptr1-1]=0;
                ptr1--;
            }
        }
    }
    if(ptr1!=0){
        printf("no\n");
        return 0;
    }
    printf("yes\n");
}