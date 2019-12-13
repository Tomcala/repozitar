#include <stdio.h>
#define N 1000
#define M 26

void nacitanie(char povodne_pole[], int *velkost_povodneho){
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
void uprava_pola(char povodne_pole[], char upravene_pole[], int *velkost_upraveneho, int velkost_povodneho){
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
void dlzka_slov(char povodne_pole[], int velkost_povodneho){
    int dlzka, i = 0, j;
    scanf("%d", &dlzka);
    char slovo[dlzka];
    int pozicia = 0;
    if(dlzka >= 1 && dlzka <= 100){
        for(i = 0; i < velkost_povodneho; i++){
            povodne_pole[velkost_povodneho] = ' ';
            slovo[pozicia] = povodne_pole[i];
                   if(pozicia <= dlzka - 1 && slovo[pozicia] == ' '){
                        pozicia = -1;
                   }
                   else if(pozicia == dlzka - 1 && povodne_pole[i + 1] == ' ' ){
                            for(j = 0; j < dlzka; j++){
                                if( slovo[j] >= 'A' && slovo[j] <= 'Z'){
                                    printf("%c", slovo[j]);
                                }
                                else{
                                    printf("%c", slovo[j]);
                                }
                            }
                            pozicia = -1;
                            putchar('\n');
                   }
                   else if(pozicia > dlzka && slovo[pozicia] == ' ' ){
                        pozicia = -1;
                   }
             pozicia++;
       }
    }
    else{
        printf("Zly vstup");
    }

}
void cesarova_sifra(char upravene_pole[], int *velkost_upraveneho){
    int i, n;
    char c;
    char pole_sifry[*velkost_upraveneho];
    scanf("%d", &n);
    if(n >= 1 && n <= 25){
        for(i = 0; i < *velkost_upraveneho; i++){
            c = upravene_pole[i];
            if(c >= 'A' + n && c <= 'Z'){
                c = c - n;
                printf("%c", c);
                pole_sifry[i];
            }
            else{
                c = c + 'Z' - n - 'A' + 1;
                printf("%c",c);
                pole_sifry[i];
            }
        }
    }
    else{
        printf("Zly kluc");
    }

    char x;
    scanf("%c", &x);
    int k, pocet = 0;
    for(i = 0; k <= *velkost_upraveneho; k++){
       if(pole_sifry[i] = x){
        pocet++;
       }
    }
}
void histogram(char upravene_pole[], int *velkost_upraveneho, int pole_histogramu[]){
    char c;
    int i = 0, j, k = 100;
    float n = 0, x = *velkost_upraveneho, percento;
        for(c = 'A'; c <= 'Z'; c++){
            for(j = 0; j < *velkost_upraveneho; j++ ){
                if(upravene_pole[j] == c){
                    n++;
                }
            }
            pole_histogramu[i] = n;
            i++;
            n = 0;
        }
        for(i = 0; i <= 10; i++){
            for(j = 0; j < M; j++){
                n = pole_histogramu[j];
                percento = n*100/x;
                if(percento == 0){
                    printf(" ");
                }
                else{
                    if(percento > k ){
                        printf("*");
                    }
                    else{
                        printf(" ");
                    }
                }
            }
            printf("\n");
            k -= 10;
        }
    for(c = 'A'; c <= 'Z'; c++){
        printf("%c", c);
    }
}
void zmazanie_pola(char upravene_pole[], int *velkost_upraveneho){
    int z, k, i = 0, j = 0;
    int *velkost_retazca;
    scanf("%d %d", &z, &k);
    int y = (k - z) + 1;
    int x = *velkost_upraveneho - y;
    char pole[x];
    char c = upravene_pole[z];
    if(c < 'A' || c > 'Z'){
        printf("Retazec nie je mozne zmazat\n");
    }
    else{
        for(i = 0; i < *velkost_upraveneho; i++){
            if(i >= z && i <= k){
            }
            else {
                pole[j] = upravene_pole[i];
                j++;
            }
        }
        printf("Retazec sa zmazal\n");
    }
    for(i = 0; i < x; i++){
        upravene_pole[i] = pole[i];
    }
    *velkost_upraveneho = x;
}

void pomer_pismen(char povodne_pole[], int velkost_povodneho){
    int i = 0;
    int pocet1 = 0, pocet2 = 0;
    if(velkost_povodneho == 0){
        printf("Sprava nie je nacitana");
    }
    else{
        for(i = 0; i < velkost_povodneho; i++){
            if(povodne_pole[i] >= 'A' && povodne_pole[i] <= 'Z'){
                pocet1++;
            }
            else if(povodne_pole[i] >= 'a' && povodne_pole[i] <= 'z'){
                pocet2++;
            }
        }
        printf("%d:%d\n", pocet1, pocet2);
    }
}
int main()
{
    char povodne_pole[N], upravene_pole[N];
    int pole_histogramu[M];
    int velkost_povodneho = 0, velkost_upraveneho = 0;
    FILE *fr;
    char c;
    int i;

    while(scanf("%c", &c) == 1){
        switch (c){
        case 'n':
            nacitanie(povodne_pole, &velkost_povodneho);
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
                uprava_pola(povodne_pole, upravene_pole, &velkost_upraveneho, velkost_povodneho);
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
        case 'd':
            dlzka_slov(povodne_pole, velkost_povodneho);
            break;
        case 'h':
                if(velkost_upraveneho == 0){
                    printf("Nie je k dispozicii upravena sprava");
                }
                else{
                    histogram(upravene_pole, &velkost_upraveneho, pole_histogramu);
                }
                printf("\n");
                break;
        case 'c':
                if(velkost_upraveneho == 0){
                    printf("Nie je k dispozicii upravena sprava");
                }
                else{
                    cesarova_sifra(upravene_pole, &velkost_upraveneho);
                }
                printf("\n");
                break;
        case 'p':
                pomer_pismen(povodne_pole, velkost_povodneho);
                break;
        case 'z':
                zmazanie_pola(upravene_pole, &velkost_upraveneho);
                break;
        case 'k':
            return 0;
        }
    }
}
