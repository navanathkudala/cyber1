#include <stdio.h>

int check_third_key(char *input)
{
		int ret = 0;
		char buf[12];
		char key[12] = "KEY_IS_12345";
		int homemade_stack_protector = (int)*(&homemade_stack_protector + 11);

		strcpy(buf, input);
		
		if(strncmp(key, buf, sizeof(key)) == 0) {
				printf("Your key#3 is matched!!\n");
				ret = 1;
		} else {
				ret = 0;
		}

		if(homemade_stack_protector != (int)*(&homemade_stack_protector + 11))
		{
				printf("The stack has been broken! Emergency Escape!\n");
				exit(0);
		}

		return ret;
}


int check_second_key(char *input)
{
		char buf[12];
		char key[12] = "KEY_IS_12345";
		
		strcpy(buf, input);
		
		if(strncmp(key, buf, sizeof(key)) == 0) {
				return 1;
		}

		return 0;
}

int check_first_key(char *input)
{
		char key[12] = "KEY_IS_12345";
		char buf[12];
		
		strcpy(buf, input);
		
		if(strncmp(key, buf, sizeof(key)) == 0) {
				return 1;
		}

		return 0;
}


int main(int argc, char **argv)
{
		int ret;

		if(argc != 4) {
				printf("Usage: %s [key#1] [key#2] [key#3]\n");
				return 0;
		}
		
		ret = 0;
  ret = check_first_key(argv[1]);
		if(ret == 1) {
				printf("Your FLAG#1 is FLG123.\n");
		} else {
				printf("Your key#1 is INCORRECT! Try again!\n");
				return 0;
		}

		ret = 0;
	 ret = check_second_key(argv[2]);
		if(ret != 1) {
				printf("Your key#2 is INCORRECT! Try again!\n");
				return 0;
		} else {
				printf("Your FLAG#2 is FLG456.\n");
		}

		ret = 0;
		check_third_key(argv[3]);

		if(ret == 0) {
				printf("Your key#3 is INCORRECT! Try again!\n");
				return 0;
		} else {
				printf("Your FLAG#3 is FLG789.\n");
		}
		printf("Congraturations!! Your retrieved all Flags!!\n");

		return 0;
}

