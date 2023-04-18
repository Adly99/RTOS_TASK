#include "..\LIB\std_types.h"
#include "..\LIB\bit_math.h"

#include "GIE_interface.h"
#include "GIE_private.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDisable(void)
{
	CLEAR_BIT(SREG,SREG_I);
}
