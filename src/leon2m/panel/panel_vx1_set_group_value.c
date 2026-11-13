/* panel_vx1_set_group_value  (FUN_a0122480)
 *
 * Write a value to one or all of the four lane groups.
 * Note: Nothing calls it and nothing points to it; panel_vx1_setup_lanes writes the same 32 registers one by
 *   one.
 * Name basis: descriptive - eight registers per group; no caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0122480, flags -mcpu=v8 -O3 -g.
 * Source form: plain if-chain over the group number; no local variables.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define VX1_GROUP_ALL 4     /* group number that selects all four groups */

/*
 * Write one value to the eight V-by-One transmitter registers of a lane group, or of all four groups.
 *
 *   group  0..3: that group; VX1_GROUP_ALL (4): all four groups; any other number: nothing
 *   value  written unchanged to every register
 *
 * Nothing calls this routine. panel_vx1_setup_lanes writes panel_vx1_second_param to these same 32 registers
 * one by one.
 */
void panel_vx1_set_group_value(unsigned int group, unsigned int value)
{
    /* Group 0: 0xcf01cd30..0xcf01cd4c. */
    if (group == 0 || group == VX1_GROUP_ALL) {
        R(0xcf01cd30) = value;
        R(0xcf01cd34) = value;
        R(0xcf01cd38) = value;
        R(0xcf01cd3c) = value;
        R(0xcf01cd40) = value;
        R(0xcf01cd44) = value;
        R(0xcf01cd48) = value;
        R(0xcf01cd4c) = value;
    }
    /* Group 1: 0xcf01cdbc..0xcf01cdd8. */
    if (group == 1 || group == VX1_GROUP_ALL) {
        R(0xcf01cdbc) = value;
        R(0xcf01cdc0) = value;
        R(0xcf01cdc4) = value;
        R(0xcf01cdc8) = value;
        R(0xcf01cdcc) = value;
        R(0xcf01cdd0) = value;
        R(0xcf01cdd4) = value;
        R(0xcf01cdd8) = value;
    }
    /* Group 2: 0xcf01ce48..0xcf01ce64. */
    if (group == 2 || group == VX1_GROUP_ALL) {
        R(0xcf01ce48) = value;
        R(0xcf01ce4c) = value;
        R(0xcf01ce50) = value;
        R(0xcf01ce54) = value;
        R(0xcf01ce58) = value;
        R(0xcf01ce5c) = value;
        R(0xcf01ce60) = value;
        R(0xcf01ce64) = value;
    }
    /* Group 3: 0xcf01ced4..0xcf01cef0. */
    if (group == 3 || group == VX1_GROUP_ALL) {
        R(0xcf01ced4) = value;
        R(0xcf01ced8) = value;
        R(0xcf01cedc) = value;
        R(0xcf01cee0) = value;
        R(0xcf01cee4) = value;
        R(0xcf01cee8) = value;
        R(0xcf01ceec) = value;
        R(0xcf01cef0) = value;
    }
}
