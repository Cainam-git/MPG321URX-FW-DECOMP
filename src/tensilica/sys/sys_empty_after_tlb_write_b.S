# sys_empty_after_tlb_write_b  (fn_4000ac30): 0x4000ac30-0x4000ac34 (firmware file offset 0x3ac30-0x3ac34), 2 instructions
# Name basis: descriptive - code only: entry + retw.n; sole caller sys_set_region_attributes, called right
#   after sys_empty_after_tlb_write_a under the same condition
# Called from: sys_set_region_attributes
#
# Does nothing: it sets up its register window (entry a1, 16) and returns at once. sys_set_region_attributes calls it
# second of two empty routines (with sys_empty_after_tlb_write_a) at its end, after sys_write_region_attributes has rewritten the TLB
# entries (witlb/wdtlb), when its local flag a3 is non-zero and bit 12 of its fourth argument is clear.
# Arguments: none used.
# Local variables: none (the 16-byte frame holds only the register-window save area).
# Return value: none.
#

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	sys_empty_after_tlb_write_b, @function
sys_empty_after_tlb_write_b:            # fn_4000ac30
	entry	a1, 16                  # 4000ac30
	# return;  (empty body)
	retw.n                          # 4000ac33
	.size	sys_empty_after_tlb_write_b, . - sys_empty_after_tlb_write_b
