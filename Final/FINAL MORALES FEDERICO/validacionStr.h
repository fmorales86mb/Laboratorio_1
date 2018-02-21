#ifndef VALIDACIONSTR_H_INCLUDED
#define VALIDACIONSTR_H_INCLUDED

int soloNumeros(char str[]);
int soloLetras(char str[]);
int soloTelefono(char str[]);
int soloAlfanumerico(char str[]);
int subString (char* str, char* subStr, int desde, int posicion);
int primerPosicionDe (char* str, int desde, char caracter);

#endif // VALIDACIONSTR_H_INCLUDED
