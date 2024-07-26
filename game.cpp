#include <iostream>
#include <cstdlib>
#include <ctime>
#include <emscripten/emscripten.h>

int secretNumber;
int attempts;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    void initGame() {
        std::srand(std::time(nullptr));
        secretNumber = std::rand() % 100 + 1;
        attempts = 0;
    }

    EMSCRIPTEN_KEEPALIVE
    int makeGuess(int guess) {
        attempts++;
        if (guess < secretNumber) return -1;
        if (guess > secretNumber) return 1;
        return 0;
    }

    EMSCRIPTEN_KEEPALIVE
    int getAttempts() {
        return attempts;
    }
}