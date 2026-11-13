! trap_fp_exception_entry  (FUN_a0028080)
!
! Trap table slot 0x08 (fp exception): reads %psr and %tbr and jumps to the handler at 0xa0029210.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028080 @ 0xa0028080  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028080
	.type FUN_a0028080, #function
FUN_a0028080:
! Slot of trap type 0x08, fp_exception. The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! trap_handle_faults at 0xA0029210, which skips the trapped instruction and goes on
! with the next one.
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0029000), %l4       ! upper bits of the handler address 0xA0029210
	jmp  %l4 + 0x210                  ! jump to 0xA0029210: skip the trapped instruction
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0028080, .-FUN_a0028080
