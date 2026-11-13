! trap_software_trap_2_entry  (FUN_a0028820)
!
! Trap table slot 0x82 (software trap 2): reads %psr and %tbr and jumps to the handler at 0xa0029460.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028820 @ 0xa0028820  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028820
	.type FUN_a0028820, #function
FUN_a0028820:
! Slot of trap type 0x82, software trap 2 ('ta 2'). The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! the fatal-trap path of trap_handle_faults: it saves every register at 0xA803FF60
! and calls the crash hook (trap_dump_crash_and_halt: crash report, then halt).
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0029400), %l4       ! upper bits of the handler address 0xA0029460
	jmp  %l4 + 0x60                   ! jump to 0xA0029460: fatal-trap path: save registers, crash report
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0028820, .-FUN_a0028820
