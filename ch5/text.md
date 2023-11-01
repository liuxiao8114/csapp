## 5.6 Eliminating Unneeded Memory Reference
.L17: loop:
vmovsd (%rbx), %xmm0        Read product from dest
vmulsd (%rdx), %xmm0, %xmm0 Multiply product by data[i]
vmovsd %xmm0, (%rbx)        Store product at dest
addq   $8, %rdx             Increment data + i
cmpq   %rax, %rdx           Compare to data + length
jne    .L17                 If !=, goto loop

.L25: loop:
2 vmulsd (%rdx), %xmm0, %xmm0 Multiply acc by data[i]
3 addq $8, %rdx Increment data+i
4 cmpq %rax, %rdx Compare to data+length
5 jne .L25 If !=, goto loop

identity element. Let v = [2, 3, 5] be a vector of three elements and consider the
following two function calls:
combine3(v, get_vec_start(v) + 2);
combine4(v, get_vec_start(v) + 2);
That is, we create an alias between the last element of the vector and the destination
for storing the result. The two functions would then execute as follows:
Function Initial Before loop i = 0 i = 1 i = 2 Final
combine3 [2, 3, 5] [2, 3, 1] [2, 3, 2] [2, 3, 6] [2, 3, 36] [2, 3, 36]
combine4 [2, 3, 5] [2, 3, 5] [2, 3, 5] [2, 3, 5] [2, 3,  5] [2, 3, 30]

### 5.7.1 Overall Operation
Processors are described in the industry as being superscalar, which means out of order.
Instruction Control Unit, which is responsible for reading a sequence of instructions from memory and generating from these  

read the instructions from the instructions cache
instructions

    Insturction Decode
    Fetch Control

Execution Unit
    Functional Units

The most common mechanism for controlling the communication of operands among the execution units is called *register renaming*.
When an instruction that updates register r is decoded, a tag t is generated giving a unique identifier to the result of the operation.
An entry (r, t) is added to a table maintaining the association between program register r and tag t for an operation that will update this register.
When a subsequent instruction using register r as an operand is decoded, the operation sent to the execution unit will contain t as the source for the operand value.
When some execution unit completes the first operation, it generates a result (v, t), indicating that the operation with tag t produced value v. Any operation waiting for t as a source will then use v as the source value, a form of data forwarding. By this mechanism, values can be forwarded directly from one operation to another, rather than being written to and read from
the register file, enabling the second operation to begin as soon as the first has
completed. The renaming table only contains entries for registers having pending
write operations. When a decoded instruction requires a register r, and there is no
tag associated with this register, the operand is retrieved directly from the register
file. With register renaming, an entire sequence of operations can be performed
speculatively, even though the registers are updated only after the processor is
certain of the branch outcomes.

                Integer                       Floating point
Operation       Latency   Issue   Capacity    Latency   Issue   Capacity
------------------------------------------------------------------------
Addition          1         1         4         3         1         1
Multiplication    3         1         1         5         1         2
Division          3–30      3–30      1         3–15      3–15      1

Figure 5.12 Latency, issue time, and capacity characteristics of reference machine
operations. Latency indicates the total number of clock cycles required to perform the
actual operations, while issue time indicates the minimum number of cycles between
two independent operations. The capacity indicates how many of these operations can
be issued simultaneously. The times for division depend on the data values.

### 5.7.2 Functional Unit Performance
We see that the latencies increase in going from integer to floating-point operations. We see also that the addition and multiplication operations all have issue times of 1, meaning that on each clock cycle, the processor can start a new one of these operations.

This short issue time is achieved through the use of pipelining. A pipelined function unit is implemented as a series of stages, each of which performs part of the operation. For example, a typical floating point adder contains three stages (and hence the three-cycle latency): one to process the exponent values, one to add the fractions, and one to round the result.

The arithmetic operations can proceed through the stages in close succession rather than waiting for one operation to complete before the next begins. This capability can be exploited only if there are successive, logically independent operations to be performed. Functional units with issue times of 1 cycle are said to be fully pipelined: they can start a new operation every clock cycle. Operations with capacity greater than 1 arise due to the capabilities of the multiple functional units, as was described earlier for the reference machine.

We see that the latencies increase in going from integer to floating-point operations. We see also that the addition and multiplication operations all have issue times of 1, meaning that on each clock cycle, the processor can start a new one of these operations. This short issue time is achieved through the use of pipelining. A pipelined function unit is implemented as a series of stages, each of which performs part of the operation. For example, a typical floating point
adder contains three stages (and hence the three-cycle latency): one to
process the exponent values, one to add the fractions, and one to round the result.
The arithmetic operations can proceed through the stages in close succession
rather than waiting for one operation to complete before the next begins. This
capability can be exploited only if there are successive, logically independent
operations to be performed. Functional units with issue times of 1 cycle are said
to be fully pipelined: they can start a new operation every clock cycle. Operations
with capacity greater than 1 arise due to the capabilities of the multiple functional
units, as was described earlier for the reference machine.

We see also that the divider (used for integer and floating-point division, as well as floating-point square root) is not pipelined — its issue time equals its latency.
What this means is that the divider must perform a complete division before it can
begin a new one. We also see that the latencies and issue times for division are given
as ranges, because some combinations of dividend and divisor require more steps
than others. The long latency and issue times of division make it a comparatively costly operation

A more common way of expressing issue time is to specify the maximum
throughput of the unit, defined as the reciprocal of the issue time. A fully pipelined
functional unit has a maximum throughput of 1 operation per clock cycle, while
units with higher issue times have lower maximum throughput. Having multiple
functional units can increase throughput even further. For an operation with
capacity C and issue time I , the processor can potentially achieve a throughput of
C/I operations per clock cycle. For example, our reference machine is capable of
performing floating-point multiplication operations at a rate of 2 per clock cycle.
We will see how this capability can be exploited to increase program performance.
Circuit designers can create functional units with wide ranges of performance
characteristics. Creating a unit with short latency or with pipelining requires
more hardware, especially for more complex functions such as multiplication
and floating-point operations. Since there is only a limited amount of space for
these units on the microprocessor chip, CPU designers must carefully balance
the number of functional units and their individual performance to achieve optimal
overall performance. They evaluate many different benchmark programs
and dedicate the most resources to the most critical operations. As Figure 5.12
indicates, integer multiplication and floating-point multiplication and addition
were considered important operations in the design of the Core i7 Haswell processor,
even though a significant amount of hardware is required to achieve the
low latencies and high degree of pipelining shown. On the other hand, division
is relatively infrequent and difficult to implement with either short latency or full
pipelining.
The latencies, issue times, and capacities of these arithmetic operations can
affect the performance of our combining functions. We can express these effects
in terms of two fundamental bounds on the CPE values:
            Integer        Floating point
Bound      +      *       +       *
Latency    1.00   3.00    3.00    5.00
Throughput 0.50   1.00    1.00    0.50

The latency bound gives a minimum value for the CPE for any function that must
perform the combining operation in a strict sequence. The throughput bound
gives a minimum bound for the CPE based on the maximum rate at which the
functional units can produce results. For example, since there is only one integer
multiplier, and it has an issue time of 1 clock cycle, the processor cannot possibly
sustain a rate of more than 1 multiplication per clock cycle. On the other hand,
with four functional units capable of performing integer addition, the processor
can potentially sustain a rate of 4 operations per cycle. Unfortunately, the need
to read elements from memory creates an additional throughput bound. The
two load units limit the processor to reading at most 2 data values per clock
cycle, yielding a throughput bound of 0.50. We will demonstrate the effect of
both the latency and throughput bounds with different versions of the combining
functions.

### 5.7.3 An Abstract Model of Processor Operation
As a tool for analyzing the performance of a machine-level program executing on a
modern processor, we will use a data-flow representation of programs, a graphical
notation showing how the data dependencies between the different operations
constrain the order in which they are executed. These constraints then lead to
critical paths in the graph, putting a lower bound on the number of clock cycles
required to execute a set of machine instructions.
Before proceeding with the technical details, it is instructive to examine the
CPE measurements obtained for function combine4, our fastest code up to this point:
                                       Integer   Floating point
Function Page Method                   +     *     +     *
---------------------------------------------------------------
combine4 551 Accumulate in temporary   1.27  3.01  3.01  5.01
Latency bound                          1.00  3.00  3.00  5.00
Throughput bound                       0.50  1.00  1.00  0.50

We can see that these measurements match the latency bound for the processor,
except for the case of integer addition. This is not a coincidence—it indicates
that the performance of these functions is dictated by the latency of the sum
or product computation being performed. Computing the product or sum of n
elements requires around L * n + K clock cycles, where L is the latency of the
combining operation and K represents the overhead of calling the function and
initiating and terminating the loop. The CPE is therefore equal to the latency
bound L.

As a step toward generating a data-flow graph representation of the program,
the boxes and lines along the left-hand side of Figure 5.13 show how the registers
are used and updated by the different operations, with the boxes along the top
representing the register values at the beginning of the loop, and those along the
bottom representing the values at the end. For example, register %rax is only used
as a source value by the cmp operation, and so the register has the same value at
the end of the loop as at the beginning. Register %rdx, on the other hand, is both
used and updated within the loop. Its initial value is used by the load and add
operations; its new value is generated by the add operation, which is then used
by the cmp operation. Register %xmm0 is also updated within the loop by the mul
operation, which first uses the initial value as a source value.

In Figure 5.14(b), we have eliminated the operators that were colored white
on the left, and we have retained only the loop registers. What we have left is an
abstract template showing the data dependencies that form among loop registers
due to one iteration of the loop. We can see in this diagram that there are two
data dependencies from one iteration to the next. Along one side, we see the
dependencies between successive values of program value acc, stored in register
%xmm0. The loop computes a new value for acc by multiplying the old value by a
data element, generated by the load operation. Along the other side, we see the
dependencies between successive values of the pointer to the ith data element.
On each iteration, the old value is used as the address for the load operation, and
it is also incremented by the add operation to compute its new value.
Figure 5.15 shows the data-flow representation of n iterations by the inner loop
of function combine4. This graph was obtained by simply replicating the template
shown in Figure 5.14(b) n times. We can see that the program has two chains of data

#### Other Performance Factors
For the case of integer addition, on the other hand, our measurements of combine4
show a CPE of 1.27, slower than the CPE of 1.00 we would predict based on the
chains of dependencies formed along either the left- or the right-hand side of the
graph of Figure 5.15. This illustrates the principle that the critical paths in a dataflow representation provide only a lower bound on how many cycles a program
will require. Other factors can also limit performance, including the total number
of functional units available and the number of data values that can be passed
among the functional units on any given step. For the case of integer addition as
the combining operation, the data operation is sufficiently fast that the rest of the operations cannot supply data fast enough. Determining exactly why the program
requires 1.27 cycles per element would require a much more detailed knowledge
of the hardware design than is publicly available.
To summarize our performance analysis of combine4: our abstract data-flow
representation of program operation showed that combine4 has a critical path of
length L . n caused by the successive updating of program value acc, and this path
limits the CPE to at least L. This is indeed the CPE we measure for all cases except
integer addition, which has a measured CPE of 1.27 rather than the CPE of 1.00
we would expect from the critical path length.
It may seem that the latency bound forms a fundamental limit on how fast
our combining operations can be performed. Our next task will be to restructure
the operations to enhance instruction-level parallelism. We want to transform the
program in such a way that our only limitation becomes the throughput bound,
yielding CPEs below or close to 1.00.

Second, it exposes ways in which we can further transform the code to reduce the number of operations in the critical paths of the overall computation.

Figure 5.16 shows a version of our combining code using what we will refer
to as "2 × 1 loop unrolling." The first loop steps through the array two elements
at a time. That is, the loop index i is incremented by 2 on each iteration, and the
combining operation is applied to array elements i and i + 1 in a single iteration.
In general, the vector length will not be a multiple of 2. We want our code
to work correctly for arbitrary vector lengths. We account for this requirement in
two ways. First, we make sure the first loop does not overrun the array bounds.
For a vector of length n, we set the loop limit to be n − 1. We are then assured that
the loop will only be executed when the loop index i satisfies i < n − 1, and hence
the maximum array index i + 1 will satisfy i + 1< (n − 1) + 1= n.
We can generalize this idea to unroll a loop by any factor k, yielding k × 1
loop unrolling. To do so, we set the upper limit to be n − k + 1 and within the
loop apply the combining operation to elements i through i + k − 1. Loop index i
is incremented by k in each iteration. The maximum array index i + k − 1 will
then be less than n. We include the second loop to step through the final few
elements of the vector one at a time. The body of this loop will be executed
between 0 and k − 1 times. For k = 2, we could use a simple conditional statement


## 5.12 Understanding Memory Performance
All of the code we have written thus far, and all the tests we have run, access
relatively small amounts of memory. For example, the combining routines were
measured over vectors of length less than 1,000 elements, requiring no more than
8,000 bytes of data. All modern processors contain one or more cache memories
to provide fast access to such small amounts of memory. In this section, we will
further investigate the performance of programs that involve load (reading from
memory into registers) and store (writing from registers to memory) operations,
considering only the cases where all data are held in cache. In Chapter 6, we go
into much more detail about how caches work, their performance characteristics,
and how to write code that makes best use of caches.

As Figure 5.11 shows, modern processors have dedicated functional units to
perform load and store operations, and these units have internal buffers to hold
sets of outstanding requests for memory operations. For example, our reference
machine has two load units, each of which can hold up to 72 pending read requests.
It has a single store unit with a store buffer containing up to 42 write requests. Each
of these units can initiate 1 operation every clock cycle.

### 5.12.1 Load Performance
The performance of a program containing load operations depends on both the
pipelining capability and the latency of the load unit. In our experiments with
combining operations using our reference machine, we saw that the CPE never
got below 0.50 for any combination of data type and combining operation, except
when using SIMD operations. One factor limiting the CPE for our examples is
that they all require reading one value from memory for each element computed.
With two load units, each able to initiate at most 1 load operation every clock
cycle, the CPE cannot be less than 0.50. For applications where we must load k
values for every element computed, we can never achieve a CPE lower than k/2
(see, for example, Problem 5.15).
In our examples so far, we have not seen any performance effects due to the
latency of load operations. The addresses for our load operations depended only
on the loop index i, and so the load operations did not form part of a performance
limiting critical path.
To determine the latency of the load operation on a machine, we can set up
a computation with a sequence of load operations, where the outcome of one
determines the address for the next. As an example, consider the function list_
len in Figure 5.31, which computes the length of a linked list. In the loop of this
function, each successive value of variable ls depends on the value read by the
pointer reference ls->next. Our measurements show that function list_len has

```c
typedef struct ELE {
  struct ELE *next;
  long data;
} list_ele, *list_ptr;

long list_len(list_ptr ls) {
  long len = 0;
  while (ls) {
    len++;
    ls = ls->next;
  }

  return len;
}

```
