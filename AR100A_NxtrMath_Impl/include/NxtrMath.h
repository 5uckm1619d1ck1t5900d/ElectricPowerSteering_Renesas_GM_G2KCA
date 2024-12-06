/**********************************************************************************************************************
* Copyright 2015 Nexteer 
* Nexteer Confidential
*
* Module File Name  : NxtrMath.h
* Module Description: Nexteer Math Library Header
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       nz4qtt %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 02/04/15  1        LWW       Initial Version                                                                 EA4#73	
* 09/29/15  2        Rijvi     Add new sine & cosine algorithm                                                 EA4#1758																
* 07/01/16  3        KK        Moving sine lookup function to the Nexteer math library from SF107A.            EA4#6438																
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef NXTRMATH_H
#define NXTRMATH_H

/************************************************ Include Statements *************************************************/
#include <math.h>
#include "Std_Types.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 1.1 [NXTRDEV 1.1.1]: Inline functions are used for Nexteer Math library macros to allow for throughput optimization */
/* MISRA-C:2004 Rule 8.5 [NXTRDEV 8.5.1]: Function definitions are required to be in a header for inline function usage */

/****************************************************** Macros *******************************************************/

/* MISRA-C:2004 Rule 19.7 [NXTRDEV 19.7.1]: This rule is only intended to apply in situations where a function call is permitted.  This macro is targeted 
											for the pre-processor to resolve to a constant and therefore a function call is not permitted */ 
#define TblSize_m(Tbl)   (sizeof(Tbl)/sizeof((Tbl)[0]))


/********************************************* Embedded Local Constants **********************************************/
#define SIN22PT5DEG_ULS_F32		0.3826834323650897717284599840304F  		   /* SIn(22.5deg) */ 
#define SIN45PT0DEG_ULS_F32		0.70710678118654752440084436210485F  		   /* Sin(45.0deg) */
#define SIN67PT5DEG_ULS_F32		0.92387953251128675612818318939679F 		   /* Sin(67.5deg) */
#define EIGHTOVERPI_ULS_F32     2.5464790894703253723021402139602F             /* (8.0F / 3.1415926535897932384626433832795F) */
#define PIOVEREIGHT_ULS_F32     0.39269908169872415480783042290994F            /* (3.1415926535897932384626433832795F / 8.0F) */
#define ONEOVERSIX_ULS_F32      0.16666666666666666666666666666667F            /* (1.0F/6.0F) */
#define ONEOVERTWO_ULS_F32      0.5F                                           /* (1.0F/2.0F) */
#define ONEOVER2PI_ULS_F32      0.1591549F		
#define ONEOVER2_ULS_F32        0.5F			
#define ONEOVER4_ULS_F32        0.25F
#define SINCNVNCON1_ULS_F32     2048.0F
#define SINCNVNCON2_ULS_F32     1.5259021e-05F		 


/*********************************************** Exported Declarations ***********************************************/
INLINE FUNC(float32, NxtrMath_CODE) Blnd_f32(float32 Inp1,
											 float32 Inp2,
											 float32 Fac);

INLINE FUNC(uint8, NxtrMath_CODE) Abslt_u08_s08(sint8 Inp);

INLINE FUNC(uint16, NxtrMath_CODE) Abslt_u16_s16(sint16 Inp);

INLINE FUNC(uint32, NxtrMath_CODE) Abslt_u32_s32(sint32 Inp);

INLINE FUNC(float32, NxtrMath_CODE) Abslt_f32_f32(float32 Inp);

INLINE FUNC(sint8, NxtrMath_CODE) Sign_s08_s08(sint8 Inp);

INLINE FUNC(sint8, NxtrMath_CODE) Sign_s08_s16(sint16 Inp);

INLINE FUNC(sint8, NxtrMath_CODE) Sign_s08_s32(sint32 Inp);

INLINE FUNC(sint8, NxtrMath_CODE) Sign_s08_f32(float32 Inp);

INLINE FUNC(sint8, NxtrMath_CODE) Min_s08(sint8 Inp1,
										sint8 Inp2);

INLINE FUNC(uint8, NxtrMath_CODE) Min_u08(uint8 Inp1,
										uint8 Inp2);

INLINE FUNC(sint16, NxtrMath_CODE) Min_s16(sint16 Inp1,
											sint16 Inp2);

INLINE FUNC(uint16, NxtrMath_CODE) Min_u16(uint16 Inp1,
											uint16 Inp2);

INLINE FUNC(sint32, NxtrMath_CODE) Min_s32(sint32 Inp1,
											sint32 Inp2);

INLINE FUNC(uint32, NxtrMath_CODE) Min_u32(uint32 Inp1,
											uint32 Inp2);

INLINE FUNC(float32, NxtrMath_CODE) Min_f32(float32 Inp1,
											float32 Inp2);

INLINE FUNC(sint8, NxtrMath_CODE) Max_s08(sint8 Inp1,
										sint8 Inp2);

INLINE FUNC(uint8, NxtrMath_CODE) Max_u08(uint8 Inp1,
										uint8 Inp2);

INLINE FUNC(sint16, NxtrMath_CODE) Max_s16(sint16 Inp1,
											sint16 Inp2);

INLINE FUNC(uint16, NxtrMath_CODE) Max_u16(uint16 Inp1,
											uint16 Inp2);

INLINE FUNC(sint32, NxtrMath_CODE) Max_s32(sint32 Inp1,
											sint32 Inp2);

INLINE FUNC(uint32, NxtrMath_CODE) Max_u32(uint32 Inp1,
											uint32 Inp2);

INLINE FUNC(float32, NxtrMath_CODE) Max_f32(float32 Inp1,
											float32 Inp2);	

INLINE FUNC(sint8, NxtrMath_CODE) Lim_s08(sint8 Inp,
											sint8 RngLo,
											sint8 RngHi);

INLINE FUNC(uint8, NxtrMath_CODE) Lim_u08(uint8 Inp,
											uint8 RngLo,
											uint8 RngHi);

INLINE FUNC(sint16, NxtrMath_CODE) Lim_s16(sint16 Inp,
											sint16 RngLo,
											sint16 RngHi);

INLINE FUNC(uint16, NxtrMath_CODE) Lim_u16(uint16 Inp,
											uint16 RngLo,
											uint16 RngHi);

INLINE FUNC(sint32, NxtrMath_CODE) Lim_s32(sint32 Inp,
											sint32 RngLo,
											sint32 RngHi);

INLINE FUNC(uint32, NxtrMath_CODE) Lim_u32(uint32 Inp,
											uint32 RngLo,
											uint32 RngHi);

INLINE FUNC(float32, NxtrMath_CODE) Lim_f32(float32 Inp,
												float32 RngLo,
												float32 RngHi);

INLINE FUNC(float32, NxtrMath_CODE) Arctan2_f32(float32 Numer,
												float32 Denom);

INLINE FUNC(float32, NxtrMath_CODE) Sin_f32(float32 Inp);

INLINE FUNC(float32, NxtrMath_CODE) Cos_f32(float32 Inp);

INLINE FUNC(float32, NxtrMath_CODE) Exp_f32(float32 Inp);

INLINE FUNC(float32, NxtrMath_CODE) Sqrt_f32(float32 Inp);

INLINE FUNC(float32, NxtrMath_CODE) Mod_f32(float32 Numer,
												float32 Denom);	
												
INLINE FUNC(void, NxtrMath_CODE) SinCos_f32(float32 Inp,
												float32* SinVal,
												float32* CosVal);	

INLINE FUNC(float32, NxtrMath_CODE) SinLookup(float32 MotCoggAg_Rad_T_f32);
								
												
/*****************************************************************************
*  Name:           Blnd_f32()
*  Description:    Unity gain blend of two input signals
*  Inputs:         Inp1 - first signal to be blended 
*				   Inp2 - second signal to be blended
*				   Fac - contribution of the second signal
*  Outputs:        Blended signal result
*  Usage Notes:    Fac input is constrained to min of 0.0 and max of 1.0 for
*                  proper functionality
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Blnd_f32(float32 Inp1,
											 float32 Inp2,
											 float32 Fac)
{
    return (((Inp1 * (1.0F - Fac)) + (Inp2 * Fac)));
}

/*****************************************************************************
*  Name:           Abslt_u08_s08()
*  Description:    8bit Absolute Value
*  Inputs:         Inp
*  Outputs:        Absolute Value of Input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint8, NxtrMath_CODE) Abslt_u08_s08(sint8 Inp)
{
	/* Rollover in the following line of code will occur if Inp is -128, however, type castings will provide proper overall result */
    return (((Inp)>=0)?((uint8)(Inp)):((uint8)(sint8)(-(Inp))));
}

/*****************************************************************************
*  Name:           Abslt_u16_s16()
*  Description:    16bit Absolute Value
*  Inputs:         Inp
*  Outputs:        Absolute Value of Input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint16, NxtrMath_CODE) Abslt_u16_s16(sint16 Inp)
{
	/* Rollover in the following line of code will occur if Inp is -32768, however, type castings will provide proper overall result */
    return (((Inp)>=0)?((uint16)(Inp)):((uint16)(sint16)(-(Inp))));
}

/*****************************************************************************
*  Name:           Abslt_u32_s32()
*  Description:    32bit Absolute Value
*  Inputs:         Inp
*  Outputs:        Absolute Value of Input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint32, NxtrMath_CODE) Abslt_u32_s32(sint32 Inp)
{
	/* Rollover in the following line of code will occur if Inp is -2147483648, however, type castings will provide proper overall result */
    return (((Inp)>=0)?((uint32)(Inp)):((uint32)(sint32)(-(Inp))));
}

/*****************************************************************************
*  Name:           Abslt_f32_f32()
*  Description:    Single Precision Float Absolute Value
*  Inputs:         Inp
*  Outputs:        Absolute Value of Input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Abslt_f32_f32(float32 Inp)
{
    return (fabsf(Inp));
}

/*****************************************************************************
*  Name:           Sign_s08_s08()
*  Description:    8bit Sign
*  Inputs:         Inp
*  Outputs:        Sign of input (inputs of zero treated as positive)
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint8, NxtrMath_CODE) Sign_s08_s08(sint8 Inp)
{
    return (((Inp)>=0)?((sint8)(1)):((sint8)-1));
}

/*****************************************************************************
*  Name:           Sign_s08_s16()
*  Description:    16bit Sign
*  Inputs:         Inp
*  Outputs:        Sign of input (inputs of zero treated as positive)
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint8, NxtrMath_CODE) Sign_s08_s16(sint16 Inp)
{
    return (((Inp)>=0)?((sint8)(1)):((sint8)-1));
}

/*****************************************************************************
*  Name:           Sign_s08_s32()
*  Description:    32bit Sign
*  Inputs:         Inp
*  Outputs:        Sign of input (inputs of zero treated as positive)
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint8, NxtrMath_CODE) Sign_s08_s32(sint32 Inp)
{
    return (((Inp)>=0)?((sint8)(1)):((sint8)-1));
}

/*****************************************************************************
*  Name:           Sign_s08_f32()
*  Description:    Single Precision Float Sign
*  Inputs:         Inp
*  Outputs:        Sign of input (inputs of zero treated as positive)
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint8, NxtrMath_CODE) Sign_s08_f32(float32 Inp)
{
    return (((Inp)>=0.0F)?((sint8)(1)):((sint8)-1));
}

/*****************************************************************************
*  Name:           Min_s08()
*  Description:    8bit signed minimum
*  Inputs:         Inp1, Inp2
*  Outputs:        Minimum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint8, NxtrMath_CODE) Min_s08(sint8 Inp1,
										sint8 Inp2)
{
    return (((Inp1)<=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Min_u08()
*  Description:    8bit unsigned minimum
*  Inputs:         Inp1, Inp2
*  Outputs:        Minimum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint8, NxtrMath_CODE) Min_u08(uint8 Inp1,
										uint8 Inp2)
{
    return (((Inp1)<=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Min_s16()
*  Description:    16bit signed minimum
*  Inputs:         Inp1, Inp2
*  Outputs:        Minimum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint16, NxtrMath_CODE) Min_s16(sint16 Inp1,
											sint16 Inp2)
{
    return (((Inp1)<=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Min_u16()
*  Description:    16bit unsigned minimum
*  Inputs:         Inp1, Inp2
*  Outputs:        Minimum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint16, NxtrMath_CODE) Min_u16(uint16 Inp1,
											uint16 Inp2)
{
    return (((Inp1)<=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Min_s32()
*  Description:    32bit signed minimum
*  Inputs:         Inp1, Inp2
*  Outputs:        Minimum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint32, NxtrMath_CODE) Min_s32(sint32 Inp1,
											sint32 Inp2)
{
    return (((Inp1)<=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Min_u32()
*  Description:    32bit unsigned minimum
*  Inputs:         Inp1, Inp2
*  Outputs:        Minimum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint32, NxtrMath_CODE) Min_u32(uint32 Inp1,
											uint32 Inp2)
{
    return (((Inp1)<=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Min_f32()
*  Description:    Single Precision Float minimum
*  Inputs:         Inp1, Inp2
*  Outputs:        Minimum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Min_f32(float32 Inp1,
											float32 Inp2)
{
    return (((Inp1)<=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Max_s08()
*  Description:    8bit signed maximum
*  Inputs:         Inp1, Inp2
*  Outputs:        Maximum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint8, NxtrMath_CODE) Max_s08(sint8 Inp1,
										sint8 Inp2)
{
    return (((Inp1)>=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Max_u08()
*  Description:    8bit unsigned maximum
*  Inputs:         Inp1, Inp2
*  Outputs:        Maximum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint8, NxtrMath_CODE) Max_u08(uint8 Inp1,
										uint8 Inp2)
{
    return (((Inp1)>=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Max_s16()
*  Description:    16bit signed maximum
*  Inputs:         Inp1, Inp2
*  Outputs:        Maximum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint16, NxtrMath_CODE) Max_s16(sint16 Inp1,
											sint16 Inp2)
{
    return (((Inp1)>=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Max_u16()
*  Description:    16bit unsigned maximum
*  Inputs:         Inp1, Inp2
*  Outputs:        Maximum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint16, NxtrMath_CODE) Max_u16(uint16 Inp1,
											uint16 Inp2)
{
    return (((Inp1)>=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Max_s32()
*  Description:    32bit signed maximum
*  Inputs:         Inp1, Inp2
*  Outputs:        Maximum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint32, NxtrMath_CODE) Max_s32(sint32 Inp1,
											sint32 Inp2)
{
    return (((Inp1)>=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Max_u32()
*  Description:    32bit unsigned maximum
*  Inputs:         Inp1, Inp2
*  Outputs:        Maximum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint32, NxtrMath_CODE) Max_u32(uint32 Inp1,
											uint32 Inp2)
{
    return (((Inp1)>=(Inp2))?(Inp1):(Inp2));
}

/*****************************************************************************
*  Name:           Max_f32()
*  Description:    Single Precision Float maximum
*  Inputs:         Inp1, Inp2
*  Outputs:        Maximum of Inp1 and Inp2
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Max_f32(float32 Inp1,
											float32 Inp2)
{
    return (((Inp1)>=(Inp2))?(Inp1):(Inp2));
}


/*****************************************************************************
*  Name:           Lim_s08()
*  Description:    8bit signed limit
*  Inputs:         Inp, RngLo, RngHi
*  Outputs:        Bounded value of input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint8, NxtrMath_CODE) Lim_s08(sint8 Inp,
											sint8 RngLo,
											sint8 RngHi)
{
    return (((Inp)>=(RngHi))?(RngHi):(((Inp)<=(RngLo))?(RngLo):(Inp)));
}

/*****************************************************************************
*  Name:           Lim_u08()
*  Description:    8bit unsigned limit
*  Inputs:         Inp, RngLo, RngHi
*  Outputs:        Bounded value of input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint8, NxtrMath_CODE) Lim_u08(uint8 Inp,
											uint8 RngLo,
											uint8 RngHi)
{
    return (((Inp)>=(RngHi))?(RngHi):(((Inp)<=(RngLo))?(RngLo):(Inp)));
}

/*****************************************************************************
*  Name:           Lim_s16()
*  Description:    16bit signed limit
*  Inputs:         Inp, RngLo, RngHi
*  Outputs:        Bounded value of input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint16, NxtrMath_CODE) Lim_s16(sint16 Inp,
											sint16 RngLo,
											sint16 RngHi)
{
    return (((Inp)>=(RngHi))?(RngHi):(((Inp)<=(RngLo))?(RngLo):(Inp)));
}

/*****************************************************************************
*  Name:           Lim_u16()
*  Description:    16bit unsigned limit
*  Inputs:         Inp, RngLo, RngHi
*  Outputs:        Bounded value of input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint16, NxtrMath_CODE) Lim_u16(uint16 Inp,
											uint16 RngLo,
											uint16 RngHi)
{
    return (((Inp)>=(RngHi))?(RngHi):(((Inp)<=(RngLo))?(RngLo):(Inp)));
}

/*****************************************************************************
*  Name:           Lim_s32()
*  Description:    32bit signed limit
*  Inputs:         Inp, RngLo, RngHi
*  Outputs:        Bounded value of input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(sint32, NxtrMath_CODE) Lim_s32(sint32 Inp,
											sint32 RngLo,
											sint32 RngHi)
{
    return (((Inp)>=(RngHi))?(RngHi):(((Inp)<=(RngLo))?(RngLo):(Inp)));
}

/*****************************************************************************
*  Name:           Lim_u32()
*  Description:    32bit unsigned limit
*  Inputs:         Inp, RngLo, RngHi
*  Outputs:        Bounded value of input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(uint32, NxtrMath_CODE) Lim_u32(uint32 Inp,
											uint32 RngLo,
											uint32 RngHi)
{
    return (((Inp)>=(RngHi))?(RngHi):(((Inp)<=(RngLo))?(RngLo):(Inp)));
}

/*****************************************************************************
*  Name:           Lim_f32()
*  Description:    Single Precision Float limit
*  Inputs:         Inp, RngLo, RngHi
*  Outputs:        Bounded value of input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Lim_f32(float32 Inp,
												float32 RngLo,
												float32 RngHi)
{
    return (((Inp)>=(RngHi))?(RngHi):(((Inp)<=(RngLo))?(RngLo):(Inp)));
}

/*****************************************************************************
*  Name:           Arctan2_f32()
*  Description:    Single Precision Float Arctangent 2
*  Inputs:         Numer, Denom
*  Outputs:        Arctangent of Num/Den
*  Usage Notes:    Numer and Denom must not be both zero
*                  The output is in the range of -pi to pi radians
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Arctan2_f32(float32 Numer,
												float32 Denom)
{
    return (atan2f(Numer, Denom));
}

/*****************************************************************************
*  Name:           Sin_f32()
*  Description:    Single Precision Float Sine
*  Inputs:         Inp
*  Outputs:        Sine of input
*  Usage Notes:    Inp must be in radians
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Sin_f32(float32 Inp)
{
    return (sinf(Inp));
}

/*****************************************************************************
*  Name:           Cos_f32()
*  Description:    Single Precision Float Cosine
*  Inputs:         Inp
*  Outputs:        Cosine of input
*  Usage Notes:    Inp must be in radians
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Cos_f32(float32 Inp)
{
    return (cosf(Inp));
}

/*****************************************************************************
*  Name:           Exp_f32()
*  Description:    Single Precision Float Exponential
*  Inputs:         Inp
*  Outputs:        Exponential of input
*  Usage Notes:    None
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Exp_f32(float32 Inp)
{
    return (expf(Inp));
}

/*****************************************************************************
*  Name:           Sqrt_f32()
*  Description:    Single Precision Float Square Root
*  Inputs:         Inp
*  Outputs:        Square Root of input
*  Usage Notes:    Input must not be negative
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Sqrt_f32(float32 Inp)
{
    return (sqrtf(Inp));
}

/*****************************************************************************
*  Name:           Mod_f32()
*  Description:    Single Precision Float Modulus
*  Inputs:         Numer, Denom
*  Outputs:        Remainder of Numer over Denom
*  Usage Notes:    The output sign is the same sign as Numer
*****************************************************************************/
INLINE FUNC(float32, NxtrMath_CODE) Mod_f32(float32 Numer,
												float32 Denom)
{
    return (fmodf(Numer, Denom));
}




/*****************************************************************************
*  Name:           SinCos_f32()
*  Description:    Optimized SinCos Algorithm
*  Inputs:         Inp, *SinVal, *CosVal
*  Outputs:        *SinVal = Sin(Inp) and *CosVal = Cosine(Inp)
*  Usage Notes:    Inp must be in radians.
*                  Input Range [-10000 to 10000]
*****************************************************************************/
INLINE FUNC(void, NxtrMath_CODE) SinCos_f32(float32 Inp,
												float32* SinVal,
												float32* CosVal)
{

	VAR(sint32,    AUTOMATIC)  n;
	VAR(uint8,     AUTOMATIC)  Normdn;
	VAR(float32,   AUTOMATIC)  InpSqd;
	VAR(float32,   AUTOMATIC)  SinA;
	VAR(float32,   AUTOMATIC)  CosA;
	VAR(float32,   AUTOMATIC)  Tmp; 
	
	
	Tmp = (Inp < 0.0F) ? ( (Inp * EIGHTOVERPI_ULS_F32) - 0.5F  ) : ( (Inp * EIGHTOVERPI_ULS_F32) + 0.5F ); 
	n = (sint32)Tmp;
	Inp = Inp - ((float32)n * PIOVEREIGHT_ULS_F32); 	/* Determine 'A' part of 'Inp' angle. 'Inp' = 'A' + 'n' * 'B' */
	Normdn = (uint8)( (uint32)n & 0x0000000FU ); 		/* Determine normalized 'n' */
	    
	InpSqd = Inp * Inp;

	SinA = Inp * ( 1.0F - (InpSqd * ONEOVERSIX_ULS_F32) );
	CosA = 1.0F - (InpSqd  * ONEOVERTWO_ULS_F32);
	
	
	switch ( Normdn )
	{
		case 0U:
			*SinVal = SinA;
			*CosVal = CosA;
			break;
			
		case 1U:
			*SinVal = (SIN67PT5DEG_ULS_F32 * SinA) + (SIN22PT5DEG_ULS_F32 * CosA);
			*CosVal = (-SIN22PT5DEG_ULS_F32 * SinA) + (SIN67PT5DEG_ULS_F32 * CosA);
			break;
			
		case 2U:
			*SinVal = (SIN45PT0DEG_ULS_F32 * SinA) + (SIN45PT0DEG_ULS_F32 * CosA);
			*CosVal = (-SIN45PT0DEG_ULS_F32 * SinA) + (SIN45PT0DEG_ULS_F32 * CosA);
			break;
			
		case 3U:
			*SinVal = (SIN22PT5DEG_ULS_F32 * SinA) + (SIN67PT5DEG_ULS_F32 * CosA);
			*CosVal = (-SIN67PT5DEG_ULS_F32 * SinA) + (SIN22PT5DEG_ULS_F32 * CosA);
			break;
			
		case 4U:
			*SinVal = CosA;
			*CosVal = -SinA;
			break;
			
		case 5U:
			*SinVal = (-SIN22PT5DEG_ULS_F32 * SinA) + (SIN67PT5DEG_ULS_F32 * CosA);
			*CosVal = (-SIN67PT5DEG_ULS_F32 * SinA) + (-SIN22PT5DEG_ULS_F32 * CosA);
			break;
			
		case 6U:
			*SinVal = (-SIN45PT0DEG_ULS_F32 * SinA) +  (SIN45PT0DEG_ULS_F32 * CosA);
			*CosVal = (-SIN45PT0DEG_ULS_F32 * SinA) + (-SIN45PT0DEG_ULS_F32 * CosA);
			break;
			
		case 7U:
			*SinVal = (-SIN67PT5DEG_ULS_F32 * SinA) + (SIN22PT5DEG_ULS_F32 * CosA);
			*CosVal = (-SIN22PT5DEG_ULS_F32 * SinA) + (-SIN67PT5DEG_ULS_F32 * CosA);
			break;
			
		case 8U:
			*SinVal = -SinA;
			*CosVal = -CosA;
			break;
			
		case 9U:
			*SinVal = (-SIN67PT5DEG_ULS_F32 * SinA) + (-SIN22PT5DEG_ULS_F32 * CosA);
			*CosVal =  (SIN22PT5DEG_ULS_F32 * SinA) + (-SIN67PT5DEG_ULS_F32 * CosA);
			break;
			
		case 10U:
			*SinVal = (-SIN45PT0DEG_ULS_F32 * SinA) + (-SIN45PT0DEG_ULS_F32 * CosA);
			*CosVal =  (SIN45PT0DEG_ULS_F32 * SinA) + (-SIN45PT0DEG_ULS_F32 * CosA);
			break;
			
		case 11U:
			*SinVal = (-SIN22PT5DEG_ULS_F32 * SinA) + (-SIN67PT5DEG_ULS_F32 * CosA);
			*CosVal =  (SIN67PT5DEG_ULS_F32 * SinA) + (-SIN22PT5DEG_ULS_F32 * CosA);
			break;
			
		case 12U:
			*SinVal = -CosA;
			*CosVal =  SinA;
			break;
			
		case 13U:
			*SinVal =  (SIN22PT5DEG_ULS_F32 * SinA) + (-SIN67PT5DEG_ULS_F32 * CosA);
			*CosVal =  (SIN67PT5DEG_ULS_F32 * SinA) +  (SIN22PT5DEG_ULS_F32 * CosA);
			break;
			
		case 14U:
			*SinVal =  (SIN45PT0DEG_ULS_F32 * SinA) + (-SIN45PT0DEG_ULS_F32 * CosA);
			*CosVal =  (SIN45PT0DEG_ULS_F32 * SinA) +  (SIN45PT0DEG_ULS_F32 * CosA);
			break;
			
		/* case 15U:   */
		default :
			*SinVal =  (SIN67PT5DEG_ULS_F32 * SinA) + (-SIN22PT5DEG_ULS_F32 * CosA);
			*CosVal =  (SIN22PT5DEG_ULS_F32 * SinA) +  (SIN67PT5DEG_ULS_F32 * CosA);
			break;
			
	}	
													
}


 /*****************************************************************************
 *
 *  Function Name:     SinLookup
 *	
 *  Description:       TrqCanc Sine lookup to improve throughput
 *
 *  Inputs:            MotCoggAg_Rad_T_f32  (angle in radians)
 *
 *  Outputs:           SinVal_Uls_T_f32 (Output sine value- Precision of p8)
 *
 *****************************************************************************/

 INLINE FUNC(float32, NxtrMath_CODE) SinLookup(float32 MotCoggAg_Rad_T_f32)
{
	VAR(float32, AUTOMATIC) Theta_Rev_T_f32;
	VAR(uint16,  AUTOMATIC) Theta_Cnt_T_u16;
	VAR(sint8, AUTOMATIC) SignFlip_Cnt_T_s08;
	VAR(float32, AUTOMATIC) SinVal_Uls_T_f32;
	CONST(uint16, AUTOMATIC) SINCNVNCONTBL_ULS_U16[513] =                													
	  { 0u,    201u,  402u,  603u,  804u,  1005u, 1206u, 1407u, 1608u, 1809u, 2010u, 2211u, 2412u, 2613u, 2814u, 3015u,
		3216u, 3416u, 3617u, 3818u, 4019u, 4219u, 4420u, 4621u, 4821u, 5022u, 5222u, 5422u, 5623u, 5823u, 6023u, 6223u,
		6424u, 6624u, 6824u, 7024u, 7223u, 7423u, 7623u, 7823u, 8022u, 8222u, 8421u, 8620u, 8820u, 9019u, 9218u, 9417u,
		9616u, 9815u, 10014u,10212u,10411u,10609u,10808u,11006u,11204u,11402u,11600u,11798u,11996u,12193u,12391u,12588u,
		12785u,12982u,13179u,13376u,13573u,13770u,13966u,14163u,14359u,14555u,14751u,14947u,15142u,15338u,15533u,15729u,
		15924u,16119u,16313u,16508u,16703u,16897u,17091u,17285u,17479u,17673u,17866u,18060u,18253u,18446u,18639u,18831u,
		19024u,19216u,19408u,19600u,19792u,19984u,20175u,20366u,20557u,20748u,20939u,21129u,21319u,21509u,21699u,21889u,
		22078u,22267u,22456u,22645u,22834u,23022u,23210u,23398u,23586u,23773u,23960u,24147u,24334u,24521u,24707u,24893u,
		25079u,25265u,25450u,25635u,25820u,26005u,26189u,26374u,26557u,26741u,26925u,27108u,27291u,27473u,27656u,27838u,
		28020u,28201u,28383u,28564u,28745u,28925u,29106u,29286u,29465u,29645u,29824u,30003u,30181u,30360u,30538u,30716u,
		30893u,31070u,31247u,31424u,31600u,31776u,31952u,32127u,32302u,32477u,32651u,32826u,32999u,33173u,33346u,33519u,
		33692u,33864u,34036u,34208u,34379u,34550u,34721u,34891u,35061u,35231u,35400u,35569u,35738u,35906u,36074u,36242u,
		36409u,36576u,36743u,36909u,37075u,37241u,37406u,37571u,37736u,37900u,38064u,38227u,38390u,38553u,38715u,38877u,
		39039u,39200u,39361u,39522u,39682u,39842u,40001u,40161u,40319u,40478u,40635u,40793u,40950u,41107u,41263u,41419u,
		41575u,41730u,41885u,42039u,42194u,42347u,42500u,42653u,42806u,42958u,43109u,43261u,43411u,43562u,43712u,43861u,
		44011u,44159u,44308u,44456u,44603u,44750u,44897u,45043u,45189u,45334u,45479u,45624u,45768u,45912u,46055u,46198u,
		46340u,46482u,46624u,46765u,46905u,47046u,47185u,47325u,47464u,47602u,47740u,47877u,48014u,48151u,48287u,48423u,
		48558u,48693u,48827u,48961u,49095u,49228u,49360u,49492u,49624u,49755u,49885u,50016u,50145u,50274u,50403u,50531u,
		50659u,50787u,50913u,51040u,51166u,51291u,51416u,51540u,51664u,51788u,51911u,52033u,52155u,52277u,52398u,52518u,
		52638u,52758u,52877u,52995u,53113u,53231u,53348u,53464u,53580u,53696u,53811u,53925u,54039u,54153u,54266u,54378u,
		54490u,54602u,54713u,54823u,54933u,55042u,55151u,55260u,55367u,55475u,55582u,55688u,55794u,55899u,56003u,56108u,
		56211u,56314u,56417u,56519u,56620u,56721u,56822u,56922u,57021u,57120u,57218u,57316u,57413u,57510u,57606u,57702u,
		57797u,57891u,57985u,58079u,58171u,58264u,58356u,58447u,58537u,58628u,58717u,58806u,58895u,58983u,59070u,59157u,
		59243u,59329u,59414u,59498u,59582u,59666u,59749u,59831u,59913u,59994u,60075u,60155u,60234u,60313u,60391u,60469u,
		60546u,60623u,60699u,60775u,60850u,60924u,60998u,61071u,61144u,61216u,61287u,61358u,61429u,61498u,61567u,61636u,
		61704u,61772u,61838u,61905u,61970u,62035u,62100u,62164u,62227u,62290u,62352u,62414u,62475u,62535u,62595u,62654u,
		62713u,62771u,62829u,62886u,62942u,62998u,63053u,63107u,63161u,63214u,63267u,63319u,63371u,63422u,63472u,63522u,
		63571u,63620u,63668u,63715u,63762u,63808u,63853u,63898u,63943u,63986u,64030u,64072u,64114u,64155u,64196u,64236u,
		64276u,64315u,64353u,64391u,64428u,64464u,64500u,64535u,64570u,64604u,64638u,64671u,64703u,64734u,64765u,64796u,
		64826u,64855u,64883u,64911u,64939u,64966u,64992u,65017u,65042u,65066u,65090u,65113u,65136u,65158u,65179u,65199u,
		65219u,65239u,65258u,65276u,65293u,65310u,65327u,65342u,65357u,65372u,65386u,65399u,65412u,65424u,65435u,65446u,
		65456u,65466u,65475u,65483u,65491u,65498u,65504u,65510u,65515u,65520u,65524u,65527u,65530u,65532u,65534u,65535u,65535u
		};

	
	Theta_Rev_T_f32 = MotCoggAg_Rad_T_f32 * ONEOVER2PI_ULS_F32;
	
	Theta_Rev_T_f32 = Theta_Rev_T_f32 - ((float32)((sint32)Theta_Rev_T_f32)); /* casting used for 'mod 1' functionality */
	
	if( Theta_Rev_T_f32 < 0.0f )
	{
		Theta_Rev_T_f32 += 1.0f;
	}
	
	/* Conditioned: 0 <= Theta <= 1 */
	
	if( Theta_Rev_T_f32 > ONEOVER2_ULS_F32 )
	{
		SignFlip_Cnt_T_s08 = -1;
		Theta_Rev_T_f32 -= ONEOVER2_ULS_F32;
	}
	else
	{
		SignFlip_Cnt_T_s08 = 1;
	}
	
	if( Theta_Rev_T_f32 > ONEOVER4_ULS_F32 )
	{
		Theta_Rev_T_f32 = ONEOVER2_ULS_F32 - Theta_Rev_T_f32;
	}
	
	/* Conditioned: 0 <= Theta <= 0.25 */
	
	Theta_Cnt_T_u16 = (uint16)(uint32)(float32)(Theta_Rev_T_f32 * SINCNVNCON1_ULS_F32);
	
	SinVal_Uls_T_f32 = ((float32)SINCNVNCONTBL_ULS_U16[Theta_Cnt_T_u16])*SINCNVNCON2_ULS_F32;
	
	
	SinVal_Uls_T_f32 = SinVal_Uls_T_f32 * (float32)SignFlip_Cnt_T_s08;
	
	
	return SinVal_Uls_T_f32;
}

#endif

