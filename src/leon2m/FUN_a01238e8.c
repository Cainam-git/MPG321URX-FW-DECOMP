/* leon2m FUN_a01238e8 @ 0xa01238e8-0xa0123c4c (-mcpu=v8 -O3 -g).
 * When register word (0xf190 + 2 * DAT_a802d87e) reads 0x96: writes 0x47 to the next register word and waits until
 * it changes; then, unless the first word reads 0x9b, issues the commands 0x52..0x58 to register 0xcf03c660 (each
 * time waiting until the register no longer holds the command) and copies the six register words 0xf19a..0xf19f
 * into row 0..6 of the 7 x 6 byte table DAT_a802d850, and prints the table with "%s\r\n ".
 * Source form: the per-command read is a static helper inlined seven times; the row is addressed through a pointer
 * taken inside the copy loop, which gives the firmware's [row + index] operand order.
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

extern unsigned char DAT_a802d87e;
extern unsigned char DAT_a802d850[7][6];
extern int FUN_a00df170(const char *, ...);

static void rd6(unsigned char cmd, unsigned char n)
{
    unsigned char i;

    REG(0xcf03c660) = cmd;
    while (REG(0xcf03c660) == cmd)
        ;
    for (i = 0; i <= 5; i++) {
        unsigned char *row = DAT_a802d850[n];
        row[i] = RB(0xf19a + i);
    }
}

void FUN_a01238e8(void)
{
    if (RB(DAT_a802d87e * 2 + 0xf190) == 0x96) {
        RB(DAT_a802d87e * 2 + 0xf191) = 0x47;
        while (RB(DAT_a802d87e * 2 + 0xf191) == 0x47)
            ;
        if (RB(DAT_a802d87e * 2 + 0xf190) != 0x9b) {
            rd6(0x52, 0);
            rd6(0x53, 1);
            rd6(0x54, 2);
            rd6(0x55, 3);
            rd6(0x56, 4);
            rd6(0x57, 5);
            rd6(0x58, 6);
            FUN_a00df170("%s\r\n ", DAT_a802d850);
        }
    }
}
