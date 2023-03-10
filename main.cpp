#include <iostream>
using namespace std;

class game
{
    public: 
        int FieldSize;
        int Field[81];
        game(int size){
            FieldSize = size;
            for (int i = 0; i < 81; i++){Field[i] = 0;}
        }
        int interpret(string input){
            int n1 = 0;
            char chars[9] = {'a','b','c','d','e','f','g','h','i'};
            char chars2[9] = {'A','B','C','D','E','F','G','H','I'};
            for (int i = 0; i < 9; i++)
            {
                if(chars[i] == input.at(0) || chars2[i] == input.at(0)){
                    n1 = i;
                }
            }
            return (n1 * FieldSize) + stringTOint(input);
        }
        int quad(int num, int q){
            int number = 1;
            for (int i = 0; i < q; i++)
            {
                number *= num;
            }
            return number;
        }
        int stringTOint(string text){
            int num = 0;
            char  nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
            int k = 0;
            bool test = false;
            for (int i = text.length()-1; i >= 0; i--)
            {
                for (int j = 0; j < 10 && test == false; j++)
                {
                    if (text.at(i) == nums[j])
                    {
                        num += j * quad(10,k);
                        test=true;
                    }
                }
                test=false;
                k++;
            }
            return num;
        }
};
int main(){
    game MyGame(5);
    string input;
    cout << "input: ";
    cin >> input;
    cout << "field: "<< MyGame.interpret(input);
    return 0;
}

