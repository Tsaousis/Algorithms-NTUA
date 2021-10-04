#include <iostream>
#include <algorithm> //sort
//#include<bits/stdc++.h> //binsearch
using namespace std;
int Ts, Cs, Tf, Cf, K, T, D;
float besttime(int C, int d) {
	if (C >= d * Cf) return d * Tf; //if possible to go fast the whole way, do it
	else if (C <= d * Cs) { //if only option is to go slow 
		return d * Ts;
	}
	else {
		float fastnum = C - d * Cs;
		int fastdenom = Cf - Cs;	//how much distance travelled fast
		float fastd = fastnum / fastdenom;

		float slowd = d - fastd; //how much distance travelled slowly
		return (slowd * Ts + fastd * Tf);
	}
}
//float iztime = 0.0f;
int binsearch(int d[], int l, int r) {
	int stationdistance = d[0];
	int solution = 0;
	int i = 0;
	while (l <= r)
	{
		float iztime = 0.0f;
		int m = l + (r - l) / 2; //fuel burnt. 
		if (K == 1) iztime += besttime(m, d[0]);
		else if (K == 2) {
			iztime += besttime(m, d[0]);
			iztime += besttime(m, d[1] - d[0]);
		}
		else {
			for (int i = 0; i < K - 1; i++) {
				iztime += besttime(m, stationdistance);
				stationdistance = d[i + 1] - d[i];
			}
		}
		iztime += besttime(m, D - d[K - 1]); //final distance as well
		if (iztime > T) { //if time>T look right -> burn more fuel
			//solvedproblem = false;
			l = m + 1;
		}
		else { //if time is good (time<T), look left to find an lower fuel consumption
			//solvedproblem = false;//true;
			solution = m;
			r = m - 1;
		}
		//time += besttime(m, dmax);

	}
	if (solution != 0) return solution;//l=r 
	else return -1;
}

int main() {
	int N, dmax; /*K,*/ /*D,*/ /*T, Ts, Cs, Tf, Cf,*/
	scanf("%d %d %d %d", &N, &K, &D, &T); //cin >> N >> K >> D >> T;
	int p[N], c[N], d[K]; //p->price, c->capacity, d->distance
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &p[i], &c[i]); //cin >> p[i] >> c[i];
	}
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &d[i]); //cin >> d[i];
	}
	scanf("%d %d %d %d", &Ts, &Cs, &Tf, &Cf); //cin >> Ts >> Cs >> Tf >> Cf;
	if (K == 1) {
		if (D - d[0] > d[0]) dmax = D - d[0];
		else dmax = d[0];
	}
	else {
		sort(d, d + K); //sorts di

		/*dmax = d[1] - d[0];
		for (int i = 1; i < K - 1; i++)
		{
			if ((d[i + 1] - d[i]) > dmax) dmax = d[i + 1] - d[i]; //calculates max distance between stations
		}*/
		dmax = d[0];
		for (int i = 0; i < K - 1; i++)
		{
			if ((d[i + 1] - d[i]) > dmax) dmax = d[i + 1] - d[i]; //calculates max distance between stations
		}
		if ((D - d[K - 1]) > dmax) dmax = D - d[K - 1];

	}
	int leastfuelcapacity = binsearch(d, Cs * dmax, Cf * dmax); //no need to put them in an array, they already form a theoretical array. The d array is used to give the info of the distances to binsearch function
	if (leastfuelcapacity == -1) printf("-1\n");//cout << "-1" << endl;
	else {
		int bestcar = 0;
		bool foundone = false;
		for (int i = 0; i < N; i++) {
			if (/*valid[i] == true*/ c[i] >= leastfuelcapacity) {
				bestcar = i;
				foundone = true;
				break;
			}
		}
		if (foundone == false) printf("-1\n");//cout << "-1" << endl;
		else {
			for (int i = 0; i < N; i++)
			{
				if (c[i] >= leastfuelcapacity && p[i] < p[bestcar]) bestcar = i;
			}
			printf("%d\n", p[bestcar]); //cout << p[bestcar] << endl;
		}
	}

}