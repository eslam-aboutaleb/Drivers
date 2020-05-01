/* ///////////////////////////////////////////////////////////////////////////
 * BIT_MATH.h
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#ifndef BIT_MATH_H
#define BIT_MATH_H

/* STD TYPES FUNCTIONS */

/*SET BIT */
#define SET_BIT(REG,BIT)           REG|=(1<<BIT)
/*Clear BIT */
#define CLEAR_BIT(REG,BIT)         REG&=~(1<<BIT)
/*Toggle BIT */
#define TOGGLE_BIT(REG,BIT)        REG^=(1<<BIT)
/*Read BIT */
#define GET_BIT(REG,BIT)         ((REG>>BIT)&1)
/*check if a specified Bit is Set*/
#define BIT_IS_SET(REG,BIT)      ((REG>>BIT)&1)
/*Check if a specified BIT is Clear*/
#define BIT_IS_CLEAR(REG,BIT)  (!((REG>>BIT)&1))







#endif

