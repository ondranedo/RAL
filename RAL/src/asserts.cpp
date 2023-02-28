/*
	function will print the line number, file and a custom message
	can change const char if necessary
*/

#include <stdio.h>

void info(const char* message){
	
	printf("File: %s Line: %s | %s", __FILE__, __LINE__, message);
}
