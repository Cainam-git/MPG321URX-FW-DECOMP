/* 8051_bank1 FUN_CODE_b802 @ 0xb802 (127 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * m = byte 0 of entry [XDATA 0xA64D] of the 3-byte table at XDATA 0xA62F, low five bits. For m = 0..12 a 13-way
 * switch (jump table) sets m to the same value and FUN_CODE_9bde(m) is called; other values return.
 * Callers: FUN_CODE_a57e (twice). Table layout as in FUN_CODE_a57e and FUN_CODE_ccc2.
 * Source form: 'm = (unsigned long)(entry.a & 0x1f);': the value passes through the long conversion into R7 and
 *   Keil loads A from R7 again for the switch ('MOV R7,A; MOV A,R7'); a plain char assignment switches on A.
 */
struct ent3 { unsigned char a, b, c; };
extern struct ent3 xdata DAT_EXTMEM_a62f[10];
extern unsigned char xdata DAT_EXTMEM_a64d;
void FUN_CODE_9bde(unsigned char n);

void FUN_CODE_b802(void)
{
    unsigned char m;

    m = (unsigned long)(DAT_EXTMEM_a62f[DAT_EXTMEM_a64d].a & 0x1f);
    switch (m) {
    case 0: m = 0; break;
    case 1: m = 1; break;
    case 2: m = 2; break;
    case 3: m = 3; break;
    case 4: m = 4; break;
    case 5: m = 5; break;
    case 6: m = 6; break;
    case 7: m = 7; break;
    case 8: m = 8; break;
    case 9: m = 9; break;
    case 10: m = 10; break;
    case 11: m = 11; break;
    case 12: m = 12; break;
    default: return;
    }
    FUN_CODE_9bde(m);
}
