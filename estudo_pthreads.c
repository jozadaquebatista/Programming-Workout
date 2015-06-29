#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* função que será usada nas threads */
void *myfunc(void *myvar);

int main()
{
    setlocale(0, "portuguese");

    pthread_t thread01,
              thread02,
              thread03,
              thread04,
              thread05,
              thread06,
              thread07,
              thread08,
              thread09,
              thread10;
    
    char *msg01 = "01 Primeira Thread!",
         *msg02 = "02 Segunda Thread!",
         *msg03 = "03 Terceira Thread!",
         *msg04 = "04 Quarta Thread!",
         *msg05 = "05 Quinta Thread!",
         *msg06 = "06 Sexta Thread!",
         *msg07 = "07 Sétima Thread!",
         *msg08 = "08 Oitava Thread!",
         *msg09 = "09 Nona Thread!",
         *msg10 = "10 Décima Thread!";         
         
    int ret01, 
        ret02,
        ret03,
        ret04,
        ret05,
        ret06,
        ret07,
        ret08,
        ret09,
        ret10;
         
    ret01 = pthread_create(&thread01, NULL, myfunc, (void*)msg01);
    ret02 = pthread_create(&thread02, NULL, myfunc, (void*)msg02);
    ret03 = pthread_create(&thread03, NULL, myfunc, (void*)msg03);
    ret04 = pthread_create(&thread04, NULL, myfunc, (void*)msg04);
    ret05 = pthread_create(&thread05, NULL, myfunc, (void*)msg05);
    ret06 = pthread_create(&thread06, NULL, myfunc, (void*)msg06);
    ret07 = pthread_create(&thread07, NULL, myfunc, (void*)msg07);
    ret08 = pthread_create(&thread08, NULL, myfunc, (void*)msg08);
    ret09 = pthread_create(&thread09, NULL, myfunc, (void*)msg09);
    ret10 = pthread_create(&thread10, NULL, myfunc, (void*)msg10);
    
    fprintf(stdout, "\n-------> [ Função principal após pthread_create ] <-------\n\n");
    
    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);
    pthread_join(thread03, NULL);
    pthread_join(thread04, NULL);
    pthread_join(thread05, NULL);
    pthread_join(thread06, NULL);
    pthread_join(thread07, NULL);
    pthread_join(thread08, NULL);
    pthread_join(thread09, NULL);
    pthread_join(thread10, NULL);
    
    fprintf(stdout, "\nPrimeira thread ret01 = %d\n", ret01);
    fprintf(stdout, "Segunda thread ret02 = %d\n", ret02);
    fprintf(stdout, "Terceira thread ret03 = %d\n", ret03);
    fprintf(stdout, "Quarte thread ret04 = %d\n", ret04);
    fprintf(stdout, "Quinta thread ret05 = %d\n", ret05);
    fprintf(stdout, "Sexta thread ret06 = %d\n", ret06);
    fprintf(stdout, "Sétima thread ret07 = %d\n", ret07);
    fprintf(stdout, "Oitava thread ret08 = %d\n", ret08);
    fprintf(stdout, "Nona thread ret09 = %d\n", ret09);
    fprintf(stdout, "Décima thread ret10 = %d\n\n", ret10);

    return 0;
}

void *myfunc(void *myvar)
{
    char *msg;
    msg = (char*)myvar;
    
    for(int i=0; i<10; i++)
    {
        fprintf(stdout, "(%d) %s %d\n", i+1, msg, i);
        for(int i=0; i<1000000000; i++);
    }
    return NULL;
}
