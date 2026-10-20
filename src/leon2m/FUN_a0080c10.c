/* leon2m FUN_a0080c10 @ 0xa0080c10..0xa0081e0c  APP event generator (flags -mcpu=v8 -O3 -g; -msoft-float gives
 * the same code).
 *
 * Runs once per APP step (first call in FUN_a008a210), unless DAT_a802af41 bit 0 is set.
 * - Head: FUN_a0143fb8() set -> af49 = 0, FUN_a0143fc4(0); else event 0x3D when FUN_a0143fa8() rises from 0.
 * - For each used port p (FUN_a0080320 rule: 0 always, 1 if d2af != 0, 2 if d2af 4..7, 3 if d2af == 7):
 *   one-time init of af50[] = 0x3F / af60[] = 0xFF. If a delayed event af50[p] waits and the port timer 4+p
 *   (FUN_a0086a3c) expired or af45 bit p is set, it is posted (base + p). Otherwise the mapped port state
 *   FUN_a0143c14(p) (forced 0 while the power-suspend field is 1) is turned into an event on a state change
 *   (af60[p] = last state): 0->1, 1->2, 2->0x3E, 3->0, 4->4/0xA (stored in af50[p] as a delayed event, posted
 *   as 0xF now; 4 when FUN_a0143ff0(p) (or FUN_a014412c() on port 0 with settings bit 9) == 1, else 0xA),
 *   5->0x18, 6->0x1C, 8->0x20 (only from state 10), 9->0x25, 10->0x38/0x33/0x2E; port events get +p,
 *   and any event clears af42 bits p, 5+p, 10+p and 4/9/14.
 *   af64 bit p mirrors the port's "active" bit; a change while in state 4 runs FUN_a0080978 (fake-sleep exit,
 *   power-suspend field 2) or the LED pair FUN_a0124b40/FUN_a0124a68, and resets af60 (FUN_a00808ac(p, 0)).
 * - After each posted event (ev != 0x3F): 0 -> 3 (all used ports <= 3); 0xF..0x12 -> 0x13, then 0x14 once
 *   (af41 bit 3) when all <= 4; 4..7 / 0xA..0xD with all <= 4 and every other used port's timer done or af45 bit
 *   set -> final event 8 / 0xE (0xE for port 0's 0xA with d2af == 0, or FUN_a0144114() == 0), posted after the
 *   loop; 0x20..0x23 -> 0x24 (all <= 8); 0x38.. -> 0x3C, 0x33.. -> 0x37 (all <= 4 or FUN_a0143e70/FUN_a0143f0c);
 *   0x25.. -> 0x29; 0x2E.. -> 0x32.
 * Inlined helpers (standalone copies exist in the firmware): FUN_a0080320 (port used), FUN_a00808ac(p, 0)
 * (state reset), FUN_a00803a4 (all used ports <= 4); all_le3() is the same loop with limit 3 (port rule inline).
 * Source form: the post-event chain is ONE block 'if (ev != 0x3f) { FUN_a008a184(ev); ... }' (not
 * 'if (ev == 0x3f) continue;'): that is what lifts the 'ev - 56' test to the frequency the fw layout needs
 * (bgu,a + 'add -51' in the delay slot at 0xA0081720); the 0x20 / 4..7 / 0x38 / 0x33 range tests
 * carry no hints (all 50/50 as in the fw). Case orders: timer_id 3, 1, 2; delayed-event
 * add switch 1, 3, 2; state switch 0, 3, 1, 2, 4, 5, 6, 8, 9, 10; port-event add switch 2, 3, 1; af42 clear
 * default, 1, 2, 3. The switch blocks all end in break/return, so their order does not change behaviour.
 * port_used_m() / port_used() are the same function body.
 * Compiler aid: the code-free kinds PRED_CONTINUE 'do continue; while (0);' and PRED_GOTO 'goto L; L: ;'
 * (tools/lessons.txt); they emit no instructions and only set gcc 3.4 branch predictions for bb-reorder /
 * global-alloc. Every hint line in the code below is one of these; none is in the 'ev - K' range tests.
 * port_used_m() and port_used_f() are inline copies of the FUN_a0080320 rule (identical code) used only by
 * the main loop / by all_le4_f0c, so that their arms can carry hints without touching the other inlined copies:
 * port_used_m i == 3 arm PRED_CONTINUE (main-loop port-3 stub above the 0x20 test trace, fw 0xA0081400);
 * port_used_f i == 1 and i == 3 arms PRED_GOTO + 3x PRED_CONTINUE each (net branch odds x0.88: the f0c port-1 /
 * port-3 stubs land between the head 0x3D call / af42 case-1 stub and after the LED-pair block, fw 0xA0081D3C /
 * 0xA0081DBC). The all_le3 port-1/2/3 stubs land at fw 0xA0081318 / 0xA00813C8 / 0xA00814D0 with no hints.
 */
struct Scff4 { unsigned short h000, h002; unsigned short b15 : 1, susp : 2, rest : 13;
               unsigned char pad06[0x16]; unsigned char b1c; };
extern struct Scff4 DAT_a802cff4;
struct Set { unsigned int w000; unsigned char pad04[0x1b]; unsigned char b01f; unsigned char pad20[0x88];
             unsigned int w0a8; };
extern struct Set DAT_a802d290;
extern unsigned char DAT_a802af41, DAT_a802af45, DAT_a802af49, DAT_a802af4a, DAT_a802af64;
extern unsigned short DAT_a802af42;
extern unsigned char DAT_a802af50[4], DAT_a802af60[4];

extern unsigned char FUN_a0143fb8(void);
extern unsigned char FUN_a0143fa8(void);
extern void FUN_a0143fc4(unsigned char);
extern void FUN_a008a184(unsigned char);
extern unsigned char FUN_a0143c14(unsigned char);
extern unsigned char FUN_a0143ff0(unsigned char);
extern unsigned char FUN_a0143d14(unsigned char);
extern unsigned char FUN_a0143e70(unsigned char);
extern unsigned char FUN_a0143f0c(unsigned char);
extern unsigned char FUN_a014412c(void);
extern unsigned char FUN_a0144114(void);
extern unsigned short FUN_a0086a3c(int);
extern void FUN_a0080978(void);
extern unsigned char FUN_a01279dc(void);
extern unsigned char FUN_a01279c4(void);
extern void FUN_a0124b40(void);
extern void FUN_a0124a68(void);

/* main-loop copy of FUN_a0080320 (same code; hint only) */
static unsigned char port_used_m(unsigned char i)
{
    unsigned char sel = 0;
    if (i == 0) sel = 1;
    else if (i == 1) { if (DAT_a802d290.b01f != 0) sel = 1; }
    else if (i == 2) { if ((unsigned char)(DAT_a802d290.b01f - 4) <= 3) sel = 1; }
    else if (i == 3) { do continue; while (0); if (DAT_a802d290.b01f == 7) sel = 1; }
    return sel & 1;
}

/* all_le4_f0c copy of FUN_a0080320 (same code; hint only) */
static unsigned char port_used_f(unsigned char i)
{
    unsigned char sel = 0;
    if (i == 0) sel = 1;
    else if (i == 1) { goto f1; f1: ; do continue; while (0); do continue; while (0); do continue; while (0); if (DAT_a802d290.b01f != 0) sel = 1; }
    else if (i == 2) { if ((unsigned char)(DAT_a802d290.b01f - 4) <= 3) sel = 1; }
    else if (i == 3) { goto f3; f3: ; do continue; while (0); do continue; while (0); do continue; while (0); if (DAT_a802d290.b01f == 7) sel = 1; }
    return sel & 1;
}

/* = FUN_a0080320 */
static unsigned char port_used(unsigned char i)
{
    unsigned char sel = 0;
    if (i == 0) sel = 1;
    else if (i == 1) { if (DAT_a802d290.b01f != 0) sel = 1; }
    else if (i == 2) { if ((unsigned char)(DAT_a802d290.b01f - 4) <= 3) sel = 1; }
    else if (i == 3) { if (DAT_a802d290.b01f == 7) sel = 1; }
    return sel & 1;
}

static int timer_id(unsigned char p)
{
    switch (p) {
    case 3: return 7;
    case 1: return 5;
    case 2: return 6;
    }
    return 4;
}

static unsigned char pending(unsigned char p)
{
    if (p == 0) { if (DAT_a802af45 & 1) return 1; }
    else if (p == 1) { if (DAT_a802af45 & 2) return 1; }
    else {
        if (p == 2) { if (DAT_a802af45 & 4) return 1; }
        else if (p == 3) { if (DAT_a802af45 & 8) return 1; }
    }
    return 0;
}

static void clear_pending(unsigned char p)
{
    if (p == 0) DAT_a802af45 &= ~1;
    else if (p == 1) DAT_a802af45 &= ~2;
    else {
        if (p == 2) DAT_a802af45 &= ~4;
        else {
            if (p == 3) DAT_a802af45 &= ~8;
            else if (p == 4) DAT_a802af45 = 0;
        }
    }
}

/* = FUN_a00808ac(p, 0) */
static void reset_state(unsigned char p)
{
    if (p == 4) {
        do continue; while (0); goto h121; h121: ;
        do continue; while (0);
        do continue; while (0);
        DAT_a802af60[0] = 0xff;
        DAT_a802af60[1] = 0xff;
        DAT_a802af60[2] = 0xff;
        DAT_a802af60[3] = 0xff;
    } else
        DAT_a802af60[p] = 0xff;
}

static unsigned char active(unsigned char p)
{
    unsigned char r = FUN_a014412c();
    if ((DAT_a802d290.w000 & 0x200) && p == 0) {
        do continue; while (0);
        if (r) return 1;
    } else {
        do continue; while (0);
        return FUN_a0143ff0(p); }
    return 0;
}

/* FUN_a00803a4 family: every used port's mapped state <= lim */
static unsigned char all_le(unsigned char lim)
{
    unsigned char ok = 1;
    unsigned char i;
    for (i = 0; i <= 3; i++) {
        if (port_used(i) && FUN_a0143c14(i) > lim) { ok = 0; break; }
    }
    return ok & 1;
}

static unsigned char all_le3(void)
{
    unsigned char ok = 1;
    unsigned char i;
    for (i = 0; i <= 3; i++) {
        unsigned char sel = 0;
        if (i == 0) { sel = 1; }
        else { if (i == 1) { if (DAT_a802d290.b01f != 0) { sel = 1; } }
        else if (i == 2) { if ((unsigned char)(DAT_a802d290.b01f - 4) <= 3) sel = 1; }
        else if (i == 3) { if (DAT_a802d290.b01f == 7) sel = 1; } }
        if (sel && FUN_a0143c14(i) > 3) { ok = 0; break; }
    }
    return ok & 1;
}

static unsigned char all_le4_e70(void)
{
    unsigned char ok = 1;
    unsigned char i;
    for (i = 0; i <= 3; i++) {
        if (port_used(i) && FUN_a0143c14(i) > 4 && !FUN_a0143e70(i)) { ok = 0; break; }
    }
    return ok & 1;
}

static unsigned char all_le4_f0c(void)
{
    unsigned char ok = 1;
    unsigned char i;
    for (i = 0; i <= 3; i++) {
        if (port_used_f(i) && FUN_a0143c14(i) > 4 && !FUN_a0143f0c(i)) { ok = 0; break; }
    }
    return ok & 1;
}

static unsigned char port_step(unsigned char p)
{
    unsigned char ev;

    if (DAT_a802af50[p] != 0x3f && (FUN_a0086a3c(timer_id(p)) == 0 || pending(p) == 1)) {
        ev = DAT_a802af50[p];
        DAT_a802af50[p] = 0x3f;
        clear_pending(p);
        switch (p) {
        case 1: ev += 1; break;
        case 3: ev += 3; break;
        case 2: ev += 2; break;
        }
        return ev;
    } else {
        do continue; while (0);
        do continue; while (0);
        goto st_path; st_path: ;
        do continue; while (0);
        unsigned char st = FUN_a0143c14(p);
        unsigned char changed;

        do continue; while (0);

        if (DAT_a802cff4.susp == 1)
            st = 0;
        ev = 0x3f;
        changed = 0;
        if (st == 4) {
            if (((DAT_a802af64 >> p) & 1) != active(p))
                changed = 1;
        }
        if (active(p) == 1)
            DAT_a802af64 |= 1 << p;
        else
            DAT_a802af64 &= ~(1 << p);
        if (changed) {
            goto cold; cold: ;
            if (DAT_a802cff4.susp == 2 && (!(DAT_a802d290.w000 & 0x200) || (DAT_a802d290.w0a8 & 0x8000)))
                FUN_a0080978();
            else if (FUN_a01279dc() == 1 && FUN_a01279c4() != 2) {
                FUN_a0124b40();
                FUN_a0124a68();
            }
            reset_state(p);
        }
        DAT_a802cff4.b1c &= ~(1 << p);
        if (DAT_a802af60[p] != st) {
            DAT_a802af50[p] = 0x3f;
            switch (st) {
            case 0: ev = 1; break;
            case 3: ev = 0; break;
            case 1: ev = 2; break;
            case 2: ev = 0x3e; break;
            case 4: ev = active(p) == 1 ? 4 : 10; break;
            case 5:
                if (FUN_a0143d14(p)) DAT_a802cff4.b1c |= 1 << p;
                ev = 0x18; break;
            case 6:
                if (FUN_a0143d14(p)) DAT_a802cff4.b1c |= 1 << p;
                ev = 0x1c; break;
            case 8:
                if (DAT_a802af60[p] == 10) ev = 0x20;
                break;
            case 9:
                if (FUN_a0143d14(p)) DAT_a802cff4.b1c |= 1 << p;
                ev = 0x25; break;
            case 10:
                if (FUN_a0143e70(p) == 1) ev = 0x38;
                else if (FUN_a0143f0c(p) == 1) ev = 0x33;
                else {
                    if (FUN_a0143d14(p)) DAT_a802cff4.b1c |= 1 << p;
                    ev = 0x2e;
                }
                break;
            }
            if (ev == 4 || ev == 10) {
                DAT_a802af50[p] = ev;
                ev = 0xf;
            }
            if (ev == 10 || ev == 4 || ev == 0xf || ev == 0x18 || ev == 0x1c || ev == 0x25 || ev == 0x2a
                || ev == 0x38 || ev == 0x33 || ev == 0x2e || ev == 0x20 || ev == 0x21 || ev == 0x22
                || ev == 0x23) {
                switch (p) {
                case 2: ev += 2; break;
                case 3: ev += 3; break;
                case 1: ev += 1; break;
                }
            }
            if (ev != 0x3f) {
                switch (p) {
                default: DAT_a802af42 &= ~0x421; break;
                case 1: DAT_a802af42 &= ~0x842; break;
                case 2: DAT_a802af42 &= ~0x1084; break;
                case 3: DAT_a802af42 &= ~0x2108; break;
                }
                DAT_a802af42 &= ~0x4210;
            }
            DAT_a802af60[p] = st;
        }
        return ev;
    }
}

void FUN_a0080c10(void)
{
    unsigned char final = 0x3f;
    unsigned char flag = 0;
    unsigned char p, i;

    if (DAT_a802af41 & 1)
        return;
    if (FUN_a0143fb8()) {
        DAT_a802af49 = 0;
        FUN_a0143fc4(0);
    } else {
        if (FUN_a0143fa8() != DAT_a802af49 && DAT_a802af49 == 0)
            FUN_a008a184(0x3d);
        DAT_a802af49 = FUN_a0143fa8();
    }

    for (p = 0; p < 4; p++) {
        unsigned char ev;

        if (!port_used_m(p))
            continue;
        if (DAT_a802af4a == 0) {
        do continue; while (0);
            for (i = 0; i < 4; i++) {
        do continue; while (0);
                DAT_a802af50[i] = 0x3f;
                DAT_a802af60[i] = 0xff;
            }
            DAT_a802af4a = 1;
            DAT_a802af64 = 0;
        }
        ev = port_step(p);
        if (ev != 0x3f) {
        FUN_a008a184(ev);
        if (ev == 0 && all_le3()) {
        do continue; while (0);
        goto ev0_arm; ev0_arm: ;
            goto cold0; cold0: ;
            FUN_a008a184(3);
        }
        else if ((unsigned char)(ev - 15) <= 3) {
            FUN_a008a184(0x13);
            if (all_le(4) && !(DAT_a802af41 & 8)) {
        goto h330; h330: ;
        goto ev13_arm; ev13_arm: ;
                if (!flag) {
                    DAT_a802af41 |= 8;
                    FUN_a008a184(0x14);
                }
            }
        } else if ((unsigned char)(ev - 4) < 4 || (unsigned char)(ev - 10) < 4) {
            if (all_le(4)) {
        do continue; while (0);
        do continue; while (0); do continue; while (0);
        goto h338; h338: ;
        goto cold4; cold4: ;
                unsigned char ok = 1;
                for (i = 0; i <= 3; i++) {
                    if (!port_used(i))
                        continue;
        do continue; while (0); goto h353; h353: ;
        do continue; while (0); do continue; while (0);
                    if (i != p && FUN_a0086a3c(timer_id(i)) != 0) {
                        if (!pending(i))
                            ok = 0;
                    }
                }
                if (ok == 1) {
        goto ok_arm; ok_arm: ;
                    flag = 1;
                    if (DAT_a802d290.b01f == 0) {
                        if (ev == 10) final = 0xe; else final = 8;
                    } else {
                        if (FUN_a0144114() == 0) final = 0xe; else final = 8;
                    }
                }
            }
        } else if ((unsigned char)(ev - 32) <= 3) {
            if (all_le(8))
                FUN_a008a184(0x24);
        } else if ((unsigned char)(ev - 56) <= 3) {
            if (all_le4_e70())
                FUN_a008a184(0x3c);
        } else if ((unsigned char)(ev - 51) <= 3) {
            if (all_le4_f0c())
                FUN_a008a184(0x37);
        } else if ((unsigned char)(ev - 37) <= 3)
            FUN_a008a184(0x29);
        else if ((unsigned char)(ev - 46) <= 3)
            FUN_a008a184(0x32);
        }
    }
    DAT_a802af41 &= ~8;
    if (final != 0x3f)
        FUN_a008a184(final);
}
