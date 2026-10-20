/* leon2m FUN_a00daa7c @ 0xa00daa7c-0xa00daad0 (21 words), flags -mcpu=v8 -O3 -g.
 * Code facts: fills the 8-byte buffer DAT_a802d268 with {0x35, 0x38, 0x30, 0x30, 0x3b, 0x34, 0x30, 0x0d} and
 * leaf-sibcalls FUN_a01487e8(2, 8, DAT_a802d268). The buffer address is the third argument (fw 'or %o4,0x268,%o2'
 * stays live into the call; a01487e8 forwards %o2 to a01337e8).
 * Source form: the stores in ascending index order in the source (sched gives the fw order 0,1,4,5,6,7,2,3).
 * Compiler aids: none.
 */
extern unsigned char DAT_a802d268[8];
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00daa7c(void)
{
    DAT_a802d268[0] = 0x35;
    DAT_a802d268[1] = 0x38;
    DAT_a802d268[2] = 0x30;
    DAT_a802d268[3] = 0x30;
    DAT_a802d268[4] = 0x3b;
    DAT_a802d268[5] = 0x34;
    DAT_a802d268[6] = 0x30;
    DAT_a802d268[7] = 0xd;
    FUN_a01487e8(2, 8, DAT_a802d268);
}
