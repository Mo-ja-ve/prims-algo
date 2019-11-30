all: make test

make:
	g++ ./gen.cpp -o gen
	g++ ./main.cpp -o exe

test:
	@echo
	@echo -e "\e[31mINTEGER\e[0m"
	@echo
	./gen int 4 9
	@echo
	@echo -e "\e[31mFLOAT\e[0m"
	@echo
	./gen float 0.4 0.9
	@echo
	@echo
	@echo -e "\e[31mTESTING\e[0m"
	./gen list 4 8 2 17 > input2.dat
	./exe < input2.dat
