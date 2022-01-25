
EXE:=exe
CPP:=$(wildcard *.cpp)
H:=$(wildcard *.h)

$(EXE) : $(CPP)
	g++ $^ -o $@

%.cpp : %.hpp

%.hpp : $(H)

clean:
	rm $(EXE)
