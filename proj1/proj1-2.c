#include <stdio.h>

void key_gen(char *k, int seed);
void print_flag();

int check_key(char *in)
{
		struct Myset {
				char key[8];
				char input[8];
				int seed;
		};

		struct Myset s;

		s.seed = time(NULL);
		strcpy(s.input, in);
		key_gen(s.key, s.seed);

		printf("Your Key \"");
		printf(in);
		if(strncmp(s.input, s.key, 7) == 0) {
				printf("\" matched!!\n");
				return 1;
		}

		printf("\" does not match! Try again!\n");
		return 0;
}


int main(int argc, char **argv)
{
		int ret;

		if(argc != 2) {
				printf("Usage: %s [key]\n");
				return 0;
		}
		ret = check_key(argv[1]);	

		if(ret == 1) {
				print_flag();
		}
		
		return 0;
}

