#include <iostream>
#include <string>

using namespace std;

class Adapter{ //converts the given int into a workable string
    public: 
        string conjunction;
        int current_digit;
        string wordify(int num){
            conjunction = "";
            if (num != 0){
                bool first = true;
                while (num > 0){
                    current_digit = num%10;
                    switch(current_digit){
                        case 1:
                            conjunction = "one" + conjunction;
                            break;
                        case 2: 
                            conjunction = "two" + conjunction;
                            break;
                        case 3:
                            conjunction = "three" + conjunction;
                            break;
                        case 4:
                            conjunction = "four" + conjunction;
                            break;
                        case 5:
                            conjunction = "five" + conjunction;
                            break;
                        case 6:
                            conjunction = "six" + conjunction;
                            break;
                        case 7:
                            conjunction = "seven" + conjunction;
                            break;
                        case 8:
                            conjunction = "eight" + conjunction;
                            break;
                        case 9:
                            conjunction = "nine" + conjunction;
                            break;
                        case 0:
                            conjunction = "zero" + conjunction;
                            break;
                    }
                    if ((num/10)>0){
                        conjunction = "," + conjunction;
                    }
                    num /= 10;
                } 
            }
            else{
                conjunction += "zero";
            }
            conjunction += "!";
            return conjunction;
        }
        
};

class Word_Maker{ //converts list into three-seven-four
    public:
        int i = 0;
        string new_string;
        string generate_id(string num){
            new_string = "[";
            const std::string s(num);
            while (s[i] != '!'){
                if (s[i] == ','){
                    new_string += "-";
                }
                else{
                    new_string += s[i];
                }
                i += 1;
            }
            new_string += "]";
            i = 0;
            cout<<new_string<<endl;
            return new_string;
        }
};

int main(){
    Adapter adapter;
    Word_Maker new_id;
    string a1 = adapter.wordify(809);
    string a2 = adapter.wordify(890);
    string a3 = adapter.wordify(800);
    string a4 = adapter.wordify(2020044884);
    new_id.generate_id(a1);
    new_id.generate_id(a2);
    new_id.generate_id(a3);
    new_id.generate_id(a4);

    return 0;
}