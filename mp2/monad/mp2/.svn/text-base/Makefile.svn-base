EXENAME1 = testimage
EXENAME2 = testscene

OBJS1 = image.o png.o rgbapixel.o testimage.o 
OBJS2 = scene.o testscene.o png.o image.o rgbapixel.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi

all : $(EXENAME1) $(EXENAME2)

$(EXENAME1) : $(OBJS1)
	$(LD) $(OBJS1) $(LDFLAGS) -o $(EXENAME1)

$(EXENAME2) : $(OBJS2)
	$(LD) $(OBJS2) $(LDFLAGS) -o $(EXENAME2)

image.o : image.cpp image.h png.h
	$(CXX) $(CXXFLAGS) image.cpp

scene.o : scene.cpp image.h png.h scene.h
	$(CXX) $(CXXFLAGS) scene.cpp

png.o : png.cpp png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) rgbapixel.cpp

testimage.o : testimage.cpp
	$(CXX) $(CXXFLAGS) testimage.cpp

testscene.o : testscene.cpp
	$(CXX) $(CXXFLAGS) testscene.cpp

clean :
	-rm -f *.o $(EXENAME1) $(EXENAME2)