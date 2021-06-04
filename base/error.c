#include "main_header.h"

int	error_processing2(int fail)
{
	if (fail == 8)
		printf(YELLOW "The R and A arguments can \
only be declared once ¯\\_(ツ)_/¯\n");
	else if (fail == 9)
		printf(YELLOW "Incorrect amount of data in a line ¯\\_(ツ)_/¯\n");
	else if (fail == 10)
		printf(YELLOW "Identifier not recognized ¯\\_(ツ)_/¯\n");
	else if (fail == 11)
		printf(YELLOW "No required argument R ¯\\_(ツ)_/¯\n");
	else if (fail == 12)
		printf(YELLOW "Wrong flag ¯\\_(ツ)_/¯\n");
	else if (fail == 13)
		printf(YELLOW "No light or ambient lightning ¯\\_(ツ)_/¯\n");
	printf(RESET);
	return (FALSE);
}

int	error_processing1(int fail)
{
	printf(RED "ERROR.\n");
	if (fail > 7)
		return (error_processing2(fail));
	if (fail == 1)
		printf(YELLOW "File cannot be read ¯\\_(ツ)_/¯\n");
	else if (fail == 2)
		printf(YELLOW "Wrong number of arguments ¯\\_(ツ)_/¯\n");
	else if (fail == 3)
		printf(YELLOW "Something with memory ¯\\_(ツ)_/¯\n");
	else if (fail == 4)
		printf(YELLOW "Icorrect data in the file ¯\\_(ツ)_/¯\n");
	else if (fail == 5)
		printf(YELLOW "Invalid file extension ¯\\_(ツ)_/¯\n");
	else if (fail == 6)
		printf(YELLOW "File is empty ¯\\_(ツ)_/¯\n");
	else if (fail == 7)
		printf(YELLOW "Screen width or height is 0 ¯\\_(ツ)_/¯\n");
	printf(RESET);
	return (FALSE);
}
