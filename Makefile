account_management:
	g++ -c src/account_management/register.cpp -o bin/register.o
	g++ -c src/account_management/login.cpp -o bin/login.o
	ld --relocatable bin/register.o bin/login.o -o bin/account_management.o
menus:
	g++ -c src/menus/start_menu.cpp -o bin/start_menu.o
	g++ -c src/menus/main_menu.cpp -o bin/main_menu.o
	ld --relocatable bin/start_menu.o bin/main_menu.o -o bin/menus.o
compile_program: account_management menus
	g++ src/main.cpp bin/account_management.o bin/menus.o -o bin/program
clean:
	rm bin/*
