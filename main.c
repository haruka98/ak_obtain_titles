#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* fp;
	char tempc;
	long long account_id;
	long title_id;
	if(fp = fopen("titles.sql", "r")) {
		fclose(fp);
		printf("Output file already exists, do you want to delete it? (y/N)\n");
		fflush(stdin);
		scanf("%c", &tempc);
		if(tempc == 'y' || tempc == 'Y') {
			remove("titles.sql");
		} else {
			return 1;
		}
	}
	fp = fopen("titles.sql", "a");
	printf("Enter account id:\n");
	fflush(stdin);
	scanf("%lld", &account_id);
	printf("Do you want to delete all your existing titles? (y/N)\n");
	fflush(stdin);
	scanf("%c", &tempc);
	if(tempc == 'y' || tempc == 'Y') {
		fprintf(fp, "DELETE FROM player_appellation WHERE account_id='%lld';\n", account_id);
	}
	printf("Enter highest title id: (ex. 1975)\n");
	fflush(stdin);
	scanf("%ld", &title_id);
	for(int i = 1; i <= title_id; i++) {
		fprintf(fp, "INSERT INTO \"player_appellation\" (\"account_id\", \"appellation_id\") VALUES (%lld, %ld);\n", account_id, i);
	}
	fclose(fp);
	return 0;
}