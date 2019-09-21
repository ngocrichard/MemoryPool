all: main.o core.o MemoryPool.o FrameMemoryPool.o List.o NodeData.o
	g++ -g -o main main.o core.o MemoryPool.o FrameMemoryPool.o List.o NodeData.o
main.o: main.cpp core.h
	g++ -g -c main.cpp
core.o: core.cpp core.h
	g++ -g -c core.cpp
MemoryPool.o: MemoryPool.cpp MemoryPool.h
	g++ -g -c MemoryPool.cpp
FrameMemoryPool.o: FrameMemoryPool.cpp FrameMemoryPool.h
	g++ -g -c FrameMemoryPool.cpp
List.o: List.cpp List.h
	g++ -g -c List.cpp
NodeData.o: NodeData.cpp NodeData.h
	g++ -g -c NodeData.cpp
clean:
	rm -f *.o main.exe