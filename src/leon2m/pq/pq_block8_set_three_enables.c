/* pq_block8_set_three_enables  (FUN_a0118b9c)
 *
 * Switch three enable registers of picture block 8 on or off.
 * Name basis: descriptive - 0xCF012FD0, 0xCF012F74 and 0xCF012F6C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118b9c, flags -mcpu=v8 -O3 -g.
 * The routine keeps a register window (save/restore) although it makes no call; plain C at -O3 -g produces
 * that frame. Source form: the three stores in each arm in the firmware's order.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define BLOCK8_TABLE1_INDEX 0xcf012fd0      /* the table 1 index register of pq_load_block8_config */
#define BLOCK8_F74          0xcf012f74      /* bit 1 is also set by pq_enable_block8_path */
#define BLOCK8_F6C          0xcf012f6c
#define F6C_VALUE_ON        4

/*
 * on != 0: write 1 to 0xCF012FD0 and 0xCF012F74 and 4 to 0xCF012F6C.
 * on == 0: write 0 to all three.
 *
 * Nothing in the firmware calls this routine directly.
 */
void pq_block8_set_three_enables(unsigned char on)
{
    if (on) {
        R(BLOCK8_TABLE1_INDEX) = 1;
        R(BLOCK8_F74) = 1;
        R(BLOCK8_F6C) = F6C_VALUE_ON;
    } else {
        R(BLOCK8_F74) = 0;
        R(BLOCK8_TABLE1_INDEX) = 0;
        R(BLOCK8_F6C) = 0;
    }
}
