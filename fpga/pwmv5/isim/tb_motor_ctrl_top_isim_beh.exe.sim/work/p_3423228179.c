/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
extern char *STD_STANDARD;



int work_p_3423228179_sub_1142729663_4135806074(char *t1, int t2)
{
    char t3[248];
    char t4[8];
    char t9[8];
    char t15[8];
    int t0;
    int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    int t21;
    unsigned char t22;
    char *t23;
    int t24;
    int t25;
    char *t26;

LAB0:    t5 = (t2 - 1);
    t6 = (t3 + 4U);
    t7 = ((STD_STANDARD) + 832);
    t8 = (t6 + 88U);
    *((char **)t8) = t7;
    t10 = (t6 + 56U);
    *((char **)t10) = t9;
    *((int *)t9) = t5;
    t11 = (t6 + 80U);
    *((unsigned int *)t11) = 4U;
    t12 = (t3 + 124U);
    t13 = ((STD_STANDARD) + 832);
    t14 = (t12 + 88U);
    *((char **)t14) = t13;
    t16 = (t12 + 56U);
    *((char **)t16) = t15;
    *((int *)t15) = 0;
    t17 = (t12 + 80U);
    *((unsigned int *)t17) = 4U;
    t18 = (t4 + 4U);
    *((int *)t18) = t2;

LAB2:    t19 = (t6 + 56U);
    t20 = *((char **)t19);
    t21 = *((int *)t20);
    t22 = (t21 > 0);
    if (t22 != 0)
        goto LAB3;

LAB5:    t7 = (t12 + 56U);
    t8 = *((char **)t7);
    t5 = *((int *)t8);
    t0 = t5;

LAB1:    return t0;
LAB3:    t19 = (t6 + 56U);
    t23 = *((char **)t19);
    t24 = *((int *)t23);
    t25 = (t24 / 2);
    t19 = (t6 + 56U);
    t26 = *((char **)t19);
    t19 = (t26 + 0);
    *((int *)t19) = t25;
    t7 = (t12 + 56U);
    t8 = *((char **)t7);
    t5 = *((int *)t8);
    t21 = (t5 + 1);
    t7 = (t12 + 56U);
    t10 = *((char **)t7);
    t7 = (t10 + 0);
    *((int *)t7) = t21;
    goto LAB2;

LAB4:;
LAB6:;
}


extern void work_p_3423228179_init()
{
	static char *se[] = {(void *)work_p_3423228179_sub_1142729663_4135806074};
	xsi_register_didat("work_p_3423228179", "isim/tb_motor_ctrl_top_isim_beh.exe.sim/work/p_3423228179.didat");
	xsi_register_subprogram_executes(se);
}
