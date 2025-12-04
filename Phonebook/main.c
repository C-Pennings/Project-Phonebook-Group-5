#include "main.h"
#include "color.h"
#include <stdio.h>

int main() {
	ENABLE_COLORS();

	printf(GREEN BOLD "COLOR test" RESET "\n");

	return 0;
}