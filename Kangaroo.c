#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int x1; 
    int v1; 
    int x2; 
    int v2; 
    scanf("%d %d %d %d",&x1,&v1,&x2,&v2);
    int flag=0;
    int kangrooOne, kangrooTwo;
    for(int i=0;i<10000;i++){
        if(((x1>x2) && (v1>v2)) || ((x2>x1) && (v2>v1))){
                flag=0;
            break;
            }
        else{
            x1 = x1+v1;
            x2 = x2+v2;
            if(x1==x2){
                flag=1;
            break;
            }
        }
        
    }
    if(flag){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
