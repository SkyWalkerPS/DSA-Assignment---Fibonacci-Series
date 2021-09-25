#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* sum(char* a, char* b){
    char* temp = (char*)malloc(4500*sizeof(char));
    int i=0;
    int r=0;

    while(i<strlen(a) && i<strlen(b)){
        int c = a[i]+b[i]+ r -'0'-'0';
        temp[i]=(c%10 + '0');
        r = c/10;
        i++;
    }
    while(i<strlen(a)){
        int c = a[i]+ r -'0';
        temp[i]=(c%10 + '0');
        r = c/10;
        i++;
    }
    while(i<strlen(b)){
        int c = b[i]+ r -'0';
        temp[i]=(c%10 + '0');
        r = c/10;
        i++;
    }
    while(r){
        temp[i]=(r%10 + '0');
        r=r/10;
        i++;
    }
    temp[i]='\0';
    return temp;
}

char* fact(int n, char* a, char* b){
    if(n==0)return a;
    if(n==1)return b;

    char* temp=NULL;
    for(int i=2; i<=n; i++){
        temp = sum(a, b);

        free(a);
        a = b;
        b = temp;
    }
    return b;
}
int main(){
    int n;
    scanf("%d", &n);
    char *a=(char*)malloc(4500*sizeof(char));
    char *b=(char*)malloc(4500*sizeof(char));
    a = "0";
    b = "1";
    char * ans;
    ans = fact(n, a, b);
    ans = strrev(ans);
    printf("%s\n", ans);
    
    return 0;
}
