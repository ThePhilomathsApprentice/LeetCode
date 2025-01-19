1: 1_TwoSum.cpp
	g++ -std=c++20 1_TwoSum.cpp -o ./bin/1.out
	./bin/1.out

88: 88_MergedSort.cpp printVector.cpp
	g++ -std=c++20 88_MergedSort.cpp printVector.cpp -o ./bin/88.out
	./bin/88.out

118: 118_PascalTriangle.cpp
	g++ 118_PascalTriangle.cpp -o ./bin/118.out
	./bin/118.out
119: 119_PascalTriangle2.cpp
	g++ 119_PascalTriangle2.cpp -o ./bin/119.out
	./bin/119.out

190: 190_ReverseBits.c
	gcc 190_ReverseBits.c -o  ./bin/190.out
	./bin/190.out
191: 191_Num1Bit.c
	gcc 191_Num1Bit.c -o  ./bin/191.out
	./bin/191.out

338: 338_CountBits.c
	gcc 338_CountBits.c -o  ./bin/338.out
	./bin/338.out
# 1114: 1114_PrintInOrder.cpp
# 	g++ 1114_PrintInOrder.cpp -o ./bin/1114.out
# 	./bin/bin1114.out

1346: 1346_CheckNOrDoubleExit.cpp printVector.cpp
	g++ -std=c++20 1346_CheckNOrDoubleExit.cpp printVector.cpp -o  ./bin/1346.out
	./bin/1346.out

2220: 2220_MinFlipsToConvert.c
	gcc 2220_MinFlipsToConvert.c -o  ./bin/2220.out
	./bin/2220.out

2239: 2239_ClosestNumberToZero.cpp printVector.cpp
	g++ 2239_ClosestNumberToZero.cpp printVector.cpp -o  ./bin/2239.out
	./bin/2239.out

memcpy: my_memcpy.c
	gcc my_memcpy.c -o ./bin/memcpy.out
	./bin/memcpy.out

clean:
	rm -rf ./bin/*.out