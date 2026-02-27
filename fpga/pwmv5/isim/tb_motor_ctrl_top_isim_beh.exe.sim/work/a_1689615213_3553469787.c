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
static const char *ng0 = "C:/Users/ZiggyStardust/OneDrive/Documentos/pwm/pwmv5/tb_motor_ctrl_top.vhd";



static void work_a_1689615213_3553469787_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 4832U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);

LAB4:    if ((unsigned char)1 != 0)
        goto LAB5;

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 5464);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(41, ng0);
    t2 = (t0 + 3248U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 4640);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;

LAB1:    return;
LAB6:;
LAB8:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 5464);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 3248U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 4640);
    xsi_process_wait(t2, t8);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    goto LAB4;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

}

static void work_a_1689615213_3553469787_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;
    int t9;
    int t10;
    int t11;
    int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned char t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    t1 = (t0 + 5080U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 5528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 5592);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 5656);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 5720);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(56, ng0);
    t7 = (200 * 1000LL);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 5720);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(60, ng0);
    t7 = (200 * 1000LL);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t7);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 5528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 3248U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (2 * t7);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t8);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 9372);
    *((int *)t2) = 7;
    t3 = (t0 + 9376);
    *((int *)t3) = 0;
    t9 = 7;
    t10 = 0;

LAB16:    if (t9 >= t10)
        goto LAB17;

LAB19:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 3368U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t7);

LAB31:    *((char **)t1) = &&LAB32;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB17:    xsi_set_current_line(66, ng0);
    t4 = (t0 + 3608U);
    t5 = *((char **)t4);
    t4 = (t0 + 9372);
    t11 = *((int *)t4);
    t12 = (t11 - 7);
    t13 = (t12 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, *((int *)t4));
    t14 = (1U * t13);
    t15 = (0 + t14);
    t6 = (t5 + t15);
    t16 = *((unsigned char *)t6);
    t17 = (t0 + 5592);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    *((unsigned char *)t21) = t16;
    xsi_driver_first_trans_fast(t17);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 3368U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t7);

LAB22:    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB18:    t2 = (t0 + 9372);
    t9 = *((int *)t2);
    t3 = (t0 + 9376);
    t10 = *((int *)t3);
    if (t9 == t10)
        goto LAB19;

LAB28:    t11 = (t9 + -1);
    t9 = t11;
    t4 = (t0 + 9372);
    *((int *)t4) = t9;
    goto LAB16;

LAB20:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 5656);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 3488U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t7);

LAB26:    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

LAB24:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 5656);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    goto LAB18;

LAB25:    goto LAB24;

LAB27:    goto LAB25;

LAB29:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 5528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 3248U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (2 * t7);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t8);

LAB35:    *((char **)t1) = &&LAB36;
    goto LAB1;

LAB30:    goto LAB29;

LAB32:    goto LAB30;

LAB33:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 5528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(78, ng0);
    t2 = (t0 + 3248U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (2 * t7);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t8);

LAB39:    *((char **)t1) = &&LAB40;
    goto LAB1;

LAB34:    goto LAB33;

LAB36:    goto LAB34;

LAB37:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 9380);
    *((int *)t2) = 7;
    t3 = (t0 + 9384);
    *((int *)t3) = 0;
    t9 = 7;
    t10 = 0;

LAB41:    if (t9 >= t10)
        goto LAB42;

LAB44:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 3368U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t7);

LAB56:    *((char **)t1) = &&LAB57;
    goto LAB1;

LAB38:    goto LAB37;

LAB40:    goto LAB38;

LAB42:    xsi_set_current_line(80, ng0);
    t4 = (t0 + 3728U);
    t5 = *((char **)t4);
    t4 = (t0 + 9380);
    t11 = *((int *)t4);
    t12 = (t11 - 7);
    t13 = (t12 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, *((int *)t4));
    t14 = (1U * t13);
    t15 = (0 + t14);
    t6 = (t5 + t15);
    t16 = *((unsigned char *)t6);
    t17 = (t0 + 5592);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    *((unsigned char *)t21) = t16;
    xsi_driver_first_trans_fast(t17);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 3368U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t7);

LAB47:    *((char **)t1) = &&LAB48;
    goto LAB1;

LAB43:    t2 = (t0 + 9380);
    t9 = *((int *)t2);
    t3 = (t0 + 9384);
    t10 = *((int *)t3);
    if (t9 == t10)
        goto LAB44;

LAB53:    t11 = (t9 + -1);
    t9 = t11;
    t4 = (t0 + 9380);
    *((int *)t4) = t9;
    goto LAB41;

LAB45:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 5656);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3488U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t7);

LAB51:    *((char **)t1) = &&LAB52;
    goto LAB1;

LAB46:    goto LAB45;

LAB48:    goto LAB46;

LAB49:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 5656);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    goto LAB43;

LAB50:    goto LAB49;

LAB52:    goto LAB50;

LAB54:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 5528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 3248U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (2 * t7);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t8);

LAB60:    *((char **)t1) = &&LAB61;
    goto LAB1;

LAB55:    goto LAB54;

LAB57:    goto LAB55;

LAB58:    xsi_set_current_line(91, ng0);
    t7 = (300 * 1000000LL);
    t2 = (t0 + 4888);
    xsi_process_wait(t2, t7);

LAB64:    *((char **)t1) = &&LAB65;
    goto LAB1;

LAB59:    goto LAB58;

LAB61:    goto LAB59;

LAB62:    xsi_set_current_line(94, ng0);
    if ((unsigned char)0 == 0)
        goto LAB66;

LAB67:    goto LAB2;

LAB63:    goto LAB62;

LAB65:    goto LAB63;

LAB66:    t2 = (t0 + 9388);
    xsi_report(t2, 17U, (unsigned char)3);
    goto LAB67;

}


extern void work_a_1689615213_3553469787_init()
{
	static char *pe[] = {(void *)work_a_1689615213_3553469787_p_0,(void *)work_a_1689615213_3553469787_p_1};
	xsi_register_didat("work_a_1689615213_3553469787", "isim/tb_motor_ctrl_top_isim_beh.exe.sim/work/a_1689615213_3553469787.didat");
	xsi_register_executes(pe);
}
