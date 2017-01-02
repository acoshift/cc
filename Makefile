BOOST=/usr/local/Cellar/boost/1.63.0
CC=clang++
CXXFLAGS=-Wall -O2 -std=c++11 -fpermissive -I$(BOOST)/include -L$(BOOST)/lib
SRC=src
O=cc
GG=gen_grammar
GP=gen_parsetable
GT=gen_tokentable
OBJ=obj
OUT=output
TOKEN=$(SRC)/token
PARSETABLE=$(SRC)/parsetable
GRAMMAR=$(SRC)/grammar
MAKEPARSETABLE=$(SRC)/makeparsetable

all: $(O)

$(O): gen_h $(OBJ)/error.o $(OBJ)/scanner.o $(OBJ)/parser.o $(OBJ)/cc.o
	$(CC) -I$(BOOST)/include -L$(BOOST)/lib -lboost_regex $(OBJ)/error.o $(OBJ)/scanner.o $(OBJ)/parser.o $(OBJ)/cc.o -o $(OUT)/$(O)

$(OBJ)/%.o: $(SRC)/%.cc
	$(CC) -c $(CXXFLAGS) $< -o $@

$(GG):
	$(CC) $(CXXFLAGS) $(SRC)/$(GG).cc -o $(OUT)/$(GG)

$(GP):
	$(CC) $(CXXFLAGS) -lboost_regex $(SRC)/$(GP).cc -o $(OUT)/$(GP)

$(GT):
	$(CC) $(CXXFLAGS) $(SRC)/$(GT).cc -o $(OUT)/$(GT)

gen:
	make $(GG); make $(GP); make $(GT)

gen_h: gen
	# $(MAKEPARSETABLE) $(GRAMMAR) $(PARSETABLE) ;
	$(OUT)/$(GT) $(TOKEN) $(SRC)/tokentable.h CC_TOKENTABLE_H_ ;
	$(OUT)/$(GP) $(PARSETABLE) $(SRC)/parsetable.h CC_PARSETABLE_H_ ;
	$(OUT)/$(GG) $(GRAMMAR) $(SRC)/grammar.h CC_GRAMMAR_H_

clean_cc:
	rm -f $(OBJ)/*.o $(OUT)/$(O)

clean:
	rm -f $(OBJ)/*.o $(OUT)/$(O) $(OUT)/$(GG) $(OUT)/$(GP) $(OUT)/$(GT) $(SRC)/tokentable.h $(SRC)/parsetable.h $(SRC)/grammar.h
