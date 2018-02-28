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
#define fim_algoritmo PREVENT_SEMICOLON_ERROR }

// Recreate lasso to apear more like portugol
#define se PREVENT_SEMICOLON_ERROR if( 
#define entao ){
#define senaose PREVENT_SEMICOLON_ERROR } else if (
#define senao PREVENT_SEMICOLON_ERROR } else {
#define fimse PREVENT_SEMICOLON_ERROR }

// Redefine functions
#define variavel_numerica "%d"
#define variavel_decimal "%f"
#define escreva(_TEXT, ...) PREVENT_SEMICOLON_ERROR printf(_TEXT "\n", ## __VA_ARGS__);

// Redefine functions more difficults
#define leia_inteiro(_NUMBER) PREVENT_SEMICOLON_ERROR scanf("%d", &_NUMBER);

// Redefine reserved words
#define retorna PREVENT_SEMICOLON_ERROR return

// Redefine types
#define declareType(_TYPE, _NAME) PREVENT_SEMICOLON_ERROR _TYPE _NAME;
#define numerico1(_NAME) declareType(int, _NAME)
#define decimal1(_NAME) declareType(float, _NAME)

// Types with values
#define declareTypeValue(_TYPE, _NAME, _VALUE) PREVENT_SEMICOLON_ERROR _TYPE _NAME = _VALUE;
#define numerico2(_NAME, _VALUE) declareTypeValue(int, _NAME, _VALUE)
#define decimal2(_NAME, _VALUE) declareTypeValue(float, _NAME, _VALUE)

// Overloaded declare functions
#define numerico(...) GET_MACRO(__VA_ARGS__, numerico2, numerico1)(__VA_ARGS__)
#define decimal(...) GET_MACRO(__VA_ARGS__, decimal2, decimal1)(__VA_ARGS__)

// And then the function to declare any number of vars
#define declare(_TYPE, ...) PREVENT_SEMICOLON_ERROR CALL_MACRO_X_FOR_EACH(_TYPE, __VA_ARGS__)

// While in portugol style
#define enquanto PREVENT_SEMICOLON_ERROR while(
#define faca )

// For in portugol style
#define para PREVENT_SEMICOLON_ERROR for(
#define de = 
#define ate(_X, _Y) ; _X <= _Y ; _X++

// Basic arduino reserved function name
#define configura void setup()
#define algoritmo void loop()

// Basic void Arduino Functions
#define modoPino(_PIN, _MODE) PREVENT_SEMICOLON_ERROR pinMode(_PIN, _MODE);
#define escrevaDigital(_PIN, _STATE) PREVENT_SEMICOLON_ERROR digitalWrite(_PIN, _STATE);
#define escrevaAnalogico(_PIN, _VALUE) PREVENT_SEMICOLON_ERROR analogWrite(_PIN, _VALUE);
#define espera(_TIME) PREVENT_SEMICOLON_ERROR delay(_TIME);

// Basic functions with return
#define leiaAnalogico(_PIN) analogRead(_PIN);
#define leiaDigital(_PIN) digitalRead(_PIN);

// Methods
#define comecar begin
#define imprime(_TEXT) println(_TEXT);
#define imprimeln(_TEXT) print(_TEXT);

// Constants
#define ALTO HIGH
#define BAIXO LOW
#define LIGADO HIGH
#define DESLIGADO LOW
#define SAIDA OUTPUT
#define ENTRADA INPUT
#define ENTRADA_PULLUP INPUT_PULLUP
#define LED_INTEGRADO LED_BUILTIN

// Boolean functions
#define ou ||
#define e &&

// Time constants
#define MEIO_SEGUNDO 500
#define UM_SEGUNDO 1000
#define DOIS_SEGUNDOS 2000
#define TRES_SEGUNDOS 3000

#endif
