/* panel_vx1_set_group_table_value  (FUN_a01112c0)
 *
 * Write an entry of a 13-byte table to one or all of the four lane groups.
 * Note: Its groups have six registers each and are not the eight-register groups of panel_vx1_set_group_value.
 *   Nothing calls it.
 * Name basis: descriptive - six registers per group; no caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01112c0, flags -mcpu=v8 -O3 -g.
 * Source form: the group number is an unsigned int and the table index an unsigned char; each group reads
 * table[index] once into the unsigned char value and then writes its six registers.
 */
#define REG(a) (*(volatile unsigned int *)(a))

#define VX1_GROUP_ALL 4     /* group number that selects all four groups */

/*
 * Look up one entry of the 13-byte table and write it to the V-by-One transmitter registers of one lane group,
 * or of all four.
 *
 *   group  0..3: that group's six registers; VX1_GROUP_ALL (4): all four groups; any other number: nothing
 *   index  position in the table; there is no range check
 *
 * Nothing calls this routine. panel_vx1_start_transmitter holds the same table and writes the entry it picks
 * (index = the top five bits of word 0 of the working panel row) to the 24 registers of all four groups. The six
 * registers of a group here are not the eight-register groups of panel_vx1_set_group_value: the runs differ.
 */
void panel_vx1_set_group_table_value(unsigned int group, unsigned char index)
{
    unsigned char table[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14 };
    unsigned char value;

    /* Group 0: 0xcf01cd30..0xcf01cd44. */
    if (group == 0 || group == VX1_GROUP_ALL) {
        value = table[index];
        REG(0xcf01cd30) = value;
        REG(0xcf01cd34) = value;
        REG(0xcf01cd38) = value;
        REG(0xcf01cd3c) = value;
        REG(0xcf01cd40) = value;
        REG(0xcf01cd44) = value;
    }
    /* Group 1: 0xcf01cd48, 0xcf01cd4c and 0xcf01cdbc..0xcf01cdc8. */
    if (group == 1 || group == VX1_GROUP_ALL) {
        value = table[index];
        REG(0xcf01cd48) = value;
        REG(0xcf01cd4c) = value;
        REG(0xcf01cdbc) = value;
        REG(0xcf01cdc0) = value;
        REG(0xcf01cdc4) = value;
        REG(0xcf01cdc8) = value;
    }
    /* Group 2: 0xcf01ce58..0xcf01ce64, 0xcf01ced4 and 0xcf01ced8. */
    if (group == 2 || group == VX1_GROUP_ALL) {
        value = table[index];
        REG(0xcf01ce58) = value;
        REG(0xcf01ce5c) = value;
        REG(0xcf01ce60) = value;
        REG(0xcf01ce64) = value;
        REG(0xcf01ced4) = value;
        REG(0xcf01ced8) = value;
    }
    /* Group 3: 0xcf01cedc..0xcf01cef0. */
    if (group == 3 || group == VX1_GROUP_ALL) {
        value = table[index];
        REG(0xcf01cedc) = value;
        REG(0xcf01cee0) = value;
        REG(0xcf01cee4) = value;
        REG(0xcf01cee8) = value;
        REG(0xcf01ceec) = value;
        REG(0xcf01cef0) = value;
    }
}
