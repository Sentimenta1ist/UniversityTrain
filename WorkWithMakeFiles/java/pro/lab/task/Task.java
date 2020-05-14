package pro.lab.task;

import java.util.function.Function;
import pro.lab.matrix.Matrix;

public class Task {

	public static Matrix Func(Matrix m){
		var matrix  = m;
		int n = m.n;

		int i_first_max = 0;
    	int i_last_min = 0;
    	double value_first_max = matrix.data[0][n-1], value_last_min = matrix.data[0][n-1];

		for(int i = 0; i < n; i++){
            if(matrix.data[i][n - 1 - i] > value_first_max){
                i_first_max = i;
                value_first_max = matrix.data[i][n - 1 - i];
            }
            if(matrix.data[i][n - 1 - i] <= value_last_min){
                i_last_min = i;
                value_last_min = matrix.data[i][n - 1 - i];
            }

        }

        System.out.printf("Swap: First max - (%d;%d), Last min - (%d;%d)\n\n",
        i_first_max,n - 1 - i_first_max,i_last_min,n - 1 - i_last_min);
        matrix.data[i_first_max][ n - 1 - i_first_max] = value_last_min;
    	matrix.data[i_last_min][ n - 1 - i_last_min] = value_first_max;


		return matrix;
	}

}
