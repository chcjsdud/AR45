#include <iostream>
#include <conio.h>
#include "Monster.h"
#include "Player.h"


//class int
//{
//};
class DamageSimulGame 
{
public:
    void EndMassage() 
    {
        printf_s("게임이 종료되었습니다.\n");
    }
};

int main()
{
    DamageSimulGame NewGame;
    Player NewPlayer;
    Monster NewMonster;

    // NewMonster + NewMonster;

    // NewMonster + NewMonster;


    while (true)
    {
        system("cls");

        NewPlayer.StatusRender();
        NewMonster.StatusRender();
        _getch();

        NewMonster.Damage(NewPlayer.GetAtt());

        if (true == NewMonster.IsDeath())
        {
            NewGame.EndMassage();
            return 0;
        }

        NewPlayer.Damage(NewMonster.GetAtt());

        if (true == NewPlayer.IsDeath())
        {
            NewGame.EndMassage();
            return 0;
        }
    }
}
