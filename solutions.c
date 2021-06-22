#include <stdio.h>
#include <stdlib.h>
#include <dtools.h>
#include "solutions.h"

int *naive_fsort(arg_st nms)
{
	/* full sort */
	unsigned int index = 0;
	unsigned int inside;

	/* TODO remember free it the return data */
	int *result = (int *)malloc(sizeof(nms.nums));
	int template;
	for (; index < (nms.size - 1); index++) {
		inside = index + 1;
		for (; inside < nms.size; inside++) {
			// TODO del
			// printf("%d\t%d\n", index, inside);
			if (*(nms.nums + inside) < *(nms.nums + index)) {
				template = *(nms.nums + index);
				*(nms.nums + index) = *(nms.nums + inside);
				*(nms.nums + inside) = template;
			}
		}
	}
	result = nms.nums;
	return result;
}

void naive_fsort_r(arg_st nms, int **result_arg)
{
	/* full sort */
	unsigned int index = 0;
	unsigned int inside;
	int template;
	for (; index < (nms.size - 1); index++) {
		inside = index + 1;
		for (; inside < nms.size; inside++) {
			if (*(nms.nums + inside) < *(nms.nums + index)) {
				template = *(nms.nums + index);
				*(nms.nums + index) = *(nms.nums + inside);
				*(nms.nums + inside) = template;
			}
		}
	}
	for (index = 0; index < nms.size; index++) {
		*(*result_arg + index) = *(nms.nums + index);
	}
	return (void) NULL;
}

static inline __is_into__(int num, int *nums, int size)
{
	for (unsigned int index = 0; index < size; index++)
		if (num == *(nums + index))
			return 0;
	return 1;
}

void naive_rotate(int *nms, const int siz, const int mov)
{}

/* naive intersect */
int *naive_intersect(int *nms1, int *nms2, int nms1_siz, int nms2_siz)
{
	unsigned int index = 0;
	unsigned int count = 0;
	unsigned int inside = 0;
	int _min = ((nms1_siz < nms2_siz) ? nms1_siz : nms2_siz);
	int buf[_min];
	for (; index < _min; index++) {
		for (inside = 0; inside < nms2_siz; inside++) {
			if (*(nms1 + index) == *(nms2 + inside)) {
				buf[count] = *(nms1 + index);
				nms2_siz--;
				count++;
				//mov_index(nms2, insde, nms2_siz);
				for (unsigned int _index = inside; \
						_index < (nms2_siz - 1);\
					       	_index++)
					*(nms2 + _index) = *(nms2 + (_index + 1));
				break;
			}
		}
}

int main()
{
	int nms[5] = {0,1,2,3,4};
	return 0;
}
