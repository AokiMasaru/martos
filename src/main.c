#define UART0DR (volatile unsigned char *) 0x10000000
#define PRINT_UART0(x) print_uart(UART0DR, x)
#define MTVEC_VECTORED_MODE 0x1U

extern unsigned long trap_vectors;
extern void setTrapVector(unsigned long);

void print_uart(volatile unsigned char* base_addr, const char *s) {
  while(*s != '\0') {
    *UART0DR = (unsigned char)(*s);
    s++;
  }
}

int main() {
  setTrapVector((unsigned long)trap_vectors + MTVEC_VECTORED_MODE);
  const char* msg = "Hello world!\n";
  PRINT_UART0(msg);
  
  return 0;
}

void dispatch_entry()
{
  const char* disp = "dispatch_entry";
  PRINT_UART0(disp);
}
