CC			=	g++ -Wall -Wextra -Werror -std=c++17 -pedantic
TEST_FLAGS  =   -lgtest -lgtest_main -lpthread
COV         =   -lgcov -coverage
TEST_SRC    =   ./test/test.cpp


all: install

install: uninstall
	mkdir build
	cd build/ && cmake build ../calc_v2
	make -C build

open:
	./build/calc_v2.app/Contents/MacOS/calc_v2 ; exit;

uninstall: clean
	rm -rf build*

clean:
	rm -rf Calc_v2.tar 
	rm -rf ./.clang-format
	rm -rf calc_v2/html
	rm -rf calc_v2/latex
	rm -rf test/test_result
	rm -rf test_output_list
	rm -rf test.info
	rm -rf calc_v2/CMakeLists.txt.user

dvi: 
	doxygen Doxyfile

dvi_open:
	open calc_v2/html/index.html

dist:	dvi
	mkdir ./Distribution
	cp -R ./calc_v2/ ./Distribution/calc_v2
	cp ./Makefile ./Distribution
	tar -cf ./calc_v2.tar ./Distribution
	rm -rf ./Distribution

tests:
	$(CC) $(TEST_SRC) $(TEST_FLAGS) -o ./test/test_result
	./test/test_result		


clang:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -n --verbose calc_v2/*.h calc_v2/*.cpp
	clang-format -i --verbose calc_v2/*.h calc_v2/*.cpp

gcov_report: 
	$(CC) $(COV) $(TEST_SRC) $(TEST_FLAGS) -o ./test/test_result
	./test/test_result
	lcov --no-external -t "test_result" -o test.info -c -d .
	genhtml -o test_output_list test.info
	@cd ./test_output_list ; open index.html
	rm -rf *.gcno *.gcda
