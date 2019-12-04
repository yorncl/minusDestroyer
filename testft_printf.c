#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int		ft_printf(const char *s, ...);

#define PRINT_TEST(...){\
	int r = PRINT(__VA_ARGS__);\
	PRINT("returned : %d\n", r);\
}\

void	test_int_minus(int padd, int value)
{
	PRINT_TEST("|%-d|\n", value);
	PRINT_TEST("|%-5d|\n", value);
	PRINT_TEST("|%-50d|\n", value);
	PRINT_TEST("|%----d|\n", value);
	PRINT_TEST("|%*d|\n", padd , value);
	PRINT_TEST("|%-*d|\n", padd , value);
	PRINT_TEST("|%----*d|\n", padd , value);
	PRINT_TEST("|%*d|\n", padd , value);
}

void	test_char_minus(int padd, int value)
{
	PRINT_TEST("|%-c|\n", value);
	PRINT_TEST("|%----c|\n", value);
	PRINT_TEST("|%-5c|\n", value);
	PRINT_TEST("|%-50c|\n", value);
	PRINT_TEST("|%----50c|\n", value);
	PRINT_TEST("|%----c|\n", value);
	PRINT_TEST("|%*c|\n", padd , value);
	PRINT_TEST("|%-*c|\n", padd , value);
	PRINT_TEST("|%----*c|\n", padd , value);
	PRINT_TEST("|%*c|\n", padd , value);
}

void	test_hex_minus(int padd, unsigned int value)
{
	PRINT_TEST("|%-x|\n", value);
	PRINT_TEST("|%----x|\n", value);
	PRINT_TEST("|%-50x|\n", value);
	PRINT_TEST("|%----50x|\n", value);
	PRINT_TEST("|%*x|\n", padd , value);
	PRINT_TEST("|%-*x|\n", padd , value);
	PRINT_TEST("|%----*x|\n", padd , value);
	PRINT_TEST("|%*x|\n", padd , value);
}

void	test_HEX_minus(int padd, unsigned int value)
{
	PRINT_TEST("|%-X|\n", value);
	PRINT_TEST("|%----X|\n", value);
	PRINT_TEST("|%-50X|\n", value);
	PRINT_TEST("|%----50X|\n", value);
	PRINT_TEST("|%*X|\n", padd , value);
	PRINT_TEST("|%-*X|\n", padd , value);
	PRINT_TEST("|%----*X|\n", padd , value);
	PRINT_TEST("|%*X|\n", padd , value);
}

void	test_unsigned_minus(int padd, unsigned int value)
{
	PRINT_TEST("|%-u|\n", value);
	PRINT_TEST("|%----u|\n", value);
	PRINT_TEST("|%-50u|\n", value);
	PRINT_TEST("|%----50u|\n", value);
	PRINT_TEST("|%*u|\n", padd , value);
	PRINT_TEST("|%-*u|\n", padd , value);
	PRINT_TEST("|%----*u|\n", padd , value);
	PRINT_TEST("|%*u|\n", padd , value);
}

void	test_ptr_minus(int padd, unsigned long int value)
{
	char *data = "afs";
	PRINT_TEST("|%-p|\n", value);
	PRINT_TEST("|%----p|\n", value);
	// PRINT_TEST("|%-50p|\n", value);
	// PRINT_TEST("|%----50p|\n", value);
	// PRINT_TEST("|%*p|\n", padd , value);
	// PRINT_TEST("|%-*p|\n", padd , value);
	// PRINT_TEST("|%----*p|\n", padd , value);
	// PRINT_TEST("|%*p|\n", padd , value);
	// PRINT_TEST("|%-p|\n", data);
	// PRINT_TEST("|%----p|\n", data);
	// PRINT_TEST("|%-50p|\n", data);
	// PRINT_TEST("|%----50p|\n", data);
	// PRINT_TEST("|%*p|\n", padd , data);
	// PRINT_TEST("|%-*p|\n", padd , data);
	// PRINT_TEST("|%----*p|\n", padd , data);
	// PRINT_TEST("|%*p|\n", padd , data);
}

void	test_percent_minus(int padd, int value)
{
	(void) padd;
	(void) value;
	PRINT_TEST("|%-05%|\n");
	PRINT_TEST("|%-%|\n");
	PRINT_TEST("|%-----%|\n");
	// PRINT_TEST("|%----%|\n", value);
	// PRINT_TEST("|%*%|\n", padd , value);
	// PRINT_TEST("|%-*%|\n", padd , value);
	// PRINT_TEST("|%----*%|\n", padd , value);
	// PRINT_TEST("|%*%|\n", padd , value);
}

void	test_str_minus(int padd, char * value)
{
	PRINT_TEST("|%-s|\n", value);
	PRINT_TEST("|%----s|\n", value);
	PRINT_TEST("|%-50s|\n", value);
	PRINT_TEST("|%----50s|\n", value);
	PRINT_TEST("|%*s|\n", padd , value);
	PRINT_TEST("|%-*s|\n", padd , value);
	PRINT_TEST("|%----*s|\n", padd , value);
	PRINT_TEST("|%-----*s|\n", padd , value);
	PRINT_TEST("|%*s|\n", padd , value);
}


int main(void)
{
	//d - i
	//random +
	test_int_minus(-50, 42);
	test_int_minus(0, 42);
	test_int_minus(50, 42);
	//random -
	test_int_minus(-50, -42);
	test_int_minus(0, -42);
	test_int_minus(50, -42);
	// 0
	test_int_minus(-50, 0);
	test_int_minus(0, 0);
	test_int_minus(50, 0);
	// INT_MAX
	test_int_minus(-50, INT_MAX);
	test_int_minus(0, INT_MAX);
	test_int_minus(50, INT_MAX);
	// INT_MIN
	test_int_minus(-50, INT_MIN);
	test_int_minus(0, INT_MIN);
	test_int_minus(50, INT_MIN);

	//c

	// '\0'
	test_char_minus(50, 150);
	test_char_minus(0, 150);
	test_char_minus(-50, 150);
	//random +
	test_char_minus(50, 'a');
	test_char_minus(0, 'a');
	test_char_minus(-50, 'a');
	//random 
	test_char_minus(50, 20);
	test_char_minus(0, 20);
	test_char_minus(-50, 20);

	// x
	
	//random +
	test_hex_minus(-50, 42);
	test_hex_minus(0, 42);
	test_hex_minus(50, 42);
	//random -
	test_hex_minus(-50, -42);
	test_hex_minus(0, -42);
	test_hex_minus(50, -42);
	// 0
	test_hex_minus(-50, 0);
	test_hex_minus(0, 0);
	test_hex_minus(50, 0);
	// INT_MAX
	test_hex_minus(-50, INT_MAX);
	test_hex_minus(0, INT_MAX);
	test_hex_minus(50, INT_MAX);
	// UINT_MAX
	test_hex_minus(-50, UINT_MAX);
	test_hex_minus(0, UINT_MAX);
	test_hex_minus(50, UINT_MAX);
	// INT_MIN
	test_hex_minus(-50, INT_MIN);
	test_hex_minus(0, INT_MIN);
	test_hex_minus(50, INT_MIN);

	// X
	
	//random +
	test_HEX_minus(-50, 42);
	test_HEX_minus(0, 42);
	test_HEX_minus(50, 42);
	//random -
	test_HEX_minus(-50, -42);
	test_HEX_minus(0, -42);
	test_HEX_minus(50, -42);
	// 0
	test_HEX_minus(-50, 0);
	test_HEX_minus(0, 0);
	test_HEX_minus(50, 0);
	// INT_MAX
	test_HEX_minus(-50, INT_MAX);
	test_HEX_minus(0, INT_MAX);
	test_HEX_minus(50, INT_MAX);
	// UINT_MAX
	test_HEX_minus(-50, UINT_MAX);
	test_HEX_minus(0, UINT_MAX);
	test_HEX_minus(50, UINT_MAX);
	// INT_MIN
	test_HEX_minus(-50, INT_MIN);
	test_HEX_minus(0, INT_MIN);
	test_HEX_minus(50, INT_MIN);

	// p
	
	//random +
	test_ptr_minus(-50, 42);
	test_ptr_minus(0, 42);
	test_ptr_minus(50, 42);
	//random -
	test_ptr_minus(-50, -42);
	test_ptr_minus(0, -42);
	test_ptr_minus(50, -42);
	// 0
	test_ptr_minus(-50, 0);
	test_ptr_minus(0, 0);
	test_ptr_minus(50, 0);
	// INT_MAX
	test_ptr_minus(-50, INT64_MAX);
	test_ptr_minus(0, INT64_MAX);
	test_ptr_minus(50, INT64_MAX);
	// UINT_MAX
	test_ptr_minus(-50, UINT64_MAX);
	test_ptr_minus(0, UINT64_MAX);
	test_ptr_minus(50, UINT64_MAX);
	// INT_MIN
	test_ptr_minus(-50, INT64_MIN);
	test_ptr_minus(0, INT64_MIN);
	test_ptr_minus(50, INT64_MIN);

	// u
	
	//random +
	test_unsigned_minus(-50, 42);
	test_unsigned_minus(0, 42);
	test_unsigned_minus(50, 42);
	//random -
	test_unsigned_minus(-50, -42);
	test_unsigned_minus(0, -42);
	test_unsigned_minus(50, -42);
	// 0
	test_unsigned_minus(-50, 0);
	test_unsigned_minus(0, 0);
	test_unsigned_minus(50, 0);
	// INT_MAX
	test_unsigned_minus(-50, INT_MAX);
	test_unsigned_minus(0, INT_MAX);
	test_unsigned_minus(50, INT_MAX);
	// UINT_MAX
	test_unsigned_minus(-50, UINT_MAX);
	test_unsigned_minus(0, UINT_MAX);
	test_unsigned_minus(50, UINT_MAX);
	// INT_MIN
	test_unsigned_minus(-50, INT_MIN);
	test_unsigned_minus(0, INT_MIN);
	test_unsigned_minus(50, INT_MIN);

	//s

	//null
	test_str_minus(-50, 0);
	test_str_minus(0, 0);
	test_str_minus(50, 0);
	// empty stringa
	test_str_minus(-50, "");
	test_str_minus(0, "");
	test_str_minus(50, "");
	// random string
	test_str_minus(-50, "aadfsdgefg	wrg	ewg");
	test_str_minus(0, "aadfsdgefg	wrg	ewg");
	test_str_minus(50, "aadfsdgefg	wrg	ewg");

	//percent
	test_percent_minus(-50, 42);
	test_percent_minus(-50, -42);

}
