##################################################################
# You can modify this portion
  # Loop header
  xorq %rax,%rax		# count = 0;
	andq %rdx,%rdx		# len <= 0?
	jle Done		# if so, goto Done:

Loop:
	mrmovq (%rdi), %r10	# read val from src...
	rmmovq %r10, (%rsi)	# ...and store it to dst
	andq %r10, %r10			# val <= 0?
	jle Npos						# if so, goto Npos:
	iaddq $1, %rax			# count++
Npos:
	irmovq $1, %r10
	subq %r10, %rdx			# len--
	iaddq $8, %rdi			# src++
	iaddq $8, %rsi			# dst++
	andq %rdx,%rdx			# len > 0?
	jg Loop							# if so, goto Loop:
##################################################################


                              1       2       3       4       5       6       7       8       9
1   xorq %rax,%rax
2   andq %rdx,%rdx
3   jle Done
4   ret
5   mrmovq (%rdi), %r10
6   rmmovq %r10, (%rsi)
7   andq %r10, %r10
8   jle Npos
9   irmovq $1, %r10

if(x)
  do this
npos
