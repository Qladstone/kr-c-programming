#include <stdio.h>
#include <limits.h>

signed char min_signed_char(void);
signed char max_signed_char(void);
signed short min_signed_short(void);
signed short max_signed_short(void);
signed int min_signed_int(void);
signed int max_signed_int(void);
signed long min_signed_long(void);
signed long max_signed_long(void);

unsigned char max_unsigned_char(void);
unsigned short max_unsigned_short(void);
unsigned int max_unsigned_int(void);
unsigned long max_unsigned_long(void);

int main() {
	printf("Variable ranges from limits.h:\n");
	printf("signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("signed int: %d to %d\n", INT_MIN, INT_MAX);
	printf("signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned char: %u to %u\n", 0, UCHAR_MAX);
	printf("unsigned short: %u to %u\n", 0, USHRT_MAX);
	printf("unsigned int: %u to %u\n", 0, UINT_MAX);
	printf("unsigned long: %lu to %lu\n", 0, ULONG_MAX);
	printf("Variable ranges by computation:\n");
	printf("signed char: %d to %d\n", min_signed_char(), max_signed_char());
	printf("signed short: %d to %d\n", min_signed_short(), max_signed_short());
	printf("signed int: %d to %d\n", min_signed_int(), max_signed_int());
	printf("signed long: %ld to %ld\n", min_signed_long(), max_signed_long());
	printf("unsigned char: %u to %u\n", 0, max_unsigned_char());
	printf("unsigned short: %u to %u\n", 0, max_unsigned_short());
	printf("unsigned int: %u to %u\n", 0, max_unsigned_int());
	printf("unsigned long: %lu to %lu\n", 0, max_unsigned_long());
}

signed char min_signed_char(void) {
	signed char curr = 0;
	signed char next = curr - 1;
	while (next < curr) {
		curr--;
		next--;
	}
	return curr;
}

signed char max_signed_char(void) {
	signed char curr = 0;
	signed char next = curr + 1;
	while (next > curr) {
		next++;
		curr++;
	}
	return curr;
}

signed short min_signed_short(void) {
	signed short curr = 0;
	signed short next = curr - 1;
	while (next < curr) {
		curr--;
		next--;
	}
	return curr;
}

signed short max_signed_short(void) {
	signed short curr = 0;
	signed short next = curr + 1;
	while (next > curr) {
		curr++;
		next++;
	}
	return curr;
}

signed int min_signed_int(void) {
	signed int curr = 0;
	signed int next = curr - 1;
	while (next < curr) {
		curr--;
		next--;
	}
	return curr;
}

signed int max_signed_int(void) {
	signed int curr = 0;
	signed int next = curr + 1;
	while (next > curr) {
		curr++;
		next++;
	}
	return curr;
}

signed long min_signed_long(void) {
	signed long curr = 0;
	signed long next = curr - 1;
	while (next < curr) {
		curr++;
		next++;
	}
	return curr;
}
signed long max_signed_long(void) {
	signed long curr = 0;
	signed long next = curr + 1;
	while (next > curr) {
		curr++;
		next++;
	}
	return curr;
}


unsigned char max_unsigned_char(void) {
	unsigned char curr = 0;
	unsigned char next = curr + 1;
	while (next > curr) {
		curr++;
		next++;
	}
	return curr;
}

unsigned short max_unsigned_short(void) {
	unsigned short curr = 0;
	unsigned short next = curr + 1;
	while (next > curr) {
		curr++;
		next++;
	}
	return curr;
}

unsigned int max_unsigned_int(void) {
	unsigned int curr = 0;
	unsigned int next = curr + 1;
	while (next > curr) {
		curr++;
		next++;
	}
	return curr;
}

unsigned long max_unsigned_long(void) {
	unsigned long curr = 0;
	unsigned long next = curr + 1;
	while (next > curr) {
		curr++;
		next++;
	}
	return curr;
}
