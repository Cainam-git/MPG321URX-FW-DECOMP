/* leon2m FUN_a00f7894 @ 0xa00f7894 (-mcpu=v8 -O3 -g)
 * Takes a 3-byte record p. m = 1 when p[2] is 8, 2 when p[2] is 16, otherwise 0. Writes
 * 0xCF00EE80 = (0xCF00EE80 & 0xF9) | (DAT_a802b7b4 << 1) and
 * 0xCF00EEC0 = (0xCF00EEC0 & 0x3A) | (p[0] << 7) | (p[1] << 6) | (m << 2), then prints
 * "Config ACE (%d) : (%d)" with DAT_a802b7b4 and p[2]. Callers: FUN_a012a774, FUN_a014737c.
 * Source form: m is set by a switch with three case labels; the third label sets m to 0 and lies below 8 (it makes
 * GCC's compare tree 'cmp 8; be; bg'); its value does not appear in the code, 0 is written here.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char DAT_a802b7b4;
extern int FUN_a00df170(const char *fmt, ...);

void FUN_a00f7894(unsigned char *p)
{
    unsigned char m = 0;

    switch (p[2]) {
    case 0:
        m = 0;
        break;
    case 8:
        m = 1;
        break;
    case 16:
        m = 2;
        break;
    }
    R(0xcf00ee80) = (R(0xcf00ee80) & 0xf9) | (DAT_a802b7b4 << 1);
    R(0xcf00eec0) = (R(0xcf00eec0) & 0x3a) | (p[0] << 7) | (p[1] << 6) | (m << 2);
    FUN_a00df170("Config ACE (%d) : (%d)\r\n", DAT_a802b7b4, p[2]);
}
