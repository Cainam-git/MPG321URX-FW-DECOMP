/* FUN_a00b28d0 (leon2s 0xa00b28d0-0xa00b34a8, 3032 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * void (void). Reads one character c through FUN_a0072c6c(&c) and returns when that returns 0. The line is kept
 * in DAT_a807def0 with its length in _DAT_a807deac.
 * DAT_a807dec4 != 0: 0x1c or '^' clears the length. '\r' with a length below 2 clears the length and
 * DAT_a807dec4; otherwise cmd = line[0] and line[1..] is read as hex digit pairs (' ' and ',' between pairs,
 * anything else sets cmd to 0xff) into DAT_a807ded0 (at most 32 bytes). The first four bytes form a big-endian
 * address. 'R'/'r' with 4 bytes reads the word through FUN_a00b22fc and prints 0x83, its eight nibbles + 0x90,
 * 0x8f; 'W'/'w' with 8 bytes writes the next word through FUN_a00b2304; 'U'/'u' with 12 bytes writes
 * (old & ~mask) | (value & mask). Each prints 0x83 0x8f, a failed command 0x82 0x8f (in DAT_a807ded0 through
 * FUN_a0061280); then the length and DAT_a807dec4 are cleared. Any other character is appended while the length
 * is below 0xfe.
 * DAT_a807dec4 == 0: '\b' removes one character and prints "\b \b", 0x1b clears the line and prints
 * "\n\rDBG >>", '^' as the first character sets DAT_a807dec4, any other character is appended (length below
 * 0xfe) and passed to FUN_a006122c. '\r' prints "\n\r" and terminates the line, then:
 *  - DAT_a807dea8 == 0: a line starting with '*' or '{' for which FUN_a00b1568("*CB00000" or "{#UTIL#}", line)
 *    returns 0 sets DAT_a807dea8 to 1. Any other line is split at ' ', '\t', ',' and NUL into at most five
 *    words of up to 31 characters in the rows DAT_a807dff0[5][32] (count in DAT_a807deb0). Word 0 is compared
 *    by FUN_a00b1568 with the names of the 8-entry table ARR_a00b4e3c (32-byte name, function pointer): on a
 *    result of 0 "\n\r" is printed and a non-null function is called with FUN_a00b25f8() of words 1 to 4,
 *    followed by "\n\r", word 0 and " OK.\n\r";
 *    otherwise "\n\rCommand Not Found!\n\r". The rows and the count are cleared, and "DBG >>" is printed.
 *  - DAT_a807dea8 != 0 and length above 2: a = FUN_a00b2790(line + 3, 4). "*qt", "*RD", "*WD", "*RB", "*WB"
 *    and "*CB" set the record DAT_a807deb4 (cmd 0xffff, 1, 2, 3, 4, 5; address, value from
 *    FUN_a00b2790(line + 7, 8) and sum line[15] for "*WD"); "*RD" and "*CB" need FUN_a00b288c(a, 0) & 0xff to
 *    equal line[7] (else cmd 0), "*CB" sets DAT_a807e0b0 to (a == 0x1000). Other lines skip to the end. cmd
 *    0xffff clears DAT_a807dea8; cmd 1 reads the word at _DAT_a807dec8 + (address & ~3) and prints DAT_a807e090:
 *    '#', the bytes FUN_a00b281c writes for the word, its FUN_a00b288c result and " OK!#\n"; cmd 2 writes the
 *    value there when FUN_a00b288c(address, value) matches the sum and prints "#OK!#\n"; cmd 5 sets _DAT_a807dec8 to
 *    address << 16 and prints '#', bytes 4..7 of the FUN_a00b281c output for the address and " OK!#\n".
 * The length is cleared at the end.
 * Source form: the print right after the table function call names the "\n\r" string as s_a0068f00_nl, a
 * second symbol for the same address 0xa0068f00: this models two separate "\n\r" strings that the linker
 * merged into the tail of "AVI 422 \n\r". The firmware builds that address again at the call (sethi/or into
 * %o0) because its high part is not shared with the earlier prints; with one symbol GCSE shares it and %l4 is
 * no longer free for the function pointer. The word loop stores through 'char (*args)[32]' as args[*pn][j];
 * the clearing loop addresses the rows through the constant 0xa807dff0.
 * Source forms: the '\r' handler of the hex mode parses only 'if (_DAT_a807deac >= 2)' and shares the
 * clear/return tail with the short line; found is set to 0 before the 'if (err == 0)' test (0xa00b2f74);
 * the command table loop runs to ncmd = sizeof table / sizeof entry, kept in a local (cmp 8; bl at
 * 0xa00b302c); the '*' command result keeps its quit request as bit ST_QUIT of the status word st (tested
 * at 0xa00b348c).
 */
#define ST_QUIT 0x01

struct CmdEnt {
    char name[32];
    void (*fn)(int, int, int, int);
};
struct Req {
    unsigned int cmd;
    unsigned int addr;
    unsigned int val;
    char sum;
};
extern struct CmdEnt ARR_a00b4e3c[8];
extern struct Req DAT_a807deb4;
extern unsigned char DAT_a807dec4;
extern unsigned char DAT_a807dea8;
extern int _DAT_a807deac;
extern unsigned char DAT_a807deb0;
extern unsigned int _DAT_a807dec8;
extern unsigned char DAT_a807ded0[];
extern char DAT_a807def0[];
extern unsigned char DAT_a807e090[];
extern unsigned char DAT_a807e0b0;
extern const char s_a006c6b8[];
extern const char s_a006c6c0[];
extern const char s_a006c6d0[];
extern const char s_a006c6d8[];
extern const char s_a006c6f0[];
extern const char s_a0068f00[];
extern const char s_a0068f00_nl[];
extern const char s_a00b4e20[];
extern const char s_a00b4e30[];

extern int FUN_a0072c6c(unsigned char *);
extern void FUN_a0061280(const char *);
extern void FUN_a006122c(unsigned char);
extern int FUN_a00b1538(char *);
extern int FUN_a00b1568(const char *, const char *);
extern int FUN_a00b25f8(char *);
extern int FUN_a00b2790(const unsigned char *, int);
extern int FUN_a00b281c(unsigned char *, unsigned int);
extern int FUN_a00b288c(unsigned int, unsigned int);
extern unsigned int FUN_a00b22fc(unsigned int *);
extern void FUN_a00b2304(unsigned int *, unsigned int);

extern char DAT_a807dff0[5][32];

void FUN_a00b28d0(void)
{
    char c;

    if (FUN_a0072c6c((unsigned char *)&c) == 0)
        return;

    if (DAT_a807dec4 != 0) {
        unsigned char cmd, half, hi, d, n, ok;
        unsigned int i, cnt, addr, v, m;
        int sh;

        switch (c) {
        case 0x1c:
        case '^':
            _DAT_a807deac = 0;
            return;
        case '\r':
            if (_DAT_a807deac >= 2) {
            n = _DAT_a807deac;
            cmd = DAT_a807def0[0];
            half = 0;
            hi = 0;
            cnt = 0;
            for (i = 1; i < n; i++) {
                d = DAT_a807def0[i];
                if (d >= 'a' && d <= 'f')
                    d = d - 'a' + 10;
                else if (d >= 'A' && d <= 'F')
                    d = d - 'A' + 10;
                else if (d >= '0' && d <= '9')
                    d = d - '0';
                else if (d == ' ' || d == ',') {
                    if (half) {
                        cmd = 0xff;
                        break;
                    }
                    hi = 0;
                    continue;
                } else {
                    cmd = 0xff;
                    break;
                }
                if (!half) {
                    hi = d;
                    half = 1;
                } else {
                    half = 0;
                    if (cnt <= 0x1f) {
                        DAT_a807ded0[cnt++] = (hi << 4) + d;
                        continue;
                    }
                    cmd = 0xff;
                    break;
                }
            }
            if (cnt < 0x20 && half)
                cmd = 0xff;
            addr = 0;
            v = 0;
            m = 0;
            switch (cmd) {
            case 'R':
            case 'W':
            case 'U':
            case 'r':
            case 'w':
            case 'u':
                for (i = 0; i < 4; i++)
                    addr = (addr << 8) + DAT_a807ded0[i];
                break;
            }
            ok = 0;
            switch (cmd) {
            case 'R':
            case 'r':
                if (cnt != 4)
                    break;
                v = FUN_a00b22fc((unsigned int *)addr);
                DAT_a807ded0[0] = 0x83;
                for (i = 1, sh = 0x1c; i < 9; i++, sh -= 4)
                    DAT_a807ded0[i] = ((v >> sh) & 0xf) + 0x90;
                DAT_a807ded0[9] = 0x8f;
                DAT_a807ded0[10] = 0;
                FUN_a0061280((const char *)DAT_a807ded0);
                ok = 1;
                break;
            case 'U':
            case 'u':
                if (cnt != 12)
                    break;
                for (i = 4; i < 8; i++)
                    v = (v << 8) + DAT_a807ded0[i];
                for (i = 8; i < 12; i++)
                    m = (m << 8) + DAT_a807ded0[i];
                v &= m;
                FUN_a00b2304((unsigned int *)addr, (FUN_a00b22fc((unsigned int *)addr) & ~m) | v);
                DAT_a807ded0[0] = 0x83;
                DAT_a807ded0[1] = 0x8f;
                DAT_a807ded0[2] = 0;
                FUN_a0061280((const char *)DAT_a807ded0);
                ok = 1;
                break;
            case 'W':
            case 'w':
                if (cnt != 8)
                    break;
                for (i = 4; i < 8; i++)
                    v = (v << 8) + DAT_a807ded0[i];
                FUN_a00b2304((unsigned int *)addr, v);
                DAT_a807ded0[0] = 0x83;
                DAT_a807ded0[1] = 0x8f;
                DAT_a807ded0[2] = 0;
                FUN_a0061280((const char *)DAT_a807ded0);
                ok = 1;
                break;
            }
            if (!ok) {
                DAT_a807ded0[0] = 0x82;
                DAT_a807ded0[1] = 0x8f;
                DAT_a807ded0[2] = 0;
                FUN_a0061280((const char *)DAT_a807ded0);
            }
            }
            _DAT_a807deac = 0;
            DAT_a807dec4 = 0;
            return;
        default:
            if (_DAT_a807deac < 0xfe) {
                DAT_a807def0[_DAT_a807deac] = c;
                _DAT_a807deac++;
            }
            return;
        }
    } else {
        unsigned char enter = 0;

        switch (c) {
        case '\b':
            if (_DAT_a807deac > 0) {
                _DAT_a807deac--;
                FUN_a0061280(s_a006c6b8);
            }
            break;
        case '\r':
            enter = 1;
            break;
        case 0x1b:
            _DAT_a807deac = 0;
            FUN_a0061280(s_a006c6c0);
            break;
        default:
            if (_DAT_a807deac == 0 && c == '^') {
                DAT_a807dec4 = 1;
                _DAT_a807deac = 0;
            } else if (_DAT_a807deac < 0xfe) {
                DAT_a807def0[_DAT_a807deac] = c;
                _DAT_a807deac++;
                FUN_a006122c(c);
            }
            break;
        }
        if (!enter)
            return;

        FUN_a0061280(s_a0068f00);
        if (_DAT_a807deac < 0x100)
            DAT_a807def0[_DAT_a807deac] = 0;
        else if (_DAT_a807deac != 0)
            DAT_a807def0[_DAT_a807deac - 1] = 0;
        else
            DAT_a807def0[0] = 0;

        if (DAT_a807dea8 == 0) {
            int len, i, j, err, k, found, ncmd;
            char (*argv)[32];
            unsigned char *q;
            unsigned char *pn;
            char (*args)[32];
            unsigned char *p;
            void (*fn)(int, int, int, int);

            if ((unsigned char)DAT_a807def0[0] == '*') {
                if (FUN_a00b1568(s_a00b4e30, DAT_a807def0) == 0)
                    DAT_a807dea8 = 1;
            } else if ((unsigned char)DAT_a807def0[0] == '{') {
                if (FUN_a00b1568(s_a00b4e20, DAT_a807def0) == 0)
                    DAT_a807dea8 = 1;
            } else {
            p = (unsigned char *)DAT_a807def0;
            len = FUN_a00b1538((char *)p);
            pn = &DAT_a807deb0;
            args = DAT_a807dff0;
            if (len != 0) {
                err = -1;
                j = 0;
                for (i = 0; i < len; i++) {
                    unsigned char ch = p[i];

                    switch (ch) {
                    case ' ':
                    case 0:
                    case '\t':
                    case ',':
                        if (j != 0) {
                            (*pn)++;
                            j = 0;
                            if (*pn > 4) {
                                err = 1;
                                i = len;
                            }
                        }
                        break;
                    default:
                        if (j + 1 > 0x1f) {
                            err = 1;
                            i = len;
                        } else {
                            args[*pn][j] = ch;
                            j++;
                            err = 0;
                        }
                        break;
                    }
                }
                if (err == 0)
                    (*pn)++;
                if (err == 1) {
                    err = 0;
                }
                found = 0;
                if (err == 0) {
                    argv = DAT_a807dff0;
                    ncmd = sizeof(ARR_a00b4e3c) / sizeof(ARR_a00b4e3c[0]);
                    for (k = 0; k < ncmd; k++) {
                        if (FUN_a00b1568(ARR_a00b4e3c[k].name, argv[0]) == 0) {
                            FUN_a0061280(s_a0068f00);
                            fn = ARR_a00b4e3c[k].fn;
                            if (fn != 0) {
                                fn(FUN_a00b25f8(argv[1]), FUN_a00b25f8(argv[2]), FUN_a00b25f8(argv[3]),
                                   FUN_a00b25f8(argv[4]));
                                FUN_a0061280(s_a0068f00_nl);
                                FUN_a0061280(argv[0]);
                                FUN_a0061280(s_a006c6f0);
                                found = 1;
                            }
                            break;
                        }
                    }
                    if (!found)
                        FUN_a0061280(s_a006c6d8);
                    q = (unsigned char *)0xa807dff0;
                    {
                        int r, c;

                        for (r = 0; r < 5; r++) {
                            for (c = 0; c < 0x20; c++)
                                q[c] = 0;
                            q += 0x20;
                        }
                    }
                    DAT_a807deb0 = 0;
                }
            }
            FUN_a0061280(s_a006c6d0);
            }
        } else if (_DAT_a807deac > 2) {
            unsigned int a;
            unsigned int w;
            char *s;
            unsigned int st;

            s = DAT_a807def0;
            a = FUN_a00b2790((unsigned char *)s + 3, 4);
            if (s[0] == '*' && s[1] == 'q' && s[2] == 't')
                DAT_a807deb4.cmd = 0xffff;
            else if (s[0] == '*' && s[1] == 'R' && s[2] == 'D') {
                if ((FUN_a00b288c(a, 0) & 0xff) == s[7]) {
                    DAT_a807deb4.addr = a;
                    DAT_a807deb4.cmd = 1;
                } else
                    DAT_a807deb4.cmd = 0;
            } else if (s[0] == '*' && s[1] == 'W' && s[2] == 'D') {
                w = FUN_a00b2790((unsigned char *)s + 7, 8);
                DAT_a807deb4.addr = a;
                DAT_a807deb4.val = w;
                DAT_a807deb4.sum = s[15];
                DAT_a807deb4.cmd = 2;
            } else if (s[0] == '*' && s[1] == 'R' && s[2] == 'B')
                DAT_a807deb4.cmd = 3;
            else if (s[0] == '*' && s[1] == 'W' && s[2] == 'B')
                DAT_a807deb4.cmd = 4;
            else if (s[0] == '*' && s[1] == 'C' && s[2] == 'B') {
                if ((FUN_a00b288c(a, 0) & 0xff) != s[7])
                    DAT_a807deb4.cmd = 0;
                else {
                    DAT_a807deb4.cmd = 5;
                    DAT_a807deb4.addr = a;
                    if (a == 0x1000)
                        DAT_a807e0b0 = 1;
                    else
                        DAT_a807e0b0 = 0;
                }
            } else
                goto out;

            st = 0;
            switch (DAT_a807deb4.cmd) {
            case 0xffff:
                st |= ST_QUIT;
                break;
            case 1: {
                unsigned int w = FUN_a00b22fc((unsigned int *)(_DAT_a807dec8 + (DAT_a807deb4.addr & ~3)));
                int s = FUN_a00b288c(w, 0);

                FUN_a00b281c(&DAT_a807e090[1], w);
                DAT_a807e090[0] = '#';
                DAT_a807e090[9] = s;
                DAT_a807e090[10] = ' ';
                DAT_a807e090[11] = 'O';
                DAT_a807e090[12] = 'K';
                DAT_a807e090[13] = '!';
                DAT_a807e090[14] = '#';
                DAT_a807e090[15] = '\n';
                DAT_a807e090[16] = 0;
                FUN_a0061280((const char *)DAT_a807e090);
                break;
            }
            case 2:
                if ((FUN_a00b288c(DAT_a807deb4.addr, DAT_a807deb4.val) & 0xff) != DAT_a807deb4.sum)
                    break;
                FUN_a00b2304((unsigned int *)(_DAT_a807dec8 + (DAT_a807deb4.addr & ~3)), DAT_a807deb4.val);
                DAT_a807e090[0] = '#';
                DAT_a807e090[1] = 'O';
                DAT_a807e090[2] = 'K';
                DAT_a807e090[3] = '!';
                DAT_a807e090[4] = '#';
                DAT_a807e090[5] = '\n';
                DAT_a807e090[6] = 0;
                FUN_a0061280((const char *)DAT_a807e090);
                break;
            case 5:
                _DAT_a807dec8 = DAT_a807deb4.addr << 16;
                FUN_a00b281c(&DAT_a807e090[0x10], DAT_a807deb4.addr);
                DAT_a807e090[0] = '#';
                DAT_a807e090[1] = DAT_a807e090[0x14];
                DAT_a807e090[2] = DAT_a807e090[0x15];
                DAT_a807e090[3] = DAT_a807e090[0x16];
                DAT_a807e090[4] = DAT_a807e090[0x17];
                DAT_a807e090[5] = ' ';
                DAT_a807e090[6] = 'O';
                DAT_a807e090[7] = 'K';
                DAT_a807e090[8] = '!';
                DAT_a807e090[9] = '#';
                DAT_a807e090[10] = '\n';
                DAT_a807e090[11] = 0;
                FUN_a0061280((const char *)DAT_a807e090);
                break;
            }
            if (st & ST_QUIT)
                DAT_a807dea8 = 0;
        }
    }
out:
    _DAT_a807deac = 0;
}
