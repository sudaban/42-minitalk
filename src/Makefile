NAME = minitalk
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SERVER = server
CLIENT = client
B_SERVER = server_bonus
B_CLIENT = client_bonus
PRINTF = printf/libftprintf.a

SERVER_SRC = server.c
CLIENT_SRC = client.c
SERVER_SRC_B = server_bonus.c
CLIENT_SRC_B = client_bonus.c
PRINTF_SRC = printf/ft_printf.c printf/ft_extra.c printf/ft_printf_utils.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ_B = ${SERVER_SRC_B:.c=.o}
CLIENT_OBJ_B = ${CLIENT_SRC_B:.c=.o}
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -Lprintf -lftprintf -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -Lprintf -lftprintf -o $(CLIENT)

${SERVER_OBJ_B}: ${SERVER_SRC_B}
	${CC} ${CFlAGS} -c ${SERVER_SRC_B}

${CLIENT_OBJ_B}: ${CLIENT_SRC_B}
	${CC} ${CFlAGS} -c ${CLIENT_SRC_B}

${B_SERVER}:	${SERVER_OBJ_B} ${PRINTF}
	${CC} ${CFlAGS} ${SERVER_OBJ_B} -Lprintf -lftprintf -o server_bonus

${B_CLIENT}:	${CLIENT_OBJ_B} ${PRINTF}
	${CC} ${CFlAGS} ${CLIENT_OBJ_B} -Lprintf -lftprintf -o client_bonus

bonus:	${B_SERVER} ${B_CLIENT}

$(PRINTF): $(PRINTF_OBJ)
	ar rcs $(PRINTF) $(PRINTF_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(PRINTF_OBJ) ${SERVER_OBJ_B} ${CLIENT_OBJ_B}

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(PRINTF) ${B_SERVER} ${B_CLIENT}

re: fclean all

.PHONY: all clean fclean re