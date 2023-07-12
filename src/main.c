#define UART0DR (volatile unsigned char *) 0x10000000
#define PRINT_UART0(x) print_uart(UART0DR, x)

void print_uart(volatile unsigned char* base_addr, const char *s) {
  while(*s != '\0') {
    *UART0DR = (unsigned char)(*s);
    s++;
  }
}

int main() {
  const char* msg = "Hello world!\n";
  PRINT_UART0(msg);
  return 0;
}