#include <iostream>
#include <vector>

using namespace std;

int gap_penalty = -2;
int match = 5;
int miss = -1;

int get_match_score(char a, char b)
{
	if(a == b)
		return match;

	return miss;
}

unsigned int nw_align(const string seq_one, const string seq_two, int offset_seq1,
			int offset_seq2, int seq1_len, int seq2_len)
{
	string seq1 = seq_one.substr(offset_seq1, seq1_len);
	string seq2 = seq_two.substr(offset_seq2, seq2_len);

	int m = seq1_len;
	int n = seq2_len;

	vector<vector<int> > score(m+1, vector<int>(n+1));
	
	for(int i=0; i<=m; i++)
		score[i][0] = gap_penalty * i;

	for(int i=0; i<=n; i++) 
                score[0][i] = gap_penalty * i; 

	cout << "\nDP Matrix Initialized" << endl;	

	int iden = 0;
	int del = 0;
	int ins = 0;

	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {

			iden = score[i-1][j-1] + get_match_score(seq1[i-1], seq2[j-1]);
			del = score[i-1][j] + gap_penalty;
			ins = score[i][j-1] + gap_penalty;

			score[i][j] = max(max(iden, del), ins);
		}
	}

	cout << "Score Calculated!" << endl;


	string align1="", align2="";

	int i = m, j= n;

	int scr_cur;
	int scr_diag;
	int scr_left;
	int scr_up;

	while(i && j) {

		scr_cur = score[i][j];
		scr_diag = score[i-1][j-1];
		scr_up = score[i][j-1];
		scr_left = score[i-1][j];


		if(scr_cur == scr_diag + get_match_score(seq1[i-1], seq2[j-1])) {
			align1 += seq1[i-1];
			align2 += seq2[j-1];

			i--;
			j--;
		}
		else if(scr_cur == scr_left + gap_penalty) {
			align1 += seq1[i-1];
			align2 += '-';
			
			i--;
		}
		else if(scr_cur == scr_up + gap_penalty) {
			align1 += '-';
			align2 += seq2[j-1];
		
			j--;
		}	

	}


	while(i>0) {

		align1 += seq1[i-1];
		align2 += '-';
		i--;

	}


	while(j > 0) {
		align1 += '-';
		align2 += seq2[j-1];
	}

	string output(align2.rbegin(), align2.rend());
	string orig_seq(align1.rbegin(), align1.rend()); 

	cout << "\nOutput   :  " << output << endl; 
	cout << "Sequence :  " << orig_seq << endl; 
	
}

int main()
{
	string seq1_init = "DDFGACTACTTAC";
	string seq2_init = "FACGC";

	int m1 = 3;
	int length = 6;
	int m2 = 1;
	int length2 = 4;

	string seq1 = seq1_init.substr(m1, length);
	string seq2 = seq2_init.substr(m2, length2);
 
	cout << "Sequence 1 : " << seq1 << endl;
	cout << "Sequence 2 : " << seq2 << endl;

	nw_align(seq1_init, seq2_init, m1, m2, length, length2);
	return 0;
}  
