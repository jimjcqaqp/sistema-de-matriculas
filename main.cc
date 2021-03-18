#include "Form.h"
#include "menu_admin.h"
#include "menu_teacher.h"
#include "menu_student.h"

#define DEFAULT_WIDTH	90
#define DEFAULT_HEIGHT 26

void init();

int main()
{
	initscr();
	init();
	endwin();
	return 0;
}

void init()
{
	WINDOW *window;
	std::string title = "S I S T E M A   D E   M A T R I C U L A S";
	int globalw, globalh;
	getmaxyx(stdscr, globalh, globalw);
	window = newwin(DEFAULT_HEIGHT, DEFAULT_WIDTH, 
			(globalh - DEFAULT_HEIGHT)/2, (globalw - DEFAULT_WIDTH)/2);
	box(window, 0, 0);

	mvwaddch(window, 2, 0, ACS_LTEE);
	mvwhline(window, 2, 1, ACS_HLINE, DEFAULT_WIDTH - 2);
	mvwaddch(window, 2, DEFAULT_WIDTH - 1, ACS_RTEE);
	mvwprintw(window, 1, (DEFAULT_WIDTH - title.size()) / 2, title.c_str());

	wrefresh(window);

 	Menu menu;
	menu.w = 30;
	menu.parent = window;
	menu.hc = menu.vc = true;
	menu.add("Administrador");
	menu.add("Profesor");
	menu.add("Estudiante");
	menu.header = "Menu principal";
	menu.footer = "(q) para cancelar";
	menu.addkey('q');

	int index = 0;
	while(true)
	{	
		if(menu.running() == false)
			index = menu.start();
		else
			index = menu.resume();

		if(menu.keypress == 'q')
		{
			menu.resetkey();

			Dialog dconfirm;
			dconfirm.w = 40;
			dconfirm.parent = window;
			dconfirm.hc = dconfirm.vc = true;
			dconfirm.addlinebody("Esta seguro que desea salir?");
			if(dconfirm.start() == DIALOG_OK)
				break;
			else
				continue;
		}
		Form form;
		form.parent = window;
		form.addquittext("q");
		form.vc = form.hc = true;
		form.w = 30;
		form.header = "Login";
		form.footer = "(q) cancelar";
		form.addInput("Code", INPUT_STRING, 10);
		form.addInput("Password", INPUT_PASSWORD, 10);
		form.addquittext("q");
		
		if(index == 0) form.header = "Login administrador";
		if(index == 1) form.header = "Login profesor";
		if(index == 2) form.header = "Login estudiante";

		if(form.start() == false)
			continue;

		switch(index)
		{
			case 0: menu_admin(form); break;
			case 1: menu_teacher(form); break;
			case 2: menu_student(form); break;
		}
	}
}

