#include <algorithm>            //std::getline, std::for_each
#include <iterator>             //std::istream_iterator
#include <iostream>             //std::cout, std::cin
#include <map>                  //std::map
#include <sstream>              //std::stringstream
#include <string>               //std::string

amespace nonstd
{
    class Line : public std::string {};

    std::istream & operator>>(std::istream & is, Line & line)
    {
        return std::getline(is, line);
    }
}

enum Case {insert=1, erase, print};

int main() {
    using namespace std;

    map<string, int> m;
    int c;
    string name;
    int mark;

    using input_it = istream_iterator<nonstd::Line>;
    for_each(input_it(cin), input_it(), [&](nonstd::Line l){

        stringstream ss(l);
        ss >> c;

        switch(c){
            case insert:
                ss >> name >> mark;

                m[name] += mark;
                break;

            case erase:
                ss >> name;

                m.erase(name);
                break;

            case print:
                ss >> name;

                cout << m[name] << endl;
                break;
        }
    });
}
