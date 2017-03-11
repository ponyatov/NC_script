test.nc: test.ncs ./ncs.exe
	./ncs.exe < $< > $@ && tail $@
C = cpp.cpp lex.yy.c
H = hpp.hpp
./ncs.exe: $(C) $(H)
	$(CXX) -o $@ $(C)
lex.yy.c: lpp.lpp
	flex $<
