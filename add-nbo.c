#include <stdio.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t read_num(char* f_name)
{
	FILE* f = fopen(f_name, "rb");

	fseek(f, 0, SEEK_END);
	int filesize = ftell(f);
	if(filesize < 4){
		printf("Error : file size is less than 4 bytes.\n");
		exit(0);
	}
	
	fseek(f, 0, SEEK_SET);
	uint32_t value;
	fread(&value, sizeof(uint32_t), 1, f);
	uint32_t result = ntohl(value);
	
	fclose(f);
	return result;
}

int main(int argc, char *argv[]){
	char* f1_name = argv[1];
	char* f2_name = argv[2];

	uint32_t f1_value = read_num(f1_name);
	uint32_t f2_value = read_num(f2_name);
	uint32_t sum = f1_value + f2_value;

	printf("%d\(0X%X\) + %d\(0X%X\) = %d\(0X%X\)",f1_value, f1_value, f2_value, f2_value, sum, sum);
	return 0;
}
