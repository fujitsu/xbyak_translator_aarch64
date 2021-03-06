#include <xbyak_translator_aarch64/xbyak.h>

static bool s_testMode = false;
bool Xbyak::CodeGenerator::isTestMode() const { return s_testMode; }
void Xbyak::CodeGenerator::setTestMode(bool b) {
  s_testMode = b;
  if (b) {
    X_TRANSLATOR_STACK = xa::XReg{31};
  } else {
    X_TRANSLATOR_STACK = x22;
  }
}

#include "xbyak_translator_inc.h"

#define UNIMPLEMENTED                                                          \
  std::cerr << "########################################" << std::endl         \
            << __FILE__ << ":" << __LINE__ << ":Unimplemented" << std::endl    \
            << "########################################" << std::endl;        \
  assert(NULL)
#define SOMETHING_WRONG                                                        \
  std::cerr << "########################################" << std::endl         \
            << __FILE__ << ":" << __LINE__ << ":Something wroing!"             \
            << std::endl                                                       \
            << "########################################" << std::endl;        \
  assert(NULL)
#define NO_MATCHING_INSTRUCTION                                                \
  std::cerr << "########################################" << std::endl         \
            << __FILE__ << ":" << __LINE__                                     \
            << ":No mathcing instruction in AArch64! Uhmmm" << std::endl       \
            << "########################################" << std::endl;        \
  assert(NULL)

#define UNIMPLEMENTED2                                                         \
  std::cerr << "########################################" << std::endl         \
            << __FILE__ << ":" << __LINE__ << ":Unimplemented" << std::endl    \
            << "########################################" << std::endl;        \
  assert(NULL)
#define SOMETHING_WRONG2                                                       \
  std::cerr << "########################################" << std::endl         \
            << __FILE__ << ":" << __LINE__ << ":Something wroing!"             \
            << std::endl                                                       \
            << "########################################" << std::endl;        \
  assert(NULL)
#define NO_MATCHING_INSTRUCTION2                                               \
  std::cerr << "########################################" << std::endl         \
            << __FILE__ << ":" << __LINE__                                     \
            << ":No mathcing instruction in AArch64! Uhmmm" << std::endl       \
            << "########################################" << std::endl;        \
  assert(NULL)
#include "xbyak_impl.h"

#include "xbyak_mnemonic_impl.h"

#include "debug_impl.h"
