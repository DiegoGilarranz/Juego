CXX = gcc
CXXFLAGS = -g
LDLIBS = -lallegro -lallegro_image

DEPS = juego.o
OBJ = juego.o juego.o

bouncy: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean

clean:
	$(RM) *.o *~
