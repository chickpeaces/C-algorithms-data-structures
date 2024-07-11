#include <stdio.h>
#include <stdlib.h>

typedef struct LCG{
    int state;
    int a;
    int m;
    int c;
}LCG;

int roll(LCG *lcg){
    lcg->state= (lcg->a * lcg->state + lcg->c);
    return (lcg->state > 0 ? lcg->state : 0-lcg->state) % lcg->m;
}

int main(void){
    /* determine period length of mixed LCG*/
    LCG *test_lcg= (LCG*) malloc(sizeof(LCG));
    test_lcg->state = 123454321;
    test_lcg->a= 2113;
    test_lcg->c= 2039;
    test_lcg->m= 100;
    int p= 1, out= 0;
    int loop= roll(test_lcg);
    printf("\n[%d]\n", loop);
    do{
        out= roll(test_lcg);
        p+= 1;
        printf("%d ", out);
    }while( out != loop);
    printf("\n%d rolls until this LCG repeats\n", p);

    return 0;
}
