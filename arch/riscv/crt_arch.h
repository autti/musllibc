__asm__("\
.global _start \n\
.align  4 \n\
_start: \n\
  la   s0, __cstart \n\
  jalr s0 \n\ 
");
