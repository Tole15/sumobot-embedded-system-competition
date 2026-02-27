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
static const char *ng0 = "C:/Users/ZiggyStardust/OneDrive/Documentos/CoquineitorV1/dual_motor_pwm_top_led/tb_dual_motor_pwm_led.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );


void work_a_2913921608_3671711236_sub_585533252_2913225385(char *t0, char *t1, char *t2, unsigned int t3, unsigned int t4, char *t5, char *t6, unsigned int t7, unsigned int t8, char *t9, char *t10, unsigned int t11, unsigned int t12, char *t13, char *t14)
{
    char t16[24];
    char t17[16];
    char *t18;
    char *t19;
    int t20;
    unsigned int t21;
    unsigned char t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    int t28;
    int t29;
    int t30;
    int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t37;
    char *t38;
    int64 t39;
    int64 t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;

LAB0:    t18 = (t17 + 0U);
    t19 = (t18 + 0U);
    *((int *)t19) = 7;
    t19 = (t18 + 4U);
    *((int *)t19) = 0;
    t19 = (t18 + 8U);
    *((int *)t19) = -1;
    t20 = (0 - 7);
    t21 = (t20 * -1);
    t21 = (t21 + 1);
    t19 = (t18 + 12U);
    *((unsigned int *)t19) = t21;
    t19 = (t16 + 4U);
    t22 = (t14 != 0);
    if (t22 == 1)
        goto LAB3;

LAB2:    t23 = (t16 + 12U);
    *((char **)t23) = t17;
    t21 = (0 + t11);
    t24 = (t13 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    *((unsigned char *)t27) = (unsigned char)2;
    xsi_driver_first_trans_delta(t13, t21, 1, 0LL);
    t20 = 7;
    t28 = 0;

LAB4:    if (t20 >= t28)
        goto LAB5;

LAB7:    t21 = (0 + t3);
    t18 = (t5 + 56U);
    t24 = *((char **)t18);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    *((unsigned char *)t26) = (unsigned char)2;
    xsi_driver_first_trans_delta(t5, t21, 1, 0LL);
    t21 = (0 + t11);
    t18 = (t13 + 56U);
    t24 = *((char **)t18);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    *((unsigned char *)t26) = (unsigned char)3;
    xsi_driver_first_trans_delta(t13, t21, 1, 0LL);
    t18 = (t0 + 3168U);
    t24 = *((char **)t18);
    t39 = *((int64 *)t24);
    xsi_process_wait(t1, t39);

LAB24:    t18 = (t1 + 88U);
    t25 = *((char **)t18);
    t26 = (t25 + 2480U);
    *((unsigned int *)t26) = 1U;
    t27 = (t1 + 88U);
    t36 = *((char **)t27);
    t37 = (t36 + 0U);
    getcontext(t37);
    t38 = (t1 + 88U);
    t41 = *((char **)t38);
    t42 = (t41 + 2480U);
    t21 = *((unsigned int *)t42);
    if (t21 == 1)
        goto LAB25;

LAB26:    t43 = (t1 + 88U);
    t44 = *((char **)t43);
    t45 = (t44 + 2480U);
    *((unsigned int *)t45) = 3U;

LAB22:
LAB23:
LAB21:
LAB1:    return;
LAB3:    *((char **)t19) = t14;
    goto LAB2;

LAB5:    t18 = (t17 + 0U);
    t29 = *((int *)t18);
    t24 = (t17 + 8U);
    t30 = *((int *)t24);
    t31 = (t20 - t29);
    t21 = (t31 * t30);
    t25 = (t17 + 4U);
    t32 = *((int *)t25);
    xsi_vhdl_check_range_of_index(t29, t32, t30, t20);
    t33 = (1U * t21);
    t34 = (0 + t33);
    t26 = (t14 + t34);
    t22 = *((unsigned char *)t26);
    t35 = (0 + t7);
    t27 = (t9 + 56U);
    t36 = *((char **)t27);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    *((unsigned char *)t38) = t22;
    xsi_driver_first_trans_delta(t9, t35, 1, 0LL);
    t21 = (0 + t3);
    t18 = (t5 + 56U);
    t24 = *((char **)t18);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    *((unsigned char *)t26) = (unsigned char)2;
    xsi_driver_first_trans_delta(t5, t21, 1, 0LL);
    t18 = (t0 + 3048U);
    t24 = *((char **)t18);
    t39 = *((int64 *)t24);
    t40 = (t39 / 2);
    xsi_process_wait(t1, t40);

LAB11:    t18 = (t1 + 88U);
    t25 = *((char **)t18);
    t26 = (t25 + 2480U);
    *((unsigned int *)t26) = 1U;
    t27 = (t1 + 88U);
    t36 = *((char **)t27);
    t37 = (t36 + 0U);
    getcontext(t37);
    t38 = (t1 + 88U);
    t41 = *((char **)t38);
    t42 = (t41 + 2480U);
    t21 = *((unsigned int *)t42);
    if (t21 == 1)
        goto LAB12;

LAB13:    t43 = (t1 + 88U);
    t44 = *((char **)t43);
    t45 = (t44 + 2480U);
    *((unsigned int *)t45) = 3U;

LAB9:
LAB10:
LAB8:    t21 = (0 + t3);
    t18 = (t5 + 56U);
    t24 = *((char **)t18);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    *((unsigned char *)t26) = (unsigned char)3;
    xsi_driver_first_trans_delta(t5, t21, 1, 0LL);
    t18 = (t0 + 3048U);
    t24 = *((char **)t18);
    t39 = *((int64 *)t24);
    t40 = (t39 / 2);
    xsi_process_wait(t1, t40);

LAB17:    t18 = (t1 + 88U);
    t25 = *((char **)t18);
    t26 = (t25 + 2480U);
    *((unsigned int *)t26) = 1U;
    t27 = (t1 + 88U);
    t36 = *((char **)t27);
    t37 = (t36 + 0U);
    getcontext(t37);
    t38 = (t1 + 88U);
    t41 = *((char **)t38);
    t42 = (t41 + 2480U);
    t21 = *((unsigned int *)t42);
    if (t21 == 1)
        goto LAB18;

LAB19:    t43 = (t1 + 88U);
    t44 = *((char **)t43);
    t45 = (t44 + 2480U);
    *((unsigned int *)t45) = 3U;

LAB15:
LAB16:
LAB14:
LAB6:    if (t20 == t28)
        goto LAB7;

LAB20:    t29 = (t20 + -1);
    t20 = t29;
    goto LAB4;

LAB12:    xsi_saveStackAndSuspend(t1);
    goto LAB13;

LAB18:    xsi_saveStackAndSuspend(t1);
    goto LAB19;

LAB25:    xsi_saveStackAndSuspend(t1);
    goto LAB26;

}

static void work_a_2913921608_3671711236_p_0(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    int64 t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(54, ng0);

LAB3:    t1 = (t0 + 2928U);
    t2 = *((char **)t1);
    t3 = *((int64 *)t2);
    t4 = (t3 / 2);
    t1 = (t0 + 1032U);
    t5 = *((char **)t1);
    t6 = *((unsigned char *)t5);
    t7 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t6);
    t1 = (t0 + 4920);
    t8 = (t1 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = t7;
    xsi_driver_first_trans_delta(t1, 0U, 1, t4);
    t12 = (t0 + 4920);
    xsi_driver_intertial_reject(t12, t4, t4);

LAB2:    t13 = (t0 + 4840);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2913921608_3671711236_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 4520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(83, ng0);
    t7 = (1 * 1000000LL);
    t2 = (t0 + 4328);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(85, ng0);
    t7 = (5 * 1000000000LL);
    t2 = (t0 + 4328);
    xsi_process_wait(t2, t7);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 4328);
    t3 = (t0 + 1312U);
    t4 = (t0 + 5048);
    t5 = (t0 + 1472U);
    t6 = (t0 + 5176);
    t8 = (t0 + 1632U);
    t9 = (t0 + 5112);
    t10 = (t0 + 9013);
    work_a_2913921608_3671711236_sub_585533252_2913225385(t0, t2, t3, 0U, 0U, t4, t5, 0U, 0U, t6, t8, 0U, 0U, t9, t10);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 4328);
    t3 = (t0 + 1312U);
    t4 = (t0 + 5048);
    t5 = (t0 + 1472U);
    t6 = (t0 + 5176);
    t8 = (t0 + 1632U);
    t9 = (t0 + 5112);
    t10 = (t0 + 9021);
    work_a_2913921608_3671711236_sub_585533252_2913225385(t0, t2, t3, 0U, 0U, t4, t5, 0U, 0U, t6, t8, 0U, 0U, t9, t10);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 9029);
    xsi_report(t2, 19U, (unsigned char)0);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 3288U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4328);
    xsi_process_wait(t2, t7);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(98, ng0);
    t2 = (t0 + 4328);
    t3 = (t0 + 1312U);
    t4 = (t0 + 5048);
    t5 = (t0 + 1472U);
    t6 = (t0 + 5176);
    t8 = (t0 + 1632U);
    t9 = (t0 + 5112);
    t10 = (t0 + 9048);
    work_a_2913921608_3671711236_sub_585533252_2913225385(t0, t2, t3, 0U, 0U, t4, t5, 0U, 0U, t6, t8, 0U, 0U, t9, t10);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 4328);
    t3 = (t0 + 1312U);
    t4 = (t0 + 5048);
    t5 = (t0 + 1472U);
    t6 = (t0 + 5176);
    t8 = (t0 + 1632U);
    t9 = (t0 + 5112);
    t10 = (t0 + 9056);
    work_a_2913921608_3671711236_sub_585533252_2913225385(t0, t2, t3, 0U, 0U, t4, t5, 0U, 0U, t6, t8, 0U, 0U, t9, t10);
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 9064);
    xsi_report(t2, 19U, (unsigned char)0);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 3288U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4328);
    xsi_process_wait(t2, t7);

LAB18:    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB16:    xsi_set_current_line(106, ng0);
    t2 = (t0 + 4328);
    t3 = (t0 + 1312U);
    t4 = (t0 + 5048);
    t5 = (t0 + 1472U);
    t6 = (t0 + 5176);
    t8 = (t0 + 1632U);
    t9 = (t0 + 5112);
    t10 = (t0 + 9083);
    work_a_2913921608_3671711236_sub_585533252_2913225385(t0, t2, t3, 0U, 0U, t4, t5, 0U, 0U, t6, t8, 0U, 0U, t9, t10);
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 4328);
    t3 = (t0 + 1312U);
    t4 = (t0 + 5048);
    t5 = (t0 + 1472U);
    t6 = (t0 + 5176);
    t8 = (t0 + 1632U);
    t9 = (t0 + 5112);
    t10 = (t0 + 9091);
    work_a_2913921608_3671711236_sub_585533252_2913225385(t0, t2, t3, 0U, 0U, t4, t5, 0U, 0U, t6, t8, 0U, 0U, t9, t10);
    xsi_set_current_line(108, ng0);
    t2 = (t0 + 9099);
    xsi_report(t2, 26U, (unsigned char)0);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 3288U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4328);
    xsi_process_wait(t2, t7);

LAB22:    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB17:    goto LAB16;

LAB19:    goto LAB17;

LAB20:    xsi_set_current_line(112, ng0);
    if ((unsigned char)0 == 0)
        goto LAB24;

LAB25:    goto LAB2;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

LAB24:    t2 = (t0 + 9125);
    xsi_report(t2, 17U, (unsigned char)3);
    goto LAB25;

}


extern void work_a_2913921608_3671711236_init()
{
	static char *pe[] = {(void *)work_a_2913921608_3671711236_p_0,(void *)work_a_2913921608_3671711236_p_1};
	static char *se[] = {(void *)work_a_2913921608_3671711236_sub_585533252_2913225385};
	xsi_register_didat("work_a_2913921608_3671711236", "isim/tb_dual_motor_pwm_led_isim_beh.exe.sim/work/a_2913921608_3671711236.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
