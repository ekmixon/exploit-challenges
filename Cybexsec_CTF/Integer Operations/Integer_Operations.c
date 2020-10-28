/**
*
* Author: Razvi 
* Twitter: @Razvieu
* Date: February the 17th 2020
* CybexCTF 2020
*
**/

// 2147483647
// -2147483648
// 4294968633
// 4294967296
// 132654
#include<stdio.h>
#include<unistd.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#include<errno.h>

void level_1();
void level_2();
void level_3();
void level_4();

void print_cybex_header();
void print_header();
void print_separator();
void print_level_1();
void print_level_2();
void print_level_3();
void print_level_4();
void print_flag();
int random_number(int min, int max);
int random_negative_number();

int main(int argc,char **argv){

	print_cybex_header();
	print_header();

	level_1();
	level_2();
	level_3();
	level_4();
	
	printf(":) Congratulations, you passed the challenge. Here's your flag:\n");
	print_flag();
					
	return 0;
}

void level_1(){

	/**  Level 1: Basics of addition + **/
	print_level_1();

	int number_1 = random_number(1, INT_MAX);

	int user_number;

	printf("[+] Can you obtain a negative number adding a positive integer to %d?\n[+] Please insert a positive integer (decimal): ", number_1);
	fflush(stdout);

	// All numbers must be specified in decimal format
	int scanf_ret_value = scanf("%d", &user_number);

	if(scanf_ret_value <= 0){
		printf("[!] You must insert a valid number!\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else if(user_number < 0){
		printf("[!] You must insert a positive number!\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else if(errno == ERANGE) {
		printf("[!] You inserted a huge number!\n     PLEASE THINK THE LOGIC BEHING THE OPERATIONS! :)\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else {
		printf("[✓] Number %d is positive.\n", user_number);
		fflush(stdout);
	}

	int result = number_1 + user_number;
	printf("[....] %d + %d = %d\n", number_1, user_number, result);
	fflush(stdout);
	if(result >= 0){
		printf("[!] The result is not negative. Try again!\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else {
		printf("[✓] The result is %d. How's that even possible? Well... Let's move on.\n", result);
		fflush(stdout);
		print_separator();
		sleep(1);
	}
}

void level_2(){

	/**  Level 2: Basics of subtraction - **/
	print_level_2();

	int negative_number = random_negative_number();
	int user_negative_number;

	printf("[+] Can you obtain a positive integer subtracting a negative one from %d\n", negative_number);
	printf("[+] Please insert a negative integer (decimal): ");
	fflush(stdout);
	int scanf_ret_value = scanf("%d", &user_negative_number);

	if(scanf_ret_value <= 0){
		printf("[!] You must insert a valid number!\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else if(user_negative_number >= 0){
		printf("[!] You must insert a negative number!\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else if(errno == ERANGE) {
		printf("[!] You inserted a huge number!\n     PLEASE THINK THE LOGIC BEHING THE OPERATIONS! :)\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else {
		printf("[✓] Number %d is negative.\n", user_negative_number);
		fflush(stdout);
	}

	int result = negative_number - user_negative_number;
	printf("[....] %d + %d = %d\n", negative_number, user_negative_number, result);
	fflush(stdout);
	if(result <= 0){
		printf("[!] The result is not positive. Try again!\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else {
		printf("[✓] The result is %d, and it's positive :)\n", result);
		fflush(stdout);
		print_separator();
		sleep(1);
	}
}

void level_3(){
	/** Level 3: Simple Equations **/

	print_level_3();

	long long int X, Y;

	printf("[+] Insert X value (decimal):");
	fflush(stdout);
	int scanf_ret_value = scanf("%Ld", &X);

	if(scanf_ret_value <= 0){
		printf("[!] You must insert a valid number!\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else if(X < 1337){
		printf("[!] X must be bigger than 1337!\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else {
		printf("[✓] X is bigger than 1337!\n");
		printf("[+] Insert Y value (decimal):");
		fflush(stdout);
		scanf("%Ld", &Y);
		if(Y < 1337){
			printf("[!] Y must be bigger than 1337!\n");
			fflush(stdout);
			exit(EXIT_FAILURE);
		} else {
			int truncated_X = X;
			int truncated_Y = Y;

			if(truncated_X + truncated_Y != 1337){
				printf("[!] X+Y doest not equal to 1337! Try again\n");
				fflush(stdout);
				exit(EXIT_FAILURE);
			} else {
				printf("[✓] X = %d, Y= %d; X+Y = 1337\n", truncated_X, truncated_Y);
				printf("[✓] Great, you understand how truncation works! :)\n");
				fflush(stdout);
				print_separator();
				sleep(1);
			}
		}
	}
}

void level_4(){
	/** Level 4: Alternative Solutions **/

	print_level_4();

	long long user_X;
	int expected_result = 417061379;
	int subtracted_number = 153153;

	printf("[+] Insert X value (decimal): ");
	fflush(stdout);
	int scanf_ret_value = scanf("%Ld", &user_X);

	if(scanf_ret_value <= 0){
		printf("[!] You must insert a valid number!\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else if(user_X <= 1337){
		printf("[!] X must be bigger than %d!\n", 1337);
		fflush(stdout);
		exit(EXIT_FAILURE);
	} else {

		int truncated_X  = user_X*user_X; // X² (long long user_x (64 bits) * long long user_x (64 bits) truncated into int (32 bits))

		int user_result = truncated_X - subtracted_number;
		if( user_result == expected_result){
			printf("[✓] Good job! %Ld² is: %d (in 32 bits); then %Ld² - %d = %d\n", user_X, truncated_X, user_X, subtracted_number, expected_result);
			printf("[✓] Great, you do have some knowledge about how integers and primitive data types behave at memory and cpu level! :)\n");
			fflush(stdout);
			print_separator();
			sleep(1);
		} else {
			printf("[!] %Ld² - %d = %d which =/= %d! Try again\n", user_X, subtracted_number, user_result, expected_result);
			fflush(stdout);
			exit(EXIT_FAILURE);
		}
	}

}

int random_number(int min, int max){
	struct timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
	srand(time.tv_nsec);
	return (rand() % (max - min + 1)) + min;
}

int random_negative_number(){
	return random_number(0, INT_MAX) - INT_MIN;
}

void print_cybex_header(){
	printf("   _____      _                _____ _______ ______   ___   ___ ___   ___  \n");
	printf("  / ____|    | |              / ____|__   __|  ____| |__ \\ / _ |__ \\ / _ \\ \n");
	printf(" | |    _   _| |__   _____  _| |       | |  | |__       ) | | | | ) | | | |\n");
	printf(" | |   | | | | '_ \\ / _ \\ \\/ | |       | |  |  __|     / /| | | |/ /| | | |\n");
	printf(" | |___| |_| | |_) |  __/>  <| |____   | |  | |       / /_| |_| / /_| |_| |\n");
	printf("  \\_____\\__, |_.__/ \\___/_/\\_\\\\_____|  |_|  |_|      |____|\\___|____|\\___/ \n");
	printf("         __/ |                                                             \n");
	printf("        |___/                                                              \n");
}

void print_header(){

	printf("          _____       _                        \n");
	printf("          \\_   \\_ __ | |_ ___  __ _  ___ _ __  \n");
	printf("           / /\\/ '_ \\| __/ _ \\/ _` |/ _ \\ '__| \n");
	printf("        /\\/ /_ | | | | ||  __/ (_| |  __/ |    \n");
	printf("        \\____/ |_| |_|\\__\\___|\\__, |\\___|_|    \n");
	printf("                              |___/            \n");
	printf("     ___                      _   _                  \n");
	printf("    /___\\_ __   ___ _ __ __ _| |_(_) ___  _ __  ___  \n");
	printf("   //  // '_ \\ / _ \\ '__/ _` | __| |/ _ \\| '_ \\/ __| \n");
	printf("  / \\_//| |_) |  __/ | | (_| | |_| | (_) | | | \\__ \\ \n");
	printf("  \\___/ | .__/ \\___|_|  \\__,_|\\__|_|\\___/|_| |_|___/ \n");
	printf("        |_|                                          \n");
	printf("                   _            __  __ \n");
	printf("                 _| |_   _____  \\ \\/ / \n");
	printf("                |_   _| |_____|  >  <  \n");
	printf("                  |_|           /_/\\_\\ \n");
	printf("By Razvi\n");

	printf("\n[!]\n[******] PLEASE KEEP IN MIND:\n[******]\t If you fail a level you must start all over again.\n[******]\t Save your correct answers so you can insta write them.\n[!]\n");                               

	print_separator();
	fflush(stdout);
	sleep(1);

}

void print_level_1(){

printf("     _                    _   __     ______           _          \n");
printf("    | |                  | | /  | _  | ___ \\         (_)         \n");
printf("    | |     _____   _____| | `| |(_) | |_/ / __ _ ___ _  ___ ___ \n");
printf("    | |    / _ \\ \\ / / _ \\ |  | |    | ___ \\/ _` / __| |/ __/ __|\n");
printf("    | |___|  __/\\ V /  __/ | _| |__  | |_/ / (_| \\__ \\ | (__\\__ \\\n");
printf("    \\_____/\\___| \\_/ \\___|_| \\___(_) \\____/ \\__,_|___/_|\\___|___/\n");
printf("             __             _     _ _ _   _                     \n");
printf("            / _|           | |   | (_) | (_)                _   \n");
printf("       ___ | |_    __ _  __| | __| |_| |_ _  ___  _ __    _| |_ \n");
printf("      / _ \\|  _|  / _` |/ _` |/ _` | | __| |/ _ \\| '_ \\  |_   _|\n");
printf("     | (_) | |   | (_| | (_| | (_| | | |_| | (_) | | | |   |_|  \n");
printf("      \\___/|_|    \\__,_|\\__,_|\\__,_|_|\\__|_|\\___/|_| |_|        \n");

	printf("\n");
	printf("[+] Turns out you're back in school, learning what sums are.\n");
	printf("[+] There is a rumor going around about two positive integers resulting in a negative one after adding them up.\n");
	printf("[+] Could it be true?\n");
	fflush(stdout);
}

void print_level_2(){

	printf("   _                    _   _____     ______           _                   __ \n");
	printf("  | |                  | | / __  \\ _  | ___ \\         (_)                 / _|\n");
	printf("  | |     _____   _____| | `' / /'(_) | |_/ / __ _ ___ _  ___ ___    ___ | |_ \n");
	printf("  | |    / _ \\ \\ / / _ \\ |   / /      | ___ \\/ _` / __| |/ __/ __|  / _ \\|  _|\n");
	printf("  | |___|  __/\\ V /  __/ | ./ /___ _  | |_/ / (_| \\__ \\ | (__\\__ \\ | (_) | |  \n");
	printf("  \\_____/\\___| \\_/ \\___|_| \\_____/(_) \\____/ \\__,_|___/_|\\___|___/  \\___/|_|  \n");
	printf("                   _     _                  _   _                      \n");
	printf("                  | |   | |                | | (_)                     \n");
	printf("         ___ _   _| |__ | |_ _ __ __ _  ___| |_ _  ___  _ __    ______ \n");
	printf("        / __| | | | '_ \\| __| '__/ _` |/ __| __| |/ _ \\| '_ \\  |______|\n");
	printf("        \\__ \\ |_| | |_) | |_| | | (_| | (__| |_| | (_) | | | |         \n");
	printf("        |___/\\__,_|_.__/ \\__|_|  \\__,_|\\___|\\__|_|\\___/|_| |_|         \n");
	printf("\n");                                                                                                                                     
	printf("[+] Allright! Good job :)\n");
	printf("[+] Now, is it possible to obtain a positive integer from subtracting two negative ones?\n");
	fflush(stdout);
}


void print_level_3(){

	printf(" _                    _   _____     _____ _                 _      \n");
	printf("| |                  | | |____ |_  /  ___(_)               | |     \n");
	printf("| |     _____   _____| |     / (_) \\ `--. _ _ __ ___  _ __ | | ___ \n");
	printf("| |    / _ \\ \\ / / _ \\ |     \\ \\    `--. \\ | '_ ` _ \\| '_ \\| |/ _ \\\n");
	printf("| |___|  __/\\ V /  __/ | .___/ /_  /\\__/ / | | | | | | |_) | |  __/\n");
	printf("\\_____/\\___| \\_/ \\___|_| \\____/(_) \\____/|_|_| |_| |_| .__/|_|\\___|\n");
	printf("                                                     | |           \n");
	printf("                                                     |_|           \n");
	printf("                                   _   _                 \n");
	printf("                                  | | (_)                \n");
	printf("             ___  __ _ _   _  __ _| |_ _  ___  _ __  ___ \n");
	printf("            / _ \\/ _` | | | |/ _` | __| |/ _ \\| '_ \\/ __|\n");
	printf("           |  __/ (_| | |_| | (_| | |_| | (_) | | | \\__ \\\n");
	printf("            \\___|\\__, |\\__,_|\\__,_|\\__|_|\\___/|_| |_|___/\n");
	printf("                    | |                                  \n");
	printf("                    |_|                                  \n");
	printf("\n");
	printf("[+] Now let us learn about some simple equations.\n");
	printf("[+] Solve the following equation:\n");
	printf("[+] X + Y = 1337 where X > 1337 and Y > 1337\n");
	fflush(stdout);
}

void print_level_4(){

	
	printf("  _                    _     ___     _____        _     _   _             \n");
	printf(" | |                  | |   /   |_  |_   _|      (_)   | | (_)            \n");
	printf(" | |     _____   _____| |  / /| (_)   | |_      ___ ___| |_ _ _ __   __ _ \n");
	printf(" | |    / _ \\ \\ / / _ \\ | / /_| |     | \\ \\ /\\ / / / __| __| | '_ \\ / _` |\n");
	printf(" | |___|  __/\\ V /  __/ | \\___  |_    | |\\ V  V /| \\__ \\ |_| | | | | (_| |\n");
	printf(" \\_____/\\___| \\_/ \\___|_|     |_(_)   \\_/ \\_/\\_/ |_|___/\\__|_|_| |_|\\__, |\n");
	printf("                                                                     __/ |\n");
	printf("                                                                    |___/ \n");
	printf("        _   _                                  _                   \n");
	printf("       | | | |                                | |                  \n");
	printf("       | |_| |__   ___   _ __  _   _ _ __ ___ | |__   ___ _ __ ___ \n");
	printf("       | __| '_ \\ / _ \\ | '_ \\| | | | '_ ` _ \\| '_ \\ / _ \\ '__/ __|\n");
	printf("       | |_| | | |  __/ | | | | |_| | | | | | | |_) |  __/ |  \\__ \\\n");
	printf("        \\__|_| |_|\\___| |_| |_|\\__,_|_| |_| |_|_.__/ \\___|_|  |___/\n");
	printf("\n");
	printf("[+] For the final level, let us twist the numbers and see what can be achieved. Given the following equation: \n");
	printf("\t x > 1337\n");
	printf("\t x² - 153153 = 417061379\n");
	printf("[+] What's the integer X that satisfies it?\n");
	// x valid solution = 132654
	//132654^2 = 17597083716
	//17597083716 in 32 bits is 417214532; 417214532 - 153153 = 417061379
	fflush(stdout);

}

void print_separator(){
	printf("_________________________________________________________________________________________________________\n");
}

void print_flag(){
	printf("man_Im_gonna_quit_programming_who_tf_knew_signed_primitive_data_types_are_so_delicate_and_truncable\n");
}