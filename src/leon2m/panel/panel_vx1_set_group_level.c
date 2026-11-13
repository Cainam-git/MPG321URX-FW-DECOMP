/* panel_vx1_set_group_level  (FUN_a0122634)
 *
 * Set the level of one or all of the four lane groups.
 * Name basis: descriptive - control register and four level registers per group; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0122634 @ 0xa0122634-0xa01227f0 (111 words), flags -mcpu=v8 -O3 -g.
 * Source form: the value level * 17 - 17 is computed once into an unsigned int local and narrowed to a byte at
 * each store. The four groups are written out one after another (no loop).
 */
#define R(a) (*(volatile unsigned int *)(a))

/* The four transmitter register blocks of the V-by-One link, 0x8C bytes apart (the same blocks as in
 * panel_vx1_setup_lanes; block n is lane group n). */
#define VX1_BLOCK(n)            (0xcf01ccec + 0x8c * (n))
#define VX1_BLOCK_FIRST(n, k)   (VX1_BLOCK(n) + 0x10 + 4 * (k))  /* four registers that take the level */
#define VX1_BLOCK_FIRST_ON(n)   (VX1_BLOCK(n) + 0x20)            /* 0xFF: the four level registers are used */

#define VX1_GROUP_ALL 4         /* group selector value: all four groups */
#define VX1_ON        0xff
#define VX1_OFF       0

/*
 * Set the level of the four-register set of lane group "group" (0..3), or of all four groups when group is
 * VX1_GROUP_ALL.
 *
 * level == 0 switches the set off: only the group's control register VX1_BLOCK_FIRST_ON gets 0. Any other level
 * switches the set on (control register gets 0xFF) and writes the same byte, (level - 1) * 17, to the four
 * level registers of the group. The level registers are the ones panel_vx1_setup_lanes fills with
 * (panel_vx1_first_param - 1) * 17.
 *
 * Nothing calls this routine by name. A group selector of 5 or more does nothing.
 */
void panel_vx1_set_group_level(unsigned int group, unsigned int level)
{
    unsigned int level_byte = level * 17 - 17;

    if (group == 0 || group == VX1_GROUP_ALL) {
        if (!level)
            R(VX1_BLOCK_FIRST_ON(0)) = VX1_OFF;
        else {
            R(VX1_BLOCK_FIRST_ON(0)) = VX1_ON;
            R(VX1_BLOCK_FIRST(0, 0)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(0, 1)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(0, 2)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(0, 3)) = (unsigned char)level_byte;
        }
    }
    if (group == 1 || group == VX1_GROUP_ALL) {
        if (!level)
            R(VX1_BLOCK_FIRST_ON(1)) = VX1_OFF;
        else {
            R(VX1_BLOCK_FIRST_ON(1)) = VX1_ON;
            R(VX1_BLOCK_FIRST(1, 0)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(1, 1)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(1, 2)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(1, 3)) = (unsigned char)level_byte;
        }
    }
    if (group == 2 || group == VX1_GROUP_ALL) {
        if (!level)
            R(VX1_BLOCK_FIRST_ON(2)) = VX1_OFF;
        else {
            R(VX1_BLOCK_FIRST_ON(2)) = VX1_ON;
            R(VX1_BLOCK_FIRST(2, 0)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(2, 1)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(2, 2)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(2, 3)) = (unsigned char)level_byte;
        }
    }
    if (group == 3 || group == VX1_GROUP_ALL) {
        if (!level)
            R(VX1_BLOCK_FIRST_ON(3)) = VX1_OFF;
        else {
            R(VX1_BLOCK_FIRST_ON(3)) = VX1_ON;
            R(VX1_BLOCK_FIRST(3, 0)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(3, 1)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(3, 2)) = (unsigned char)level_byte;
            R(VX1_BLOCK_FIRST(3, 3)) = (unsigned char)level_byte;
        }
    }
}
