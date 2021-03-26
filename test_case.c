#include "_levenshtein.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char** argvs) {
	const char* str1 = "自然语言生成可以视为自然语言理解的反向：自然w语言理你解系统需要厘清输入句的意涵，从而产生机器表述语言；自然语言生成系统需要决定如何把概念转化成语言。";
	const char* str2 = "自然语言生成可以视为自然语言解的反向：言理解系统需要厘清输入句的意涵，从而产生机器表述语言，自然语言生成系统需要决定如何把概转化语言。";
	struct timeval start1, end1;
	gettimeofday(&start1, NULL);
	int i = 0;
	for (; i < 100000; ++i) {
		int distance = lev_edit_distance(strlen(str1), str1, strlen(str2), str2, 0);
		if (i % 10000 == 0)
			printf("%d : %ld\n", i, distance);
	}
	gettimeofday(&end1, NULL);
	printf("cost: %.2f ms\n", (float)((end1.tv_sec - start1.tv_sec) * 1000000 + (end1.tv_usec - start1.tv_usec)) / 1000);

}
