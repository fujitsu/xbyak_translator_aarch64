# Build instruction



## Build test application on Armv8-A native environment

### Build libxed

Xbyak_translator_aarch64 uses libxed so that it must be built in advance.

```
git clone https://github.com/fujitsu/xbyak_translator_aarch64.git
cd xbyak_translator_aarch64
git submodule update --init
cd translator/third_party
mkdir build_xed_aarch64
cd build_xed_aarch64
../xed/mfile.py --shared examples install  # Python3 is required.
cd kits/
ln -sf xed-install-base-* xed
```

Once you build libxed, please try the following command.

```
# Inside "xbyak_translator_aarch64/translator/test" directory
./test3.sh -a -A -E pattern/mov/mov000.cpp
```

`mov000.cpp` checks that xbyak_translator_aarch64 correctly translates x86_64 mov instructions into corresponding Armv8-A + SVE instructions. The test pattern in `mov000.cpp` shows below. This program tests translation of mov instructions with various immediate values.

```
  void genJitTestCode() {
    mov(rax, uint64_t(0xaaaaaaaaaaaaaaaa));
    mov(rcx, uint32_t(0xaaaaaaaa));
    mov(rdx, uint16_t(0xaaaa));
    mov(rbx, uint8_t(0xaa));

    mov(rbp, int64_t(0xaaaaaaaaaaaaaaaa));
    mov(rsi, int32_t(0xaaaaaaaa));
    mov(rdi, int16_t(0xaaaa));
    mov(r8, int8_t(0xaa));

    mov(r9, int64_t(0x5555555555555555));
    mov(r10, int32_t(0x55555555));
    mov(r11, int16_t(0x5555));
    mov(r12, int8_t(0x55));
  }
};
```

`mov000.cpp` generates Armv8-A machine code correspond to the above instructions and execute the translated machine code. Outputs are the register values after execution as below.
You can see that immediate values are correctly set to Armv8-A registers.

**Note**:x86_64's rax, rcx, rdx, rbx, rbp, rsi, rdi has register indexes of zero, one, two, three, five, six, seven, respectively.

```
Output:G[ 0]:aaaaaaaa_aaaaaaaa
Output:G[ 1]:00000000_aaaaaaaa
Output:G[ 2]:00000000_0000aaaa
Output:G[ 3]:00000000_000000aa
Output:G[ 4]:00000000_00000000
Output:G[ 5]:aaaaaaaa_aaaaaaaa
Output:G[ 6]:ffffffff_aaaaaaaa
Output:G[ 7]:ffffffff_ffffaaaa
Output:G[ 8]:ffffffff_ffffffaa
Output:G[ 9]:55555555_55555555
Output:G[10]:00000000_55555555
Output:G[11]:00000000_00005555
Output:G[12]:00000000_00000055
```

## Build test application on x86_64 + QEMU environment

If you don't have Armv8-A native environment, you can try Xbyak_translator_aarch64 on your x86_64 Linux computer with QEMU.

### Prepare QEMU

Some linux distributions have QEMU install packages, but we recommend to build latest QEMU version (5.0.0 or higher).
The following is an example of build instructions. (Please refer the official build instructions.)

```
wget https://download.qemu.org/qemu-5.0.0.tar.xz
tar xvJf qemu-5.0.0.tar.xz
cd qemu-5.0.0
./configure --target-list=aarch64-linux-user
make
make install # If you need.
```

### Build libxed

Xbyak_translator_aarch64 uses libxed so that it must be built in advance.
Cross compiler for AArch64 is required. The following list is required packages in case of Ubuntu 16.04.6.

```
dpkg -l | grep -iw -e arm -e arm64 -e aarch -e aarch64
ii  binutils-aarch64-linux-gnu                 2.26.1-1ubuntu1~16.04.8                      amd64        GNU binary utilities, for aarch64-linux-gnu target
ii  cpp-5-aarch64-linux-gnu                    5.4.0-6ubuntu1~16.04.9cross1                 amd64        GNU C preprocessor
ii  cpp-aarch64-linux-gnu                      4:5.3.1-1ubuntu1                             amd64        GNU C preprocessor (cpp) for the arm64 architecture
ii  g++-5-aarch64-linux-gnu                    5.4.0-6ubuntu1~16.04.9cross1                 amd64        GNU C++ compiler
ii  g++-aarch64-linux-gnu                      4:5.3.1-1ubuntu1                             amd64        GNU C++ compiler for the arm64 architecture
ii  gcc-5-aarch64-linux-gnu                    5.4.0-6ubuntu1~16.04.9cross1                 amd64        GNU C compiler
ii  gcc-5-aarch64-linux-gnu-base:amd64         5.4.0-6ubuntu1~16.04.9cross1                 amd64        GCC, the GNU Compiler Collection (base package)
ii  gcc-aarch64-linux-gnu                      4:5.3.1-1ubuntu1                             amd64        GNU C compiler for the arm64 architecture
ii  libasan2-arm64-cross                       5.4.0-6ubuntu1~16.04.9cross1                 all          AddressSanitizer -- a fast memory error detector
ii  libatomic1-arm64-cross                     5.4.0-6ubuntu1~16.04.9cross1                 all          support library providing __atomic built-in functions
ii  libc6-arm64-cross                          2.23-0ubuntu3cross1                          all          GNU C Library: Shared libraries (for cross-compiling)
ii  libc6-dev-arm64-cross                      2.23-0ubuntu3cross1                          all          GNU C Library: Development Libraries and Header Files (for cross-compiling)
ii  libgcc-5-dev-arm64-cross                   5.4.0-6ubuntu1~16.04.9cross1                 all          GCC support library (development files)
ii  libgcc1-arm64-cross                        1:5.4.0-6ubuntu1~16.04.9cross1               all          GCC support library
ii  libgomp1-arm64-cross                       5.4.0-6ubuntu1~16.04.9cross1                 all          GCC OpenMP (GOMP) support library
ii  libitm1-arm64-cross                        5.4.0-6ubuntu1~16.04.9cross1                 all          GNU Transactional Memory Library
ii  libstdc++-5-dev-arm64-cross                5.4.0-6ubuntu1~16.04.9cross1                 all          GNU Standard C++ Library v3 (development files)
ii  libstdc++6-arm64-cross                     5.4.0-6ubuntu1~16.04.9cross1                 all          GNU Standard C++ Library v3
ii  libubsan0-arm64-cross                      5.4.0-6ubuntu1~16.04.9cross1                 all          UBSan -- undefined behaviour sanitizer (runtime)
ii  linux-libc-dev-arm64-cross                 4.4.0-18.34cross1                            all          Linux Kernel Headers for development (for cross-compiling)
ii  pkg-config-aarch64-linux-gnu               4:5.3.1-1ubuntu1                             amd64        manage compile and link flags for libraries for arm64 architecture
```

If cross compiler is prepared, you can build libxed for AArch64 

```
git clone https://github.com/fujitsu/xbyak_translator_aarch64.git
cd xbyak_translator_aarch64
git submodule update --init
cd translator/third_party
mkdir build_xed_aarch64
cd build_xed_aarch64
../xed/mfile.py --strip=/usr/bin/aarch64-linux-gnu-strip  --cc=/usr/bin/aarch64-linux-gnu-gcc \
--cxx=/usr/bin/aarch64-linux-gnu-g++ --host-cpu=aarch64 --shared examples install
cd kits/
ln -sf xed-install-base-* xed
```

Once you build qemu-aarch64, you can try Xbyak_translator_aarch64 with the following instructions and
obtain the same result on Armv8-A native environment.

```
# Inside "xbyak_translator_aarch64/translator/test" directory
export PATH=(path of qemu-aarch64 you build);$PATH

./test2.sh -a -A -E pattern/mov/mov000.cpp
```

On x86_64 computer, you can also try test applications without translation.

```
./test2.sh -x -X -E pattern/mov/mov000.cpp
```

This command makes `mov000.cpp` without Xbyak_translator_aarch64, 
it means `mov000.cpp` is built as a pure x86_64 application written in Xbyak,
and run it on x86_64 native environment (not QEMU). 
It generates x86_64 machine code, executes the machine code generated, 
and outputs the register values after execution to std:cout.
The number of general purpose registers of x86_64 is 16, it is less than that of Armv8-A,
so that output contains dummy value such as 
`Output:G[16]:00000000_00000000` to `Output:G[31]:00000000_00000000`.
However the others, except the fourth register which is used as a stack pointer in x86_64 CPU,
 are the same as the output of QEMU or the Armv8-A native environment.
