/**
 * @file osc.c
 * @author Kacper Janowski
 * @brief 
 * @version 0.1
 * @date 2021-05-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "osc.h"

void OSC_Init(OSC_Cfg_t *cfg, float A, float f, float sfill){
	cfg->amplitude = A;
	cfg->frequency = f;
	cfg->n = 0;
	cfg->fill = sfill;
	cfg->type;
}

int OSC_GetValue(OSC_Cfg_t *cfg){
	float y;
	float sample_fill;
	switch (cfg->type)
	{
	case 1:		// type = 1 - sygnal harmoniczny
		y = cfg->amplitude * pdsp_sinf(PDSP_2PI_DIV_FS * cfg->frequency * cfg->n);
		cfg->n++;
		break;
	case 2:		// type = 2 - sygnal prostokatny
		sample_fill = (cfg->fill/100.0f)*(FS/cfg->frequency); // obliczenie wspolczynnika wypelnienia wzgledem podanje czestotliwosci

		// jezeli probka jest w przedziale podanego wypelnienia to jest + amplituda jezeli jest poza przedzialem czestotliwosci 
		// wypelnienia to jest - amplituda
		cfg->n++;
    	if(cfg->n % (int)(FS/cfg->frequency) >= (int)sample_fill) 
   		{	
    		y = cfg->amplitude;
    	}
    	else{
    		y = -(cfg->amplitude);
		}
		break;
	case 3:		// type = 3 - sygnal trojkatny
		sample_fill = (cfg->fill/100.0f)*(FS/cfg->frequency);
		y = (2 * cfg->amplitude) / M_PI * pdsp_asinf(pdsp_sinf((PDSP_2PI_DIV_FS * cfg->frequency * cfg->n) / (int)sample_fill));
		cfg->n++;
		break;
	case 4:		// type = 4 - sygnal losowy o rozkladzie rownomiernym

		break;
	case 5:		// type = 5 - sygnal losowy o rozkladzie normalnym

		break;
	default:
		break;
	}
	return (int)y;
}

void OSC_SetFrequency(OSC_Cfg_t *cfg, float f){
	cfg->frequency = f;
}

void OSC_SetAmplitude(OSC_Cfg_t *cfg, float A){
	cfg->amplitude = A;
}

void OSC_SetFill (OSC_Cfg_t *cfg, float fill){
	cfg->fill = fill;
}

void OSC_SetType (OSC_Cfg_t *cfg, uint8_t type){
	cfg->type = type;
}
