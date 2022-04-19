#ifndef CONTROL_LIB
#define CONTROL_LIB

/*  PIcontroller  struct  */
struct PICTRL
{
  float y;
  float x;
  float Ts;
  float Ti;
  float Kr;
  float a;
  float b;
  float c;
  float c_1;
  float d;
  float d_1;
  float e;
  float f;
  float f_1;
  float max;
  float min;
};

void InitPIctrl(struct PICTRL *pictrl, int Ts, float Kr, float Ti, int max,
                int min);
void CalcPIctrl(struct PICTRL *pictrl, float x);

#endif