#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

#endif // INPUT_H_INCLUDED
