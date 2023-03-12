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
        bool checkfield(int field){
            if (Field[field] == 0){return true;}
            return false;
        }
        void writefield(int field,int player){
            Field[field] = whatplayer(player);
        }
        int whatplayer(int player){
            if (player % 2 != 0){return 1;}
            return 2;
        }
        int isgamewon(){
            for (int i = 0; i <= FieldSize * FieldSize; i++)
            {
                checkfield(i);
            }
            
            return 0;
        }
        bool checksquares(int field){
            for (int i = 0; i < FieldSize; i++)
            {
                checksquare(field);
            }
        }
        int checksquare(int Field){
            switch (Field)
            {
            case 1:
                return Field - FieldSize + 1;
            case 2:
                return Field - FieldSize;
            case 3:
                return Field - FieldSize + 1;
            case 4:
                return Field + 1;
            case 5:
                return Field + FieldSize + 1;
            case 6:
                return Field + FieldSize;
            case 7:
                return Field + FieldSize - 1;
            case 8:
                return Field - 1;
            default:
                cout << "Error: trying to check field that does not exist";
                return 0;
            }
        }
};
int main(){
    game MyGame(10);
    //checks if the square to be filled is already occupied
    bool check = false;
    int user = 1;
    
    bool gameover = false;

    while (gameover == false)
    {
        while (check == false)
        {
            cout << ">>";
            string input;
            cin >> input;
            check = MyGame.checkfield(MyGame.interpret(input));
            MyGame.writefield(MyGame.interpret(input),user);
            user++;
            if (check == false)
            {
                cout << "already occupied! try again." << endl;
            }
        }

    }
    
    return 0;
}