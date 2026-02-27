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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *WORK_P_3423228179;
char *IEEE_P_2592010699;
char *STD_STANDARD;
char *IEEE_P_1242562249;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    ieee_p_1242562249_init();
    work_p_3423228179_init();
    work_a_0900697890_3212880686_init();
    work_a_1361990604_1516540902_init();
    work_a_2263464102_1516540902_init();
    work_a_0063972740_3212880686_init();
    work_a_2163240216_3212880686_init();
    work_a_1117997334_3212880686_init();
    work_a_2620338790_3212880686_init();
    work_a_2361052958_1181938964_init();
    work_a_1689615213_3553469787_init();


    xsi_register_tops("work_a_1689615213_3553469787");

    WORK_P_3423228179 = xsi_get_engine_memory("work_p_3423228179");
    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");

    return xsi_run_simulation(argc, argv);

}
