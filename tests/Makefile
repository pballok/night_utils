CC=clang++
CFLAGS=--std=c++14 -I../include -I../../googletest/googletest -I../../googletest/googletest/include
GTEST_SOURCE= ../../googletest/googletest/src/gtest-all.cc ../../googletest/googletest/src/gtest_main.cc
TARGET=test_night_utils
.DEFAULT_GOAL=all

FORCE:

%.o: %.cpp ../include/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): not_null.o $(GTEST_SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) not_null.o $(GTEST_SOURCE)

$(TARGET)-run: $(TARGET) FORCE
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -f *.o

all: $(TARGET)-run
