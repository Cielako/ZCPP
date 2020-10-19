main.exe:main.obj
	link /DEBUG /OUT:main.exe main.obj

main.obj: main.cpp
	cl /std:c++17 /EHsc /c /Zi /W4 /WX /Zi /Fo:main.obj main.cpp