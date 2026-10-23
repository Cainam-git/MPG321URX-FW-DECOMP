/* leon2m FUN_a012b7b8 @ 0xa012b7b8..0xa012b86c (45 words)  start-up step 7 of FUN_a015266c (after the display
 * start-up): input-side set-up chosen by the settings bit 25.
 * What it does (code facts): s = bit 25 of the first word of the settings record in RAM (0xA802E1A0, loaded from
 * EEPROM 0x470 by FUN_a0153c74; the same bit FUN_a012ad6c returns and FUN_a0141b60 uses to swap the input entries
 * 2/3 between port numbers 5 and 6). Then FUN_a012b458(s), FUN_a012b458(!s), FUN_a0107a14(s); then pin set-up
 * FUN_a0107bac(0, FUN_a0125124(entry 2 +0x10), 1, 0) and FUN_a0107bac(1, FUN_a0125124(entry 3 +0x10), 1, 0)
 * (entries of the 18-byte table 0xA802E116; FUN_a0125124(k) = byte +2 of ROM port record 0x1A42A8[k]); finally the
 * tail call FUN_a0137d40(1) (sends 1 through FUN_a01370dc(0x2F, 4, buf, 1)). The word is re-read before each use
 * (it is not volatile, but every call may change it).
 * The function itself has no loop. Runs after FUN_a0106d64.
 * Exact form: bit 25 as a bitfield; each call written in both arms of an if/else (crossjumping merges them into one
 * call with the argument in the branch delay slot, as in the fw; a ?: argument becomes branch-free code).
 */
struct Ent { unsigned short h0; unsigned char rest[14]; unsigned char b10, b11; };
struct W { unsigned int hi:6, b25:1, lo:25; };
extern struct W DAT_a802e1a0;
extern struct Ent DAT_a802e116[];
extern void FUN_a012b458(unsigned char);
extern void FUN_a0107a14(unsigned char);
extern unsigned char FUN_a0125124(unsigned char);
extern void FUN_a0107bac(unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a0137d40(unsigned char);

void FUN_a012b7b8(void)
{
    if (DAT_a802e1a0.b25)
        FUN_a012b458(1);
    else
        FUN_a012b458(0);
    if (DAT_a802e1a0.b25)
        FUN_a012b458(0);
    else
        FUN_a012b458(1);
    if (DAT_a802e1a0.b25)
        FUN_a0107a14(1);
    else
        FUN_a0107a14(0);
    FUN_a0107bac(0, FUN_a0125124(DAT_a802e116[2].b10), 1, 0);
    FUN_a0107bac(1, FUN_a0125124(DAT_a802e116[3].b10), 1, 0);
    FUN_a0137d40(1);
}
