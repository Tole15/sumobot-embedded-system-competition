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

char *WORK_P_0359128566;
char *WORK_P_3423228179;
char *IEEE_P_1242562249;
char *IEEE_P_2592010699;
char *STD_STANDARD;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    ieee_p_1242562249_init();
    work_p_3423228179_init();
    work_p_0359128566_init();
    work_a_2877627901_1516540902_init();
    work_a_2525468362_1516540902_init();
    work_a_0930057798_1516540902_init();
    work_a_0880638641_1516540902_init();
    work_a_0063972740_1516540902_init();
    work_a_2163240216_1516540902_init();
    work_a_1117997334_1516540902_init();
    work_a_2620338790_0318166943_init();
    work_a_3386789208_1516540902_init();
    work_a_0726022559_1516540902_init();
    work_a_2913921608_3671711236_init();


    xsi_register_tops("work_a_2913921608_3671711236");

    WORK_P_0359128566 = xsi_get_engine_memory("work_p_0359128566");
    WORK_P_3423228179 = xsi_get_engine_memory("work_p_3423228179");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");

    return xsi_run_simulation(argc, argv);

}
