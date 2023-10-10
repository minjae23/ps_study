#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//  ���� 
// ��� �� number , ���ݷ� ���Ѽ�ġ limit ���� ��ġ�� �ʰ������� ����ҹ����� ���ݷ� power
// 1.1~number�� ������ ����� ������ ���ѵ� ����
// 2.���� ����� ������ limit ���� ũ�ٸ� -> power

// ����� ���� ���ϴ� �˰���
// ��� �ϳ��� �˸� �ٸ� �ϳ��� �˼� �ִ� . ex)  -> 10 �� ��� 2�� �˸� 10/2 =5 �� ���

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
                if (i != sqrtNum) {// ���� ����� ������ 1 2 4 8 16 ���� Ȧ���� ��� sqrt(num)���� �� i�� �����ϴٸ� ���
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