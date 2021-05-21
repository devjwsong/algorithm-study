#include <iostream>
#include <vector>

using namespace std;

int N, M;

void track(int cur, int num, vector<int> seq) {
	
	if (num == M) {
		for (int i=0; i<seq.size(); ++i) {
			printf("%d ", seq[i]);
		}
		printf("\n");
	} else {
		for (int j=cur; j<=N; ++j) {
				vector<int> cpy = seq;
			    cpy.push_back(j);
			    track(j, num+1, cpy);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i=1; i<=N; ++i) {
		vector<int> note;
		note.push_back(i);
		track(i, 1, note);
	}
	
	return 0;
}