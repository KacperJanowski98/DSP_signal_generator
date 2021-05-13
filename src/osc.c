#include "osc.h"

void OSC_Init(OSC_Cfg_t *cfg, float A, float f){
	cfg->amplituda = A;
	cfg->frequency = f;
	cfg->n = 0;
}

int8_t OSC_GetValue(OSC_Cfg_t *cfg){
	float y;
	y = cfg->amplituda * pdsp_sinf(PDSP_2PI_DIV_FS * cfg->frequency * cfg->n);
	cfg->n++;

	return (int8_t)y;
}

void OSC_SetFrequency(OSC_Cfg_t *cfg, float f){
	cfg->frequency = f;
}

void OSC_SetAmplitude(OSC_Cfg_t *cfg, float A){
	cfg->amplituda = A;
}