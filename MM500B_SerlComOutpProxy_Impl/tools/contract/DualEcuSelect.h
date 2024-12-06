#ifndef DUALECUSELECT_HEADER
#define DUALECUSELECT_HEADER

#define EPS_A
/* #define EPS_B */

#if defined(DUALECUSELECT_EPSA)
	#define DUALECUSELECT_EPSA_SELECTED
#elif defined(DUALECUSELECT_EPSB)
	#define DUALECUSELECT_EPSB_SELECTED
#elif defined(EPS_A)
	#define DUALECUSELECT_EPSA_SELECTED
#elif defined(EPS_B)
	#define DUALECUSELECT_EPSB_SELECTED
#endif

#if defined(DUALECUSELECT_EPSA) && defined(EPS_B)
#warning "Global macros have higher priority. EPS A selected."
#endif

#if defined(DUALECUSELECT_EPSB) && defined(EPS_A)
#warning "Global macros have higher priority. EPS B selected."
#endif

#if !defined(DUALECUSELECT_EPSA_SELECTED) && !defined(DUALECUSELECT_EPSB_SELECTED)
#warning "No ECU selected. By default EPS A will be selected."
#define DUALECUSELECT_EPSA_SELECTED
#endif

#if defined(DUALECUSELECT_EPSA_SELECTED) && defined(DUALECUSELECT_EPSB_SELECTED)
#error "Both ECUs can not be selected at the same time"
#endif

#endif
