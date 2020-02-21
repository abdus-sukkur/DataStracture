/// Update data in array (user input)

#include<stdio.h>
int main(){
    int age[10] = {2,4,6,8,10,12,14,16,18,20};

    int i, index, value;
    while(scanf("%d%d",&index,&value) != EOF){
        age[index] = value;
    }

    for(i=0; i<10; i++){
        printf("%d\n",age[i]);
    }

    return 0;
}

