#include <stdio.h>
#define N 1000

void n(char povodne_pole[], int *velkost_povodneho){
FILE *fr;
if((fr = fopen("sifra.txt", "r")) == NULL){
    printf("Subor sa nepodarilo otvorit");
    return ;
}
char c;
int k = 0;
while((c = getc(fr)) != EOF){
    povodne_pole[k] = c;
    k++;
}
if((fclose(fr)) == EOF){
    printf("Subor sa nepodarilo zatvorit");
    return ;
}
    *velkost_povodneho = k;

}

int main()
{
    char povodne_pole[N], upravene_pole[N];
    int velkost_povodneho = 0, velkost_upraveneho = 0;
    FILE *fr;
    char c;
    int i;

    while(scanf("%c", &c) == 1){
        switch (c){
        case 'n':
            n(povodne_pole, &velkost_povodneho);
            printf("\n");
            break;
        case 'v':
            if(velkost_povodneho == 0){
                printf("Sprava nie je nacitana");
            }
            else{
                for(i = 0; i < velkost_povodneho; i++){
                    printf("%c", povodne_pole[i]);
                }
            }
            printf("\n");
            break;
        case 'k':
            return 0;
        }
    }
}
