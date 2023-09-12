/*
 * STD_TYPES.h
 *
 * Created: 8/21/2023 11:53:29 PM
 *  Author: HashimAbdulAzizHashi
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define CPU_TYPE_8	 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64

#define CPU_TYPE (CPU_TYPE_8)

#if(CPU_TYPE == CPU_TYPE_8)
typedef unsigned char			 u8;
//typedef unsigned short		u16;
//typedef unsigned int			u16;
typedef unsigned short int		u16;
//typedef unsigned long			u32;
//typedef unsigned short long	u24;
typedef unsigned long	int		u32;
typedef unsigned long long int  u64;
//typedef unsigned long long	u64;
typedef signed char				 s8;
//typedef signed short			s16;
//typedef signed int			s16;
typedef signed short int		s16;
//typedef signed long			s32;
//typedef signed short long		s24;
typedef signed long	int			s32;
typedef signed long long int	s64;
//typedef signed long long int	s64;
typedef float					f32;
typedef double					f64;

#elif(CPU_TYPE == CPU_TYPE_16)
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int u32;
typedef signed long long s64;
typedef float f32;
typedef double f64;

#elif(CPU_TYPE == CPU_TYPE_32)
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int u32;
typedef signed long long s64;
typedef float f32;
typedef double f64;

#elif(CPU_TYPE == CPU_TYPE_64)
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int u32;
typedef signed long long s64;
typedef float f32;
typedef double f64;
#endif

#endif /* STD_TYPES_H_ */