#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//�� ���� 
// 1. ������ 5�������� ��� ����ġ�� �ְ� ����ġ�� ���� ������� ���� 
// 2. ������ 5�������� �������� (���̾� , ö ,��) ��̷� ä�������� �Ƿε��� ����ü�� ���������.
// 3. ���� picks �迭�� �ִ� ����� 0 -> 1 ->2 ������ ������ �������ų� ��̸� �پ��� ���� ���� �����ָ鼭 �Ƿε��� �����ָ� ->answer�� 

struct MineSet
{
    int d_f = 0; // ���̾� ä����
    int i_f = 0; // ö ä���� 
    int s_f = 0; // �� ä����
    int weight = 0; // ����ġ
};

bool cmp(MineSet m1, MineSet m2)
{
    return m1.weight > m2.weight;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    vector<MineSet> mineset_list;

    int total_picks = picks[0] + picks[1] + picks[2]; // ��� ����

    for (int i = 0; i < minerals.size(); i += 5)
    {
        if (total_picks <= 0)
            break;

        // 5���� ������ ������ ��̸� ����������� ������ �Ƿε�
        MineSet mineset;


        for (int j = 0; j < 5; j++)
        {

            if (i + j < minerals.size())
            {
                auto mineral = minerals.begin() + i + j;
                if (mineral == minerals.end())
                    continue;

                if (*mineral == "diamond") // ������ ���̾Ƹ� ���̾� ��� �Ƿε� 1 , ö ��� �Ƿε� 5 , �� ��� �Ƿε� 25 �߰�
                {
                    mineset.d_f += 1;
                    mineset.i_f += 5;
                    mineset.s_f += 25;
                    mineset.weight += 25;
                }
                else if (*mineral == "iron")// ������ ö�̸� ���̾� ��� �Ƿε� 1 , ö ��� �Ƿε� 1 , �� ��� �Ƿε� 5 �߰�
                {
                    mineset.d_f += 1;
                    mineset.i_f += 1;
                    mineset.s_f += 5;
                    mineset.weight += 5;
                }
                else if (*mineral == "stone")//������ ���� ���̾� ��� �Ƿε� 1 , ö ��� �Ƿε� 1, �� ��� �Ƿε� 1 �߰�
                {
                    mineset.d_f += 1;
                    mineset.i_f += 1;
                    mineset.s_f += 1;
                    mineset.weight += 1;
                }
            }

        }
        total_picks--;
        mineset_list.push_back(mineset);
    }
    ::sort(mineset_list.begin(), mineset_list.end(), cmp);

    for (const auto& m : mineset_list)
    {
        if (picks[0] > 0)
        {
            picks[0]--;
            answer += m.d_f;
        }
        else if (picks[1] > 0)
        {
            picks[1]--;
            answer += m.i_f;
        }
        else if (picks[2] > 0)
        {
            picks[2]--;
            answer += m.s_f;
        }

    }

    return answer;
    
}
   
int main()
{
    vector<int>v = { 1,3,2 };
    vector<string>s_v = {"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"};

    int a = solution(v, s_v);

    cout << "answer :" << a << endl;
}

