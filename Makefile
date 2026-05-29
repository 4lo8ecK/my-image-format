CC=g++

src=src/myimg.cpp src/myimg.h
main=main.cpp

all: app

app: $(main) $(src)
	$(CC) $(main) $(src) -o myimage
