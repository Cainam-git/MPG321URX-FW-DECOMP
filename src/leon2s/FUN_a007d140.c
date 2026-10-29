/* leon2s FUN_a007d140 @ 0xa007d140-0xa007d21c (-mcpu=v8 -Os -g)
 * Returns 1 when FUN_a007d054(port) is 0. Otherwise up to three passes read a = FUN_a00a7314(port, 0x1e98) >> 24,
 * b = FUN_a00a7314(port, 0x1e9c) and c = FUN_a00a7314(port, 0x1e9c) >> 8 (low bytes); if a != 0x18,
 * (b & 0xf) > 1, (b & 0xf0) > 0x1f or (c & 0xf0) > 0x1f it prints s_a0067b58
 * ("Port%c 0x1E98=0x%02X, 0x1E9C=0x%02X, 0x1E9D=0x%02X ...") with port + 'A', a, b, c through FUN_a0073044,
 * prints s_a0067b90 through FUN_a00734c4 and returns 0; after three good passes it returns 1.
 * Source form: FUN_a007d054 is declared returning unsigned char (the firmware tests only its low byte).
 */
extern char s_a0067b58[], s_a0067b90[];
extern unsigned char FUN_a007d054(unsigned char port);
extern unsigned int FUN_a00a7314(unsigned int param_1, unsigned short param_2);
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);

unsigned char FUN_a007d140(unsigned char port)
{
    unsigned char i;
    unsigned char a;
    unsigned char b;
    unsigned char c;

    if (FUN_a007d054(port)) {
        for (i = 0; i < 3; i++) {
            a = FUN_a00a7314(port, 0x1e98) >> 24;
            b = FUN_a00a7314(port, 0x1e9c);
            c = FUN_a00a7314(port, 0x1e9c) >> 8;
            if (a != 0x18 || (b & 0xf) > 1 || (b & 0xf0) > 0x1f || (c & 0xf0) > 0x1f) {
                FUN_a0073044(s_a0067b58, (char)(port + 'A'), a, b, c);
                FUN_a00734c4(s_a0067b90);
                return 0;
            }
        }
    }
    return 1;
}
