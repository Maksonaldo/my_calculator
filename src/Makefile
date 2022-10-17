CLANG_FILE_WAY=calculator_oop
CHECK_FILES_C=$(CLANG_FILE_WAY)/controller/*.cpp $(CLANG_FILE_WAY)/controller/*.h
CHECK_FILES_V=$(CLANG_FILE_WAY)/view/*.cpp $(CLANG_FILE_WAY)/view/*.h
CHECK_FILES_M=$(CLANG_FILE_WAY)/model/*.cpp $(CLANG_FILE_WAY)/model/*.h
CHECK_FILES_T=test/*.cpp
OBJECTS = $(SOURCES:.cpp=.o)
CPPCH_SETUP=--enable=warning,performance,portability -v --language=c++ --std=c++17

#     These special targets are called phony     #
.PHONY: all dist clean install uninstall dvi gcov build Qmakefile test

build:
	cmake -S ./calculator_oop -B ./../build
	cmake --build ./../build

install: build
	mkdir -p ../SmartCalc;
	cp -rf ./../build/calculator_oop.app  ../SmartCalc
	cp documentation/man/index.html ../SmartCalc

uninstall:
	rm -rf ../SmartCalc ../build

style: 
	clang-format -n --style=Google $(CHECK_FILES_C) $(CHECK_FILES_V)  $(CHECK_FILES_M)  $(CHECK_FILES_T) $(CLANG_FILE_WAY)/main.cpp


dist:
	tar -czf SmartCalc.tgz ./*



cppcheck:
	cppcheck $(CPPCH_SETUP) $(CHECK_FILES_C) $(CHECK_FILES_V)  $(CHECK_FILES_M)  $(CHECK_FILES_T) $(CLANG_FILE_WAY)/main.cpp

leaks: test
	leaks --atExit -- ./tests/build/SmartCalc_v2_test

test:
	cmake -S tests -B tests/build
	cmake --build tests/build
	cd tests/build; ctest

gcov_report: test
	lcov -t "SmartCalc_v2_test" -o ./tests/build/CMakeFiles/SmartCalc_v2_test.dir/SmartCalc_v2_test.info -c -d ./tests/build/CMakeFiles/SmartCalc_v2_test.dir 
	genhtml -o report ./tests/build/CMakeFiles/SmartCalc_v2_test.dir/SmartCalc_v2_test.info

clean:
	rm -rf ./../build
	rm -rf ./../SmartCalc
	rm -rf *.o a.out *.gcda *.gcno report/ *.info *.cfg *.user* *.clang-format test.out *.a
	rm -rf ./documentation/3DViewer
	rm -rf ./CMakeFiles
	rm -rf ./tests/build
