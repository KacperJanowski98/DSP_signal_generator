#ifndef OSC_H_
#define OSC_H_

#include "stdint.h"
#include "math.h"

#define pdsp_sinf(fi)       sinf(fi)   
#define PDSP_2PI_DIV_FS     ((M_PI *2.0f)/8000.0f)

/**
 * @brief Structure with oscillator parameters
 * 
 */
typedef struct {
	//GenType
	float amplituda;
	float frequency;
	uint32_t n;
}OSC_Cfg_t;

/**
 * @brief Oscillator initialization method
 * 
 * @param cfg Generator structure
 * @param A Amplitude
 * @param f Frequency
 */
void OSC_Init(OSC_Cfg_t *cfg, float A, float f);

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

#endif  // OSC_H_