#include "stdio.h"
#include "stdint.h"
#include "math.h"

#define pdsp_sinf(fi)       sinf(fi)
#define PDSP_2PI_DIV_FS     ((M_PI *2.0f)/8000.0f)

FILE *f;

typedef struct {
	//GenType
	float amplituda;
	float frequency;
	uint32_t n;
}OSC_Cfg_t;

OSC_Cfg_t Gen1; 

int8_t OSC_GetValue(OSC_Cfg_t *cfg){
	float y;
	y = cfg->amplituda * pdsp_sinf(PDSP_2PI_DIV_FS * cfg->frequency * cfg->n);
	cfg->n++;

	return (int8_t)y;
}

void OSC_Init(OSC_Cfg_t *cfg, float A, float f){
	cfg->amplituda = A;
	cfg->frequency = f;
	cfg->n = 0;
}

void OSC_SetFrequency(OSC_Cfg_t *cfg, float f){
	cfg->frequency = f;
}

void OSC_SetAmplitude(OSC_Cfg_t *cfg, float A){
	cfg->amplituda = A;
}

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