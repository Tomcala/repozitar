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
void u(char povodne_pole[], char upravene_pole[], int *velkost_upraveneho, int velkost_povodneho){
    int i , k = 0;
    char c;
    for(i = 0; i < velkost_povodneho; i++){
        c = povodne_pole[i];
        if(c >= 'A' && c <= 'Z'){

            upravene_pole[k] = povodne_pole[i];
            k++;
        }
         if(c >= 'a' && c <= 'z'){
            upravene_pole[k] = c - 'a' + 'A';
            k++;
        }
    }
    *velkost_upraveneho = k;
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
        case 'u':
            if(velkost_povodneho == 0){
                    printf("Sprava nie je nacitana");
                }
                else{
                u(povodne_pole, upravene_pole, &velkost_upraveneho, velkost_povodneho);
                }
                break;
        case 's':
                if(velkost_upraveneho == 0){
                    printf("Nie je k dispozicii upravena sprava");
                }
                else{
                    for(i = 0; i < velkost_upraveneho; i++){
                        printf("%c", upravene_pole[i]);
                    }
                }
                printf("\n");
                break;
        case 'k':
            return 0;
        }
    }
}
