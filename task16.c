#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

char reply();

main(){
    printf("Select any symbol: ");
    char c = reply();
    printf("\nYou've selected: %c\n", c);
}

char reply(){
    char c;
    struct termios tty, savtty;
    fflush(stdout);
    tcgetattr(0, &tty);
    savtty = tty;
    tty.c_lflag &= ~(ISIG | ICANON);
    tty.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &tty);
    read(0, &c, 1);
    tcsetattr(0, TCSANOW, &savtty);
    return c;
}