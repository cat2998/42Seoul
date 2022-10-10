CLIDIR = ./client/
SRVDIR = ./server/

all:
			$(MAKE) -C $(CLIDIR)
			$(MAKE) -C $(SRVDIR)

bonus:
			$(MAKE) -C $(CLIDIR) bonus
			$(MAKE) -C $(SRVDIR) bonus

clean:
			$(MAKE) -C $(CLIDIR) clean
			$(MAKE) -C $(SRVDIR) clean

fclean:
			$(MAKE) -C $(CLIDIR) fclean
			$(MAKE) -C $(SRVDIR) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus