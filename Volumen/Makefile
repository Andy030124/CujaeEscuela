NAME:=volumen

GCC:=gcc
FLAGS:= -Wall -Wpedantic 

RELEASE_FILES:= $(shell find ./* -type f -iname "*.c" | grep release)
DEBUG_FILES:= $(shell find ./* -type f -iname "*.c" | grep dbg)
MAIN_FILES:= $(shell find ./* -type f -iname "*.c" | grep main)

ifdef RELEASE
ALLFILES:= $(RELEASE_FILES) $(MAIN_FILES)
FLAGS+= -O3
else
ALLFILES:= $(DEBUG_FILES) $(MAIN_FILES)
FLAGS+= -O0
endif
LDFLGS:= $(FLAGS)

OBJ_FILES:= $(patsubst %.c,%.o,$(ALLFILES))

$(NAME): $(OBJ_FILES)
	$(GCC) $(LDFLGS) $(OBJ_FILES) -o $(NAME)


%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $@

info:
	$(info $(ALLFILES))
	$(info $(OBJ_FILES))

clean:
	rm -f *.o
