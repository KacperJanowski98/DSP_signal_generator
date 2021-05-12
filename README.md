# DSP_signal_generator

A function in C language for creating a programmable oscillator that can determine the value of the next sample based on:
amplitudes - actual value in mV in the range from 0 to 1650, if the saturation range is exceeded;
frequency - actual value in Hz in the range from 0 to Fs / 2 (Fs - sampling frequency);
sample number - positive integer value;
fills - actual value from 0 to 100;

The oscillators are implemented:
harmonic (e.g. sinusoidal);
rectangular;
triangular (the fill affects the slope rise time, the extreme for 0 or 100 is a sawtooth signal);
random with even distribution (random value from the range + - amplitude every S samples);
random, normally distributed (amplitude corresponds to 3 standard deviations, expected value is 0).
