#include "xbyak.h"

class Code : public Xbyak::CodeGenerator {
public:
  Code() {
    genAbiWrapping();
    add(rdi, rsi);
    mov(rax, rdi);
    ret();
  }
  void genAbiWrapping() {
    /*
      This is the function generating AArch64 mov instruction implemented by
      Xbyak_aarch64.
    */
    xa_->mov(x7, x0);
    xa_->mov(x6, x1);
  }
};

int main() {
  Code c;
  c.ready();
  auto f = c.getCode<int (*)(int, int)>();
  std::cout << f(3, 4) << std::endl;
}
