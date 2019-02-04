#include <stdio.h>
#include <time.h>

int fib1(int n)
{
    if (n<2)return n;
    else return fib1(n-1) + fib1(n-2);
}

int fib2(int n)
{
    int i=1;
    int j=0;
    for (int k=1;k<=n;k++){
        j=j+i;
        i = j-i;
    }
    return j;
}
int fib3(int n)
{
    int i = 1;
    int j = 0;
    int k = 0;
    int h = 1;
    int x = 0;
    int y = 0;
    while (n>0){
        x++;
        if (n%2){
            int t = j*h;
            j = i*h + j*k + t;
            i = i*k + t;
            y++;
        }
        int t = h*h;
        h = 2*k*h + t;
        k = k*k + t;
        n = n/2;
    }
    printf("Voici x : %d et y : %d", x, y);
    return j;
}

int test()
{
    int x = 0;
    for (int i = 1; i <= 10; i++) {
        x++;
    }
    printf("%d", x);
}

int main()
{
    int fibNumber = 0;
    int algoWanted = 0;
    int fibResult = 0;
    time_t execTime;
    double execTimeSec = 0;

    printf("Quel algorithme voulez-vous utilisez? ");
    scanf("%d", &algoWanted);
    if (algoWanted >= 1 && algoWanted <= 3) {
        printf("Quelle valeur de Fibbonaci voulez-vous? ");
        scanf("%d", &fibNumber);
        switch (algoWanted) {
            case 1 : {
                execTime = clock();
                fibResult =  fib1(fibNumber);
                execTime = clock() - execTime;
                printf("Voici le resultat : %d \n", fibResult);
                execTimeSec = ((double)execTime)/CLOCKS_PER_SEC;
                printf("L'execution a duree %f secondes", execTimeSec);
                break;
            }
            case 2 : {
                execTime = clock();
                fibResult =  fib2(fibNumber);
                execTime = clock() - execTime;
                printf("Voici le resultat : %d \n", fibResult);
                execTimeSec = ((double)execTime)/CLOCKS_PER_SEC;
                printf("L'execution a duree %f secondes", execTimeSec);
                break;
            }
            case 3 : {
                execTime = clock();
                fibResult =  fib3(fibNumber);
                execTime = clock() - execTime;
                printf("Voici le resultat : %d \n", fibResult);
                execTimeSec = ((double)execTime)/CLOCKS_PER_SEC;
                printf("L'execution a duree %f"
                       " secondes", execTimeSec);
                break;
            }
            default: {
                printf("Veuillez entrer une valeur valide!");
                break;
            }
        }
    } else
    {
        printf("Veuillez entrer un algo valide! (1-3)");
    }
    return 0;
}
