/* leon2m FUN_a00bd6e4 @ 0xa00bd6e4 (-mcpu=v8 -O2 -g)
 * This function formats a two-digit value into a display buffer at `DAT_a802d078`. It reads a byte from `DAT_a802d41d`, and based on whether it's > 9, writes either "1X" (where X is the value + 0x26, i.e., 0x30-0x39 for values 10-19) or "0X" (where X is the value + 0x30, i.e., 0x30-0x39 for values 0-9) into offsets 8-9 of the buffer. It always writes '0' to offset 7. Then it calls the trace/display functions with the parameter and 0xb. The main uncertainty is whether the comparison should be signed or unsigned (the target uses `bleu`, suggesting unsigned), and the exact parameter types for the c
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0

extern unsigned char DAT_a802d41d;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern int FUN_a00ba950();
extern void FUN_a00babe4(undefined1 param_1, undefined1 param_2);

void FUN_a00bd6e4(byte param_1)
{
    unsigned char val = DAT_a802d41d;
    
    DAT_a802d078[7] = 0x30;
    if (val > 9) {
        DAT_a802d078[8] = 0x31;
        DAT_a802d078[9] = (val + 0x26);
    } else {
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (val + 0x30);
    }
    (void)FUN_a00bac3c(0x2b);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
    return;
}
