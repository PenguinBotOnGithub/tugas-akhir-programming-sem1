account_management:
	g++ -c src/account_management/register.cpp -o bin/register.o
	g++ -c src/account_management/login.cpp -o bin/login.o
	g++ -c src/account_management/info.cpp -o bin/info.o
	g++ -c src/account_management/delete.cpp -o bin/delete.o
	ld --relocatable bin/register.o bin/login.o bin/info.o bin/delete.o -o bin/account_management.o
menus:
	g++ -c src/menus/start_menu.cpp -o bin/start_menu.o
	g++ -c src/menus/main_menu.cpp -o bin/main_menu.o
	ld --relocatable bin/start_menu.o bin/main_menu.o -o bin/menus.o
transaction:
	g++ -c src/transaction/transfer.cpp -o bin/transfer.o
	g++ -c src/transaction/deposit.cpp -o bin/deposit.o
	g++ -c src/transaction/withdraw.cpp -o bin/withdraw.o
	ld --relocatable bin/transfer.o bin/deposit.o bin/withdraw.o -o bin/transaction.o
compile_program: account_management menus transaction
	g++ src/main.cpp bin/account_management.o bin/menus.o bin/transaction.o -o bin/program
clean:
	rm bin/*
run:
	bin/program
