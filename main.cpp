/*
ADVANTAGES/DISADVANTAGES LINKED LIST

ADVANTAGES/DISADVANTAGES ARRAY
*/

#include "linkedlist.h"





int main()
{

    string userName, newCommandToAdd, oldCommandTodelete;
    int selection;
    ifstream infile;
    infile.open("commands.csv");
    ifstream playerfile;
    playerfile.open("playerinfo.csv");
    LinkedList<string, string> commands = {};
    LinkedList<string, int> playerinfo = {};
    Node<string, string>* n;
    int answer = 0, one = 1, two = 2, three = 3;
    commands.createlist(infile);
    playerinfo.createlist(playerfile);
    while (true)
    {
        cout << "Please select an option listed below:\n";
        cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit\n";
        cout << "Your selection: ";
        cin >> selection;

        if (cin.fail()) // the input is not an integer
        {
            cout << "Your selection is invalid. Please select again." << endl;
            cout << "=============================================================================" << endl << endl;
            cin.clear();
            cin.ignore();
        }
        else
        {
            switch (selection)
            {
            case 1: // Game Rules
            {
                cout << "================================= Game Rule ===================================" << endl;
                cout << "To play the game, select \"2\" where you will be prompted for your name and number of questions.\n";
                cout << "Each question presents a specific Linux command where you will be able to choose from 3 different options. Each correct answer yields a point.\n";
                cout << "You can also add and delete commands as needed.\n";
                cout << "================================= Game Rule ===================================" << endl << endl;

                break;
            }

            case 2:// 2. Play Game;   // 3. Load Previous Game
            {
                cout << "Please enter your name: ";
                cin >> userName;

                while (playerinfo.getpRoam() != nullptr)
                {
                    playerinfo.setpRoam(*playerinfo.getpRoam()->getpNext());

                }
                playerinfo.getpRoam()->setVar1(userName);
                while (answer != 4)
                {
                    cout << commands.getpRoam()->getVar1() << endl;
                    cout << one << ": " << commands.getpRoam()->getVar2() << endl;
                    cout << two << ": " << commands.getpRoam()->getpNext()->getVar2() << endl;
                    cout << three << ": " << commands.getpRoam()->getpNext()->getpNext()->getVar2() << endl;
                    cout << "4: " << "exit" << endl;
                    cin >> answer;
                    if (answer == 1)
                    {
                        cout << "correct" << endl;
                        playerinfo.getpRoam()->setVar2(playerinfo.getpRoam()->getVar2() + 1);
                    }
                    else
                    {
                        cout << "incorrect" << endl;
                        playerinfo.getpRoam()->setVar2(playerinfo.getpRoam()->getVar2() - 1);
                    }
                    commands.setpRoam(*commands.getpRoam()->getpNext());
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 3:// 2. Play Game;   // 3. Load Previous Game
            {
                cout << "Please enter your name: ";
                cin >> userName;

                while (playerinfo.getpRoam()->getVar1() != userName)
                {
                    playerinfo.setpRoam(*playerinfo.getpRoam()->getpNext());
                    if (playerinfo.getpRoam() == nullptr)
                    {
                        cout << "this player does not exist";
                        break;
                    }
                }
                while (answer != 4)
                {
                    cout << commands.getpRoam()->getVar1() << endl;
                    cout << one << ": " << commands.getpRoam()->getVar2() << endl;
                    cout << two << ": " << commands.getpRoam()->getpNext()->getVar2() << endl;
                    cout << three << ": " << commands.getpRoam()->getpNext()->getpNext()->getVar2() << endl;
                    cout << "4: " << "exit" << endl;
                    cin >> answer;
                    if (answer == 1)
                    {
                        cout << "correct" << endl;
                        playerinfo.getpRoam()->setVar2(playerinfo.getpRoam()->getVar2() + 1);
                    }
                    else
                    {
                        cout << "incorrect" << endl;
                        playerinfo.getpRoam()->setVar2(playerinfo.getpRoam()->getVar2() - 1);
                    }
                    commands.setpRoam(*commands.getpRoam()->getpNext());
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 4: // Add Command
            {
                cout << "To add a command to the library, please enter the command name that you would add: ";
                cin >> newCommandToAdd;
                while (commands.getpRoam() != nullptr)
                {
                    commands.setpRoam(*commands.getpRoam()->getpNext());
                }
                commands.getpRoam()->setVar1(newCommandToAdd);
                cout << "now enter the definition of the command";
                commands.getpRoam()->setVar2(newCommandToAdd);
                break;
            }

            case 5: // Remove Command
            {
                cout << "Please enter the name of the command that you would remove: ";
                cin >> oldCommandTodelete;
                while (commands.getpRoam()->getpNext()->getVar1() != oldCommandTodelete)
                {
                    commands.setpRoam(*commands.getpRoam()->getpNext());
                    if (commands.getpRoam() == nullptr)
                    {
                        cout << "this command does not exist";
                        break;
                    }
                }
                n = commands.getpRoam()->getpNext();
                commands.getpRoam()->setpNext(commands.getpRoam()->getpNext()->getpNext());
                delete n;
                break;
            }

            case 6: // Exit
            {
                return 0;
            }

            
            } // end of switch(selection)
            system("pause");
            system("cls");
        } // end of else: check (cin.fail())

    } // end of while(true)

    infile.close();
    playerfile.close();
    ofstream playerfile2;
    playerfile2.open("playerinfo.csv");
    ofstream commsfile;
    commsfile.open("commands.csv");
    commands.outputtofile(commsfile);
    playerinfo.outputtofile(playerfile2);
    playerfile.close();
    commsfile.close();
} // end of int main()


