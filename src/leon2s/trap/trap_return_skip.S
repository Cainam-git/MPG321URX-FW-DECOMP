! trap_return_skip  (FUN_a00604fc)
!
! Return from a trap past the trapped instruction.
! Note: Unreached; its 'rett %l2 + 4' delay slot is the first word of the next piece (0xA0060500).
! Name basis: descriptive - jmp %l2 (+ rett %l2+4 at 0xA0060500); no reference to 0xA00604FC
!
! Matching notes
! --------------
! leon2s FUN_a00604fc @ 0xa00604fc  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00604fc
	.type FUN_a00604fc, #function
FUN_a00604fc:
! Unreached: no trap-table slot, call or stored word points at 0xA00604FC. The return that skips the
! trapped instruction; its delay slot is the first word of trap_write_buffer_error_part1.S.
	jmp  %l2                          ! jump to the instruction after the trapped one (its nPC)
	.size FUN_a00604fc, .-FUN_a00604fc
