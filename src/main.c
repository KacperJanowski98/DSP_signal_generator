#include "stdio.h"
#include "osc.h"

FILE *f;

OSC_Cfg_t Gen1; 

int main(int argc, char const *argv[])
{
    int type_Gen; 
    float amp;
    float freq;
    float fill_sig;
    uint32_t number_s;
    int con = 1;

    printf("Wybierz oscylator:\n");
    printf("1. Sygnal harmoniczny\n");
    printf("2. Sygnal prostokatny\n");
    printf("3. Sygnal losowy o rozkladzie rownomiernym\n");
    printf("4. Sygnal losowy o rozkladzie normalnym\n");

    scanf("%d", &type_Gen);

    switch (type_Gen)
    {
    case 1:
        while (con){
            printf("Podaj wartosc amplitudy w mV w zakresie od 0 do 1650\n");
            scanf("%f", &amp);
            if (amp > 1650.0f){
                printf("Nasycenie\n");
            } else {
                printf("Poprawna wartosc\n");
                con = 0;
            }
        }
        con = 1;
        while (con){
            printf("Podaj wartosc czestotliwosci nie wieksza niz 4000 hz\n");
            scanf("%f", &freq);
            if (freq >= 4000.0f){
                printf("Za duza wartosc!\n");
            } else {
                printf("Poprawna wartosc\n");
                con = 0;
            }
        }

        printf("Podaj liczbe probek\n");
        scanf("%d", &number_s);

        OSC_Init(&Gen1, amp, freq);

        f = fopen("test.m", "w");

        fprintf(f,"y = [");
        for (uint32_t i = 0; i < number_s; i++){
            fprintf(f, "%d, ", OSC_GetValue(&Gen1));
        }
        fprintf(f, "%d];", OSC_GetValue(&Gen1));

        fclose(f);

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    default:

        break;
    }

    return 0;
}