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
        bool isgamewon(){
            int n = 1;

            for (int i = 0; i < FieldSize; i++)
            {
                if (Field[i] == n && Field[i] + (FieldSize * (FieldSize - 1)) == n)
                {
                    int c = 0;
                    for (int j = 1; j < Field[i] + (FieldSize * (FieldSize - 1)); j += FieldSize)
                    {
                        if(Field[j] == n){
                            c++;
                        }
                        if (c == FieldSize)
                        {
                            return true;
                        }
                    }   
                }
            }
            
            for (int i = 0; i < (FieldSize * (FieldSize - 1)) + 1; i += FieldSize)
            {

                if (Field[i] == n && Field[1] + Field[i] - 1 == n)
                {
                    int c = 0;
                    for (int j = 0; j < FieldSize; j++)
                    {
                        if (Field[j] == n)
                        {
                            c++;
                        }
                        if (c == FieldSize)
                        {
                            return 0;
                        }
                    }
                }  
            }
            return false;
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
            if (MyGame.whatplayer(user) == 1){cout << "player1" << endl;}
            else if (MyGame.whatplayer(user) == 2){cout << "player2" << endl;}
            else{ cout << "something went wrong!" << endl;}
            
            
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
        gameover = MyGame.isgamewon();
        cout << gameover;
    }
    return 0;
}