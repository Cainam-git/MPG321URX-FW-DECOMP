/* leon2m FUN_a0141b60 @ 0xa0141b60..0xa0141c48 (58 words)  start-up step 2 (FUN_a015266c): resets the 7-entry
 * 18-byte input-entry table at 0xA802E116.
 * What it does at power-on (code facts): for entries E[0..6] (E = 0xA802E116 + 18*k) clears bit 7 of the flag
 * halfword E+0; sets the byte E+0x10 of E[0] = 3 and E[1] = 4; asks FUN_a012ad6c (bit 25 of the RAM word
 * 0xA802E1A0) and sets E[2]+0x10 / E[3]+0x10 = 6 / 5 when that bit is 1, 5 / 6 when it is 0 (two sockets swapped
 * by one configuration bit); sets the type nibble (bits 15..12 of E+0)
 * of E[0..3] to 2 and the byte E+0x10 of E[4], E[5], E[6] to 0xFC, 0xFD, 0xFE. FUN_a0142910 (the per-port sync state
 * machine) later reads these entries (type 5 = signal present; this function puts 2 into entries 0..3).
 * Can it fail or wait? No: one fixed 7-turn loop, one call that only reads RAM, no registers, no timeout.
 * Runs before FUN_a0106d64 (start-up order); RAM init only.
 * Exact form: bitfields for bit 7 and the type nibble, u8 loop counter, the E[0]/E[1] stores before the call, E[2]
 * before E[3] in both arms, and the 0xFC..0xFE stores written before the four type stores.
 */
struct Ent {
    unsigned short type:4, e11:1, e10:1, e9:1, e8:1, e7:1, e6_0:7;   /* +0 */
    unsigned char rest2[14];
    unsigned char b10, b11;                                           /* +0x10 */
};
extern struct Ent DAT_a802e116[];
extern unsigned int FUN_a012ad6c(void);

void FUN_a0141b60(void)
{
    unsigned char i;
    for (i = 0; i < 7; i++)
        DAT_a802e116[i].e7 = 0;
    DAT_a802e116[0].b10 = 3;
    DAT_a802e116[1].b10 = 4;
    if (FUN_a012ad6c() & 0xff) {
        DAT_a802e116[2].b10 = 5;
        DAT_a802e116[3].b10 = 6;
    } else {
        DAT_a802e116[2].b10 = 6;
        DAT_a802e116[3].b10 = 5;
    }
    DAT_a802e116[4].b10 = 0xfc;
    DAT_a802e116[5].b10 = 0xfd;
    DAT_a802e116[6].b10 = 0xfe;
    DAT_a802e116[0].type = 2;
    DAT_a802e116[1].type = 2;
    DAT_a802e116[2].type = 2;
    DAT_a802e116[3].type = 2;
}
