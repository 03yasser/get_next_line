SRCS = get_next_line_utils_bonus.c get_next_line_bonus.c
all : $(SRCS)
	rm -rf a.out
	cc -W -W -W main.c $(SRCS) -g -fsanitize=address
	./a.out
