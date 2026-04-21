#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <random>
#include <vector>
#include <fstream>

struct Time {
	uint32_t minutes{};
	uint32_t seconds{};

	static Time decrement(Time const& T) noexcept {
		Time t = T;

		if(t.seconds > 0) {
			t.seconds--;
		} else {
			t.minutes--;
			t.seconds = 59;
		}

		return t;
	}

	static std::string toString(uint32_t const& MS) {
		std::string str{};
		if(MS < 10) {
			str = std::string("0") + std::to_string(MS);
		} else {
			str = std::to_string(MS);
		}
		return str;
	}
	friend std::ostream& operator<<(std::ostream& os, const Time& time);
};

std::ostream& operator<<(std::ostream& os, const Time& time) {
	os << Time::toString(time.minutes) << ":" << Time::toString(time.seconds);
    return os;
}

double random() noexcept {
	static std::default_random_engine gEngine(static_cast<unsigned>(time(nullptr)));
	static std::uniform_real_distribution gRange(0.0f, 1.0f);

	return gRange(gEngine);
}

void putFile(const std::string& name, const std::string& content, bool append = true) {
    std::ofstream outfile;
    if (append)
        outfile.open(name, std::ios_base::app);
    else
        outfile.open(name);
    outfile << content;
}

std::vector<std::pair<std::string, std::string>> msgs{
	{"Hey chud! Did you ", "?"},
	{"Don't worry, you're only going to hell if you didn't ", "."},
	{"You're going to heaven actually. But you did ", " right?"},
	{"It's not easy when it's hard, especially when you have to ", "."},
	{"The journey is the reward when you're trying to ", "."},
	{"Success or fail: ", ""},
	{"Just did it (or not): ", ""}
};

int main() {
	ma_engine engine;
	ma_engine_init(nullptr, &engine);

	std::string goal{};
	std::cout << "GOAL: ";
	std::getline(std::cin, goal);

	double minutes{};
	std::cout << "MINUTES: ";
	std::cin >> minutes;

	double pureMinutes{};
	double decimal = std::modf(minutes, &pureMinutes);

	Time timeLeft{pureMinutes, decimal * 60.0};
	std::string initialTimeLeft = Time::toString(timeLeft.minutes) + ":" + Time::toString(timeLeft.seconds);

	ma_engine_play_sound(&engine, R"(C:\Users\paulp\datrueoneFiles\DUCKSWORTH.mp3)", nullptr);
		
	while(timeLeft.minutes > 0 || timeLeft.seconds > 0) {
		std::cout << timeLeft << "\n";
		timeLeft = Time::decrement(timeLeft);
		Sleep(1000);
	}
	std::cout << timeLeft << "\n";

	ma_engine_play_sound(&engine, R"(C:\Users\paulp\datrueoneFiles\Tolle Bell.mp3)", nullptr);
	std::pair<std::string, std::string> msg = msgs[random() * 7.0];
	std::cout << msg.first + goal + msg.second + " ";
	std::string result{};
	std::getline(std::cin, result);

	putFile(R"(C:\Users\paulp\datrueoneFiles\Tally.txt)", msg.first + goal + msg.second + " " + result + " (" + initialTimeLeft + ")\n");
}
