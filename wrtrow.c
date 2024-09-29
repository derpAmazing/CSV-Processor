/*
 * wrtrow
 *
 * usage:   Writes a CSV row to the output. The columns in the output row
 *          are selected columns from the input row. The columns selected for
 *          output are contained in the entries in coltab. The order of columns
 *          in the output row is from element 0 to element cnt-1 in coltab.
 *          An array of pointers to each of the input columns is used to output
 *          the column's data.
 *          Note: Use printf to output the column data and the delimiters
 *
 * arguments:
 *  ptable  points at array of pointers, each element points at a single columns
 *          data
 *  coltab points array of ints, each element is an offset into ptable. The order
 *          of elements in the array specifies the column order in the output
 *          row
 *  cnt     number of elements in array coltab
 *  delim   the output column delimiter to use
 *
 * Return values:
 *          -1 if if an error is detected (printf fails)
 *          otherwise returns the number of columns printed
 *
 * error messages:
 *          this function does not write any error messages
 */

#include "version.h"
#ifndef MYWRTROW
#warning("WARNING - USING THE SOLUTION writerow.c NOT MY CODE")
#else
#include <stdio.h>
#include "wrtrow.h"

int
wrtrow(char **ptable, int *coltab, int cnt, char delim)        
{
	int columnsPrinted = 0;
	for (int i = 0; i < cnt; i++) {
		int columnToPrint = *(coltab + i);
		if (printf("%s", *(ptable + columnToPrint)) < 0) {
			return -1;
		}
		columnsPrinted += 1;
		
		if (i < (cnt - 1)) {
			if (printf("%c", delim) < 0) {
				return -1;
			}
		}
	}

	if (printf("\n") < 0) {
		return -1;
	}

	return columnsPrinted;
}
#endif  // do not delete this line
