/* leon2m FUN_a01341dc @ 0xa01341dc-0xa0134394 (110 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table). n selects a hardware register address (1: 0xcf03c000, 2: 0xcf03c004, 3: 0xcf03c008,
 * 4: 0xcf03c00c, 5: 0xcf03c010, 6: 0xcf03c040, 7: 0xcf03c048, 8: 0xcf03c450, 9: 0xcf03c458, 10: 0xcf03c460,
 * 11: 0xcf03c468, 12: 0xcf03c470, 13: 0xcf03c478, 14: 0xcf03cc00, 15: 0xcf03cc04, 16: 0xcf03cc08, 17: 0xcf03cc0c;
 * jump table at 0xd2b2c); any other n gives address 0 and, when FUN_a00dd614(0x20) returns non-zero, prints
 * "port is not correct\r\n". v = FUN_a00ddf24(n) and a = address >> 2. When FUN_a00dd614(0x20) returns non-zero,
 * prints "\nSet Indicator : %02X %02X %02X %08lx %02x\r\n" with n, the low bytes of mask and c, a and the low byte
 * of v. Then func_0x4008f3f4(0x19, 0, v | mask, c, 1), func_0x4008f3f4(0x1a, 0, v & ~mask, c, 1) and the tail call
 * func_0x4008f3f4(0x18, 0, a & 0x1f, (a >> 8) & 0xf3, 1) (the RAM copy of FUN_a002f3f4).
 * Source form: FUN_a00ddf24 is declared returning int here (v is masked where it is used, not after the call), and
 * v is an unsigned int; with a byte v GCC puts mask first in the 'or'. Case 1 is written last; address 0 is set at
 * the start of the default case.
 */
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170(const char *fmt, ...);
extern int FUN_a00ddf24(unsigned char n);
extern void func_0x4008f3f4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a01341dc(unsigned char n, unsigned int mask, unsigned int c)
{
    unsigned int addr;
    unsigned int v;

    switch (n) {
    case 2: addr = 0xcf03c004; break;
    case 3: addr = 0xcf03c008; break;
    case 4: addr = 0xcf03c00c; break;
    case 5: addr = 0xcf03c010; break;
    case 6: addr = 0xcf03c040; break;
    case 7: addr = 0xcf03c048; break;
    case 8: addr = 0xcf03c450; break;
    case 9: addr = 0xcf03c458; break;
    case 10: addr = 0xcf03c460; break;
    case 11: addr = 0xcf03c468; break;
    case 12: addr = 0xcf03c470; break;
    case 13: addr = 0xcf03c478; break;
    case 14: addr = 0xcf03cc00; break;
    case 15: addr = 0xcf03cc04; break;
    case 16: addr = 0xcf03cc08; break;
    case 17: addr = 0xcf03cc0c; break;
    case 1: addr = 0xcf03c000; break;
    default:
        addr = 0;
        if (FUN_a00dd614(0x20))
            FUN_a00df170("port is not correct\r\n");
        break;
    }
    v = FUN_a00ddf24(n);
    addr >>= 2;
    if (FUN_a00dd614(0x20))
        FUN_a00df170("\nSet Indicator : %02X %02X %02X %08lx %02x\r\n", n, (unsigned char)mask, (unsigned char)c, addr, (unsigned char)v);
    func_0x4008f3f4(0x19, 0, v | mask, c, 1);
    func_0x4008f3f4(0x1a, 0, v & ~mask, c, 1);
    func_0x4008f3f4(0x18, 0, addr & 0x1f, (addr >> 8) & 0xf3, 1);
}
