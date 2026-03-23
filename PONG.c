//Pong in the terminal made by heart and without ai

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <signal.h>
#include <string.h>


//https://www.youtube.com/watch?v=WvSOSyi5lWY 19:00

static struct termios old_termios, new_termios;


void reset_terminal() {
    printf("\e[m"); // reset color changes
    printf("\e[?25h"); // show cursor
    printf("\e[%d;%dH\n", MAX_Y + 3, MAX_X); // move cursor after game board
    fflush(stdout);
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}

void configure_terminal() {
    tcgetattr(STDIN_FILENO, &old_termios);
    new_termios = old_termios; // copie de l'ancien terminal
	
    new_termios.c_lflag &= ~(ICANON | ECHO); // turn off echo + non-canonical mode
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 0;


    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    printf("\e[?25l"); // hide cursor
    atexit(reset_terminal);
}
int main() {
	Configure_terminal();
	
	while (1) {
		key = read_input();
		print_key(key);
		sleep(0.1seconds)
	}
}
