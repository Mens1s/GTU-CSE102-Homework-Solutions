all: clean compile run clean
test: clean compileTest runTest clean
compileTest: testDriver.c 
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o testDriver testDriver.c util.c
compile: main.c 
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o test main.c util.c
runTest:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./testDriver
	@echo "================================================================================="
	@echo "Completed tests...."
run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./test
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test


