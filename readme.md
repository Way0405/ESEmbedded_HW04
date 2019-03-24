HW04
===
This is the hw04 sample. Please follow the steps below.

# Build the Sample Program

1. Fork this repo to your own github account.

2. Clone the repo that you just forked.

3. Under the hw04 dir, use:

	* `make` to build.

	* `make flash` to flash the binary file into your STM32F4 device.

	* `make clean` to clean the ouput files.

# Build Your Own Program

1. Edit or add files if you need to.

2. Make and run like the steps above.

3. Please avoid using hardware dependent C standard library functions like `printf`, `malloc`, etc.

# HW04 Requirements

1. Please practice to reference the user manuals mentioned in [Lecture 04], and try to use the user button (the blue one on the STM32F4DISCOVERY board).

2. After reset, the device starts to wait until the user button has been pressed, and then starts to blink the blue led forever.

3. Try to define a macro function `READ_BIT(addr, bit)` in reg.h for reading the value of the user button.

4. Push your repo to your github. (Use .gitignore to exclude the output files like object files, executable files, or binary files)

5. The TAs will clone your repo, build from your source code, and flash to see the result.

[Lecture 04]: http://www.nc.es.ncku.edu.tw/course/embedded/04/

--------------------

- [x] **If you volunteer to give the presentation (demo) next week, check this.**

--------------------
可以查出USER button的位址是PA0
所以在blink.c內建立button_init()來初始化PA0
(enalbe PORTA,設定MODE 為input(設成00), PUPDR)
ps:因為是input,所以可以不設定OTYPER,OSPEEDR

在reg.h內 define READ_BIT(addr, bit) (REG(addr) &= UINT32_1 << (bit))
(說明
輸入為xxxxxx......y
     &000000......1
結果為000000......y
結果為000000......y
若y為1則READ_BIT為1，反之亦然
)

(input會存到Input Data Reg)
使用時就可以用if(READ_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_IDR_OFFSET, IDRy_BIT(0))==1)做判斷式
(#define GPIOx_IDR_OFFSET 0X10)
(#define IDRy_BIT(y) (y))


