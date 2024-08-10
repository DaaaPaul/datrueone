#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <iostream>

int main() {
	ma_engine engine;
	ma_engine_init(nullptr, &engine);

	while(true) {
		sleep(3600);
		ma_engine_play_sound(&engine, "/Users/paulpeng/Downloads/TheFatRat's Horn.wav", nullptr);
	}
}
