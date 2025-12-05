account_management:
	g++ -c src/account_management/register.cpp -o bin/account_management.o
menus:
	g++ -c src/menus/start_menu.cpp -o bin/menus.o
compile_program: account_management menus
	g++ src/main.cpp bin/account_management.o bin/menus.o -o bin/program
clean:
	rm bin/*
