#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#define MAX_ORA 23
#define MAX_LUNGHEZZA_STRINGA 50
#define MAX_GIORNI 31
#define MAX_MESE 12
#define MAX_IMPEGNI 5
#define MAX_UTENTE 20
#define MAX_ANNO 2023

//struct per nome, cognome e max utenti
struct{
  char Nome[MAX_UTENTE][MAX_LUNGHEZZA_STRINGA];
  char Cognome[MAX_UTENTE][MAX_LUNGHEZZA_STRINGA];
  int indice[MAX_UTENTE];
  int num_utenti;
}agenda;

//struct per impegni, descrizione, ora, mese, giorno e anno
struct{
   int libero;
   int num_impegni;
   char description[MAX_IMPEGNI][MAX_LUNGHEZZA_STRINGA];
   int ora[MAX_IMPEGNI];
   int mese[MAX_IMPEGNI];
   int giorno[MAX_IMPEGNI];
   int anno[MAX_IMPEGNI];
}utente[MAX_UTENTE]; 

//dichiarazioni delle function 
void crea_agenda();
void inizializza();
void visualizza();
void disdire();
void aggiorna();

//questa function serve ad inizializzare il numero di utenti e gli impegni
void inizializza(){
   int i,j;
   agenda.num_utenti=0;
   for(i=0;i<MAX_UTENTE;i++)
   {
      utente[i].libero=1;
      for(j=0;j<MAX_IMPEGNI;j++)
      {
      utente[i].ora[j]=-1;
      }
   }
}

//questa function permette agli utenti di registrarsi e di inserire i propri impegni in agenda 
void crea_agenda(){
   int n_utente=0;
   int loop;
   int i,j;

   printf("Inserisci il numero di utenti da registrare:\t");
   do{
      loop=1;
      scanf("%d",&n_utente);
      fflush(stdin);
      if(n_utente+agenda.num_utenti > MAX_UTENTE)
      {
         printf("Non posso gestire tutti questi utenti! Ridefinire numeri di utenti:\a\t");
         loop=0;
      }
   }while(loop==0);

   agenda.num_utenti=agenda.num_utenti+n_utente;


   for(i=agenda.num_utenti-n_utente;i<agenda.num_utenti;i++){
      printf("Inserire il proprio nome:\t");
      scanf("%s",&agenda.Nome[i]);
      printf("Inserire il proprio cognome:\t");
      scanf("%s",&agenda.Cognome[i]);

      do{
         agenda.indice[i]=rand()%MAX_UTENTE; 
      }while(utente[agenda.indice[i]].libero!=1);

      do{
         loop=1;
         printf("Definire il numero di impegni:\t");
         scanf("%d",&utente[agenda.indice[i]].num_impegni);
         fflush(stdin);
         if(utente[agenda.indice[i]].num_impegni > MAX_IMPEGNI)
         {
            printf("Troppi impegni, Rischi di collassare! Ridefinire impegni:\a\t");
            loop=0;
         }
      }while(loop == 0);

      for(j=0;j<utente[agenda.indice[i]].num_impegni;j++){
         printf("Definire impegno %d.\n",j+1);
         do{
            printf("\nInserisci l' ora in cui vuoi inserire l' impegno:\t");
            scanf("%d",&utente[agenda.indice[i]].ora[j]);
            fflush(stdin);
         }while(utente[agenda.indice[i]].ora[j] > MAX_ORA || utente[agenda.indice[i]].ora[j] < 0);
         do{
            printf("\nInserisci il giorno in cui vuoi inserire l' impegno:\t");
            scanf("%d",&utente[agenda.indice[i]].giorno[j]);
            fflush(stdin);
         }while((utente[agenda.indice[i]].giorno[j] > MAX_GIORNI) || (utente[agenda.indice[i]].giorno[j] <= 0));

         do{
            printf("\nInserisci l' anno in cui vuoi inserire l' impegno:\t");
            scanf("%d",&utente[agenda.indice[i]].anno[j]);
            fflush(stdin);
         }while(utente[agenda.indice[i]].anno[j] < MAX_ANNO);

         do{
            printf("\nInserisci il mese in cui vuoi inserire l' impegno:\t");
            scanf("%d",&utente[agenda.indice[i]].mese[j]);
            fflush(stdin);
         }while(utente[agenda.indice[i]].mese[j] > MAX_MESE || utente[agenda.indice[i]].mese[j] <= 0);

         printf("\nInserisci la descrizione del tuo impegno %d:\t",j+1);
         scanf("%s",&utente[agenda.indice[i]].description[j]);
         system("cls");
      }
   }

}

//questa functiton visualizza a schermo gli appuntamenti
void visualizza(){
   int i;
   for(i=0;i<agenda.num_utenti;i++){
         int mia_ora,j,mio_mese,mio_giorno;
         printf("Inserci l' ora degli appuntamenti :\t");
         scanf("%d",&mia_ora);
         printf("Inserisci il giorno dove cercare :\t");
         scanf("%d",&mio_giorno);
         printf("Inserisci il mese dove cercare :\t");
         scanf("%d",&mio_mese);
         int count=0;
         do{
         	j=0;
            if((mia_ora==utente[agenda.indice[i]].ora[j]) && (mio_mese==utente[agenda.indice[i]].mese[j])){
               mio_giorno=utente[agenda.indice[i]].giorno[j];
               printf("Gli appuntamenti del mese %d del giorno %d dell ora %d sono :\n",mio_mese,mio_giorno,mia_ora);
               printf("Impegno: %d \nDescrizione: %s \n",j+1,utente[agenda.indice[i]].description[j]);
               count++;
            }
            j++;
         }while(count<utente[agenda.indice[i]].num_impegni || j > MAX_GIORNI );
         break;
      }
   }

//questa function disdice gli appuntamenti in agenda
void disdire(){
   int i;
   for(i=0;i<agenda.num_utenti;i++)
   {
         int mia_ora,j,mio_mese,mio_giorno,mio_anno;
         printf("Inserci l' ora dell' appuntamento da disdire :\t");
         scanf("%d",&mia_ora);
         printf("Inserire il giorno dell' appuntamento da disdire:\t");
         scanf("%d",&mio_giorno);
         printf("Inserisci il mese dove cercare:\t");
         scanf("%d",&mio_mese);
         printf("Inserisci l' anno:\t");
         scanf("%d",&mio_anno);
         for(j=0;j<utente[agenda.indice[i]].num_impegni;j++){
            if(mia_ora==utente[agenda.indice[i]].ora[j] && mio_mese==utente[agenda.indice[i]].mese[j] && mio_anno==utente[agenda.indice[i]].anno[j] && mio_giorno==utente[agenda.indice[i]].giorno[j]){
               strcpy(utente[agenda.indice[i]].description[j],"DELETED\n");
               printf("\n");
               utente[agenda.indice[i]].ora[j]=utente[agenda.indice[i]].mese[j]=-1;
               utente[agenda.indice[i]].num_impegni--;
               printf("%s",utente[agenda.indice[i]].description[j]);
               break;
            }
         }
      break;
      }
   }

//questa function inserisce nuovi appuntamenti in agenda
void aggiorna(){
   int i,j;
   for(i=0;i<agenda.num_utenti;i++){      
         for(j=0;j<MAX_IMPEGNI;j++){
         if(utente[agenda.indice[i]].ora[j]==-1){
            printf("Definire impegno\n");
            do{
               printf("Inserisci l' ora in cui vuoi inserire l' impegno:\t");
               scanf("%d",&utente[agenda.indice[i]].ora[j]);
               fflush(stdin);
            }while(utente[agenda.indice[i]].ora[j] > MAX_ORA || utente[agenda.indice[i]].ora[j] < 0);
            do{
               printf("\nInserisci il giorno in cui vuoi inserire l' impegno:\t");
               scanf("%d",&utente[agenda.indice[i]].giorno[j]);
               fflush(stdin);
            }while((utente[agenda.indice[i]].giorno[j] > MAX_GIORNI) || (utente[agenda.indice[i]].giorno[j] <= 0));

            do{
               printf("\nInserisci l' anno in cui vuoi inserire l' impegno:\t");
               scanf("%d",&utente[agenda.indice[i]].anno[j]);
               fflush(stdin);
            }while(utente[agenda.indice[i]].anno[j] < MAX_ANNO);

            do{
               printf("\nInserisci il mese in cui vuoi inserire l' impegno:\t");
               scanf("%d",&utente[agenda.indice[i]].mese[j]);
               fflush(stdin);
            }while(utente[agenda.indice[i]].mese[j] > MAX_MESE || utente[agenda.indice[i]].mese[j] <= 0);

            printf("\nInserisci la descrizione del tuo impegno:\t");
            scanf("%s",&utente[agenda.indice[i]].description[j]);
            utente[agenda.indice[i]].num_impegni++;
            printf("\nImpegno inserito.\n");
            break;
           }
         }
        break;
      }
   }

//questo main serve per inserire disdire visualizzare ed uscire dall'agenda dopo la registrazione 
int main(){
   srand(time(NULL));
   char cosa_fare;
   int flag=0;
   inizializza();
   crea_agenda();
   while(flag==0)
   {

      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("~ Benvenuto/a nella proria agenda elettronica ~\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("Digitare la propria scelta\n");
      printf("'A' per Visualizzare un appuntamento\n");
      printf("'I' per Inserire un appuntamento\n");
      printf("'D' per Disdire un appuntamento\n");
      printf("'E' per Uscire dall'agenda elettronica\n");
      printf("Inserire la propria scelta:\t");

       cosa_fare= getchar();
       fflush(stdin);
       system("cls");
       if(cosa_fare == 'a' || cosa_fare == 'A'){
          visualizza();
       }
       if(cosa_fare == 'i' || cosa_fare == 'I'){
          aggiorna();
       }
       if(cosa_fare == 'D' || cosa_fare == 'd'){
          disdire();
       }
       if(cosa_fare == 'E' || cosa_fare == 'e'){
           printf("Ciao e' stato un piacere esserti stato utile\n");
           flag=1;
       }
   system("pause");
   }
     return 0;
}