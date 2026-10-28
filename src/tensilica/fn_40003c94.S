# fn_40003c94: 0x40003c94-0x40003ccd (firmware file offset 0x33c94-0x33ccd), 21 instructions
# Called from: fn_4000a3cc
# Calls: fn_40009ca8, fn_400099bc
# Text loaded: "\n-----------------------------------------\n", "Core %s\n", "NVT_Formal_RG20189",
#              "NT68500 FW Version: %d.%d.%d (customer id = %d)\n", "Built time: %s %s\n", "Nov 10 2025",
#              "09:47:58", "--------------------------------------------\n"
# Addresses loaded: data_3ffe2704

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003c94, @function
fn_40003c94:
	entry	a1, 32                  # 40003c94
	l32r	a10, lit_3ffe1cfc       # 40003c97  = data_3ffe2704
	call8	fn_40009ca8             # 40003c9a
	l32r	a10, lit_3ffe1d00       # 40003c9d  = ro_3ffe0538 "\n-----------------------------------------\n"
	call8	fn_400099bc             # 40003ca0
	l32r	a10, lit_3ffe1d04       # 40003ca3  = ro_3ffe0564 "Core %s\n"
	l32r	a11, lit_3ffe1d08       # 40003ca6  = ro_3ffe0570 "NVT_Formal_RG20189"
	call8	fn_400099bc             # 40003ca9
	l32r	a10, lit_3ffe1d0c       # 40003cac  = ro_3ffe0584 "NT68500 FW Version: %d.%d.%d (customer id = %d)\n"
	movi.n	a11, 0                  # 40003caf
	movi.n	a12, 1                  # 40003cb1
	movi.n	a13, 0                  # 40003cb3
	movi.n	a14, 1                  # 40003cb5
	call8	fn_400099bc             # 40003cb7
	l32r	a10, lit_3ffe1d10       # 40003cba  = ro_3ffe05b8 "Built time: %s %s\n"
	l32r	a11, lit_3ffe1d14       # 40003cbd  = ro_3ffe05cc "Nov 10 2025"
	l32r	a12, lit_3ffe1d18       # 40003cc0  = ro_3ffe05d8 "09:47:58"
	call8	fn_400099bc             # 40003cc3
	l32r	a10, lit_3ffe1d1c       # 40003cc6  = ro_3ffe05e4 "--------------------------------------------\n"
	call8	fn_400099bc             # 40003cc9
	retw.n                          # 40003ccc
	.size	fn_40003c94, . - fn_40003c94
