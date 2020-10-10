Rozwiazanie.exe: Rozwiazanie.obj
	link /DEBUG /OUT:Rozwiazanie.exe Rozwiazanie.obj

Rozwiazanie.obj: Rozwiazanie.cpp
	cl /std:c++17 /EHsc /c /Zi /W4 /WX /Zi /Fo:Rozwiazanie.obj Rozwiazanie.cpp
