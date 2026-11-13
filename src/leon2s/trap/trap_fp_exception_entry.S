! trap_fp_exception_entry  (FUN_a0060080)
!
! Trap table slot 0x08 (fp exception): reads %psr and %tbr and jumps to the handler at 0xa00604d0.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2s FUN_a0060080 @ 0xa0060080  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060080
	.type FUN_a0060080, #function
FUN_a0060080:
! Slot of trap type 0x08, fp_exception. The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! trap_fp_exception_skip (0xA00604D0), which skips the trapped instruction and goes
! on with the next one.
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0060400), %l4       ! upper bits of the handler address 0xA00604D0
	jmp  %l4 + 0xd0                   ! jump to 0xA00604D0: skip the trapped instruction
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0060080, .-FUN_a0060080
