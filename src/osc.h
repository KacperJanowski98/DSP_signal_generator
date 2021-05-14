#ifndef OSC_H_
#define OSC_H_

#include "stdint.h"
#include "math.h"

#define pdsp_sinf(fi)       sinf(fi)  
#define FS					8000.0f
#define PDSP_2PI_DIV_FS     ((M_PI *2.0f)/FS)

/**
 * @brief Structure with oscillator parameters
 * 
 */
typedef struct {
	uint8_t type;
	float amplitude;
	float frequency;
	uint32_t n;
	float fill;
}OSC_Cfg_t;

/**
 * @brief Oscillator initialization method
 * 
 * @param cfg Oscillator structire
 * @param A Aamplitude
 * @param f Frequency
 * @param sfill Fill signal
 * @param tp type of oscillator
 */
void OSC_Init(OSC_Cfg_t *cfg, float A, float f, float sfill, uint8_t tp);

/**
 * @brief Generator executing function
 * 
 * @param cfg Generator structure
 * @return int8_t The function returns the determined signal samples
 */
int8_t OSC_GetValue(OSC_Cfg_t *cfg);

/**
 * @brief Method for setting the oscillator frequency
 * 
 * @param cfg Generator structure
 * @param f Frequency
 */
void OSC_SetFrequency(OSC_Cfg_t *cfg, float f);

/**
 * @brief Method to set the amplitude of the oscillator
 * 
 * @param cfg Generator structure
 * @param A Amplitude
 */
void OSC_SetAmplitude(OSC_Cfg_t *cfg, float A);

//////////////

// float sign_function(float wynik);

// int8_t OSC_GetSquer(OSC_Cfg_t * cfg);

#endif  // OSC_H_