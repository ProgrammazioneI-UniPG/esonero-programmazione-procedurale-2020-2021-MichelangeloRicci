// ESONERO 2021
// MICHELANGELO
// RICCI
// MATRICOLA 324372
// Aggiungo i miei dati anche qua per evitare qualsiasi mio errore su github


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXLENGTH 129

 int l (char stringa[]){               //l sta per lunghezza

  int i = 0;

  while (stringa[i] != EOF){

    i++;

  }
  return i;
}

int main (){

char  m [128];           // frase da cifrare
char  k [128];           // chiave
char mc [128];           // frase cifrata
char md [128];           // frase de-cifrata
int lm;                  // lunghezza m
int  i;                  // variabile di incremento
int  s;                  // scelta


printf("\n\n\t\tBENVENUTO NELLA CIFRATURA/DECIFRATURA XOR\t\t\t\n");
printf ("\nInserisci il testo che vuoi criptare con una dimensione di carateri massima di 128 \n");

fgets (m, 128, stdin);
m[l(m) - 1] = '\0';
lm = strlen(m) - 1;

printf ("\nIl testo da criptare è : %s\n", m);
printf ("E la sua lunghezza equilavale a: %d caratteri\n\n", lm);

printf ("\n1- Se vuoi cifrare il tuo testo con la chiave generata random \n");
printf ("\n2- Se invece desideri cifrarlo con la chiave creata da te \n");

scanf  ("%d", &s);

while  (s != 1 && s != 2){
  printf ("cortesemente... scegli 1 o 2 \n");
  scanf  ("%d", &s);
}

if (s == 1){

char* kr;
  printf ("\n\t\tHAI SCELTO DI GENERARE UNA CHIAVE RANDOM\t\t \n");

kr = (char*) calloc (lm, sizeof(char));
srand ((unsigned)time(NULL));

printf ("la chiave generata automaticamente è: \n");

for (i=0 ; i!=lm ; i++){
  kr[i] = rand()%128;
}
printf("%s\n", kr);

printf ("\n\nQUINDI:\n  Il tuo testo è: %s  E la tua chiave random è: %s\n",m ,kr);

for (i=0 ; i < strlen(kr) ; i++){
  mc[i] = m[i] ^ kr[i];
}
printf("\nIL TUO TESTO CIFRATO CON CHIAVE RANDOM E': ");
printf("\n%s\n", mc);

printf ("\nOra desideri decodificare la tua frase?");
printf ("\n 1-SI\n 2-NO\n");

scanf  ("\n%d", &s);

while (s != 1 && s != 2){
  printf ("cortesemente... scegli 1 o 2 \n");
  scanf  ("%d", &s);
  }

  switch (s){
    case 1:
    printf("\n Hai deciso di decodificare il tuo testo\n");
    printf("\n IL TUO TESTO DECODIFICATO E': \n");
    for (i=0 ; i < strlen(m) ; i++ ){
      m[i]= mc[i] ^ kr[i];
  }
      printf("%s\n", m);
    break;

    case 2:
    printf("\n \t\tHai deciso di NON decodificare il tuo testo\t\t\n");
    printf ("\n \t\t\tL'applicazione si chiuderà\t\t\t");
    printf ("\n\n \t\t\t\t GRAZIE \t\t\t\t \n");
  }

}               //chiusura if 1

else if (s == 2){


printf ("\n\n\t\tHai scelto di generare una chiave manualmente, \n");
printf ("\n crea la tua chiave con dimensioni uguali o superiosi al testo iniziale\n ");

do {

fgets (k,128,stdin);

}while (strlen(k) < strlen(m));

printf ("\nLa tua chiave è: %s \n", k);
printf ("\n\nQUINDI:\n  Il tuo testo è: %s  E la tua chiave è: %s\n",m ,k);

for ( i=0 ; i < strlen(k)-'\0' ; i++){
mc[i] = m[i] ^ k[i];

}

printf ("\n FRASE CIFRATA: %s \n", mc);

printf ("\nOra desideri decodificare la tua frase?");
printf ("\n 1-SI\n 2-NO\n");

scanf  ("\n%d", &s);

switch (s){
  case 1:
  printf("\n Hai deciso di decodificare il tuo testo\n");
  printf("\n IL TUO TESTO DECODIFICATO E': ");

  for (i=0 ; i < strlen(m)-1 ; i++ ){

    m[i]= mc[i] ^ k[i];

    }
    printf("%s", m);
  break;

  case 2:
  printf("\n \t\tHai deciso di NON decodificare il tuo testo\t\t\n");
  printf ("\n \t\t\tL'applicazione si chiuderà\t\t\t");
  printf ("\n\n \t\t\t\t GRAZIE \t\t\t\t \n");
}

}               //chiusura if 2
return 0;
}               //chiusura main
