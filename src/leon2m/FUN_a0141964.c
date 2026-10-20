/* leon2m FUN_a0141964 @ 0xa0141964  display output start-up (byte-exact with -mcpu=v8 -O3 -g, gcc 3.4.4).
 * Called once by the system start-up FUN_a015266c. Sets the flag block at RAM 0xA802E110 (byte 0 = 1, half 2 = 0),
 * copies the 88-byte RAW panel row (FUN_a01241fc, RAM 0xA802E378) to the stack and remaps its 3-bit link field
 * (word 0 bits 20..22, the row's link type): 1 -> 2, 2 -> 1, 0 stays 0, others unchanged. Writes the display mode
 * (DispModeTransform FUN_a0151c84) into byte +6 of the copy, hands the copy BY VALUE to FUN_a0105c0c (output
 * configuration) and finally calls FUN_a015373c (output path set-up, NEW in FW.021). So the output path
 * is configured at power-on through this function; FUN_a0141840 (the other DispModeTransform caller) does the same
 * on a panel-row change.
 */
struct Row { unsigned int hi:9; unsigned int link:3; unsigned int lo:20; unsigned short h4; unsigned char mode; unsigned char rest[81]; };
struct Flags { unsigned char on; unsigned char pad; unsigned short val; };
extern struct Flags DAT_a802e110;
extern unsigned char *FUN_a01241fc(void);
extern int FUN_a0151c84(void);
extern void FUN_a0105c0c(struct Row r);
extern void FUN_a015373c(void);
void FUN_a0141964(void)
{
    struct Row row;
    unsigned char *src;
    unsigned char i;
    DAT_a802e110.val = 0;
    DAT_a802e110.on = 1;
    src = FUN_a01241fc();
    for (i = 0; i <= 0x57; i++) ((unsigned char *)&row)[i] = src[i];
    switch (((struct Row *)src)->link) {
    case 0: row.link = 0; break;
    case 1: row.link = 2; break;
    case 2: row.link = 1; break;
    }
    row.mode = FUN_a0151c84();
    FUN_a0105c0c(row);
    FUN_a015373c();
}
