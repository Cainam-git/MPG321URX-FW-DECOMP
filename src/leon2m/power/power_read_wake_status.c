/* power_read_wake_status  (FUN_a00de9f8)
 *
 * Read one of the sixteen wake-up status registers.
 * Returns: byte
 * Name basis: derived - low byte of 0xCF03C8C0 + 4 * n; used for the power key check
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de9f8 @ 0xa00de9f8-0xa00deb64.
 * Source form: the result starts at 0; one volatile word read per case.
 */
/* Wake-up status registers 0..15, one word each from 0xCF03C8C0. */
#define WAKE_STATUS_0  (*(volatile unsigned int *)0xcf03c8c0)
#define WAKE_STATUS_1  (*(volatile unsigned int *)0xcf03c8c4)
#define WAKE_STATUS_2  (*(volatile unsigned int *)0xcf03c8c8)
#define WAKE_STATUS_3  (*(volatile unsigned int *)0xcf03c8cc)
#define WAKE_STATUS_4  (*(volatile unsigned int *)0xcf03c8d0)
#define WAKE_STATUS_5  (*(volatile unsigned int *)0xcf03c8d4)
#define WAKE_STATUS_6  (*(volatile unsigned int *)0xcf03c8d8)
#define WAKE_STATUS_7  (*(volatile unsigned int *)0xcf03c8dc)
#define WAKE_STATUS_8  (*(volatile unsigned int *)0xcf03c8e0)
#define WAKE_STATUS_9  (*(volatile unsigned int *)0xcf03c8e4)
#define WAKE_STATUS_10 (*(volatile unsigned int *)0xcf03c8e8)
#define WAKE_STATUS_11 (*(volatile unsigned int *)0xcf03c8ec)
#define WAKE_STATUS_12 (*(volatile unsigned int *)0xcf03c8f0)
#define WAKE_STATUS_13 (*(volatile unsigned int *)0xcf03c8f4)
#define WAKE_STATUS_14 (*(volatile unsigned int *)0xcf03c8f8)
#define WAKE_STATUS_15 (*(volatile unsigned int *)0xcf03c8fc)

/*
 * Return the low byte of wake-up status register number index (0..15); any other number gives 0.
 * power_api_is_woken_by_power_key reads registers 0 and 1.
 */
unsigned char power_read_wake_status(unsigned char index)
{
    unsigned char status = 0;

    switch (index) {
    case 0: status = WAKE_STATUS_0; break;
    case 1: status = WAKE_STATUS_1; break;
    case 2: status = WAKE_STATUS_2; break;
    case 3: status = WAKE_STATUS_3; break;
    case 4: status = WAKE_STATUS_4; break;
    case 5: status = WAKE_STATUS_5; break;
    case 6: status = WAKE_STATUS_6; break;
    case 7: status = WAKE_STATUS_7; break;
    case 8: status = WAKE_STATUS_8; break;
    case 9: status = WAKE_STATUS_9; break;
    case 10: status = WAKE_STATUS_10; break;
    case 11: status = WAKE_STATUS_11; break;
    case 12: status = WAKE_STATUS_12; break;
    case 13: status = WAKE_STATUS_13; break;
    case 14: status = WAKE_STATUS_14; break;
    case 15: status = WAKE_STATUS_15; break;
    }
    return status;
}
