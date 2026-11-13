# sys_empty_after_tlb_write_a  (fn_4000ac28): 0x4000ac28-0x4000ac2c (firmware file offset 0x3ac28-0x3ac2c), 2 instructions
# Name basis: descriptive - code only: entry + retw.n; sole caller sys_set_region_attributes calls it after
#   sys_write_region_attributes (witlb/wdtlb) when a3 != 0 and arg4 bit 12 clear
# Called from: sys_set_region_attributes
#
# Does nothing: it sets up its register window (entry a1, 16) and returns at once. sys_set_region_attributes calls it
# first of two empty routines (with sys_empty_after_tlb_write_b) at its end, after sys_write_region_attributes has rewritten the TLB
# entries (witlb/wdtlb), when its local flag a3 is non-zero and bit 12 of its fourth argument is clear.
# Arguments: none used.
# Local variables: none (the 16-byte frame holds only the register-window save area).
# Return value: none.
#

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	sys_empty_after_tlb_write_a, @function
sys_empty_after_tlb_write_a:            # fn_4000ac28
	entry	a1, 16                  # 4000ac28
	# return;  (empty body)
	retw.n                          # 4000ac2b
	.size	sys_empty_after_tlb_write_a, . - sys_empty_after_tlb_write_a
