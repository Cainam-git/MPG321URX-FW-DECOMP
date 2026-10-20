/* leon2s FUN_a00ce4cc @ 0xa00ce4cc (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Per-port refresh of a 32-byte data block
 * (param_1 = port; 24-byte port records at 0xa8078bb0, the same table as FUN_a00cc900). Marks
 * the record busy (bits 16-17 = 01), reads 16 bytes via 0xa0f96400; if bit 1 of the first byte
 * is clear it marks the record (bits 16-17 = 11) and stops. Otherwise it stores the 16 bytes
 * twice into 0xa807cd88, runs FUN_a00ca6d4(port), and if any of the 32 bytes differs from
 * 0xa807d088 it clears the marks and calls FUN_a00c79c8(port). The
 * record index is port*6 words (24-byte records).
 */
extern unsigned int DAT_a8078bb0[];
extern unsigned char DAT_a807d088[];
extern unsigned char DAT_a807cd88[];
extern int FUN_a00c79c8(unsigned char);
extern int FUN_a00ca6d4(unsigned char);
extern int func_0xa0f96400(int, int, int, int, unsigned char *);

void FUN_a00ce4cc(unsigned char param_1)
{
    unsigned char local_18[16];
    unsigned short i;
    unsigned char val;
    
    param_1 = param_1 & 0xff;
    i = param_1 * 6;
    DAT_a8078bb0[i] = (DAT_a8078bb0[i] & 0xfffcffff) | 0x10000;
    
    func_0xa0f96400(0, 0x90, 0x69493, 0, local_18);
    
    if ((local_18[0] & 2) == 0) {
        DAT_a8078bb0[i] = DAT_a8078bb0[i] | 0x30000;
    } else {
        func_0xa0f96400(0, 0x90, 0x692c0, 0xf, local_18);
        for (i = 0; i < 16; i++)
            DAT_a807cd88[i] = local_18[i];
        
        func_0xa0f96400(0, 0x90, 0x692d0, 0xf, local_18);
        for (i = 0; i < 16; i++)
            DAT_a807cd88[i + 16] = local_18[i];
        
        FUN_a00ca6d4(param_1);
        
        for (i = 0; i < 32; i++) {
            if (DAT_a807d088[i] != DAT_a807cd88[i]) {
                DAT_a8078bb0[param_1 * 6] = DAT_a8078bb0[param_1 * 6] & 0xfffcffff;
                FUN_a00c79c8(param_1);
                break;
            }
        }
    }
}
