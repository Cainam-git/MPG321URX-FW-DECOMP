/* hdr_get_status_code  (FUN_a00d3efc)
 *
 * Return the HDR status code that is reported to the main processor.
 * Returns: code
 * Name basis: descriptive - 2, 0 or a stored byte depending on the state byte
 *
 * Matching notes
 * --------------
 * FUN_a00d3efc (leon2s 0xa00d3efc-0xa00d3f30, 52 bytes, leaf), flags -mcpu=v8 -Os -g.
 * It lies in the code range 0xa00d3eb0-0xa00d3fa0 that is followed by the unreferenced data 0xa00d3fa0-0xa00d649c
 * (byte tables and '[HDR]' format strings).
 */
extern unsigned char hdr_status_code;
extern unsigned char hdr_static_status_byte;

/*
 * Return the HDR status code for the main processor: 2 when hdr_status_code is above 3, 0 when it is 0, else the
 * byte hdr_static_status_byte (+0x7 of the static HDR information). The mailbox command "get HDR status" and the
 * port status word (bits 1..2) use it.
 */
unsigned char hdr_get_status_code(void)
{
    unsigned char code = 0;

    if (hdr_status_code > 3)
        code = 2;
    else if (hdr_status_code != 0)
        code = hdr_static_status_byte;
    return code;
}
