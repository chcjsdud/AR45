#include <iostream>
#include <conio.h>

//class int
//{
//};

class Player 
{
public:
    inline int GetAtt()
    {
        return Att;
    }

    inline bool IsDeath() 
    {
        return Hp <= 0;
    }

    void StatusRender() 
    {
        printf_s("플레이어 =====================================\n");
        printf_s("공격력 = %d \n", Att);
        printf_s("체  력 = %d \n", Hp);
        printf_s("============================================\n");
    }

    void Damage(int _Damage)
    {
        Hp -= _Damage;
        int Input = 0;
        printf_s("플레이어가 %d데미지를 받았습니다.\n", _Damage);
        Input = _getch();
        printf_s("플레이어는 %d체력이 남았습니다.\n", Hp);
        Input = _getch();
    }

protected:
private:
    int Att = 10;
    int Hp = 100;
};

class Monster
{
public:
    inline int GetAtt() 
    {
        return Att;
    }

    inline bool IsDeath()
    {
        return Hp <= 0;
    }

    inline void StatusRender()
    {
        printf_s("몬스터 =====================================\n");
        printf_s("공격력 = %d \n", Att);
        printf_s("체  력 = %d \n", Hp);
        printf_s("============================================\n");
    }

    inline void Damage(int _Damage)
    {
        Hp -= _Damage;
        int Input = 0;
        printf_s("몬스터가 %d데미지를 받았습니다.\n", _Damage);
        Input = _getch();
        printf_s("몬스터는 %d체력이 남았습니다.\n", Hp);
        Input = _getch();
    }

    void operator+(Monster& _Other) 
    {

    }

protected:
private:
    int Att = 10;
    int Hp = 100;
};

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
