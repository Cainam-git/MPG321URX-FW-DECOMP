/* leon2m FUN_a00e0e44 @ 0xa00e0e44-0xa00e1f50 (1091 words), flags -mcpu=v8 -O3 -g.
 * Command loop over the byte buffer s_a802d654 (pointer at 0xa802d654, length u_a802d658 at 0xa802d658),
 * starting at index pos: while pos < length, the byte at pos selects a command (switch, jump table at 0x00080d30
 * for 0..61, larger values go to the default), the argument bytes that follow are copied into a[] and pos moves on
 * to the next command byte. Command 61 returns; when pos reaches the length the function stays in for (;;).
 * Commands without a unit loop: 1 passes each byte of the zero-terminated string after the command to
 * FUN_a00df4d4, then FUN_a00df170("\n"); 2 skips such a string; 4 FUN_a00dffd8(a0, a1 << 8 | a2, a3 << 8 | a4);
 * 6 FUN_a00dffa4(a0 * 10); 7, 41 and 44 only consume 1, 2 and 3 argument bytes; 8 stores byte a4 and 9 the
 * big-endian word a4..a7 at the big-endian address a0..a3; 10 stores the word a4..a7 at a0..a3 + 0xc0150000 and
 * at a0..a3 + 0xc1150000; 5 and 32 call FUN_a00e2180 with three words built from a[] (5: a mask
 * (1 << (a4 + 1)) - (1 << a5) and the word a6..a9 shifted left by a5); 21 FUN_a00df450("setstatus NOT
 * support\n"); 30/31 FUN_a00e0090(a0); 18, 23, 28, 33, 35, 36, 37, 39 and 40 FUN_a00df170("bad!Invalid command ID
 * %d!!\n", command byte); the default FUN_a00df450("ERROR\n").
 * Unit-loop commands call their function for every k from DAT_0019962c[u].first to DAT_0019962c[u].last, with
 * u = a0 and 0xff selecting entry 4, and the following argument bytes as parameters: 22 FUN_a00e2340, 24
 * FUN_a00e05d8, 25 FUN_a00e03b0, 27 FUN_a00e0888 (24/25/27 with the 12-bit value (a1 & 0xf) << 8 | a2), 34
 * FUN_a00eecd0(k, 1), 38 FUN_a00e7eb0, 42/43 FUN_a00e0134 (16-bit a1 << 8 | a2, last argument 1 / 0), 45/46/47
 * FUN_a00e3bdc (last argument 0 / 1 / 2), 48/58 FUN_a00ed70c, 49/57 FUN_a00e7254 (48 and 49 pass a6, a7 / a4, a5
 * only when the command byte is 0x3a / 0x39, else 0), 50 FUN_a00e47f8, 51 FUN_a00ea878, 52 FUN_a00e8e6c, 53
 * FUN_a00ec6b8, 54 FUN_a00e9c80, 55 FUN_a00ee1e8, 56 FUN_a00ee964.
 * Callers: FUN_a00e1f50, FUN_a00e1fc8.
 * Accesses to addresses taken from the command data are volatile.
 * Source form: argument copy loops written 'pos++; a[j] = buf[pos]; j++;'; buffer pointer and length declared as
 * s_a802d654 / u_a802d658; the case bodies in this source order, each with its own block-scope locals in this
 * declaration order; the nine "bad!Invalid command ID" commands as separate case bodies; 'last' at function
 * scope; commands 48, 52 and 53 use the function-scope locals q1..q5, qx, qy for their argument bytes; commands
 * 24, 25, 27, 42, 43, 48 and 49 read a0 into t before the other argument bytes.
 */
struct Range { int first; int last; };
struct Pair { int a; int b; };
extern unsigned char *s_a802d654;
extern unsigned int u_a802d658;
extern const struct Range DAT_0019962c[];
extern int FUN_a00df170(const char *fmt, ...);
extern int FUN_a00df450(const char *s);
extern void FUN_a00df4d4(signed char c);
extern void FUN_a00dffa4(unsigned int n);
extern void FUN_a00dffd8(unsigned int id, int a, int b);
extern void FUN_a00e0090(unsigned char p);
extern void FUN_a00e0134(int phy, unsigned int addr, unsigned int delta, unsigned int mask, unsigned int limit, int keep, unsigned int sat, int add);
extern void FUN_a00e03b0(int phy, unsigned int addr, unsigned int val);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00e0888(int phy, unsigned int addr, unsigned int mask, unsigned int expect);
extern void FUN_a00e2180(unsigned int, unsigned int, unsigned int);
extern void FUN_a00e2340(unsigned int, unsigned int, unsigned int);
extern int FUN_a00e3bdc(unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00e47f8(unsigned int dev, unsigned int ofs, int byte_idx);
extern int FUN_a00e7254(unsigned int, unsigned int, unsigned int, unsigned int, int, int, unsigned int, unsigned int);
extern int FUN_a00e7eb0(unsigned int, unsigned int, unsigned int, unsigned int);
extern struct Pair FUN_a00e8e6c(unsigned int, unsigned int, unsigned int, int, unsigned int);
extern int FUN_a00e9c80(unsigned int unit, unsigned int p2, unsigned int p3, int b, int pct, unsigned int p6);
extern int FUN_a00ea878(unsigned int, unsigned int, unsigned int, unsigned int, int, unsigned int);
extern struct Pair FUN_a00ec6b8(unsigned int, unsigned int, unsigned int, int, unsigned int, unsigned int);
extern int FUN_a00ed70c(unsigned int unit, unsigned int p1, unsigned int type, int b, int p4, int p5, int p6, int p7);
extern int FUN_a00ee1e8(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00ee964(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00eecd0(unsigned int p, int full);

void FUN_a00e0e44(unsigned int pos)
{
    unsigned char a[16];
    unsigned char j;
    unsigned int v;
    int i;
    int last;
    unsigned int q4, q5, qy, qx, q1, q2, q3;

    while (pos < u_a802d658) {
        j = 0;
        switch (s_a802d654[pos]) {
        case 61:
            return;
        case 4:
            for (i = 0; i < 5; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            FUN_a00dffd8(a[0], a[1] << 8 | a[2], a[3] << 8 | a[4]);
            break;
        case 6:
            for (i = 0; i < 1; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            FUN_a00dffa4(a[0] * 10);
            break;
        case 8:
            for (i = 0; i < 5; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            *(volatile unsigned char *)(a[0] << 24 | a[1] << 16 | a[2] << 8 | a[3]) = a[4];
            break;
        case 28:
            FUN_a00df170("bad!Invalid command ID %d!!\n", s_a802d654[pos]);
            break;
        case 9:
            for (i = 0; i < 8; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            *(volatile unsigned int *)(a[0] << 24 | a[1] << 16 | a[2] << 8 | a[3]) = a[4] << 24 | a[5] << 16 | a[6] << 8 | a[7];
            break;
        case 10:
            {
                unsigned int w;
                for (i = 0; i < 8; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                w = a[0] << 24 | a[1] << 16 | a[2] << 8 | a[3];
                v = a[4] << 24 | a[5] << 16 | a[6] << 8 | a[7];
                *(volatile unsigned int *)(w + 0xc0150000) = v;
                *(volatile unsigned int *)(w + 0xc1150000) = v;
            }
            break;
        case 42:
            {
                unsigned int p3;
                unsigned int p4;
                unsigned int p5;
                unsigned int p6;
                unsigned int p7;
                int u;
                unsigned int t;
                int k;
                unsigned short addr;
                for (i = 0; i < 8; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                t = a[0];
                addr = a[1] << 8 | a[2];
                p3 = a[3];
                p4 = a[4];
                p5 = a[5];
                p6 = a[6];
                p7 = a[7];
                if (t == 0xff)
                    u = 4;
                else
                    u = t;
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e0134(k, addr, p3, p4, p5, p6, p7, 1);
            }
            break;
        case 43:
            {
                unsigned int p3;
                unsigned int p4;
                unsigned int p5;
                unsigned int p6;
                unsigned int p7;
                int u;
                unsigned int t;
                int k;
                unsigned short addr;
                for (i = 0; i < 8; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                t = a[0];
                addr = a[1] << 8 | a[2];
                p3 = a[3];
                p4 = a[4];
                p5 = a[5];
                p6 = a[6];
                p7 = a[7];
                if (t == 0xff)
                    u = 4;
                else
                    u = t;
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e0134(k, addr, p3, p4, p5, p6, p7, 0);
            }
            break;
        case 23:
            FUN_a00df170("bad!Invalid command ID %d!!\n", s_a802d654[pos]);
            break;
        case 7:
            for (i = 0; i < 1; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            break;
        case 21:
            for (i = 0; i < 1; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            FUN_a00df450("setstatus NOT support\n");
            break;
        case 24:
            {
                unsigned int p3;
                int u;
                unsigned int t;
                int k;
                unsigned int w;
                unsigned int p4;
                for (i = 0; i < 5; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                t = a[0];
                w = (a[1] & 0xf) << 8 | a[2];
                p3 = a[3];
                p4 = a[4];
                if (t == 0xff)
                    u = 4;
                else
                    u = t;
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e05d8(k, w, p3, p4);
            }
            break;
        case 25:
            {
                unsigned int p3;
                int u;
                unsigned int t;
                int k;
                unsigned int w;
                for (i = 0; i < 4; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                t = a[0];
                w = (a[1] & 0xf) << 8 | a[2];
                p3 = a[3];
                if (t == 0xff)
                    u = 4;
                else
                    u = t;
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e03b0(k, w, p3);
            }
            break;
        case 27:
            {
                unsigned int w;
                unsigned int p3;
                unsigned int p4;
                int u;
                unsigned int t;
                int k;
                for (i = 0; i < 5; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                t = a[0];
                w = (a[1] & 0xf) << 8 | a[2];
                p3 = a[3];
                p4 = a[4];
                if (t == 0xff)
                    u = 4;
                else
                    u = t;
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e0888(k, w, p3, p4);
            }
            break;
        case 30:
        case 31:
            for (i = 0; i < 1; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            FUN_a00e0090(a[0]);
            break;
        case 32:
            for (i = 0; i < 12; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            FUN_a00e2180(a[0] << 24 | a[1] << 16 | a[2] << 8 | a[3], a[4] << 24 | a[5] << 16 | a[6] << 8 | a[7],
                         a[8] << 24 | a[9] << 16 | a[10] << 8 | a[11]);
            break;
        case 5:
            for (i = 0; i < 10; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            FUN_a00e2180(a[0] << 24 | a[1] << 16 | a[2] << 8 | a[3], (1 << (a[4] + 1)) - (1 << a[5]),
                         (a[6] << 24 | a[7] << 16 | a[8] << 8 | a[9]) << a[5]);
            break;
        case 22:
            {
                unsigned int p1;
                unsigned int p2;
                int u;
                int k;
                for (i = 0; i < 3; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                p1 = a[1];
                p2 = a[2];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e2340(k, p1, p2);
            }
            break;
        case 45:
            {
                unsigned int p1;
                unsigned int p2;
                int u;
                int k;
                for (i = 0; i < 3; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                p1 = a[1];
                p2 = a[2];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e3bdc(k, p1, p2, 0);
            }
            break;
        case 46:
            {
                unsigned int p1;
                unsigned int p2;
                int u;
                int k;
                for (i = 0; i < 3; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                p1 = a[1];
                p2 = a[2];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e3bdc(k, p1, p2, 1);
            }
            break;
        case 36:
            FUN_a00df170("bad!Invalid command ID %d!!\n", s_a802d654[pos]);
            break;
        case 18:
            FUN_a00df170("bad!Invalid command ID %d!!\n", s_a802d654[pos]);
            break;
        case 47:
            {
                unsigned int p1;
                unsigned int p2;
                int u;
                int k;
                for (i = 0; i < 3; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                p1 = a[1];
                p2 = a[2];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e3bdc(k, p1, p2, 2);
            }
            break;
        case 50:
            {
                unsigned int p1;
                unsigned int p2;
                int u;
                int k;
                for (i = 0; i < 3; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                p1 = a[1];
                p2 = a[2];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e47f8(k, p1, p2);
            }
            break;
        case 33:
            FUN_a00df170("bad!Invalid command ID %d!!\n", s_a802d654[pos]);
            break;
        case 51:
            {
                unsigned int p4;
                unsigned int p1;
                unsigned int p2;
                unsigned int p3;
                int u;
                int k;
                for (i = 0; i < 5; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                p1 = a[1];
                p2 = a[2];
                p3 = a[3];
                p4 = a[4];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00ea878(k, p1, p2, p3, 4, p4);
            }
            break;
        case 38:
            {
                unsigned int p1;
                unsigned int p2;
                unsigned int p3;
                int u;
                int k;
                for (i = 0; i < 4; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                p1 = a[1];
                p2 = a[2];
                p3 = a[3];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e7eb0(k, p1, p2, p3);
            }
            break;
        case 40:
            FUN_a00df170("bad!Invalid command ID %d!!\n", s_a802d654[pos]);
            break;
        case 39:
            FUN_a00df170("bad!Invalid command ID %d!!\n", s_a802d654[pos]);
            break;
        case 49:
        case 57:
            {
                unsigned char c;
                unsigned int x;
                unsigned int y;
                unsigned int p1;
                unsigned int p2;
                unsigned int p3;
                int u;
                unsigned int t;
                int k;
                c = s_a802d654[pos];
                for (i = 0; i < 6; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                t = a[0];
                p1 = a[1];
                p2 = a[2];
                p3 = a[3];
                x = 0;
                y = 0;
                if (c == 0x39) {
                    x = a[4];
                    y = a[5];
                }
                if (t == 0xff)
                    u = 4;
                else
                    u = t;
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e7254(k, p1, p2, p3, 0, 0, x, y);
            }
            break;
        case 34:
            {
                int u;
                int k;
                for (i = 0; i < 1; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00eecd0(k, 1);
            }
            break;
        case 48:
        case 58:
            {
                unsigned char c;
                int u;
                unsigned int t;
                int k;
                c = s_a802d654[pos];
                for (i = 0; i < 8; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                t = a[0];
                q1 = a[1];
                q2 = a[2];
                q3 = a[3];
                q4 = a[4];
                q5 = a[5];
                qx = 0;
                qy = 0;
                if (c == 0x3a) {
                    qx = a[6];
                    qy = a[7];
                }
                if (t == 0xff)
                    u = 4;
                else
                    u = t;
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00ed70c(k, q1, q2, q3, q4, q5, qx, qy);
            }
            break;
        case 53:
            {
                int u;
                int k;
                for (i = 0; i < 6; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                q1 = a[1];
                q2 = a[2];
                q3 = a[3];
                q4 = a[4];
                q5 = a[5];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00ec6b8(k, q1, q2, q3, q5, q4);
            }
            break;
        case 52:
            {
                int u;
                int k;
                for (i = 0; i < 5; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                q1 = a[1];
                q2 = a[2];
                q3 = a[3];
                q4 = a[4];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e8e6c(k, q1, q2, q3, q4);
            }
            break;
        case 35:
            FUN_a00df170("bad!Invalid command ID %d!!\n", s_a802d654[pos]);
            break;
        case 37:
            FUN_a00df170("bad!Invalid command ID %d!!\n", s_a802d654[pos]);
            break;
        case 54:
            {
                unsigned int p5;
                unsigned int p1;
                unsigned int p2;
                unsigned int p3;
                unsigned int p4;
                int u;
                int k;
                for (i = 0; i < 6; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                p1 = a[1];
                p2 = a[2];
                p3 = a[3];
                p4 = a[4];
                p5 = a[5];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00e9c80(k, p1, p2, p3, p5, p4);
            }
            break;
        case 55:
            {
                unsigned int p6;
                unsigned int p7;
                unsigned int p1;
                unsigned int p2;
                unsigned int p3;
                unsigned int p4;
                unsigned int p5;
                int u;
                int k;
                for (i = 0; i < 8; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                p1 = a[1];
                p2 = a[2];
                p3 = a[3];
                p4 = a[4];
                p5 = a[5];
                p6 = a[6];
                p7 = a[7];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00ee1e8(k, p1, p2, p3, p4, p5, p6, p7);
            }
            break;
        case 56:
            {
                unsigned int p6;
                unsigned int p1;
                unsigned int p2;
                unsigned int p3;
                unsigned int p4;
                unsigned int p5;
                int u;
                int k;
                for (i = 0; i < 7; i++) {
                    pos++;
                    a[j] = s_a802d654[pos];
                    j++;
                }
                p1 = a[1];
                p2 = a[2];
                p3 = a[3];
                p4 = a[4];
                p5 = a[5];
                p6 = a[6];
                if (a[0] == 0xff)
                    u = 4;
                else
                    u = a[0];
                last = DAT_0019962c[u].last;
                for (k = DAT_0019962c[u].first; k <= last; k++)
                    FUN_a00ee964(k, p1, p2, p3, p4, p5, p6);
            }
            break;
        case 41:
            for (i = 0; i < 2; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            break;
        case 44:
            for (i = 0; i < 3; i++) {
                pos++;
                a[j] = s_a802d654[pos];
                j++;
            }
            break;
        case 1:
            for (;;) {
                if (s_a802d654[++pos] == 0)
                    break;
                FUN_a00df4d4(s_a802d654[pos]);
            }
            FUN_a00df170("\n");
            break;
        case 2:
            while (s_a802d654[++pos] != 0)
                ;
            break;
        default:
            FUN_a00df450("ERROR\n");
            break;
        }
        pos++;
    }
    for (;;)
        ;
}
