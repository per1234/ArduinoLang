#ifndef UTILITY_H
#define UTILITY_H

/*
 *
 * Created by Jeferson Lima
 *
 * This header provide macro expansions based on tutorial
 * https://codecraft.co/2014/11/25/variadic-macros-tricks/
 * and some other utilities in order to translate the wiring
 * and c++ language.
 *
 */

// Accept any number of args >= N, but expand to just the Nth one.
// Here, N == 6.
#define _GET_NTH_ARG(_1, _2, _3, _4, _5, N, ...) N

// Define some macros to help us create overrides based on the
// arity of a for-each-style macro.
#define _fe_0(_call, ...)
#define _fe_1(_call, x) _call(x)
#define _fe_2(_call, x, ...) _call(x) _fe_1(_call, __VA_ARGS__)
#define _fe_3(_call, x, ...) _call(x) _fe_2(_call, __VA_ARGS__)
#define _fe_4(_call, x, ...) _call(x) _fe_3(_call, __VA_ARGS__)

/**
 * Provide a for-each construct for variadic macros. Supports up
 * to 4 args.
 *
 * Example usage1:
 *     #define FWD_DECLARE_CLASS(cls) class cls;
 *     CALL_MACRO_X_FOR_EACH(FWD_DECLARE_CLASS, Foo, Bar)
 *
 * Example usage 2:
 *     #define START_NS(ns) namespace ns {
 *     #define END_NS(ns) }
 *     #define MY_NAMESPACES System, Net, Http
 *     CALL_MACRO_X_FOR_EACH(START_NS, MY_NAMESPACES)
 *     typedef foo int;
 *     CALL_MACRO_X_FOR_EACH(END_NS, MY_NAMESPACES)
 */
#define CALL_MACRO_X_FOR_EACH(x, ...) \
    _GET_NTH_ARG("ignored", ##__VA_ARGS__, \
	_fe_4, _fe_3, _fe_2, _fe_1, _fe_0)(x, ##__VA_ARGS__)


// Overload macro
#define GET_MACRO(_1,_2,NAME,...) NAME

#endif
