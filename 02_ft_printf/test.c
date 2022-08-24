#include <stdio.h>

int main(void)
{
    int a = 1;
	int* p;
	p = &a;

	printf("return: %d\n", printf("default w\n%4c|\n%4s|\n%4p|\n%4d|\n%4i|\n%4u|\n%6x|\n%6X|\n%4%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'-w'\n%-4c|\n%-4s|\n%-4p|\n%-4d|\n%-4i|\n%-4u|\n%-6x|\n%-6X|\n%-4%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'-+w'\n%-+4c|\n%-+4s|\n%-+4p|\n%-+4d|\n%-+4i|\n%-+4u|\n%-+6x|\n%-+6X|\n%-+4%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'- w'\n%- 4c|\n%- 4s|\n%- 4p|\n%- 4d|\n%- 4i|\n%- 4u|\n%- 6x|\n%- 6X|\n%- 4%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'#w'\n%#4c|\n%#4s|\n%#20p|\n%#4d|\n%#4i|\n%#4u|\n%#6x|\n%#6X|\n%#4%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'0w'\n%04c|\n%04s|\n%020p|\n%04d|\n%04i|\n%04u|\n%06x|\n%06X|\n%04%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'0#w'\n%0#4c|\n%0#4s|\n%0#20p|\n%0#4d|\n%0#+4i|\n%0#4u|\n%0#6x|\n%0#6X|\n%0#4%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'-0w'\n%-04c|\n%-04s|\n%-020p|\n%-04d|\n%-04i|\n%-04u|\n%-06x|\n%-06X|\n%-04%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'.'\n%.c|\n%.s|\n%.p|\n%.d|\n%.i|\n%.u|\n%.x|\n%.X|\n%.%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'w.'\n%4.c|\n%4.s|\n%20.p|\n%4.d|\n%4.i|\n%4.u|\n%6.x|\n%6.X|\n%4.%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'0w.'\n%04.c|\n%04.s|\n%020.p|\n%04.d|\n%04.i|\n%04.u|\n%0#6.x|\n%0#6.X|\n%04.%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'w.n'\n%6.1c|\n%6.1s|\n%12.1p|\n%+6.1d|\n%+6.1i|\n%+6.1u|\n%#6.1x|\n%#6.1X|\n%6.1%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'w.n'\n%6.5c|\n%6.5s|\n%12.5p|\n%+6.5d|\n%+6.5i|\n%+6.5u|\n%#6.5x|\n%#6.5X|\n%6.5%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'w.-n'\n%6.-5c|\n%6.-5s|\n%12.-5p|\n%+6.-5d|\n%+6.-5i|\n%+6.-5u|\n%#6.-5x|\n%#6.-5X|\n%6.-5%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'0w.n'\n%06.1c|\n%06.1s|\n%012.1p|\n%+06.1d|\n%+06.1i|\n%+06.1u|\n%#06.1x|\n%#06.1X|\n%06.1%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'0w.n'\n%06.5c|\n%06.5s|\n%012.5p|\n%+06.5d|\n%+06.5i|\n%+06.5u|\n%#06.5x|\n%#06.5X|\n%06.5%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'w.0'\n%6.0c|\n%6.0s|\n%12.0p|\n%+6.0d|\n%+6.0i|\n%+6.0u|\n%#6.0x|\n%#6.0X|\n%6.0%|\n\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	printf("return: %d\n", printf("'w.0 0'\n%6.0c|\n%6.0s|\n%12.0p|\n%+6.0d|\n%+6.0i|\n%+6.0u|\n%#6.0x|\n%#6.0X|\n%6.0%|\n\n", 0, 0, 0, 0, 0, 0, 0, 0));
}