#include "osc.h"

void OSC_Init(OSC_Cfg_t *cfg, float A, float f, float sfill, uint8_t tp){
	cfg->amplitude = A;
	cfg->frequency = f;
	cfg->n = 0;
	cfg->fill = sfill;
	cfg->type = tp;
}

int8_t OSC_GetValue(OSC_Cfg_t *cfg){
	float y;
	float sample_fill;
	switch (cfg->type)
	{
	case 1:		// type = 1 - sygnal harmoniczny
		y = cfg->amplitude * pdsp_sinf(PDSP_2PI_DIV_FS * cfg->frequency * cfg->n);
		cfg->n++;
		break;
	case 2:		// type = 2 - sygnal prostokatny
		sample_fill = (cfg->fill/100.0f)*(FS/cfg->frequency);

    	if(cfg->n % (uint8_t)(FS/cfg->frequency) >= (uint8_t)sample_fill)
   		{
    		cfg->n++;
    		y = cfg->amplitude;
    	}
    	else{
    		cfg->n++;
    		y = -(cfg->amplitude);
		}
		break;
	default:
		break;
	}
	return (int8_t)y;
}

void OSC_SetFrequency(OSC_Cfg_t *cfg, float f){
	cfg->frequency = f;
}

void OSC_SetAmplitude(OSC_Cfg_t *cfg, float A){
	cfg->amplitude = A;
}

///////////////

// float sign_function(float wynik){
// 	//return (wynik > 0) ? 1 : ((wynik < 0) ? -1 : 0);
// 	if (wynik > 0) return 1;
// 	if (wynik < 0) return -1;
// 	return 0;
// }

// int8_t OSC_GetSquer(OSC_Cfg_t *cfg){
// 	float y;
	
// 	float wynik = cfg->amplitude * (PDSP_2PI_DIV_FS * cfg->frequency * cfg->n);
// 	y = sign_function(wynik);
// 	cfg->n++;

// 	return (int8_t)y;
// }

// int8_t OSC_GetSquer(OSC_Cfg_t * cfg){
//     float y;
//     float sample_fill = (cfg->fill/100.0f)*(FS/cfg->frequency);

//     if(cfg->n % (uint8_t)(FS/cfg->frequency) >= (uint8_t)sample_fill)
//     {
//     	cfg->n++;
//     	return -(cfg->amplitude);
//     }
//     else{
//     	cfg->n++;
//     	return cfg->amplitude;
// 	}
// }

