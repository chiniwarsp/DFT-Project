CXX = g++
CXXFLAGS = -fPIC -O2 -Wall
LDFLAGS = -shared
LIB = libpi.so
SRC = pi_calc.cpp

# If Boost is not system-wide, add this (update BOOST path if needed)
# BOOST_INC = -I$(HOME)/local/include
# BOOST_LIB = -L$(HOME)/local/lib

all: $(LIB)

$(LIB): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(LIB) $(SRC) $(LDFLAGS) -lboost_system

clean:
	rm -f $(LIB)

run: $(LIB)
	python3 use_pi.py
