In a chemical laboratory, there are N different substances that are hazardous experimental waste and must be placed in K metal bottles to be safely transported to a special area outside the laboratory. The substances are numbered from 1 to N and, for safety reasons, should be placed in bottles in this order with the total amount of each substance in a single bottle. The bottles are large enough and the total amount of each substance small enough so that there are no capacity problems (ie even all the substances could fit in the same bottle). However, there is a risk of a chemical reaction between the substances in the same bottle, in which case significant amounts of energy are released. Specifically, for each pair of substances i and j contained in the same flask, the chemical reaction between them produces an energy equal to A [i, j] units.
Based on the above, the procedure followed by the laboratory managers for the packaging of the substances is as follows: The first t1 substances in a row are placed in the first bottle, the next t2 substances in the second bottle, and so on, until place all substances in the K bottles. Thus, the energy that can be produced by the chemical reaction of the substances in the first flask is \ sum {1 <= i <j <= t_1} A [i, j], for the second flask it is \ sum_ {t_1 + 1 < = i <j <= t2} A [i, j], and so on.  The total energy that could be produced by the chemical reaction of the substances in all K bottles is the sum of the above quantities. For safety reasons during the transport of the substances, the laboratory managers want to determine the ratios t1, t2, ..., t (K-1) of the substances where the bottle will be changed, so that the total energy that could be released from all bottles to be as small as possible. So you are asked to write a program for this purpose.

Input Data:
Initially, the program will read from the standard input two positive integers N and K that represent the number of substances and the number of bottles. The program will then read N-1 lines, the i-th of which will contain N-i integers separated by spaces. The j-th integer of the i-th line corresponds to the energy A [i, j + i] (array A is symmetric about the diagonal, i.e. A [i, j] = A [j, i] for every 1 <= i <j <= N, and the diagonal has zero elements, i.e. A [i, i] = 0 for every 1 <= i <= N).

Output Data:
The program must print in the standard output (on the first line) an integer corresponding to the minimum amount of energy that can be released.

Restrictions
0 <= A [i, j] <= 99
1 <= K <= 500
K <= N <= 1500

Bonus: some files with 1 <= K <= 700 and K <= N <= 2500

Execution time limit: 1 sec.
Memory limit: 64 MB.
