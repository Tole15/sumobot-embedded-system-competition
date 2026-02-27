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
static const char *ng0 = "C:/Users/ZiggyStardust/OneDrive/Documentos/CoquineitorV1/dual_motor_pwm_top_led/edge_detect.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2525468362_1516540902_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned char t12;
    unsigned int t13;
    char *t14;
    unsigned char t15;
    unsigned char t16;
    char *t17;
    unsigned char t18;
    unsigned char t19;
    unsigned char t20;
    unsigned char t21;
    char *t23;
    unsigned char t25;
    unsigned int t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned char t31;
    unsigned char t32;
    char *t33;
    unsigned char t34;
    unsigned char t35;
    unsigned char t36;
    char *t38;
    unsigned char t40;
    unsigned int t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    unsigned char t46;
    char *t47;
    unsigned char t48;
    unsigned char t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;

LAB0:    xsi_set_current_line(15, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3704);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(16, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(18, ng0);
    t1 = (t0 + 3864);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(19, ng0);
    t1 = (t0 + 6333);
    t4 = (t0 + 6337);
    t12 = 1;
    if (4U == 4U)
        goto LAB23;

LAB24:    t12 = 0;

LAB25:    if (t12 == 1)
        goto LAB20;

LAB21:    t11 = (unsigned char)0;

LAB22:    if (t11 == 1)
        goto LAB17;

LAB18:    t6 = (unsigned char)0;

LAB19:    if (t6 == 1)
        goto LAB14;

LAB15:    t10 = (t0 + 6341);
    t23 = (t0 + 6345);
    t25 = 1;
    if (4U == 4U)
        goto LAB35;

LAB36:    t25 = 0;

LAB37:    if (t25 == 1)
        goto LAB32;

LAB33:    t21 = (unsigned char)0;

LAB34:    if (t21 == 1)
        goto LAB29;

LAB30:    t20 = (unsigned char)0;

LAB31:    t5 = t20;

LAB16:    if (t5 == 1)
        goto LAB11;

LAB12:    t29 = (t0 + 6349);
    t38 = (t0 + 6353);
    t40 = 1;
    if (4U == 4U)
        goto LAB44;

LAB45:    t40 = 0;

LAB46:    if (t40 == 1)
        goto LAB41;

LAB42:    t36 = (unsigned char)0;

LAB43:    t2 = t36;

LAB13:    if (t2 != 0)
        goto LAB8;

LAB10:
LAB9:    xsi_set_current_line(22, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (t0 + 3800);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t2;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(16, ng0);
    t3 = (t0 + 3800);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(16, ng0);
    t1 = (t0 + 3864);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB8:    xsi_set_current_line(21, ng0);
    t44 = (t0 + 3864);
    t50 = (t44 + 56U);
    t51 = *((char **)t50);
    t52 = (t51 + 56U);
    t53 = *((char **)t52);
    *((unsigned char *)t53) = (unsigned char)3;
    xsi_driver_first_trans_fast(t44);
    goto LAB9;

LAB11:    t2 = (unsigned char)1;
    goto LAB13;

LAB14:    t5 = (unsigned char)1;
    goto LAB16;

LAB17:    t10 = (t0 + 1672U);
    t17 = *((char **)t10);
    t18 = *((unsigned char *)t17);
    t19 = (t18 == (unsigned char)2);
    t6 = t19;
    goto LAB19;

LAB20:    t10 = (t0 + 1352U);
    t14 = *((char **)t10);
    t15 = *((unsigned char *)t14);
    t16 = (t15 == (unsigned char)3);
    t11 = t16;
    goto LAB22;

LAB23:    t13 = 0;

LAB26:    if (t13 < 4U)
        goto LAB27;
    else
        goto LAB25;

LAB27:    t8 = (t1 + t13);
    t9 = (t4 + t13);
    if (*((unsigned char *)t8) != *((unsigned char *)t9))
        goto LAB24;

LAB28:    t13 = (t13 + 1);
    goto LAB26;

LAB29:    t29 = (t0 + 1672U);
    t33 = *((char **)t29);
    t34 = *((unsigned char *)t33);
    t35 = (t34 == (unsigned char)3);
    t20 = t35;
    goto LAB31;

LAB32:    t29 = (t0 + 1352U);
    t30 = *((char **)t29);
    t31 = *((unsigned char *)t30);
    t32 = (t31 == (unsigned char)2);
    t21 = t32;
    goto LAB34;

LAB35:    t26 = 0;

LAB38:    if (t26 < 4U)
        goto LAB39;
    else
        goto LAB37;

LAB39:    t27 = (t10 + t26);
    t28 = (t23 + t26);
    if (*((unsigned char *)t27) != *((unsigned char *)t28))
        goto LAB36;

LAB40:    t26 = (t26 + 1);
    goto LAB38;

LAB41:    t44 = (t0 + 1352U);
    t45 = *((char **)t44);
    t46 = *((unsigned char *)t45);
    t44 = (t0 + 1672U);
    t47 = *((char **)t44);
    t48 = *((unsigned char *)t47);
    t49 = (t46 != t48);
    t36 = t49;
    goto LAB43;

LAB44:    t41 = 0;

LAB47:    if (t41 < 4U)
        goto LAB48;
    else
        goto LAB46;

LAB48:    t42 = (t29 + t41);
    t43 = (t38 + t41);
    if (*((unsigned char *)t42) != *((unsigned char *)t43))
        goto LAB45;

LAB49:    t41 = (t41 + 1);
    goto LAB47;

}

static void work_a_2525468362_1516540902_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(26, ng0);

LAB3:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3928);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 3720);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_2525468362_1516540902_init()
{
	static char *pe[] = {(void *)work_a_2525468362_1516540902_p_0,(void *)work_a_2525468362_1516540902_p_1};
	xsi_register_didat("work_a_2525468362_1516540902", "isim/tb_dual_motor_pwm_led_isim_beh.exe.sim/work/a_2525468362_1516540902.didat");
	xsi_register_executes(pe);
}
