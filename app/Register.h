#ifndef __Register_H__
#define	__Register_H__

#include <stdint.h>

#ifndef HOST
#define RCC_BASE_ADDRESS 0x40023800

#else

#include "HostRcc.h"
#define RCC_BASE_ADDRESS (&HostRcc)
// #error i am gay

  
  
#endif  //HOST

#endif //__Register_H__
