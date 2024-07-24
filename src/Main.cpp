#include "Enigma.h"

int main() {
    Enigma enigma;
    enigma.input_plugs("A:B C:D");
    enigma.print_state();
}