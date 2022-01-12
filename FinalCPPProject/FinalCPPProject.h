// FinalCPPProject.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/audio/player.hpp>
#include <nana/threads/pool.hpp>
#include <nana/gui/timer.hpp>
#include <iostream>
#include <stdlib.h>  
#include <stdio.h>
#include <thread>

using namespace nana;
using namespace std;

// TODO: Reference additional headers your program requires here.

void generateSequence(vector<int>& sequence, audio::player& gAudio, audio::player& rAudio, audio::player& yAudio, audio::player& bAudio, button& redBtn, button& blueBtn, button& greenBtn, button& yellowBtn, form fm);
void check(vector<int>& sequence, int num, int& count, int& Level, audio::player& gAudio, audio::player& rAudio, audio::player& yAudio, audio::player& bAudio, audio::player& gameOver, audio::player& correct, button& redBtn, button& blueBtn, button& greenBtn, button& yellowBtn, form fm);