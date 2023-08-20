#define UART0DR (volatile unsigned char *) 0x10000000
#define PRINT_UART0(x) print_uart(UART0DR, x)
#define MTVEC_VECTORED_MODE 0x1U

extern void trap_vectors();
extern void setTrapVector(unsigned long);
extern void EnableTimer();
extern void EnableInt();

void print_uart(volatile unsigned char* base_addr, const char *s) {
  while(*s != '\0') {
    *UART0DR = (unsigned char)(*s);
    s++;
  }
}

volatile unsigned long * const reg_mtime = ((unsigned long *)0x200BFF8U);
volatile unsigned long * const reg_mtimecmp = ((unsigned long *)0x2004000U);

#define INTERVAL 10000000

static void StartTimer(void)
{
    *reg_mtimecmp = *reg_mtime + INTERVAL;
    EnableTimer();
    EnableInt();
}

void spend_time(void)
{
    unsigned long t = *reg_mtime;
    while (*reg_mtime - t < INTERVAL / 4)
        ;
}

int main() {
  setTrapVector((unsigned long)trap_vectors + MTVEC_VECTORED_MODE);
  const char* msg = "Hello world!\n";
  PRINT_UART0(msg);
//  asm volatile ("ecall") ;

  StartTimer();

  while(1)
  {
    spend_time();
    PRINT_UART0("Main\n");
  }

  return 0;
}

void dispatch_entry()
{
  const char* disp = "dispatch_entry\n";
  PRINT_UART0(disp);
}

void Timer(void)
{
    PRINT_UART0("Timer\n");

    do {
        *reg_mtimecmp += INTERVAL;
    } while ((long)(*reg_mtime - *reg_mtimecmp) >= 0);
}
