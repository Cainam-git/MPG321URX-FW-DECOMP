/* leon2m FUN_a00bc86c @ 0xa00bc86c-0xa00bc8c4 (22 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/22 mismatches.
 * Code facts: writes three ASCII digits: DAT_a802d078[7..9] = DAT_a802d290[0x12..0x14] + '0'
 * (one record base each, ldub/add 0x30/stb); FUN_a00bacc4(10); FUN_a00ba950(port); sibcall
 * FUN_a00babe4(port, 0xb). port is a u8 param (fw 'and %i0,0xff' after the first call).
 * Fixes vs the autoc draft (54.17): real bases DAT_a802d290 / DAT_a802d078 (the draft used mid-record
 * names), the stores in ascending order 7, 8, 9 in the source (sched emits them 9, 7, 8 like the fw),
 * FUN_a00bacc4 takes 1 arg. Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802d078[];
extern void FUN_a00bacc4(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00babe4(unsigned char, unsigned char);

void FUN_a00bc86c(unsigned char port)
{
    DAT_a802d078[7] = DAT_a802d290[0x12] + '0';
    DAT_a802d078[8] = DAT_a802d290[0x13] + '0';
    DAT_a802d078[9] = DAT_a802d290[0x14] + '0';
    FUN_a00bacc4(10);
    FUN_a00ba950(port);
    FUN_a00babe4(port, 0xb);
}
