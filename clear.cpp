#include "cmds.h"
/*
This is a simple test of clearing the screen with the function in cmds.h clear(), it works by using ansi escape sequences to clear the screen.
*/
int main() {
    commands::clear();
    return 0;
}
