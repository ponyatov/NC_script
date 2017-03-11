test.nc: test.ncs ./ncs.exe
	./ncs.exe < $< > $@ && tail $@
C = cpp.cpp ypp.tab.cpp lex.yy.c
H = hpp.hpp ypp.tab.hpp
CXXFLAGS += -std=gnu++11
./ncs.exe: $(C) $(H)
	$(CXX) $(CXXFLAGS) -o $@ $(C)
lex.yy.c: lpp.lpp
	flex $<
ypp.tab.cpp: ypp.ypp
	bison $<
