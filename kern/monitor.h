#ifndef JOS_KERN_MONITOR_H
#define JOS_KERN_MONITOR_H
#ifndef JOS_KERNEL
# error "This is a JOS kernel header; user programs should not #include it"
#endif

struct Trapframe;

// Activate the kernel monitor,
// optionally providing a trap frame indicating the current state
// (NULL if none).
void monitor(struct Trapframe *tf);

// Functions implementing monitor commands.
int mon_help(int argc, char **argv, struct Trapframe *tf);
int mon_infokern(int argc, char **argv, struct Trapframe *tf);
int mon_infopg(int argc, char **argv, struct Trapframe *tf);
int mon_backtrace(int argc, char **argv, struct Trapframe *tf);
int shwmap(int argc, char **argv, struct Trapframe *tf);
int memchmod(int argc, char **argv, struct Trapframe *tf);
int vadump(int argc, char **argv, struct Trapframe *tf);
int padump(int argc, char **argv, struct Trapframe *tf);

int hexsanitize(char*);
uint32_t hextoi(char*);
int addrDump(int argc, char** argv, struct Trapframe *tf, int virtual);
int streq(char*, char*);

#endif  // !JOS_KERN_MONITOR_H
