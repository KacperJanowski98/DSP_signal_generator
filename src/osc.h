/**
 * @file osc.h
 * @author Kacper Janowski
 * @brief 
 * @version 0.1
 * @date 2021-05-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef OSC_H_
#define OSC_H_

// include
#include "stdint.h"
#include "math.h"

// define
#define pdsp_sinf(fi)       sinf(fi)  
#define pdsp_asinf(fii)		asinf(fii)
#define FS					8000.0f
#define PDSP_2PI_DIV_FS     ((M_PI *2.0f)/FS)

/**
 * @brief Structure with oscillator parameters
 * 
 */
typedef struct {
	uint8_t type;	// 1 - harmoniczny, 2 - prostokatny, 3 - trojkatny, 4 - sygnal losowy o rozkladzie rownomiernym, 5 - sygnal losowy o rozkladzie normalnym
	float amplitude;
	float frequency;
	int n;
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
void OSC_Init(OSC_Cfg_t *cfg, float A, float f, float sfill);

/**
 * @brief Generator executing function
 * 
 * @param cfg Generator structure
 * @return int8_t The function returns the determined signal samples
 */
int OSC_GetValue(OSC_Cfg_t *cfg);

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

/**
 * @brief Method to set fill signal
 * 
 * @param cfg Generator structure
 * @param fill Fill parameter
 */
void OSC_SetFill (OSC_Cfg_t *cfg, float fill);

/**
 * @brief Method to set type of the oscillator
 * 
 * @param cfg Generator structure
 * @param type 1 - harmoniczny, 2 - prostokatny, 3 - trojkatny, 4 - sygnal losowy o rozkladzie rownomiernym, 5 - sygnal losowy o rozkladzie normalnym
 */
void OSC_SetType (OSC_Cfg_t *cfg, uint8_t type);

#endif  // OSC_H_