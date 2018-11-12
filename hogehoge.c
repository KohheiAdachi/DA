#include <stab.h>
int main(void){
	char *figure1;
	char **figure2;

	char buf1[50]="あいうえお";
	char buf2[50]="かきくけこ";

	//buf1のポインタを代入
	figure1=buf1;

	//ポインタfigure1のポインタをfigure2に代入
	figure2=&figure1;

	//ポインタのポインタfigure2にbuf2の先頭アドレスを格納
	// *figure2=buf2;
	figure1 = buf1;

	//表示
	printf("%s\n",figure1);

	return 0;
}