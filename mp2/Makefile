# EXENAME1 = testimage
# EXENAME2 = testscene
# # EXENAME3 = testimage-asan
# # EXENAME4 = testscene-asan


# OBJS1 = image.o png.o rgbapixel.o testimage.o 
# OBJS2 = scene.o testscene.o png.o image.o rgbapixel.o
# # OBJS3 = image.o png.o rgbapixel.o testimage.o 
# # OBJS4 = scene.o testscene.o png.o image.o rgbapixel.o


# CXX = clang++
# CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
# LD = clang++
# LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi
# ASANFLAGS = -fsanitize=address -fno-omit-frame-pointer

# all : $(EXENAME1) $(EXENAME2) 

# $(EXENAME1) : $(OBJS1)
# 	$(LD) $(OBJS1) $(LDFLAGS) -o $(EXENAME1)

# $(EXENAME2) : $(OBJS2)
# 	$(LD) $(OBJS2) $(LDFLAGS) -o $(EXENAME2)

# # $(EXENAME3) : $(OBJS3)
# # 	$(LD) $(OBJS1) $(LDFLAGS) $(ASANFLAGS) -o $(EXENAME1)

# # $(EXENAME4) : $(OBJS4)
# # 	$(LD) $(OBJS2) $(LDFLAGS) $(ASANFLAGS) -o $(EXENAME2)

# image.o : image.cpp image.h png.h
# 	$(CXX) $(CXXFLAGS) image.cpp

# scene.o : scene.cpp image.h png.h scene.h
# 	$(CXX) $(CXXFLAGS) scene.cpp

# png.o : png.cpp png.h rgbapixel.h
# 	$(CXX) $(CXXFLAGS) png.cpp

# rgbapixel.o : rgbapixel.cpp rgbapixel.h
# 	$(CXX) $(CXXFLAGS) rgbapixel.cpp

# testimage.o : testimage.cpp
# 	$(CXX) $(CXXFLAGS) testimage.cpp

# testscene.o : testscene.cpp
# 	$(CXX) $(CXXFLAGS) testscene.cpp

# clean :
# 	-rm -f *.o $(EXENAME1) $(EXENAME2) 

EXE = testscene

OBJS_DIR = .objs

OBJS_STUDENT = image.o scene.o
OBJS_PROVIDED = testscene.o png.o rgbapixel.o
# scene.o testscene.o png.o image.o rgbapixel.o

CXX = clang++
LD = clang++
WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable
CXXFLAGS = -std=c++1y -stdlib=libc++ -g -O0 $(WARNINGS) -MMD -MP -c
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi
ASANFLAGS = -fsanitize=address -fno-omit-frame-pointer

all: $(EXE) $(EXE)-asan

# Pattern rules for object files
$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@
$(OBJS_DIR)/%-asan.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $(ASANFLAGS) $< -o $@

# Create directories
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Rules for executables... we can use a pattern for the -asan versions, but, unfortunately, we can't use a pattern for the normal executables
$(EXE):
	$(LD) $^ $(LDFLAGS) -o $@
%-asan:
	$(LD) $^ $(LDFLAGS) $(ASANFLAGS) -o $@


# Executable dependencies
$(EXE):      $(patsubst %.o, $(OBJS_DIR)/%.o,      $(OBJS_STUDENT)) $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS_PROVIDED))
$(EXE)-asan: $(patsubst %.o, $(OBJS_DIR)/%-asan.o, $(OBJS_STUDENT)) $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS_PROVIDED))

# Include automatically generated dependencies
-include $(OBJS_DIR)/*.d

clean:
	rm -rf $(EXE) $(EXE)-asan $(OBJS_DIR)

tidy: clean
	rm -rf doc

.PHONY: all tidy clean
