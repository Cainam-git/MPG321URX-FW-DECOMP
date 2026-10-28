# fn_40007998: 0x40007998-0x400079b7 (firmware file offset 0x37998-0x379b7), 12 instructions
# Called from: fn_400079b8
# Calls: fn_400074b4, fn_400099bc
# Text loaded: "LED_AS3824_Unlock\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007998, @function
fn_40007998:
	entry	a1, 32                  # 40007998
	l32r	a13, lit_3ffe20ac       # 4000799b  = 0x3ffe54a0
	movi	a12, 202                # 4000799e
	s32i.n	a12, a13, 4             # 400079a1
	movi.n	a10, 54                 # 400079a3
	l32r	a11, lit_3ffe20ac       # 400079a5  = 0x3ffe54a0
	l32i.n	a11, a11, 4             # 400079a8
	extui	a11, a11, 0, 8          # 400079aa
	call8	fn_400074b4             # 400079ad
	l32r	a10, lit_3ffe20e4       # 400079b0  = ro_3ffe0d34 "LED_AS3824_Unlock\n"
	call8	fn_400099bc             # 400079b3
	retw.n                          # 400079b6
	.size	fn_40007998, . - fn_40007998
