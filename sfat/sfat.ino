#include <Arduboy2.h>
#include <ArdVoice.h>
#include "voices.h"

Arduboy2 arduboy;
ArdVoice ardvoice;

uint8_t lastbutton;


void printVoice(uint8_t button){
  switch (button) {
    case UP_BUTTON :
    arduboy.print("Ass.");
    break;

    case DOWN_BUTTON :
    arduboy.print("Fuck.");
    break;

    case A_BUTTON:
    arduboy.print("voice stopped");
    break;

    case B_BUTTON:
    arduboy.print("Shitfuckass tiiiits");
    break;

    case LEFT_BUTTON:
    arduboy.print("Ah, shit...");
    break; 

    case RIGHT_BUTTON:
    arduboy.print("God damn it...");
    break;
  }
}
void setup() {
	arduboy.begin();
	arduboy.setFrameRate(30);
	ardvoice.playVoice(sfat_q4, 0, 2317, 0.55);
  lastbutton = B_BUTTON;
}


void loop() {
	if (!(arduboy.nextFrame()))
		return;
  arduboy.clear();
	if (arduboy.pressed(B_BUTTON)){
		ardvoice.playVoice(sfat_q4, 0, 2317, 0.55);
    lastbutton = B_BUTTON;
	}

	if (arduboy.pressed(A_BUTTON)){
		ardvoice.stopVoice();
    lastbutton = A_BUTTON;
	}
  if (arduboy.pressed(UP_BUTTON)){
    ardvoice.playVoice(audio_q4, 0, 990, 0.7);
    lastbutton = UP_BUTTON;
  }
  if (arduboy.pressed(RIGHT_BUTTON)){
    ardvoice.playVoice(gdi_q6, 0, 1012, 0.7);
    lastbutton = RIGHT_BUTTON;
  }
  if (arduboy.pressed(DOWN_BUTTON)){
		ardvoice.playVoice(fuck_q7, 0, 742, 0.7);
    lastbutton = DOWN_BUTTON;
	}
  if (arduboy.pressed(LEFT_BUTTON)){
		ardvoice.playVoice(ahshithigh_q5, 0, 1395, 0.6);
     lastbutton=LEFT_BUTTON;
	}
  printVoice(lastbutton);
  arduboy.display();
}

