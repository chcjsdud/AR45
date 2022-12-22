// 73.NameSapce.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 별명 붙이기 혹은 이름 늘리기입니다.
namespace Skill 
{
    namespace AttackSkll
    {
        class Skill
        {
        public:
            int Att;
        };
    }
}

namespace Skill
{
    class DSkill 
    {

    };
}

namespace std 
{
    class MyCout 
    {
    public:
        MyCout& operator <<(const char* _Text) 
        {
            printf_s(_Text);
            return *this;
        }

        MyCout& operator <<(int _Value)
        {
            // printf_s(_Text);
            return *this;
        }
    };

    MyCout mcout;
}

// using namespace Skill;

// 절대로 사용하지 않는다.
// using namespace std;

int main()
{
    Skill::DSkill;

    // Skill::QSkill::Att;
    // Skill::AttackSkll::QSkill::Att;

    // AttackSkll::Skill;

    // std::mcout << "Hello World!\n" << "Hello World!\n";
    // std::mcout << 1;

    // std::cout << 1;

    // std::cout.operator<<(1);
}
