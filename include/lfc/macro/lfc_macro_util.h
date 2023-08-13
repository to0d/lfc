#ifndef __LFC_MACRO_UTIL__
#define __LFC_MACRO_UTIL__

#define	min(a,b)	                ((a) < (b) ? (a) : (b))
#define	max(a,b)	                ((a) > (b) ? (a) : (b))
#define ROUND( a ,b)                ((a)-((a)%(b)))
#define TIMES_OF( a,b  )            (((a)+((b)-1))/(b))
#define ROUND_UP(a,b)               (TIMES_OF(a,b)*(b))

#define JOINT_STR(a,b)              a##b	
#define AUTO_NAME(pre)              JOINT_STR(pre,__FILE__)
#define LFC_STATIC_ASSERT(e)        typedef char AUTO_NAME(Static)[(e)? 1:-1];

#define LFC_FREE_POINTER(x)         if( (x) != NULL ){free (x);(x) = NULL;}

#endif //__LFC_MACRO_UTIL__