/*
 * std_types.h
 *
 * Created: 10/7/2023 2:35:26 AM
 *  Author: Home™
 */ 
/*..............include....*/
#include <avr/io.h>
#include <alloca.h>
/*..........macro declaration......*/
#define  E_NOK                     (Std_ReturnType)0x00
#define  E_OK                     (Std_ReturnType)0x01

/*.........macro function declaration......*/

/*.............data type declaration...........*/
typedef unsigned char   uint8 ;
typedef unsigned short  uint16;
typedef unsigned int    uint32 ;
typedef signed char     sint8 ;
typedef signed short    sint16;
typedef signed int      sint32 ;
typedef uint8           Std_ReturnType ;
/*...........software interfaces declaration........*/
