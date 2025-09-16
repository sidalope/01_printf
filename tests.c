#include <stdio.h>
#include <assert.h>
#include "src/ft_printf.h"

void test_null()
{
	int len_ft = 0;
	
	ft_printf("~~~ Test NULL ~~~");
	
	len_ft = ft_printf("\n1: %c", NULL);

	len_ft = ft_printf("\n2: %s", NULL);

	len_ft = ft_printf("\n3: %p", NULL);

	len_ft = ft_printf("\n4: %d", NULL);

	len_ft = ft_printf("\n5: %i", NULL);

	len_ft = ft_printf("\n6: %u", NULL);

	len_ft = ft_printf("\n7: %x", NULL);

	len_ft = ft_printf("\n8: %X", NULL);

	len_ft = ft_printf("\n9: %%", NULL);
}

void test_c()
{
	int len_ft = 0;
	int len = 0;
	
	ft_printf("\n~~~ Test c ~~~\n");
	
	len_ft = ft_printf("%c\n", 'A');
	len = printf("%c\n", 'A');
	assert(len_ft == len);

	len_ft = ft_printf("%c\n", 'z');
	len = printf("%c\n", 'z');
	assert(len_ft == len);

	len_ft = ft_printf("%c\n", '0');
	len = printf("%c\n", '0');
	assert(len_ft == len);

	len_ft = ft_printf("Newline: |%c|\n", '\n');
	len = printf("Newline: |%c|\n", '\n');
	assert(len_ft == len);

	len_ft = ft_printf("Space: |%c|\n", ' ');
	len = printf("Space: |%c|\n", ' ');
	assert(len_ft == len);

	len_ft = ft_printf("Char: %c\n", 'Q');
	len = printf("Char: %c\n", 'Q');
	assert(len_ft == len);

	len_ft = ft_printf("First: %c, Second: %c\n", 'X', 'Y');
	len = printf("First: %c, Second: %c\n", 'X', 'Y');
	assert(len_ft == len);

	len_ft = ft_printf("Tab: |%c|\n", '\t');
	len = printf("Tab: |%c|\n", '\t');
	assert(len_ft == len);

	len_ft = ft_printf("Percent: %c\n", '%');
	len = printf("Percent: %c\n", '%');
	assert(len_ft == len);

	len_ft = ft_printf("Null: |%c|\n", '\0');
	len = printf("Null: |%c|\n", '\0');
	assert(len_ft == len);

	printf("\n");
}

void test_s()
{
	int len_ft = 0;
	int len = 0;

	ft_printf("~~~ Test s ~~~\n");

	len_ft = ft_printf("%s\n", "A");
	len = printf("%s\n", "A");
	assert(len_ft == len);

	len_ft = ft_printf("%s\n", "Hello");
	len = printf("%s\n", "Hello");
	assert(len_ft == len);

	len_ft = ft_printf("|%s|\n", "");
	len = printf("|%s|\n", "");
	assert(len_ft == len);

	len_ft = ft_printf("%s\n", "This is a test string.");
	len = printf("%s\n", "This is a test string.");
	assert(len_ft == len);

	len_ft = ft_printf("String: %s\n", "42");
	len = printf("String: %s\n", "42");
	assert(len_ft == len);

	len_ft = ft_printf("Two: %s %s\n", "foo", "bar");
	len = printf("Two: %s %s\n", "foo", "bar");
	assert(len_ft == len);

	len_ft = ft_printf("Special: %s\n", "!@#$%^&*()");
	len = printf("Special: %s\n", "!@#$%^&*()");
	assert(len_ft == len);

	len_ft = ft_printf("Long: %s\n", "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz END");
	len = printf("Long: %s\n", "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz END");
	assert(len_ft == len);

	printf("\n");
}

void test_p()
{
	int len_ft = 0;
	int len = 0;
	int a = 1;
	int b = 2;
	void *ptr = &a;

	ft_printf("~~~ Test p ~~~\n");
	
	len_ft = ft_printf("%p\n", (void*)&a);
	len = printf("%p\n", (void*)&a);
	assert(len_ft == len);

	len_ft = ft_printf("%p\n", (void*)&b);
	len = printf("%p\n", (void*)&b);
	assert(len_ft == len);

	len_ft = ft_printf("%p\n", NULL);
	len = printf("%p\n", NULL);
	assert(len_ft == len);

	len_ft = ft_printf("Pointer: %p\n", ptr);
	len = printf("Pointer: %p\n", ptr);
	assert(len_ft == len);

	len_ft = ft_printf("Self: %p\n", (void*)&ptr);
	len = printf("Self: %p\n", (void*)&ptr);
	assert(len_ft == len);

	len_ft = ft_printf("Zero: %p\n", (void*)0);
	len = printf("Zero: %p\n", (void*)0);
	assert(len_ft == len);

	len_ft = ft_printf("Max: %p\n", (void*)~0);
	len = printf("Max: %p\n", (void*)~0);
	assert(len_ft == len);

	len_ft = ft_printf("Stack: %p\n", (void*)__builtin_frame_address(0));
	len = printf("Stack: %p\n", (void*)__builtin_frame_address(0));
	assert(len_ft == len);

	len_ft = ft_printf("Heap: %p\n", malloc(1));
	len = printf("Heap: %p\n", malloc(1));
	assert(len_ft == len);

	len_ft = ft_printf("Func: %p\n", (void*)ft_printf);
	len = printf("Func: %p\n", (void*)ft_printf);
	assert(len_ft == len);

	printf("\n");
}

void test_di()
{
	int len_ft = 0;
	int len = 0;

	ft_printf("~~~ Test d & i~~~\n");

	len_ft = ft_printf("%d\n", 0);
	len = printf("%d\n", 0);
	assert(len_ft == len);

	len_ft = ft_printf("%d\n", 1);
	len = printf("%d\n", 1);
	assert(len_ft == len);

	len_ft = ft_printf("%d\n", -1);
	len = printf("%d\n", -1);
	assert(len_ft == len);

	len_ft = ft_printf("%d\n", 12345);
	len = printf("%d\n", 12345);
	assert(len_ft == len);

	len_ft = ft_printf("%d\n", -54321);
	len = printf("%d\n", -54321);
	assert(len_ft == len);

	len_ft = ft_printf("Max: %d\n", 2147483647);
	len = printf("Max: %d\n", 2147483647);
	assert(len_ft == len);

	len_ft = ft_printf("Min: %d\n", -2147483647);
	len = printf("Min: %d\n", -2147483647);
	assert(len_ft == len);

	len_ft = ft_printf("Sum: %d\n", 100 + 200);
	len = printf("Sum: %d\n", 100 + 200);
	assert(len_ft == len);

	printf("\n");
}

void test_u()
{
	int len_ft = 0;
	int len = 0;

	ft_printf("~~~ Test u ~~~\n");

	len_ft = ft_printf("%u\n", 0U);
	len = printf("%u\n", 0U);
	assert(len_ft == len);

	len_ft = ft_printf("%u\n", 1U);
	len = printf("%u\n", 1U);
	assert(len_ft == len);

	len_ft = ft_printf("%u\n", 4294967295U);
	len = printf("%u\n", 4294967295U);
	assert(len_ft == len);

	len_ft = ft_printf("%u\n", 123456789U);
	len = printf("%u\n", 123456789U);
	assert(len_ft == len);

	len_ft = ft_printf("Sum: %u\n", 100U + 200U);
	len = printf("Sum: %u\n", 100U + 200U);
	assert(len_ft == len);

	len_ft = ft_printf("Max: %u\n", 4294967295U);
	len = printf("Max: %u\n", 4294967295U);
	assert(len_ft == len);

	len_ft = ft_printf("Half: %u\n", 2147483647U);
	len = printf("Half: %u\n", 2147483647U);
	assert(len_ft == len);

	len_ft = ft_printf("Zero: %u\n", 0U);
	len = printf("Zero: %u\n", 0U);
	assert(len_ft == len);

	len_ft = ft_printf("Big: %u\n", 4000000000U);
	len = printf("Big: %u\n", 4000000000U);
	assert(len_ft == len);

	len_ft = ft_printf("Small: %u\n", 42U);
	len = printf("Small: %u\n", 42U);
	assert(len_ft == len);
	
	printf("\n");
}

void test_x()
{
	int len_ft = 0;
	int len = 0;
	
	ft_printf("~~~ Test x ~~~\n");

	len_ft = ft_printf("%x\n", 0);
	len = printf("%x\n", 0);
	assert(len_ft == len);

	len_ft = ft_printf("%x\n", 10);
	len = printf("%x\n", 10);
	assert(len_ft == len);

	len_ft = ft_printf("%x\n", 255);
	len = printf("%x\n", 255);
	assert(len_ft == len);

	len_ft = ft_printf("%x\n", 4096);
	len = printf("%x\n", 4096);
	assert(len_ft == len);

	len_ft = ft_printf("%x\n", 123456);
	len = printf("%x\n", 123456);
	assert(len_ft == len);

	len_ft = ft_printf("Max: %x\n", 4294967295U);
	len = printf("Max: %x\n", 4294967295U);
	assert(len_ft == len);

	len_ft = ft_printf("Min: %x\n", 0U);
	len = printf("Min: %x\n", 0U);
	assert(len_ft == len);

	len_ft = ft_printf("Sum: %x\n", 0x10 + 0x20);
	len = printf("Sum: %x\n", 0x10 + 0x20);
	assert(len_ft == len);

	len_ft = ft_printf("Big: %x\n", 0xABCDEF);
	len = printf("Big: %x\n", 0xABCDEF);
	assert(len_ft == len);

	len_ft = ft_printf("Small: %x\n", 0x1);
	len = printf("Small: %x\n", 0x1);
	assert(len_ft == len);
	
	printf("\n");
}

void test_X()
{
	int len_ft = 0;
	int len = 0;

	ft_printf("~~~ Test X ~~~\n");
	
	len_ft = ft_printf("%X\n", 0);
	len = printf("%X\n", 0);
	assert(len_ft == len);

	len_ft = ft_printf("%X\n", 10);
	len = printf("%X\n", 10);
	assert(len_ft == len);

	len_ft = ft_printf("%X\n", 255);
	len = printf("%X\n", 255);
	assert(len_ft == len);

	len_ft = ft_printf("%X\n", 4096);
	len = printf("%X\n", 4096);
	assert(len_ft == len);

	len_ft = ft_printf("%X\n", 123456);
	len = printf("%X\n", 123456);
	assert(len_ft == len);

	len_ft = ft_printf("Max: %X\n", 4294967295U);
	len = printf("Max: %X\n", 4294967295U);
	assert(len_ft == len);

	len_ft = ft_printf("Min: %X\n", 0U);
	len = printf("Min: %X\n", 0U);
	assert(len_ft == len);

	len_ft = ft_printf("Sum: %X\n", 0x10 + 0x20);
	len = printf("Sum: %X\n", 0x10 + 0x20);
	assert(len_ft == len);

	len_ft = ft_printf("Big: %X\n", 0xABCDEF);
	len = printf("Big: %X\n", 0xABCDEF);
	assert(len_ft == len);

	len_ft = ft_printf("Small: %X\n", 0x1);
	len = printf("Small: %X\n", 0x1);
	assert(len_ft == len);
	
	printf("\n");
}

void test_perc()
{
	int len_ft = 0;
	int len = 0;

	ft_printf("~~~ Test %% ~~~\n");

	len_ft = ft_printf("%%\n");
	len = printf("%%\n");
	assert(len_ft == len);

	len_ft = ft_printf("Percent: %%\n");
	len = printf("Percent: %%\n");
	assert(len_ft == len);

	len_ft = ft_printf("100%% sure\n");
	len = printf("100%% sure\n");
	assert(len_ft == len);

	len_ft = ft_printf("%% %% %%\n");
	len = printf("%% %% %%\n");
	assert(len_ft == len);

	len_ft = ft_printf("Value: %d%%\n", 50);
	len = printf("Value: %d%%\n", 50);
	assert(len_ft == len);

	len_ft = ft_printf("Mix: %c%%\n", 'A');
	len = printf("Mix: %c%%\n", 'A');
	assert(len_ft == len);

	len_ft = ft_printf("Percent sign: %%\n");
	len = printf("Percent sign: %%\n");
	assert(len_ft == len);

	len_ft = ft_printf("Edge: %%%% %%%%\n");
	len = printf("Edge: %%%% %%%%\n");
	assert(len_ft == len);

	len_ft = ft_printf("Start%%End\n");
	len = printf("Start%%End\n");
	assert(len_ft == len);

	printf("\n");
}

void test_printf()
{
	int len_ft = 0;
	int len = 0;

	ft_printf("~~~ Test cspdiuxX% ~~~\n");

	len_ft = ft_printf("A:%c | S:%s | P:%p | D:%d | I:%i | U:%u | X:%x | XX:%X | percent:%%\n", 'A', "hello", (void*)0x1234, -42, 42, 42U, 255, 255);
	len = printf("A:%c | S:%s | P:%p | D:%d | I:%i | U:%u | X:%x | XX:%X | percent:%%\n", 'A', "hello", (void*)0x1234, -42, 42, 42U, 255, 255);
	assert(len_ft == len);

	len_ft = ft_printf("RandomB %c, string=%s, ptr->%p, d=%d, i=%i, u=%u, x=%x, X=%X, %% done\n", 'B', "world", (void*)0, 0, 0, 0U, 0, 0);
	len = printf("RandomB %c, string=%s, ptr->%p, d=%d, i=%i, u=%u, x=%x, X=%X, %% done\n", 'B', "world", (void*)0, 0, 0, 0U, 0, 0);
	assert(len_ft == len);

	len_ft = ft_printf("C test: [%c] | [%s] | [%p] | [%d] | [%i] | [%u] | [%x] | [%X] | [%%]\n", 'C', "", (void*)0xDEADBEEF, 2147483647, -2147483647, 4294967295U, 0xabcdef, 0xABCDEF);
	len = printf("C test: [%c] | [%s] | [%p] | [%d] | [%i] | [%u] | [%x] | [%X] | [%%]\n", 'C', "", (void*)0xDEADBEEF, 2147483647, -2147483647, 4294967295U, 0xabcdef, 0xABCDEF);
	assert(len_ft == len);

	len_ft = ft_printf("D: char=%c, str=%s, ptr=%p, d=%d, i=%i, u=%u, x=%x, X=%X, percent=%%\n", 'D', "test", (void*)&ft_printf, 123, -123, 123U, 123, 123);
	len = printf("D: char=%c, str=%s, ptr=%p, d=%d, i=%i, u=%u, x=%x, X=%X, percent=%%\n", 'D', "test", (void*)&ft_printf, 123, -123, 123U, 123, 123);
	assert(len_ft == len);

	len_ft = ft_printf("E/42/%c/%s/%p/%d/%i/%u/%x/%X/%%/end\n", 'E', "42", (void*)test_perc, -1, 1, 1U, 1, 1);
	len = printf("E/42/%c/%s/%p/%d/%i/%u/%x/%X/%%/end\n", 'E', "42", (void*)test_perc, -1, 1, 1U, 1, 1);
	assert(len_ft == len);

	len_ft = ft_printf("foo%c bar%s baz%p d%d i%i u%u x%x X%X %%\n", 'F', "foo", (void*)-1, 1000, -1000, 1000U, 0x10, 0x10);
	len = printf("foo%c bar%s baz%p d%d i%i u%u x%x X%X %%\n", 'F', "foo", (void*)-1, 1000, -1000, 1000U, 0x10, 0x10);
	assert(len_ft == len);

	len_ft = ft_printf("G test: c=%c, s=%s, p=%p, d=%d, i=%i, u=%u, x=%x, X=%X, percent=%%\n", 'G', "bar", (void*)0x0, 32767, -32768, 65535U, 0x7FFF, 0x7FFF);
	len = printf("G test: c=%c, s=%s, p=%p, d=%d, i=%i, u=%u, x=%x, X=%X, percent=%%\n", 'G', "bar", (void*)0x0, 32767, -32768, 65535U, 0x7FFF, 0x7FFF);
	assert(len_ft == len);

	len_ft = ft_printf("I:%c lorem:%s ptr:%p d:%d i:%i u:%u x:%x X:%X %%\n", 'I', "lorem", (void*)0xCAFEBABE, 42, -42, 42U, 0x42, 0x42);
	len = printf("I:%c lorem:%s ptr:%p d:%d i:%i u:%u x:%x X:%X %%\n", 'I', "lorem", (void*)0xCAFEBABE, 42, -42, 42U, 0x42, 0x42);
	assert(len_ft == len);

	len_ft = ft_printf("J/ipsum/%c/%s/%p/%d/%i/%u/%x/%X/%%/!\n", 'J', "ipsum", (void*)NULL, -2147483647, 2147483647, 0U, 0x0, 0x0);
	len = printf("J/ipsum/%c/%s/%p/%d/%i/%u/%x/%X/%%/!\n", 'J', "ipsum", (void*)NULL, -2147483647, 2147483647, 0U, 0x0, 0x0);

	printf("\n");
}

int	main(int argc, char* argv[])
{
	// char	*f_specs = "cspdiuxX%";
	if (argc >= 2)
		ft_printf(argv[1]);
	test_null();
	test_c();
	test_s();
	test_p();
	test_di();
	test_u();
	test_x();
	test_X();
	test_perc();
	test_printf();
	
	return (0);
}
