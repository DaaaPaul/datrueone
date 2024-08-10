#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <iostream>

int main() {
	ma_engine engine;
	ma_engine_init(nullptr, &engine);

	while(true) {
		ma_engine_play_sound(&engine, "/Users/paulpeng/Downloads/Eckhart's Bell.wav", nullptr);
		sleep(300);
	}

	return 0;
}
