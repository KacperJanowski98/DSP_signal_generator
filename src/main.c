#include "stdio.h"
#include "osc.h"

FILE *f;

OSC_Cfg_t Gen1; 

int main(int argc, char const *argv[])
{
    //printf("Liczba argumentow: %d, argument nr.0: %s", argc, argv[0]);
    OSC_Init(&Gen1, 100, 1000);

    f = fopen("test.m", "w");

    fprintf(f,"y = [");
    for (uint32_t i = 0; i < 9; i++){
        fprintf(f, "%d, ", OSC_GetValue(&Gen1));
    }
    fprintf(f, "%d];", OSC_GetValue(&Gen1));

    fclose(f);

    return 0;
}