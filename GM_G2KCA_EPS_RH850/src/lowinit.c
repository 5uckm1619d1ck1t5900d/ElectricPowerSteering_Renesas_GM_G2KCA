//============================================================================
// PROJECT  :  Example project
//============================================================================
//                           C O P Y R I G H T
//============================================================================
// Copyright (c) 2013 by Renesas Electronics  GmbH. All rights reserved.
// Arcadiastr.10
// D-40472 Duesseldorf
// Germany
//============================================================================
//
// Warranty Disclaimer :
// Because the Product(s) is licensed free of charge, there is no warranty of
// any kind whatsoever and expressly disclaimed and excluded by Renesas, either
// expressed or implied, including but not limited to those for non-
// infringement of intellectual property, merchantability and/or fitness for
// the particular purpose. Renesas shall not have any obligation to maintain,
// service or provide bug fixes for the supplied Product(s) and/or the
// Application.
//
// Each User is solely responsible for determining the appropriateness of
// using the Product(s) and assumes all risks associated with its exercise
// of rights under this Agreement, including, but not limited to the risks
// and costs of program errors, compliance with applicable laws, damage to
// or loss of data, programs or equipment, and unavailability or
// interruption of operations.
//
// Limitation of Liability :
// In no event shall Renesas be liable to the User for any incidental,
// consequential, indirect, or punitive damage (including but not limited to
// lost profits) regardless of whether such liability is based on breach of
// contract, tort, strict liability, breach of warranties, failure of
// essential purpose or otherwise and even if advised of the possibility of
// such damages. Renesas shall not be liable for any services or products provided
// by third party vendors, developers or consultants identified or referred
// to the User by Renesas in conRenesastion with the Product(s) and/or the
// Application.
//
//============================================================================
// Enviroment : Devices    : RH850/P1M-144 (WS1.0)
//              Debugger   : GHS Multi V6.1.4/2013.1.5
//============================================================================
//
// GHS Multi Example project for use with RH850/P1M-144pin PiggyBack board
// with 16MHz MainOsc
// 
//
//============================================================================


//============================================================================
// Includes
//============================================================================

//============================================================================
// Prototypes
//============================================================================
void            __lowinit           ( void );


//============================================================================
// Variables
//============================================================================



//============================================================================
// Sub Functions
//============================================================================

void __lowinit(void)
{
    unsigned long i;

	/* Initialisation of LRAM self area with '0' */
    for( i = 0xfede0000; i < 0xfee00000; i+=4 )
    {
        *(unsigned long *)i= 0UL;
    }
}
