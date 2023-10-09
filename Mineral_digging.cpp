#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//논리 설명 
// 1. 광물을 5개단위로 묶어서 가중치를 주고 가중치가 높은 순서대로 정렬 
// 2. 광물을 5개단위로 묶었을때 (다이아 , 철 ,돌) 곡괭이로 채굴했을때 피로도가 구조체에 저장되있음.
// 3. 이후 picks 배열에 있는 곡괭이중 0 -> 1 ->2 순으로 광물이 없어지거나 곡괭이를 다쓸때 까지 광물 개패주면서 피로도를 더해주면 ->answer값 

struct MineSet
{
    int d_f = 0; // 다이아 채굴수
    int i_f = 0; // 철 채굴수 
    int s_f = 0; // 돌 채굴수
    int weight = 0; // 가중치
};

bool cmp(MineSet m1, MineSet m2)
{
    return m1.weight > m2.weight;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    vector<MineSet> mineset_list;

    int total_picks = picks[0] + picks[1] + picks[2]; // 곡괭이 총합

    for (int i = 0; i < minerals.size(); i += 5)
    {
        if (total_picks <= 0)
            break;

        // 5개의 광물을 각각의 곡괭이를 사용했을때의 각각의 피로도
        MineSet mineset;


        for (int j = 0; j < 5; j++)
        {

            if (i + j < minerals.size())
            {
                auto mineral = minerals.begin() + i + j;
                if (mineral == minerals.end())
                    continue;

                if (*mineral == "diamond") // 광물이 다이아면 다이아 곡괭이 피로도 1 , 철 곡괭이 피로도 5 , 돌 곡괭이 피로도 25 추가
                {
                    mineset.d_f += 1;
                    mineset.i_f += 5;
                    mineset.s_f += 25;
                    mineset.weight += 25;
                }
                else if (*mineral == "iron")// 광물이 철이면 다이아 곡괭이 피로도 1 , 철 곡괭이 피로도 1 , 돌 곡괭이 피로도 5 추가
                {
                    mineset.d_f += 1;
                    mineset.i_f += 1;
                    mineset.s_f += 5;
                    mineset.weight += 5;
                }
                else if (*mineral == "stone")//광물이 돌면 다이아 곡괭이 피로도 1 , 철 곡괭이 피로도 1, 돌 곡괭이 피로도 1 추가
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

