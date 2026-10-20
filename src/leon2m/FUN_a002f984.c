/* leon2m FUN_a002f984 @ 0xa002f984-0xa002fa34 (44 words).
 * Calls one of the function pointers at 0xa802cc1c (k 0), 0xa802cc20 (k 1) or 0xa802cc30 (k 5) when it is not null.
 * For k other than 1, "App Callback --> %d" is printed with k first when func_0x0007d614(0x10) returns nonzero.
 * Other k do nothing more.
 */
extern void (*DAT_a802cc1c[15])(void);
extern unsigned char func_0x0007d614(unsigned char);
extern int func_0x0007f170();
extern char s_001a74b0[];

void FUN_a002f984(unsigned char k)
{
    if (k != 1 && func_0x0007d614(0x10))
        func_0x0007f170(s_001a74b0, k);
    switch (k) {
    case 0:
        if (DAT_a802cc1c[0])
            DAT_a802cc1c[0]();
        break;
    case 1:
        if (DAT_a802cc1c[1])
            DAT_a802cc1c[1]();
        break;
    case 5:
        if (DAT_a802cc1c[5])
            DAT_a802cc1c[5]();
        break;
    }
}
