#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <random>
#include <csignal>
#include <vector>
#include <fstream>

struct Clock {
	uint32_t minutes{};
	uint32_t seconds{};

	static Clock decrement(Clock const& T) noexcept {
		Clock t = T;

		if(t.seconds > 0) {
			t.seconds--;
		} else {
			t.minutes--;
			t.seconds = 59;
		}

		return t;
	}

	static std::string digitsString(uint32_t const& MS) {
		std::string str{};
		if(MS < 10) {
			str = std::string("0") + std::to_string(MS);
		} else {
			str = std::to_string(MS);
		}
		return str;
	}

	static std::string toString(Clock const& T) {
		return Clock::digitsString(T.minutes) + ":" + Clock::digitsString(T.seconds);
	}

	friend std::ostream& operator<<(std::ostream& os, const Clock& gClock);
};

std::ostream& operator<<(std::ostream& os, const Clock& gClock) {
	os << Clock::toString(gClock);
    return os;
}

void putFile(const std::string& name, const std::string& content, bool append = true) {
    std::ofstream outfile;
    if (append)
        outfile.open(name, std::ios_base::app);
    else
        outfile.open(name);
    outfile << content;
}

float random() {
	static std::default_random_engine gEngine(static_cast<unsigned>(time(nullptr)));
	static std::uniform_real_distribution gRange(0.0f, 1.0f);

	return gRange(gEngine);
}

std::vector<std::pair<std::string, std::string>> endMsgs{
	{"Hey chud! Did you ", "?"},
	{"Don't worry, you're only going to hell if you didn't ", "."},
	{"You're going to heaven actually. But you did ", " right?"},
	{"It's not easy when it's hard, especially when you have to ", "."},
	{"The journey is the reward when you're trying to ", "."},
	{"Success or fail: ", ""},
	{"Just did it (or not): ", ""}
};

std::vector<std::string> earlyMsgs{
	"You know what they say... Early bird gets the worm!",
	"Godspeed!",
	"Yeah I'm going hard today cuz for me you would be a calllll away!!",
	"Tsssk. Not enough. You're better.",
};

const std::string TALLY_PATH = R"(C:\Users\paulp\datrueoneFiles\Tally.txt)";
const std::string START_PATH = R"(C:\Users\paulp\datrueoneFiles\DUCKSWORTH.mp3)";
const std::string FINISH_PATH = R"(C:\Users\paulp\datrueoneFiles\Tolle Bell.mp3)";
const std::string EARLY_FINISH_PATH = R"(C:\Users\paulp\datrueoneFiles\GHOSTEMANE.mp3)";

Clock gClock{};
std::string gGoal{};
std::string gGiven{};
bool gQuit = false;

void ctrlC(int x) {
	gQuit = true;
}

int main() {
	ma_engine engine;
	ma_engine_init(nullptr, &engine);

	std::cout << "GOAL: ";
	std::getline(std::cin, gGoal);

	double minutes{};
	std::cout << "MINUTES: ";
	std::cin >> minutes;

	double pureMinutes{};
	double decimal = std::modf(minutes, &pureMinutes);
	gClock.minutes = pureMinutes;
	gClock.seconds = decimal * 60.0;
	gGiven = Clock::toString(gClock);

	ma_engine_play_sound(&engine, START_PATH.c_str(), nullptr);
	signal(SIGINT, ctrlC);

	while ((!gQuit) && ((gClock.minutes > 0) || (gClock.seconds > 0))) {
		std::cout << gClock << "\n";
		gClock = Clock::decrement(gClock);
		Sleep(1000);
	}
	std::cout << gClock << "\n";

	if(gQuit) {
		ma_engine_play_sound(&engine, EARLY_FINISH_PATH.c_str(), nullptr);
		std::string msg = earlyMsgs[random() * 4.0];

		std::cout << msg << " ";

		std::string input{};
		std::getline(std::cin, input);
		std::getline(std::cin, input);

		std::string early = Clock::toString(gClock);

		putFile(TALLY_PATH, gGoal + ":" + input + " (" + gGiven + " stopped at " + early + ")\n");
	} else {
		ma_engine_play_sound(&engine, FINISH_PATH.c_str(), nullptr);
		std::pair<std::string, std::string> msg = endMsgs[random() * 7.0];
		std::cout << msg.first + gGoal + msg.second + " ";
		std::string input{};
		std::getline(std::cin, input);
		std::getline(std::cin, input);

		putFile(TALLY_PATH, gGoal + ":" + input + " (" + gGiven + ")\n");
	}
}
