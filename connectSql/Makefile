LIB_DIR=$(shell pwd)/../lib
INCLUDE=-I$(LIB_DIR)/include
LIB=-L /lib64/mysql

.PHONY:all
all:insert_cgi select_cgi

insert_cgi:insert_cgi.cpp comm.cpp
	@g++ -o $@ $^ $(INCLUDE) $(LIB) -lmysqlclient #-static
select_cgi:select_cgi.cpp comm.cpp
	@g++ -o $@ $^ $(INCLUDE) $(LIB) -lmysqlclient #-static

.PHONY:clean
clean:
	@rm -f insert_cgi select_cgi
