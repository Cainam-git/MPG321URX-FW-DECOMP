/* leon2m FUN_a0140304 @ 0xa0140304..0xa0140360 (23 words)  settings-storage "area usable?" test, called with dev 0 by
 * FUN_a0153c74 (start-up step 5) before it reads the system settings.
 * What it does (code facts): b = byte +0 of the 38-byte ROM record DAT_001a69fe[dev] (FW.021 record 0 "DG_EEPROM1":
 * b = 0). If b read as a signed byte is >= 0 (bit 7 clear) it returns 1. Otherwise it returns 1 only if byte +8 of
 * the 12-byte RAM record DAT_a802cbdc[b] is not 0xFF (that byte is the page index FUN_a01400e0's 0x55 page scan
 * found, 0xFF = none), else 0. FW.021: returns 1 (b = 0), so FUN_a0153c74 never takes its "DG_SYSSETTING OPR is
 * invalid" path.
 * Can it fail or wait? No: RAM/ROM reads only, leaf, no loop.
 * Exact form: the record byte read twice (ldub for the index, ldsb for the sign test), result 'and 1'.
 */
struct B38 { unsigned char b0, b1; unsigned short h2; unsigned char b4; char name[33]; };
struct D12 { unsigned short h0; unsigned short h2; int w4; unsigned char b8, b9; unsigned char pad[2]; };
extern const struct B38 DAT_001a69fe[];
extern struct D12 DAT_a802cbdc[];

unsigned char FUN_a0140304(unsigned char dev)
{
    unsigned char ok = 1;
    if ((signed char)DAT_001a69fe[dev].b0 < 0)
        ok = DAT_a802cbdc[DAT_001a69fe[dev].b0].b8 != 0xff;
    return ok & 1;
}
