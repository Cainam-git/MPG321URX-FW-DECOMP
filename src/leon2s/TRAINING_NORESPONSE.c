/* TRAINING_NORESPONSE (leon2s 0xa0087824-0xa0087d50, 1324 bytes), flags -mcpu=v8 -Os -g.
 * Arguments: mode (byte) and caps, a pointer to a byte whose bit n selects channel n. Returns 1 or 0.
 * Channel range: start..end = 0..0 when mode is 0, else DAT_a80761c0..DAT_a80761bf.
 * Locals: cfg[4] = {0x1e, 4, 0, 0} (filled per channel by FUN_a0086c48), lv (byte, start cfg[1]),
 * lim (start cfg[0]), buf[80], retry count 2.
 * 1. For each selected channel: channel 0 returns 0 when FUN_a0086bd8() == 2 and FUN_a00ad27c(0) != 1;
 *    clears bits 1..0 of 0xcf018d00; channels other than 0 call FUN_a00a78fc(ch, 0x66, v) with v = 0 / 0x40
 *    for FUN_a00876ec(ch) == 6 / 10, else 0x20; then FUN_a0086c48(ch, cfg) and FUN_a00865b8(ch, 1).
 * 2. Loop while retry != 0: each selected channel gets FUN_a0087734(ch, lim, ch), FUN_a0087794(ch, lv) and
 *    FUN_a0086df4(ch, lv, lim); r = FUN_a0087110(start, &lv, buf, caps).
 *    r == 4: r = FUN_a008743c(start, &lv, buf, caps); unless r == 5: a nonzero loop index after the channel
 *    loop decrements retry; r == 9 halves lv while lv > cfg[3], else counts as 8; r == 8 steps lim
 *    0x1e -> 0x14 -> 10 -> 6 and reloads lv = cfg[1] while lim > cfg[2], else r = 1.
 *    r != 4: prints "CDR fail\r" (FUN_a00734c4); same retry decrement; steps lim while lim > cfg[2]; else
 *    when FUN_a0087074(0) == 1 and lv > cfg[3], tries FUN_a00870a4(lv >> 1, buf) and FUN_a00870a4(lv >> 2,
 *    buf): the first that returns 4 becomes lv and lim = cfg[0]; otherwise r = 1.
 *    r == 2 prints "TRAINING_NORESPONSE\r", r == 1 prints "TRAINING_FAIL\r", r == 5 sets r = 0; all three
 *    leave the loop.
 * 3. For each channel: FUN_a00864d4(ch, 7) == 0 on channel 0 returns 0; when it is nonzero and r == 0,
 *    channel 0 calls func_0x9f1c649c() and func_0x9f1c64ec() if FUN_a00866a4() == 1 and FUN_a0086bd8() == 1,
 *    and every such channel calls FUN_a008661c(ch).
 * 4. r == 0: FUN_a0085914(ch), FUN_a00aa930(ch, 4) and "Channel[%02x] is Training done!!" (selected) or
 *    "... is skipped" for each channel, returns 1; else FUN_a0085914(ch), FUN_a00aa930(ch, 7) and
 *    "Channel[%02x] is Training fail", returns 0.
 * Source forms: cfg is zero-initialised and its two bytes are stored after the range setup; the halving
 * steps copy lv into an unsigned int (lv is address-taken) and both FUN_a00870a4 results are tested with !=.
 * Compiler aid: __builtin_expect(..., 1) on the first FUN_a00870a4 test emits no instructions; it fills the
 * branch delay slot from the fall-through path instead of the success block.
 */
#define R8D00 (*(volatile unsigned int *)0xcf018d00)

extern unsigned char DAT_a80761c0;
extern unsigned char DAT_a80761bf;

extern unsigned char FUN_a0086bd8(void);
extern unsigned char FUN_a00ad27c(unsigned char port);
extern unsigned char FUN_a00876ec(unsigned int port);
extern void FUN_a00a78fc(unsigned int port, unsigned short reg, unsigned int v);
extern void FUN_a0086c48(unsigned char port, unsigned char *cfg);
extern int FUN_a00865b8(int port, int v);
extern void FUN_a0087734(unsigned int port, unsigned char a, unsigned int b);
extern void FUN_a0087794(unsigned char port, unsigned int v);
extern int FUN_a0086df4(unsigned char port, unsigned char hi, unsigned char lo);
extern unsigned char FUN_a0087110(unsigned char port, unsigned char *lv, unsigned char *buf, unsigned char *caps);
extern unsigned char FUN_a008743c(unsigned char port, unsigned char *lv, unsigned char *buf, unsigned char *caps);
extern unsigned int FUN_a00734c4(const char *s);
extern unsigned char FUN_a0087074(unsigned int v);
extern unsigned char FUN_a00870a4(unsigned int mode, unsigned char *buf);
extern unsigned char FUN_a00864d4(unsigned int port, unsigned int v);
extern unsigned char FUN_a00866a4(void);
extern void func_0x9f1c649c(void);
extern void func_0x9f1c64ec(void);
extern unsigned char FUN_a008661c(unsigned char port);
extern void FUN_a0085914(unsigned char port);
extern void FUN_a00aa930(unsigned char bank, unsigned char mode);
extern int FUN_a0073044(const char *, ...);

unsigned char TRAINING_NORESPONSE(unsigned char mode, unsigned char *caps)
{
    unsigned char cfg[4] = {0};
    unsigned char buf[80];
    unsigned char lv;
    unsigned char retry = 2;
    unsigned char start = 0;
    unsigned char end = 0;
    unsigned char i;
    unsigned char lim;
    unsigned char r;
    unsigned int c;
    unsigned int t;

    if (mode) {
        start = DAT_a80761c0;
        end = DAT_a80761bf;
    }
    cfg[1] = 4;
    cfg[0] = 0x1e;

    for (i = start; i <= end; i++) {
        if ((*caps >> i) & 1) {
            if (i == 0 && FUN_a0086bd8() == 2 && FUN_a00ad27c(0) != 1)
                return 0;
            R8D00 &= ~3;
            if (i != 0) {
                r = FUN_a00876ec(i);
                if (r == 8)
                    FUN_a00a78fc(i, 0x66, 0x20);
                else if (r == 6)
                    FUN_a00a78fc(i, 0x66, 0);
                else if (r == 10)
                    FUN_a00a78fc(i, 0x66, 0x40);
                else
                    FUN_a00a78fc(i, 0x66, 0x20);
            }
            FUN_a0086c48(i, cfg);
            FUN_a00865b8(i, 1);
        }
    }

    lv = cfg[1];
    lim = cfg[0];
    do {
        for (i = start; i <= end; i++) {
            if ((*caps >> i) & 1) {
                FUN_a0087734(i, lim, i);
                FUN_a0087794(i, lv);
                FUN_a0086df4(i, lv, lim);
            }
        }
        r = FUN_a0087110(start, &lv, buf, caps);
        if (r == 4) {
            r = FUN_a008743c(start, &lv, buf, caps);
            if (r != 5) {
                if (i) {
                    retry--;
                    continue;
                }
                if (r == 9) {
                    if (lv > cfg[3]) {
                        lv = lv >> 1;
                        continue;
                    }
                    r = 8;
                }
                if (r == 8) {
                    if (lim > cfg[2]) {
                        switch (lim) {
                        case 0x1e:
                            lim = 0x14;
                            break;
                        case 0x14:
                            lim = 10;
                            break;
                        case 10:
                            lim = 6;
                            break;
                        }
                        lv = cfg[1];
                        continue;
                    }
                    r = 1;
                }
            }
        } else {
            FUN_a00734c4("CDR fail\r");
            if (i) {
                retry--;
                continue;
            }
            if (lim > cfg[2]) {
                switch (lim) {
                case 0x1e:
                    lim = 0x14;
                    break;
                case 0x14:
                    lim = 10;
                    break;
                case 10:
                    lim = 6;
                    break;
                }
                continue;
            }
            if (FUN_a0087074(0) == 1) {
                c = lv;
                if (c > cfg[3]) {
                    t = c >> 1;
                    if (__builtin_expect(FUN_a00870a4(t, buf) != 4, 1)) {
                        t = c >> 2;
                        if (FUN_a00870a4(t, buf) != 4)
                            goto fail;
                    }
                    lv = t;
                    lim = cfg[0];
                    continue;
                }
            }
        fail:
            r = 1;
        }
        if (r == 2) {
            FUN_a00734c4("TRAINING_NORESPONSE\r");
            break;
        }
        if (r == 1) {
            FUN_a00734c4("TRAINING_FAIL\r");
            break;
        }
        if (r == 5) {
            r = 0;
            break;
        }
    } while (retry);

    for (i = start; i <= end; i++) {
        if (!FUN_a00864d4(i, 7)) {
            if (i == 0)
                return 0;
        } else if (r == 0) {
            if (i == 0 && FUN_a00866a4() == 1 && FUN_a0086bd8() == 1) {
                func_0x9f1c649c();
                func_0x9f1c64ec();
            }
            FUN_a008661c(i);
        }
    }

    if (r == 0) {
        for (i = start; i <= end; i++) {
            FUN_a0085914(i);
            FUN_a00aa930(i, 4);
            if ((*caps >> i) & 1)
                FUN_a0073044("Channel[%02x] is Training done!!\r\n", i);
            else
                FUN_a0073044("Channel[%02x] is skipped\r\n", i);
        }
        return 1;
    }
    for (i = start; i <= end; i++) {
        FUN_a0085914(i);
        FUN_a00aa930(i, 7);
        FUN_a0073044("Channel[%02x] is Training fail\r\n", i);
    }
    return 0;
}
