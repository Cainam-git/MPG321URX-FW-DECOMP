/* leon2s FUN_a00d9edc @ 0xa00d9edc-0xa00da030, -mcpu=v8 -Os -g.
 * (u8 a, u8 b, u8 v), void. k = byte DAT_a8078832, j = DAT_a8078800[k]; rec = 11-byte record
 * ARR_a807a398[k][j], c = byte ARR_a8079c62[k][j]. FUN_a00d6724(buf, rec) fills a 24-byte stack buffer; in its
 * word +0x10 bits 16..21 = v, bit 15 = a and bit 14 = b (bit-field stores); r = (u8)FUN_a00d68cc(buf, rec).
 * Then r bytes of rec are copied, one byte per 32-bit word, to the register block DAT_a807609c[k] (from
 * word 0 when c == 0, from word 0x30 otherwise), table and index reloaded on every pass.
 * Same buffer, record and destination handling as FUN_a00da6ac (volatile register-block pointers).
 */
struct w4 { unsigned int hi : 10; unsigned int f16 : 6; unsigned int b15 : 1; unsigned int b14 : 1; unsigned int lo : 14; };
struct msg { unsigned int w[4]; struct w4 f; unsigned int w5; };
union buf { struct msg m; unsigned char b[24]; };

extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078800[];
extern unsigned char ARR_a8079c62[][16];
extern unsigned char ARR_a807a398[][16][11];
extern volatile unsigned int *DAT_a807609c[];
extern void FUN_a00d6724(unsigned char *, unsigned char *);
extern unsigned char FUN_a00d68cc(unsigned char *, unsigned char *);

void FUN_a00d9edc(unsigned char a, unsigned char b, unsigned char v)
{
    union buf buf;
    unsigned char *rec;
    unsigned char c, i, r;

    rec = ARR_a807a398[DAT_a8078832][DAT_a8078800[DAT_a8078832]];
    c = ARR_a8079c62[DAT_a8078832][DAT_a8078800[DAT_a8078832]];
    FUN_a00d6724(buf.b, rec);
    buf.m.f.f16 = v;
    buf.m.f.b15 = a;
    buf.m.f.b14 = b;
    r = FUN_a00d68cc(buf.b, rec);
    if (c == 0) {
        for (i = 0; i < r; i++)
            DAT_a807609c[DAT_a8078832][i] = rec[i];
    } else {
        for (i = 0; i < r; i++)
            DAT_a807609c[DAT_a8078832][i + 0x30] = rec[i];
    }
}
