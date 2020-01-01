#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char line1[10000];
	char temp1[50];
	char nat1[50][50], nat2[50][50];
	char* token;

	FILE* file1 = fopen("NAT.txt", "r");
	int i = 0;
	while (fgets(line1, sizeof(line1), file1)) {
		sscanf(line1, "%s", temp1);
		token = strtok(temp1, ",");
		strcpy(nat1[i], token);
		token = strtok(NULL, ",");
		strcpy(nat2[i], token);

		printf("%s %s\n", nat1[i], nat2[i]);
		i++;
	};
	fclose(file1);


	char line2[10000];
	char temp2[50];
	char flow[50][50];
	FILE* file2 = fopen("FLOW.txt", "r");
	int j = 0;
	while (fgets(line2, sizeof(line2), file2)) {
		sscanf(line2, "%s", temp2);
		strcpy(flow[i], temp2);
		
		printf("%s\n", flow[i]);
		j++;
	};
	fclose(file2);

	return 0;
}