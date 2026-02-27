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
extern char *IEEE_P_1242562249;
extern char *STD_STANDARD;

char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );


char *work_p_3423228179_sub_3158065152_4135806074(char *t1, char *t2, int t3, int t4)
{
    char t6[16];
    char t9[16];
    char *t0;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    unsigned int t12;
    char *t13;
    int t14;
    char *t15;
    int t16;
    char *t17;
    int t18;
    char *t19;
    char *t20;
    int t21;
    unsigned int t22;

LAB0:    t7 = (t6 + 4U);
    *((int *)t7) = t3;
    t8 = (t6 + 8U);
    *((int *)t8) = t4;
    t10 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t9, t3, t4);
    t11 = (t9 + 12U);
    t12 = *((unsigned int *)t11);
    t12 = (t12 * 1U);
    t0 = xsi_get_transient_memory(t12);
    memcpy(t0, t10, t12);
    t13 = (t9 + 0U);
    t14 = *((int *)t13);
    t15 = (t9 + 4U);
    t16 = *((int *)t15);
    t17 = (t9 + 8U);
    t18 = *((int *)t17);
    t19 = (t2 + 0U);
    t20 = (t19 + 0U);
    *((int *)t20) = t14;
    t20 = (t19 + 4U);
    *((int *)t20) = t16;
    t20 = (t19 + 8U);
    *((int *)t20) = t18;
    t21 = (t16 - t14);
    t22 = (t21 * t18);
    t22 = (t22 + 1);
    t20 = (t19 + 12U);
    *((unsigned int *)t20) = t22;

LAB1:    return t0;
LAB2:;
}

int work_p_3423228179_sub_1137588737_4135806074(char *t1, int t2)
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
	static char *se[] = {(void *)work_p_3423228179_sub_3158065152_4135806074,(void *)work_p_3423228179_sub_1137588737_4135806074};
	xsi_register_didat("work_p_3423228179", "isim/tb_dual_motor_pwm_led_isim_beh.exe.sim/work/p_3423228179.didat");
	xsi_register_subprogram_executes(se);
}
