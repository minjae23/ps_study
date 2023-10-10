#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//  설명 
// 기사 수 number , 공격력 제한수치 limit 제한 수치를 초과했을때 사용할무기의 공격령 power
// 1.1~number의 각각의 약수의 개수를 구한뒤 저장
// 2.만약 약수의 개수가 limit 보다 크다면 -> power

// 약수의 개수 구하는 알고리즘
// 약수 하나를 알면 다른 하나도 알수 있다 . ex)  -> 10 의 약수 2를 알면 10/2 =5 도 약수

int solution(int number, int limit, int power) {
    int answer = 0;
   
    vector<int>v;
    for (int num = 1; num <= number; num++)
    {
        int count = 0;
        float sqrtNum = sqrt(num);
        for (int i = 1; i <=sqrtNum; i++)
        {
            if (num % i == 0) {
                count++;
                if (i != sqrtNum) {// 만약 약수의 개수가 1 2 4 8 16 같이 홀수인 경우 sqrt(num)값이 과 i가 동일하다면 통과
                    count++;
                }
            }
        }
        v.push_back(count);
    }
    for (const auto& a : v)
    {
        if (a <= limit)
        {
            answer += a;
        }
        else if (a > limit)
        {
            answer += power;
        }
    }
    return answer;
}

int main()
{

    int result=solution(10, 3, 2);

    cout << "result : " << result << endl;
}