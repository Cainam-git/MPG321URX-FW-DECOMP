/* leon2m FUN_a012b9a8 @ 0xa012b9a8-0xa012bae0 (78 words).
 * Calls FUN_a0121258(port), then fills halfwords 0..3 of the 8-halfword record t: when FUN_a0106228() is 4, with
 * FUN_a01068e0 / FUN_a0106900 / FUN_a01062c0 / FUN_a0106274 of argument 4; else when FUN_a010a864() is 0, with the
 * same four functions of argument 0; otherwise h4 = FUN_a010a494(), h0 = FUN_a010a884(), h6 = FUN_a010a8f0(),
 * h2 = FUN_a010a9e8(). Then h8 = (h0 - h4) / 3, ha = 2 * h8, hc = (h2 - h6) / 3, he = 2 * hc (signed int
 * division, stored as halfwords). Called by FUN_a012bc08.
 */
struct Tim { unsigned short h0, h2, h4, h6, h8, ha, hc, he; };
extern unsigned char FUN_a0121258(unsigned char port);
extern unsigned char FUN_a0106228(void);
extern unsigned char FUN_a010a864(void);
extern unsigned short FUN_a01068e0(unsigned char);
extern unsigned short FUN_a0106900(unsigned char);
extern unsigned short FUN_a01062c0(unsigned char);
extern unsigned short FUN_a0106274(unsigned char);
extern unsigned short FUN_a010a494(void);
extern unsigned short FUN_a010a884(void);
extern unsigned short FUN_a010a8f0(void);
extern unsigned short FUN_a010a9e8(void);

void FUN_a012b9a8(unsigned char port, struct Tim *t)
{
    FUN_a0121258(port);
    if (FUN_a0106228() == 4) {
        t->h0 = FUN_a01068e0(4);
        t->h2 = FUN_a0106900(4);
        t->h4 = FUN_a01062c0(4);
        t->h6 = FUN_a0106274(4);
    } else if (!FUN_a010a864()) {
        t->h0 = FUN_a01068e0(0);
        t->h2 = FUN_a0106900(0);
        t->h4 = FUN_a01062c0(0);
        t->h6 = FUN_a0106274(0);
    } else {
        t->h4 = FUN_a010a494();
        t->h0 = FUN_a010a884();
        t->h6 = FUN_a010a8f0();
        t->h2 = FUN_a010a9e8();
    }
    t->h8 = (t->h0 - t->h4) / 3;
    t->ha = t->h8 * 2;
    t->hc = (t->h2 - t->h6) / 3;
    t->he = t->hc * 2;
}
