/*
 * BIT_MATH.h
 *
 * Created: 8/22/2023 12:38:41 AM
 *  Author: HashimAbdulAzizHashi
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, bit) reg |= (1<<bit)
#define CLR_BIT(reg, bit) reg &= (~(1<<bit))
#define TOG_BIT(reg, bit) reg ^= (1<<bit)
//#define GET_BIT(reg, bit) (reg & (1<<bit))>>bit
#define GET_BIT(reg, bit) (reg>>bit)&1
#define IS_BIT_SET(reg, bit) (reg & (1<<bit))>>bit
#define IS_BIT_CLR(reg, bit) !((reg & (1<<bit))>>bit)
//#define ROR(reg, bit) reg = (reg<<(REGISTER_SIZE-num))|(reg>>(num))
//#define ROL(reg, bit) reg = (reg>>(REGISTER_SIZE-num))|(reg<<(num))




#endif /* BIT_MATH_H_ */