#include <bits/stdc++.h>

using namespace std;
char chrs[] = {'A', 'G', 'C', 'T'};

string generate_beggining_seq(int l)
{
	string beggining_seq;
	for (int i = 0; i < l; i++)
	{
		beggining_seq += chrs[rand() % 4];
	}
	return beggining_seq;
}

float get_random_float()
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

string get_next_char(char c, float p, int len)
{
	float r = get_random_float();
	if (r < p)
	{
		if (len > 15)
		{
			int mut = rand() % 3;
			if (mut == 0)
				return "";
			else if (mut == 1)
				return string(1, chrs[rand() % 4]);
			else
				return string(1, c) + string(1, chrs[rand() % 4]);
		}
		else
		{
			int mut = rand() % 2;
			if (mut == 0)
				return string(1, chrs[rand() % 4]);
			else
				return string(1, c) + string(1, chrs[rand() % 4]);
		}
		
	}
	return string(1, c);
}

void generate_seq(int l, int n, double p)
{
	srand(time(0));
	int base = 0;
	srand(base);

	string beggining_seq = generate_beggining_seq(l);
	ofstream output("gen_" + to_string(base) + "_" + to_string(l) + "_" + to_string(n) + "_" + to_string(p));
	
	int cnt = 1;
	string res;
	while (cnt <= n || res.size() < l * n)
	{
		cerr << res.size() << endl;
		cnt ++;
		output << beggining_seq;
		res += beggining_seq;
		string next_seq;
		for (auto c : beggining_seq)
		{
			string res = get_next_char(c, p, beggining_seq.size());
			next_seq += res;
		}
		beggining_seq = next_seq;
	}

	output.close();
}
int main()
{
	int l, n;
	float p;
	cout << "L: ";
	// cin >> l;
	l = 25;
	cout << "N: ";
	// cin >> n;
	n = 40000;
	cout << "P: ";
	// cin >> p;
	p = 0.02;
	generate_seq(l, n, p);
}