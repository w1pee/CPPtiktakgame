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
            int n2 = 0;

            if (input.length() != 2)
            {
                return -1;
            }
            char chars[9] = {'a','b','c','d','e','f','g','h','i'};
            for (int i = 0; i < 9; i++)
            {
                if(chars[i] == input.at(i)){
                    n1 = i;
                }
            }
        }
};
int main(){

    game MyGame(9);
    return 0;
}

int stringTOint(string text){

    int num = 0;
    char  nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
    for (int i = 0; i <= 9; i++)
            {
                if(nums[i] == text.at(i)){
                    num += ;
                }
            }
}

int quad(int num, int q){
    int num;
    for (int i = 0; i < q; i++)
    {
        num *= num;
    }
    
}