build: clean
	mkdir -p build
	g++ -g -O3 -o build/program src/main.cpp -lraylib

clean:
	rm -rf build