#include <ncurses.h>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void displayText(WINDOW * textwin, WINDOW * textwin2 , string story);
void action(string options[5], WINDOW * textwin, WINDOW * textwin2);
void fly(WINDOW * textwin, WINDOW * textwin2);
void crash(WINDOW * textwin, WINDOW * textwin2);
void die(WINDOW * textwin, WINDOW * textwin2);
void burial(WINDOW * textwin, WINDOW * textwin2);
void zombie(WINDOW * textwin, WINDOW * textwin2);
void gameOver(WINDOW * textwin, WINDOW * textwin2);
void kite(WINDOW * textwin, WINDOW * textwin2);
void clouds(WINDOW * textwin, WINDOW * textwin2);
void man(WINDOW * textwin, WINDOW * textwin2);
int main(int argc, char ** argv)
{
	initscr();
	noecho();
	cbreak();
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);

	//making a menu for the start of the game
	int height, width, starty, startx;
	height = 4; width = 20;
	getmaxyx(stdscr, starty, startx);
	WINDOW * menu = newwin(height, width, 0, (startx/2)-10);

	box(menu, 0, 0);	/*making a box on the menu and shows it*/
	refresh();
	wrefresh(menu);

	//////making the box and window for my story.////////
	int h, w, yMax, xMax;
	h = 10; w = 30;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW * textwin = newwin(h, xMax-10, (yMax)-10, 5);

	WINDOW * textwin2 = newwin(h-2, xMax-12, (yMax)-9, 6);
	string scen0 = "Once upon a time, there was a girl who went out in the woods at night. The girl then heard an eerie sound and she started running. When the girl started running, she didn't realize there was a hole. As the girl kept running, she fell in the hole. The girl was lost and her family reported her missing. The police and investigators did the best they could to find her, but she was never found. The girl was sadly claimed as dead.";
	///////////////////////////////////////////////////

	keypad(menu, true);
	string choices[2] = {"Start Game", "Exit"};

	int choice;
	int highlight = 0;
	int quit = 0;

	while(quit != 1)
	{
		for(int i = 0; i < 2; i++)
		{
			if(i == highlight)
				wattron(menu, A_REVERSE);
			mvwprintw(menu, i+1, 1, "%s", choices[i].c_str());
			wattroff(menu, A_REVERSE);
		}
			
		choice = wgetch(menu);

		switch(choice)
		{
			case KEY_UP: 
				highlight--;
				if(highlight < 0)
					highlight = 0;
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight > 1)
					highlight = 1;
				break;
			default:
				break;
		}
		
		if(choice == 27)
			quit = 1;
		if(choice == 10)
		{
			if(choices[highlight] == "Exit")
			{
				quit = 1;
				break;
			}
			else if(choices[highlight] == "Start Game")
			{
				mvprintw(0,0, "Welcome to the Game");
				refresh();
				displayText(textwin, textwin2, scen0);
				string options[5] = {"Fly", "Kite", "Stay", "RUN!!", "..."};
				action(options, textwin, textwin2);

			}
		}
	}
	//mvprintw(0,0, "Welcome to the Game");

	getch();
	endwin();
}

void action(string options[5], WINDOW * textwin, WINDOW * textwin2)
{
	int height, width, starty, startx;
	height = 6; width = 10;
	getmaxyx(stdscr, starty, startx);
	WINDOW * action = newwin(height, width, 6, (startx/2)-10);

	box(action, 0, 0);	/*making a box on the menu and shows it*/
	refresh();
	wrefresh(action);

	keypad(action, true);
	int choice;
	int highlight = 0;

	string fly_ = "To their dismay, the girl did not die. Instead, she is stuck hovering in the sky. When the girl used her last amount of strength, she got up from the deep hole and saw a shining light. She opened her eyes and saw an alicorn. She went to the alicorn and got on its back. Then, the alicorn flew off into the sky and took the girl wherever she wanted to go.";

	string crash_ = "However, as the girl was flying on the alicorn, a very strong storm occurred and the girl and alicorn were struggling to stay in the sky. As they were flying, a strong wind hit them and both of them crashed and fell into the sea.";

	string survive_ = "DO YOU REALLY THINK THIS FALL IS SURVIVABLE??\n";
	survive_ += "As the girl and alicorn fell into the sea, both began to drown and failed to reach shore. They couldn't breath and both sadly died in the sea. They drowned all the way to the bottom of the sea and they were never seen after a while.";

	string die_ = "As the girl and alicorn fell into the sea, both began to drown and failed to reach shore. They couldn't breath and both sadly died in the sea. They drowned all the way to the bottom of the sea and they were never seen after a while.";
	
	string abandoned_ = "When the girl and the alicorn fell into sea, they were rushed below and drowned. After such a long time, they were never found ever again. Even through research and investigation, after 30 years, police and investigators gave up and claimed their case as dead.";

	string burial_ = "A year after their drowning, investigators were searching the area. As they went underwater to observe, they suddenly found the girl that went missing for a year, and her alicorn that she rode. The investigators contacted the police and the girls family, and they were taken out of the sea. The family arranged a funeral for the girl and alicorn the next day.";

	string afterlife_ = "All of a sudden, the girl woke up to find herself in the afterlife. Then, she saw two buttons. Reincarnate or rest. After a long decision, the girl chose the button to reincarnate. Then, she woke up and saw a light.";

	string zombie_ = "After quite a while, the girl suddenly woke up to find herself underground. She quickly got up and fought her way out. When she escaped her grave, she saw herself to be a walking zombie! As she ran out the graveyard, she saw many people, craving for their brains. Once the people noticed the zombie, they all quickly contacted the police. The police came as quick as possible and once they got her under control, they shot her to her death and everything became a blur.";

	string kite_ = "However, little did they know that the girl somehow survived. As the girl climbed out the whole, she saw something mysterious. It was a strange blue kite that was glowing. The girls curiosity lead her to walking towards the kite and picking it up. Suddenly, the girl and the kite both vanished into thin air.";

	string clouds_ = "The girl found herself on a cloud. When she got up, she suddenly fell through the clouds. Her life flashed through her eyes, but suddenly, she fell on something that caught her. As she caught her breath and vision, she realized that she fell on a farm where a village was in sight. As the girl got up, she noticed a man in a barn and headed towards the man.";
	
	string man_ = "Once the girl went up to the man, the man turned around and was shocked to see such a mysterious girl out of no where. The man asked the girl where she was from and why she was at his farm on his property. The girl responded that she got lost and didn't know how to get to her way back home. She asked the man if he could help her. At first, the man was hesitant to help a girl he didn't know, but then he gave in and agreed to help her.";

	while(1)
	{
		box(action, 0, 0);	/*making a box on the menu and shows it*/
		refresh();
		wrefresh(action);

		for(int i = 0; i < 5; i++)
		{
			if(i == highlight)
				wattron(action, A_REVERSE);
			mvwprintw(action, i+1, 1, "%s", options[i].c_str());
			wattroff(action, A_REVERSE);
		}
			
		choice = wgetch(action);

		switch(choice)
		{
			case KEY_UP: 
				highlight--;
				if(highlight < 0)
					highlight = 0;
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight > 4)
					highlight = 4;
				break;
			default:
				break;
		}
		
		if(choice == 27)
			break;
		if(choice == 10)
		{
			if(options[highlight] == "Fly")
			{
				displayText(textwin, textwin2, fly_);
				fly(textwin, textwin2);
				break;
			}
			if(options[highlight] == "Crash")
			{
				displayText(textwin, textwin2, crash_);
				crash(textwin, textwin2);
				break;
			}
			if(options[highlight] == "Survive")
			{
				displayText(textwin, textwin2, survive_);
				die(textwin, textwin2);
				break;
			}
			if(options[highlight] == "Die")
			{
				displayText(textwin, textwin2, die_);
				die(textwin, textwin2);
				break;
			}
			if(options[highlight] == "Abandoned")
			{
				displayText(textwin, textwin2, abandoned_);
				getch();
				gameOver(textwin, textwin2);
				break;
			}
			if(options[highlight] == "Burial")
			{
				displayText(textwin, textwin2, burial_);
				burial(textwin, textwin2);
				break;
			}
			if(options[highlight] == "Afterlife")
			{
				displayText(textwin, textwin2, afterlife_);
				getch();
				gameOver(textwin, textwin2);
				break;
			}
			if(options[highlight] == "Zombie")
			{
				displayText(textwin, textwin2, zombie_);
				zombie(textwin, textwin2);
				break;
			}
			if(options[highlight] == "Kite")
			{
				displayText(textwin, textwin2, kite_);
				kite(textwin, textwin2);
				break;
			}
			if(options[highlight] == "Clouds")
			{
				displayText(textwin, textwin2, clouds_);
				clouds(textwin, textwin2);
				break;
			}
			if(options[highlight] == "Man")
			{
				displayText(textwin, textwin2, man_);
				man(textwin, textwin2);
				break;
			}
			mvwprintw(stdscr, 1, 1, "%s", options[highlight].c_str());
			refresh();
		}
		wclear(action);
		wrefresh(action);
		refresh();
		
			
	}
}

void displayText(WINDOW * textwin, WINDOW * textwin2, string story)
{
	box(textwin, 0, 0);
	refresh();
	wrefresh(textwin);
	
	wclear(textwin2);
	
	wrefresh(textwin2);
	mvwprintw(textwin2, 0,0, "%s", story.c_str());
	wrefresh(textwin2);
	//getch();
	//wclear(textwin2);
	//wrefresh(textwin2);
	//getch();
	
}

void fly(WINDOW * textwin, WINDOW * textwin2)
{
	attron(A_BOLD);
	mvwprintw(textwin, 0,3, "Fly");
	attroff(A_BOLD);

	//added colors to certain words
	mvwchgat(textwin2, 0,26, 11, A_REVERSE, 2,NULL);
	wrefresh(textwin);
	wrefresh(textwin2);
	string options[5] = {"Crash", "Land", "Spinning", "...", "..."};
	action(options, textwin, textwin2);	
}
void crash(WINDOW * textwin, WINDOW * textwin2)
{
	attron(A_BOLD);
	mvwprintw(textwin, 0,3, "Crash");
	attroff(A_BOLD);

	mvwchgat(textwin2, 2,63,7, A_REVERSE, 1,NULL);
	mvwchgat(textwin2, 3,0,2, A_REVERSE, 1,NULL);
	mvwchgat(textwin2, 3,7,4, A_REVERSE, 1,NULL);
	wrefresh(textwin);
	wrefresh(textwin2);
	string options[5] = {"Survive", "Die", "...", "...", "..."};
	action(options, textwin, textwin2);
}
void die(WINDOW * textwin, WINDOW * textwin2)
{
	attron(A_BOLD);
	mvwprintw(textwin, 0,3, "Die");
	attroff(A_BOLD);
	wrefresh(textwin);
	string options[5] = {"Abandoned", "Burial", "...", "...", "..."};
	action(options, textwin, textwin2);
}
void burial(WINDOW * textwin, WINDOW * textwin2)
{
	attron(A_BOLD);
	mvwprintw(textwin, 0,3, "Burial");
	attroff(A_BOLD);
	wrefresh(textwin);
	string options[5] = {"Afterlife", "Zombie", "...", "...", "..."};
	action(options, textwin, textwin2);
}
void zombie(WINDOW * textwin, WINDOW * textwin2)
{
	attron(A_BOLD);
	mvwprintw(textwin, 0,3, "Zombie");
	attroff(A_BOLD);
	wrefresh(textwin);
	string options[5] = {"...", "...", "Afterlife", "...", "..."};
	action(options, textwin, textwin2);
}
void kite(WINDOW * textwin, WINDOW * textwin2)
{
	attron(A_BOLD);
	mvwprintw(textwin, 0,3, "Kite");
	attroff(A_BOLD);
	wrefresh(textwin);
	string options[5] = {"Clouds", "Rainbow", "Cave" "...", "..."};
	action(options, textwin, textwin2);
}
void clouds(WINDOW * textwin, WINDOW * textwin2)
{
	attron(A_BOLD);
	mvwprintw(textwin, 0,3, "Clouds");
	attroff(A_BOLD);
	wrefresh(textwin);
	string options[5] = {"Man", "Invisible", "..." "...", "..."};
	action(options, textwin, textwin2);
}
void man(WINDOW * textwin, WINDOW * textwin2)
{
	attron(A_BOLD);
	mvwprintw(textwin, 0,3, "Man");
	attroff(A_BOLD);
	wrefresh(textwin);
	string options[5] = {"Castle", "Lake", "..." "...", "..."};
	action(options, textwin, textwin2);
}

void gameOver(WINDOW * textwin, WINDOW * textwin2)
{
	string gameOver = "You've reached the end click Start Game to play again";
	displayText(textwin, textwin2, gameOver);
	attron(A_BOLD);
	mvwprintw(textwin, 0,3, "gameOver");
	attroff(A_BOLD);
	wrefresh(textwin);
}