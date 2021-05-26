#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[20];
	int kor;
	int eng;
	int math;
	int sum;
	double average;
	int rank;
} Student;

int main(void)
{

	FILE *fin;
	FILE *fout;
	
	fin = fopen("score.dat", "r");
	fout = fopen("score.out", "w");
	
	if (fin == NULL || fout == NULL) {
		printf("can't open file\n");
		exit(-1);
	}
	
	Student students[10];
	
	for(int i = 0; i < 10; ++i) {
		fscanf(fin, "%s %d %d %d", 
				students[i].name, &students[i].kor, &students[i].eng, &students[i].math);
	}
	
	for(int i = 0; i <10; ++i) {
		students[i].sum = students[i].kor + students[i].eng + students[i].math;
		students[i].average = (double)students[i].sum/3;
		students[i].rank = 1;
	}
	
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			if(students[j].sum > students[i].sum) {
					++students[i].rank;
			}
		}
	}
		
	
	fprintf(fout, "-------------------------------------------------\n");
	fprintf(fout, "   name              kor eng mat sum   avg   rnk\n");
	fprintf(fout, "-------------------------------------------------\n");
	for(int i = 0; i < 10; ++i) {
		fprintf(fout, "%-20s %3d %3d %3d %3d %6.2f %3d\n", 
				students[i].name, students[i].kor, students[i].eng, students[i].math, students[i].sum,
				students[i].average, students[i].rank);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
