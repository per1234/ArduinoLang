#ifndef PT_PORTUGOL_H
#define PT_PORTUGOL_H

#include "utility.h"

/*
 *
 * Created By Jeferson Lima
 *
 * Portuguese language with portugol (pseudolanguage-style)
 * this is a pseudo language bind to arduino program
 *
 */

// Prevent errors of expected comma
#define PREVENT_SEMICOLON_ERROR ;

// Define symbols as names
#define inicio {
#define fim PREVENT_SEMICOLON_ERROR }

// Recreate lasso to apear more like portugol
#define se PREVENT_SEMICOLON_ERROR if( 
#define entao ){
#define senaose PREVENT_SEMICOLON_ERROR } else if (
#define senao PREVENT_SEMICOLON_ERROR } else {
#define fimse PREVENT_SEMICOLON_ERROR }

// Redefine declarations
#define algoritmo int main()
#define fim_algoritmo }

// Redefine functions
#define variavel_numerica "%d"
#define variavel_decimal "%f"
#define escreva(text, ...) PREVENT_SEMICOLON_ERROR printf(text "\n", ## __VA_ARGS__);

// Redefine functions more difficults
#define leia_inteiro(number) PREVENT_SEMICOLON_ERROR scanf("%d", &number);

// Redefine reserved words
#define retorna PREVENT_SEMICOLON_ERROR return

// Redefine types
#define numerico(name) int name;
#define decimal(name) float name;

// And then the function to declare any number of vars
#define declare(tipo, ...) PREVENT_SEMICOLON_ERROR CALL_MACRO_X_FOR_EACH(tipo, __VA_ARGS__)

// While in portugol style
#define enquanto PREVENT_SEMICOLON_ERROR while(
#define faca )

// For in portugol style
#define para PREVENT_SEMICOLON_ERROR for(
#define de = 
#define ate(X, Y) ; X <= Y ; X++

// Basic arduino reserved function name
#define configura void setup()
#define algoritmo void loop()

// Basic Arduino Functions
#define modoPino(pin, mode) PREVENT_SEMICOLON_ERROR pinMode(pin, mode);
#define escrevaDigital(pin, state) PREVENT_SEMICOLON_ERROR digitalWrite(pin, state);
#define leiaDigital(pin) PREVENT_SEMICOLON_ERROR digitalRead(pin);
#define leiaAnalogico(pin) PREVENT_SEMICOLON_ERROR analogRead(pin);
#define escrevaAnalogico(pin, value) PREVENT_SEMICOLON_ERROR analogWrite(pin, value);
#define espera(time) PREVENT_SEMICOLON_ERROR delay(time);

// Constants
#define ALTO HIGH
#define BAIXO LOW
#define LIGADO HIGH
#define DESLIGADO LOW
#define SAIDA OUTPUT
#define ENTRADA INPUT
#define ENTRADA_PULLUP INPUT_PULLUP
#define LED_INTEGRADO LED_BUILTIN

// Time constants
#define MEIO_SEGUNDO 500
#define UM_SEGUNDO 1000
#define DOIS_SEGUNDOS 2000
#define TRES_SEGUNDOS 3000

#endif
