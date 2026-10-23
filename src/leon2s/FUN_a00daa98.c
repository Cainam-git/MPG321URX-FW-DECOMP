/* leon2s FUN_a00daa98 @ 0xa00daa98-0xa00dabf8, -mcpu=v8 -Os -g.
 * Returns 0 or 1. k = byte DAT_a80787fc: rec = 0x30-byte record ARR_a8079c98[k & 0xf], c = DAT_a8079c50[k];
 * DAT_a807883b = 0; FUN_a00d6724(buf, rec) fills a 24-byte stack buffer whose byte field at bits 8..15 of word
 * +0x10 is tested. f = 1 when its bit 7 is set and (u8)FUN_a00da9e8() != 0. When DAT_a807883c == 0 and f == 0:
 * FUN_a00da6ac(), FUN_a00da838(), bit 4 (c == 0) or bit 5 (c != 0) of word +0xccc of the register block
 * DAT_a80760a4[DAT_a8078832] is set, func_0xa0fbe1c0(DAT_a8078832) (ROM call). Bit 6 of the byte field set:
 * DAT_a8078838[DAT_a8078832] = 0, DAT_a807883b = 1, DAT_a807883c = 0; clear: DAT_a8078838[..] = 4.
 * Then DAT_a80787fc = (k + 1) & 0xf; f set: FUN_a00da960(0), return 0; else return 1.
 * Source form: rec is taken into a local before c is read.
 */
struct hdr { unsigned int w[4]; unsigned int hi : 16; unsigned int b2 : 8; unsigned int b3 : 8; unsigned int w5; };
union buf { struct hdr h; unsigned char b[24]; };

extern unsigned char DAT_a80787fc;
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a807883b;
extern unsigned char DAT_a807883c;
extern unsigned char DAT_a8078838[];
extern unsigned char DAT_a8079c50[];
extern unsigned char ARR_a8079c98[][0x30];
extern volatile unsigned int *DAT_a80760a4[];
extern void FUN_a00d6724(unsigned char *, unsigned char *);
extern int FUN_a00da9e8(void);
extern void FUN_a00da6ac(void);
extern void FUN_a00da838(void);
extern void FUN_a00da960(unsigned char);
extern void func_0xa0fbe1c0(unsigned char);

int FUN_a00daa98(void)
{
    union buf buf;
    unsigned char *rec;
    unsigned char c, f;

    rec = ARR_a8079c98[DAT_a80787fc & 0xf];
    c = DAT_a8079c50[DAT_a80787fc];
    DAT_a807883b = 0;
    FUN_a00d6724(buf.b, rec);
    f = 0;
    if ((buf.h.b2 & 0x80) && (unsigned char)FUN_a00da9e8() != 0)
        f = 1;
    if (DAT_a807883c == 0 && f == 0) {
        FUN_a00da6ac();
        FUN_a00da838();
        if (c == 0)
            DAT_a80760a4[DAT_a8078832][0xccc / 4] |= 0x10;
        else
            DAT_a80760a4[DAT_a8078832][0xccc / 4] |= 0x20;
        func_0xa0fbe1c0(DAT_a8078832);
    }
    if (buf.h.b2 & 0x40) {
        DAT_a8078838[DAT_a8078832] = 0;
        DAT_a807883b = 1;
        DAT_a807883c = 0;
    } else {
        DAT_a8078838[DAT_a8078832] = 4;
    }
    DAT_a80787fc = (DAT_a80787fc + 1) & 0xf;
    if (f) {
        FUN_a00da960(0);
        return 0;
    }
    return 1;
}
