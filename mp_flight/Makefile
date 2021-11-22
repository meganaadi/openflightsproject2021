# Change each semester this lab is released
TERM = fa2021

EXE =   find_green_route
TEST = test

EXE_OBJ =   main.o
OBJS =   main.o Airport.o Route.o Graph.o


#CPP_FILES += $(wildcard colorPicker/*.cpp)
CPP_FILES += $(wildcard util/*.cpp)
OBJS += $(CPP_FILES:.cpp=.o)

# other executables
#EXE_FIB = fib_generator
#OBJS_FIB = $(OBJS_DIR)/fib_generator.o $(OBJS_DIR)/fib.o


CLEAN_RM = $(EXE) 

include cs225/make/cs225.mk

data:
	curl -O https://courses.engr.illinois.edu/cs225/$(TERM)/assets/assignments/labs/dict/lab_dict_data.tar && tar -xf lab_dict_data.tar && rm lab_dict_data.tar && mv lab_dict_data data

# $(EXE_FIB): $(OBJS_FIB)
#	$(LD) $^ $(LDFLAGS) -o $@


