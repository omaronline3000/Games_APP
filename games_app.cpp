#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Global variables
short trying = 2;
string user_name, password;
bool login = false, n = true;
short answer, i = 0, ry = false;

// log in function
void log_in()
{

    for (int i = 0; i <= trying; i++)
    {
        bool user_log = false, pass_log = false;
        if (ry == false)
        {
            cout << endl
                 << "welcome in our game store !!!" << "\n"
                 << "\n";
        }
        cout << "please Enter the user name : ";
        cin >> user_name;
        if (user_name == "user")
        {
            user_log = true;
        }
        cout << "\n\nplease Enter the password : ";
        cin >> password;
        if (password == "pass")
        {
            pass_log = true;
        }
        if (user_log == 1 && pass_log == 1)
        {
            login = true;
            break;
        }
        else if ((user_log == 0 || pass_log == 0) && i < 2)
        {
            cout << "\n\nuser name or password are wrong!!!\n\n";
            ry = true;
        }
        else
        {
            cout << "\nSorry, but it seems to you don't have an e-mail , you can make one from our web site\n";
        }
    }
}

// options function
void options()
{
    cout << "\nNow , you have a lot of games to play like : (please enter the number of choice)\n\n";
    string arr[5] = {"1 - guess the number ",
                     "2 - test your general knowledge ",
                     "3 - attack on monsters",
                     "4 - SPS",
                     "\n\n\n\n\n\n5 - log out"};
    for (short i = 0; i < 5; i++)
    {
        cout << "\n"
             << arr[i] << "\n";
    }
    cout << endl
         << "choose the game (enter the number of the game) :  ";
    cin >> answer;
    cout << "\n"
         << "\n";
}

void log_out()
{ // log out function
    char ans;
    cout << "do you want play again ? (y or n ) : ";
    cin >> ans;
    if (ans == 'n')
        n = false;
    else if (ans != 'y' && ans != 'n')
    {
        cout << "\n!!wrong input!!!\n";
        log_out();
    }
}

// guess game function
void guess()
{
    int guess, NumOfGuesses = 7, num;

    srand(time(0));
    num = rand() % 15 + 1; // random number generator from 0 to 15

    cout << "you have 8 attempts. try to guess the number between 0 and 15\n";

    do
    {
        cin >> guess;
        if (NumOfGuesses == 0)
        {
            cout << "GAME OVER :( \n";
            break;
        }
        else if (guess > num)
        {
            NumOfGuesses -= 1;
            cout << "your guess is higher. \n you still have " << NumOfGuesses << " try again\n";
        }
        else if (guess < num)
        {
            NumOfGuesses -= 1;
            cout << "your guess is lower.  \n you still have " << NumOfGuesses << " try again\n";
        }
        else if (guess == num)
        {
            cout << "Excellent, You did it ;DD \n **YOU WON** \n";
            log_out();
        }

    } while (guess != num);
    if (guess != num)
        log_out();
}
// test your general knowledge  game function
void test()
{
    int score = 0;
    char user_answer, correct_answer;
    string Question[5] = {

        {"Which languages has the mor native speakers? "
         "\n"
         "a)Spanish.    b)English"},

        {"What company was originally (Cadabra) ?"
         "\n"
         "a)noon    b)Amazon"},

        {"What country drinks the most coffee per capita ?"
         "\n"
         "a)France  b)Finland"},

        {"What city is known as (The Eternal city) ?"
         "\n"
         "a)Rome    b)Paris"},

        {"what country has the most world cup ?"
         "\n"
         "a)Brazil    b)France"}};
    char an[5] = {'a', 'b', 'b', 'a', 'a'};

    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < i + 1; j++)
        {
            cout << Question[i] << "\n";
            correct_answer = an[j];
            cin >> user_answer;
            if (user_answer == correct_answer)
                score++;
        }
    }

    cout << "your score : " << score << "\n";
    log_out();
}

// attack on monsters game function
void attack()
{
    string player, computer;
    short choice, par, player_attack, computer_attack,
        computer_damage, player_damage;
    int live_player = 50, live_computer = 50, player_fire_time = 1,
        player_dam_time = 2, player_tornado_time = 4,
        computer_fire_time = 1, computer_dam_time = 2, computer_tornado_time = 4,
        fire = -20, dam = -5, tornado = -10, normal_attack = -1;
    cout << "\nwelcome in attack on monsters !!!\n\n";
    for (int i = 0; i < 54; i++)
    {
        cout << "*";
    }
    cout << "\n*now you have 50 hearts and you will try to keep it *\n";
    for (int i = 0; i < 54; i++)
    {
        cout << "*";
    }
    string arr[4] = {"\nbig spider",
                     "bloody murder",
                     "dark tracer",
                     "fire warrior"};
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << "\n";
    }
    srand(time(0));
    par = rand() % 5;
    computer = arr[par];
    cout << endl
         << endl
         << "Now choose monster : (1 or 2 or 3 or 4) : ";
    cin >> choice;
    while (true)
    {
        if (choice == 1)
        {
            player = "big spider";
            break;
        }
        else if (choice == 2)
        {
            player = "bloody murder";
            break;
        }
        else if (choice == 3)
        {
            player = "dark tracer";
            break;
        }
        else if (choice == 4)
        {
            player = "fire warrior";
            break;
        }
        else
            cout << "wrong , try again";
    }
    cout << "\n\nyou are " << player << endl
         << "VS" << "\n"
         << computer << "\n";
    cout << "\nnow the players are ready , you have these powers : \n\n";
    string arr2[4] = {"1 - fire",
                      "2 - dam",
                      "3 - tornado",
                      "4 - normal_attack"};

    while (live_player > 0 && live_computer > 0)
    {
        while (true)
        {
            for (int i = 0; i < 4; i++)
            {
                cout << arr2[i] << "\n";
            }
            cout << "\n\n";
            cout
                << "!!! warning you can use (fire : 1) , (dam : 2) , (tornado : 4) , (normal-attack : unlimited)\n\n";
            cout << "Enter the type of attack which you want : (choose : 1 or 2 or 3 or 4) : ";
            cin >> player_attack;
            if (player_attack == 1)
            {
                if (player_fire_time != 0)
                {
                    player_damage = fire;
                    player_fire_time--;
                    break;
                }
                else
                    cout << "\nwrong , you finished fire\n";
            }
            else if (player_attack == 2)
            {
                if (player_dam_time != 0)
                {
                    player_damage = dam;
                    player_dam_time--;
                    break;
                }
                else
                    cout << "\nwrong , you finished dam\n";
            }
            else if (player_attack == 3)
            {
                if (player_tornado_time != 0)
                {
                    player_damage = tornado;
                    player_tornado_time--;
                    break;
                }
                else
                    cout << "\nwrong , you finished tornado\n";
            }
            else if (player_attack == 4)
            {
                player_damage = normal_attack;
                break;
            }
            else
                cout << "wrong input , try again";
        }
        while (true)
        {

            srand(time(0));
            computer_attack = rand() % (5 - 1 + 1) + 1;

            if (computer_attack == 1)
            {
                if (computer_fire_time != 0)
                {
                    computer_damage = fire;
                    computer_fire_time--;
                    break;
                }
            }
            else if (computer_attack == 2)
            {
                if (computer_dam_time != 0)
                {
                    computer_damage = dam;
                    computer_dam_time--;
                    break;
                }
            }
            else if (computer_attack == 3)
            {
                if (computer_tornado_time != 0)
                {
                    computer_damage = tornado;
                    computer_tornado_time--;
                    break;
                }
            }
            else if (computer_attack == 4)
            {
                computer_damage = normal_attack;
                break;
            }
        }
        live_player += computer_damage;
        live_computer += player_damage;
        if (live_player < 0)
        {
            live_player = 0;
        }
        if (live_computer < 0)
        {
            live_computer = 0;
        }
        cout << "\n\nyour health is " << live_player << " and fire : " << player_fire_time
             << " and dam : " << player_dam_time << "\n"
             << " and tornado : "
             << player_tornado_time << "\n\n";

        cout << "computer health is " << live_computer << " and fire : " << computer_fire_time
             << " and dam : " << computer_dam_time << " and tornado : "
             << computer_tornado_time << "\n\n";
    }
    if (live_player < live_computer)
    {
        cout << "GAME OVER , COMPUTER WIN\n";
        log_out();
    }
    else if (live_computer < live_player)
    {
        cout << "GAME OVER , **********YOU WIN********\n";
        log_out();
    }
}

// SPS game function
void SPS()
{
    short times = 3, my_score = 0, computer_score = 0;
    // bool ry = true;
    string player, computer, user;
    srand(time(0));
    string arr[3] = {"stone", "scissors", "paper"};
    for (int i = 0; i < 58; i++)
    {
        cout << "*";
    }
    cout << "\n*welcome in our game ( (1)stone & (2)paper & (3)scissors)*\n";
    for (int i = 0; i < 58; i++)
    {
        cout << "*";
    }
    while (times > 0)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "\n"
                 << arr[i] << "\n";
        }
        cout << "\n\n please enter your turn (enter 1 or 2 or 3 ) : ";
        cin >> user;
        if (user == "1")
            player = arr[0];
        else if (user == "2")
            player = arr[1];
        else if (user == "3")
            player = arr[2];
        else
            cout << "wrong input , try again : ";
        computer = arr[rand() % 3];
        cout << "\n\n"
             << player << "\n\nvs\n\n"
             << computer << "\n";
        cout << "\n*******\n";
        if (player == "stone" && computer == "scissors")
        {
            my_score++;
            times--;
        }
        else if (player == "stone" && computer == "paper")
        {
            computer_score++;
            times--;
        }
        else if (player == "scissors" && computer == "stone")
        {
            computer_score++;
            times--;
        }
        else if (player == "scissors" && computer == "paper")
        {
            my_score++;
            times--;
        }
        else if (player == "paper" && computer == "stone")
        {
            my_score++;
            times--;
        }
        else if (player == "paper" && computer == "scissors")
        {
            computer_score++;
            times--;
        }
        else if (player == "stone" && computer == "stone")
        {
            cout << "\n**********Draw*********\n";
        }
        else if (player == "scissors" && computer == "scissors")
        {
            cout << "\n**********Draw*********\n";
        }
        else if (player == "paper" && computer == "paper")
        {
            cout << "\n**********Draw*********\n";
        }
    }
    cout << "\n\n**********finished**********\n\n";
    cout << "\nyour score is " << my_score << " and the computer is " << computer_score << endl;
    if (my_score > computer_score)
    {
        cout << "\n\n******you win******\n\n";
        log_out();
    }
    else if (my_score < computer_score)
    {
        cout << "\n\n******computer win******\n\n";
        log_out();
    }
}

// the body of the code
int main()
{

    while (i == 0)
    { // make sure that the log_in function will run only one time
        log_in();
        i++;
    }
    while (n != 0)
    {
        if (login == 1)
        { // display options
            options();
            if (answer == 1)
            { // first game (guess game)
                guess();
            }
            else if (answer == 2)
            { // second game (test your info)
                test();
            }
            else if (answer == 3)
            { // Third game(monsters game)
                attack();
            }
            else if (answer == 4)
            { // fourth game(try to survive)
                SPS();
            }
            else if (answer == 5)
            {
                n = false;
            }
            else
            {
                cout << "wrong input , try again\n\n ";
            }
        }
    }
    if (n == 0)
    {
        cout << "\nok , let us see you again :(\n\n";
    }
}