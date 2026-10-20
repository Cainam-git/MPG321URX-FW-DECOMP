/* leon2m FUN_a0141840 @ 0xa0141840  display output re-configuration on a panel-row change (MATCH -mcpu=v8 -O3 -g, gcc 3.4.4).
 * Called by FUN_a01483f4 (apply panel row). Twin of the start-up FUN_a0141964 without
 * the flag block: copies the 88-byte raw panel row (FUN_a01241fc), remaps the 3-bit link field (word 0 bits 20..22:
 * 1 -> 2, 2 -> 1, 0 stays 0), stores DispModeTransform FUN_a0151c84 in byte +6, passes the copy by value to
 * FUN_a0105c0c and calls FUN_a015373c (output path set-up, new in FW.021). This is the route by which a newly chosen
 * panel row reaches the output configuration.
 */
struct PanelRow { unsigned long long q[11]; };
extern unsigned char *FUN_a01241fc(void);
extern unsigned char FUN_a0151c84(void);
extern void FUN_a0105c0c(struct PanelRow);
extern void FUN_a015373c(void);
void FUN_a0141840(void)
{
    struct PanelRow r;                      /* working copy, passed by value */
    unsigned char *src = FUN_a01241fc();
    unsigned char i;
    int m;
    for (i = 0; i <= 0x57; i++) ((unsigned char *)&r)[i] = src[i];
    m = (*(unsigned int *)src >> 20) & 7;
    switch (m) {
    case 0: *(unsigned int *)&r &= ~0x700000; break;
    case 1: *(unsigned int *)&r = (*(unsigned int *)&r & ~0x700000) | 0x200000; break;
    case 2: *(unsigned int *)&r = (*(unsigned int *)&r & ~0x700000) | 0x100000; break;
    }
    ((unsigned char *)&r)[6] = FUN_a0151c84();
    FUN_a0105c0c(r);
    FUN_a015373c();
}
