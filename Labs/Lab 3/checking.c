#include<stdio.h>
void main(){
    int x=10, y=5, z=20;

    if(x<y)
        if(y<z)
            printf("%d is smaller than %d\n", y, z);
        else if(x<z)
            printf("%d is smaller than %d", x, z);
        else
            printf("%d is smallest\n", z);\
    else 
        printf("%d is greater than or equal to %d\n", x, y);
}