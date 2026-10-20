/* FUN_a00ce66c (leon2s, 0xa00ce66c-0xa00ce864, 126 words). Flags -mcpu=v8 -Os -g.
 Code facts: void (u8 port). Record word (24-byte record port of DAT_a8078bb0): bits 16..17 = 01. func_0xa0f96400(0, 0x90, 0x69493, 0, buf); if bit 2 of buf[0]
 is clear, bits 16..17 |= 3 and done. Else read 0x692e0 (15 bytes) into buf, FUN_a00c87e8(port, 1/3/5, 0x8000) around 2 x 8 reads of FUN_a00c7770(port, 1)
 into local[16], FUN_a00c7654(port, 1, x) for the 16 buf and 16 local bytes, and copies 5 bytes DAT_a807ce38[port*5 + i] to the record at
 0xa807cda8 + 0xa.
 Fixes vs draft: FUN_a00c87e8 takes 3 args (the draft passed 6; fw sets only %o0..%o2, see FUN_a00cf6bc); source table base is 0xa807ce38 (draft typo cc38, fw or 0x238); destination base is the struct at
 0xa807cda8 with the 5-byte array at +0xa (fw add base then 'stb [.. + 0xa]'; the draft used the mid-record name DAT_a807cdb2). Aids: none.
 */
extern unsigned int DAT_a8078bb0[];
extern unsigned char DAT_a807ce38[];
struct ev { unsigned char pad[0xa]; unsigned char b[5]; };
extern struct ev DAT_a807cda8;
extern int FUN_a00c7654(unsigned char, unsigned char, unsigned char);
extern int FUN_a00c7770(unsigned char, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern int func_0xa0f96400(int, int, int, int, unsigned char *);

void FUN_a00ce66c(unsigned char param_1)
{
    unsigned char local_18[16];
    unsigned char buf[16];
    unsigned short i;
    unsigned int idx;
    
    param_1 = param_1 & 0xff;
    idx = param_1 * 6;
    DAT_a8078bb0[idx] = (DAT_a8078bb0[idx] & 0xfffcffff) | 0x10000;
    
    func_0xa0f96400(0, 0x90, 0x69493, 0, buf);
    
    if ((buf[0] & 4) == 0) {
        DAT_a8078bb0[idx] = DAT_a8078bb0[idx] | 0x30000;
    } else {
        func_0xa0f96400(0, 0x90, 0x692e0, 0xf, buf);
        
        FUN_a00c87e8(param_1, 1, 0x8000);
        for (i = 0; i < 8; i++) {
            local_18[i] = (unsigned char)FUN_a00c7770(param_1, 1);
        }
        
        FUN_a00c87e8(param_1, 3, 0x8000);
        for (i = 8; i < 16; i++) {
            local_18[i] = (unsigned char)FUN_a00c7770(param_1, 1);
        }
        
        FUN_a00c87e8(param_1, 5, 0x8000);
        for (i = 0; i < 16; i++) {
            FUN_a00c7654(param_1, 1, buf[i]);
        }
        
        for (i = 0; i < 16; i++) {
            FUN_a00c7654(param_1, 1, local_18[i]);
        }
        
        for (i = 0; i < 5; i++) {
            DAT_a807cda8.b[i] = DAT_a807ce38[param_1 * 5 + i];
        }
    }
}
