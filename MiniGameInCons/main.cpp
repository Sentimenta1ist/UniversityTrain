#include <iostream>
using namespace std;

string words[10] =  {"gamedev", "winner", "loser", "laptop", "programming",     //dictionary of words
                     "mother", "shopping", "snow", "sda", "cap"} ;

void clear()
{
    printf("\033[H\033[J");   // printf for clear window
}


void game( string result)
{
    string downs = "";
    string symb = "";
    string answer = result;
    int    scores = 15;
    int    flag = 0;
    int    index_of_alone = 0;

    for(int i = 0 ; i < result.size(); i++)  // create string with "_ _ _ _ _ ..."
    {
        downs += "_";
    }

    while( scores > 0)
    {
        clear();
        int index = 0;
        for(int i = 0; i < result.size();i++)
        {
            if( result[i] == '*')
            {
                index++;                       // check for a win
            }
        }
        if(index == result.size())
        {
            for(int i = 0; i < downs.size(); i++)
                cout << downs[i] << ' ';

            cout << endl << endl;
            cout << "YOU WIN :)" << endl;
            return;
        }

        if(index_of_alone == 1)
        {
            cout << "Input only 1 symbol pls!!!" << endl;   // check for a input
            index_of_alone = 0;
        }
        cout << "You have " << scores << " scores !!!" << endl;  // scores

        for(int i = 0; i < downs.size(); i++)
        cout << downs[i] << ' ';

        cout << endl;
        cout << "Input 1 symbol ";
        cin >> symb;
        if(symb.size() > 1)
        {
            index_of_alone = 1;   //check for a input
            scores--;
            continue;
        }
        for(int i = 0 ; i < result.size(); i++)
        {
            if( symb[0] == result[i])  // check symbol
            {
                result[i] = '*';
                downs[i] = symb[0];
                flag = 1;
            }
        }
        if (flag == 0)
        {
            scores--; // minus score if incorrect
        }
        flag = 0;

    }
    clear();
    cout << "You LOSE  :(  " << endl <<  "Answer is '" << answer << "' ." << endl;
}

void menu()
{


    cout << "              GAME 'words'                  \n";
    cout << "                                            \n";
    cout << "              Created by Ivanenko Alexander \n";
    cout << "                                            \n";
    int end = 1;
    while (1)
    {
        if (end == 0)
        {
            return;
        }
        clear();
        cout << "                MENU                        \n";
        cout << "        1. Start game                       \n";
        cout << "        2. Rules                            \n";
        cout << "        3. About creator                    \n";
        cout << "        0. Exit                             \n";
        int option = 0;
        scanf("%i", &option);
        int exit = 1 ;
        switch(option)
        {
            case 1:
                clear();
                srand(time(0));

                game(words[rand() % 10]);
                return;
            case 2:
                clear();
                cout << " 'Words'. The program chooses the word \n "
                        "and draws on the screen as many dashes as\n"
                        " the letters in the word. Guess this word. \n "
                        "If the letter included in this word is called,\n "
                        "it is substituted instead of the corresponding dash.\n "
                        "Otherwise, the player loses one point. \n "
                        "At the beginning of the game, the player has 15 points.\n";
                cout << "                                                       \n";
                cout << "                                        0. Back to menu\n";
                cin >> exit;
                if(exit == 0) break;
            case 3:
                clear();
                cout << " Ivanenko. KV - 82. FAM. Love programming.\n";
                cout << "                                          \n";
                cout << "                           0. Back to menu\n";
                cin >> exit;
                if(exit == 0) break;
            case 0:
                clear();
                cout << " Are you sure? Press 0.";
                cin >> exit;
                if(exit == 0)
                {
                    end = 0;
                    break;
                }
        }

    }
}

int main()
{
    menu();
    return 0;
}