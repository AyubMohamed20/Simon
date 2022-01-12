#include "FinalCPPProject.h"

void generateSequence(vector<int>& sequence, audio::player &gAudio, audio::player &rAudio, audio::player &yAudio, audio::player &bAudio, button& redBtn, button& blueBtn, button& greenBtn, button& yellowBtn, form fm) {
    
	srand((unsigned int)time(NULL));
	int	next = rand() % 4;
	int i; 

	switch (next) {
	case 0:
		sequence.push_back(0);
		break;
	case 1:
		sequence.push_back(1);
		break;
	case 2:
		sequence.push_back(2);
		break;
	case 3:
		sequence.push_back(3);
		break;
	}

	for (int i = 0; i < sequence.size(); i++) {
		switch (sequence[i]) {
		case 0:
			greenBtn.bgcolor(color(144, 238, 144));
			fm.activate();
			gAudio.play();
			_sleep(500);
			greenBtn.bgcolor(color(0, 255, 0));
			break;
		case 1:
			redBtn.bgcolor(color(255, 204, 203));
			fm.activate();
			rAudio.play();
			_sleep(500);
			redBtn.bgcolor(color(255, 0, 0));
			break;
		case 2:
			yellowBtn.bgcolor(color(255, 255, 224));
			fm.activate();
			yAudio.play();
			_sleep(500);
			yellowBtn.bgcolor(color(255, 255, 0));
			break;
		case 3:
			blueBtn.bgcolor(color(173, 216, 230));
			fm.activate();
			bAudio.play();
			_sleep(500);
			blueBtn.bgcolor(color(0, 0, 255));
			break;
		}
	}

}

void check(vector<int>& sequence, int num, int& count, int &Level, audio::player &gAudio, audio::player &rAudio, audio::player &yAudio, audio::player &bAudio, audio::player &gameOver, audio::player &correct, button& redBtn, button& blueBtn, button& greenBtn, button& yellowBtn, form fm) {

	if (sequence.at(count) == num) {
		count++;
		if (count == sequence.size()) {
			correct.play();
			count = 0;
			Level++;
			generateSequence(sequence, gAudio, rAudio, yAudio, bAudio, redBtn, blueBtn, greenBtn, yellowBtn, fm);
		}
	}
	else {
		gameOver.play();

		form newForm;

		string score = "Sorry, wrong colour. You made it to round ";
		score += to_string(Level);
		score.append(" of the game");

		label gameOverLabel{ newForm ,score};
		button playAgainBtn{ newForm, "Play Again" };
		button exitBtn{ newForm, "Exit" };

		newForm.div("vert <gameOverLabel><playAgain><exit>");
		
		newForm["gameOverLabel"] << gameOverLabel;
		newForm["playAgain"] << playAgainBtn;
		newForm["exit"] << exitBtn;

		playAgainBtn.events().click([&] 
			{
				count = 0; 
				Level = 1; 
				sequence.clear();
				newForm.close();

			});

		exitBtn.events().click([&] {API::exit_all(); });

		newForm.collocate();
		newForm.show();
		exec();
		
	}

}

int main()
{
	form fm;

	label lab{ fm, "SIMON" };
	lab.format(true);

	vector<int> sequence;
	int Level = 1;
	int count = 0;

	button startGameBtn{ fm, "StartGame" };
	button redBtn{ fm, "Red" };
	button greenBtn{ fm, "Green" };
	button blueBtn{ fm, "Blue" };
	button yellowBtn{ fm, "Yellow" };

	redBtn.bgcolor(color(255, 0, 0));
	greenBtn.bgcolor(color(0, 255, 0));
	blueBtn.bgcolor(color(0, 0, 255));
	yellowBtn.bgcolor(color(255, 255, 0));

	audio::player gAudio("resources/Do_Piano.wav");
	audio::player rAudio("resources/Re_Piano.wav");
	audio::player bAudio("resources/Fa_Piano.wav");
	audio::player yAudio("resources/Mi_Piano.wav");
	audio::player gameOver("resources/GameOverAudio.wav");
	audio::player correct("resources/correctSoundEffect.wav");

	greenBtn.events().click([&] {
		gAudio.play();
		check(sequence, 0, count, Level, gAudio, rAudio, yAudio , bAudio, gameOver, correct, redBtn,blueBtn,greenBtn,yellowBtn, fm);
		});

	redBtn.events().click([&] {
		rAudio.play();
		check(sequence, 1, count, Level, gAudio, rAudio, yAudio, bAudio, gameOver, correct, redBtn, blueBtn, greenBtn, yellowBtn,fm);
		});

	yellowBtn.events().click([&] {
		yAudio.play();
		check(sequence, 2, count, Level, gAudio, rAudio, yAudio, bAudio, gameOver, correct, redBtn, blueBtn, greenBtn, yellowBtn,fm);
		});

	blueBtn.events().click([&] {
		bAudio.play();
		check(sequence, 3, count, Level, gAudio, rAudio, yAudio, bAudio, gameOver, correct, redBtn, blueBtn, greenBtn, yellowBtn,fm);
		});


	startGameBtn.events().click([&]
		{
			generateSequence(sequence, gAudio, rAudio, yAudio, bAudio, redBtn, blueBtn, greenBtn, yellowBtn,fm);
		});

	fm.div("vert <AA><StartGame><<GREEN><RED>><<YELLOW><BLUE>>");
	fm["AA"] << lab;
	fm["StartGame"] << startGameBtn;
	fm["RED"] << redBtn;
	fm["GREEN"] << greenBtn;
	fm["BLUE"] << blueBtn;
	fm["YELLOW"] << yellowBtn;


	fm.collocate();

	fm.show();

	exec();
}


