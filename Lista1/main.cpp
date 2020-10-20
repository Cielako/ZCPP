#include <iostream>
#include <string>
using namespace std;

// zadanie 1
template <typename A , typename B>
auto add1(A const& x, B const& y) { // używamy stałej referencji, ponieważ nie modyfikujemy zawartości argumentów
    return x + y;
}

// zadanie 2
template <typename A, typename B, typename R>
auto add2(A const& x,B const&  y, R const& result ) {
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
    value_type& operator[](int v_size) { return _ptab[v_size]; } // operator na rzecz obiektów edytowalnych do zmieniania zaawartości wektora
    value_type const& operator[](int v_size) const { return _ptab[v_size]; } // operator na rzecz obiektów, które nie są stałe 

};

// Zadanie 4
template<typename V1, typename V2>
auto operator * (V1 const& v1, V2 const& v2)
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
            size_t v1_s = v1.size();
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
    size_t rozmiar1 = w.size();
    for (int i = 0; i < rozmiar1; i++)
    {
        w.operator[](i) = i+1;
        cout << w.operator[](i) << " ";
    }
    cout << "\n" << endl;

    Wektor<int, 10> w2;
    size_t rozmiar2 = w2.size();
    for (int i = 0; i < rozmiar2; i++)
    {
        w2.operator[](i) = i + 1;
        cout << w2.operator[](i) << " ";
    }

    // wynik zadanie 4
    cout << "\n\nZadanie 4: \nIloczyn skalarny wektorow wynosi: " << w * w2 << endl;
}
