#pragma warning(disable:4996)
#include<iostream>
#include <stdio.h>
using namespace std;

int num(0);
int area(0);
int table[5][10] = { 0, };

void calc_area()
{
	int w1 = 0;
	int w2 = 0; 
	int h1 = 0;
	int h2 = 0;

	for (int i = 0; i < num; i++)
	{
		w1 += table[1][i];
		h1 += table[2][i];
		w2 += table[3][i];
		h2 += table[4][i];
	}

	if ((w1 == w2) && (h1 == h2) && w1 != 0 && w2 != 0 && h1 != 0 && h2 != 0)
	{
		int tmp(0);
		tmp = w1 * h1;
		if (area <= tmp)
		{
			area = tmp;
		}
	}
}


void labelling(int idx, int* beam)
{
	for (int i = 0; i<5; i++)
	{
		//cout << "idx = " << idx << endl;
		table[i][idx] = beam[idx];
		if (idx<num-1)
		{
			idx++;
			labelling(idx, beam);
			idx--;
		}
		else
		{
			calc_area();
		}
		//계산 끝났으면 초기화
		table[i][idx] = 0;
	}
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int beam[10] = { 0, };
		cin >> num;
		cout << "number of beams = " << num << endl;
		for (int i = 0; i<num; i++)
		{
			cin >> beam[i];
			cout << beam[i] << " ";
		}
		cout << endl;
		// 0: x , 1:위, 2:오른, 3:아래, 4:왼

		//labelling
		labelling(0, beam);

		printf("#%d %d\n", test_case, area);


		num = 0;
		area = 0;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}