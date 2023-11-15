#include <stdio.h>

int main (void){
        int age;
        printf("what is your age? \n");
        scanf("%d", &age);
        int isAdult = age >= 18;
        int isSenior = age >= 65;
        int isTheworkforce = isAdult && !isSenior;
        if (isTheworkforce) {
                printf("you are in the labour force\n");
        } else {
                printf("you are not n the labour force\n");
        }
        return 0;
}
