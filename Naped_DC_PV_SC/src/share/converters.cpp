#include "../../include/converters.h"

int get_Cuk_duty(int Vo, int Vs)
/* return calculated duty for Ćuk convereter in range 0-100
Args:
    Vo[mV] - Output Voltage
    Vs[mV] - Source Voltage*/
{
    constexpr int ToProc = 100;
    return (long)ToProc * Vo / (Vs + Vo);
}