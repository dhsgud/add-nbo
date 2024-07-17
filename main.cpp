#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <arpa/inet.h>



uint32_t read_int(char *filename) {
	FILE *fp;
	uint32_t number;
	fp = fopen(filename, "rb");
	fread(&number, sizeof(uint32_t), 1, fp);
	fclose(fp);
//	printf("%x\n", number); e803, f401 nthol -> 03e8, 014f
	return ntohl(number);
	//return number;
	//return htonl(number);
}


int main(int argc, char *argv[]) {
	uint32_t real = read_int(argv[1]);
	uint32_t real2 = read_int(argv[2]);
	uint32_t sum;
	sum = real + real2;
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)", real, real, real2, real2, sum, sum);

	return 0;
}
