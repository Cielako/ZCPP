#include <iostream>
#include <string>
using namespace std;

// zadanie 1
template <typename A , typename B>
A add1(A x, B y) {
    return x + y;
}

// zadanie 2
template <typename A, typename B, typename R>
A add2(A x,B y, R result ) {
    return result(x , y);
}

//Zadnie 3 
template <typename value_type, size_t v_size>
class Wektor 
{
private:
    value_type* _ptab;
    size_t _rozmiar;
public:

    Wektor(): _rozmiar(v_size), _ptab(new value_type[v_size]){
        for (int i = 0; i < v_size; i++){
            _ptab[i] = 0;
        }
    }
    ~Wektor(){
        delete[] _ptab;
    }
   
    size_t size() const { return _rozmiar; }
    value_type& operator[](int v_size) { return _ptab[v_size]; }

};

// Zadanie 4
template<typename V>
int operator * (V& v1, V& v2)
{
    try
    {
        if (v1.size() == 0 || v2.size() == 0 || v1.size() != v2.size())
        {
            throw std::length_error("Długości wektorów nie są równe lub któryś wektor ma 0 elementów");
        }
        else
        {
            int wynik = 0;
            int v1_s = v1.size();
            for (int i = 0; i < v1_s; i++)
                wynik += v1[i] * v2[i];

            return wynik;
        }
    }
    catch (const std::exception&)
    {
        throw std::length_error("Długości wektorów nie są równe lub któryś wektor ma długość równą 0");
    }
   
}



int main()
{
   // wynik zadanie 1
    cout << "Zadanie 1:" << endl;
    cout << add1(1, 2) << endl;
    cout << add1(2.3000, 1) << endl;
    cout << add1(2.3000, 11.0101010) << endl;
    cout << add1(std::string("Zupa"), std::string("Grzybowa\n")) << endl;

    // wynik zadanie 2
    auto lambda = [](auto a, auto b) { return a + b; };
    cout << "Zadanie 2:" << endl;
    cout << add2(1, 2, lambda) << endl; 
    cout << add2(2.3000, 1, lambda) << endl;
    cout << add2(2.3000, 11.0101010, lambda) << endl;
    cout << add2(std::string("Zupa"), std::string("Grzybowa\n"), lambda) << endl;
    
    // wynik zadanie 3
    cout << "Zadanie 3 :\n" << endl;
    Wektor<int, 10> w;
    int rozmiar1 = w.size();
    for (int i = 0; i < rozmiar1; i++)
    {
        w.operator[](i) = i+1;
        cout << w.operator[](i) << " ";
    }
    cout << "\n" << endl;

    Wektor<int, 10> w2;
    int rozmiar2 = w2.size();
    for (int i = 0; i < rozmiar2; i++)
    {
        w2.operator[](i) = i + 1;
        cout << w2.operator[](i) << " ";
    }

    // wynik zadanie 4
    cout << "\n\nZadanie 4: \nIloczyn skalarny wektorow wynosi: " << w * w2 << endl;
}

