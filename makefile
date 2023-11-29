INCFLAGS = -I./
CXXFLAGS = `wx-config --cxxflags`
LDFLAGS  = `wx-config --ldflags`
LDLIBS   = `wx-config --libs`
REZFLAGS = `wx-config --rez-flags`

ifdef FINAL
    EXTRAFLAGS = -MD -O2 -fno-rtti -fno-exceptions -fomit-frame-pointer
else
    EXTRAFLAGS = -MD -g
endif

# Define our sources, calculate the dependecy files and object files
TEST_SOURCES := TimerTrayUI.cpp 
TEST_OBJECTS := $(patsubst %.cc, %.o, ${TEST_SOURCES})
TEST_DEPS := $(patsubst %.cc, %.d, ${TEST_SOURCES})

#include our project dependecy files
-include $(TEST_DEPS)

all: test

test: $(TEST_OBJECTS)
    $(CXX) $(LDFLAGS) -o test $(TEST_OBJECTS) Test_resources.o $(LDLIBS)
ifdef FINAL
        strip test.exe
endif

Test_resources.o: Test.rc
    windres -i Test.rc -o Test_resources.o $(REZFLAGS)

clean:
    rm -rf test.exe test $(TEST_OBJECTS) $(TEST_DEPS) Test_resources.o