package pro.lab.matrix;

import java.util.Scanner;
import java.util.Random;
import java.util.function.BiFunction;

public class Matrix {
    public double[][] data = null;
	public int n = 0;

	public Matrix(final int n) {
		data = new double[n][n];
		this.n = n;
	}

	public static Matrix Random(final int n) {
		var m = new Matrix(n);
		var rand = new Random();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) m.data[i][j] = rand.nextDouble() * n*n;

		return m;
	}

	public static Matrix Sorted(final int n) {
		var m = new Matrix(n);
		var it = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				m.data[i][j] = it++;

		return m;
	}

	public static Matrix BackSorted(final int n) {
		var m = new Matrix(n);
		var it = n * n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				m.data[i][j] = it--;

		return m;
	}

	public static Matrix Test(final int n) {
		var m = new Matrix(n);
		var it = n * n;
		for (int i = 0; i < n/2; i++)
			for (int j = 0; j < n; j++)
				m.data[i][j] = 4;

		for (int i = n/2; i < n; i++)
			for (int j = 0; j < n; j++)
				m.data[i][j] = 8;

		return m;
	}


	public double[][] getData() {
		return data;
	}

	public void display() {
        for (int i = 0; i < n; i++) {
        	for(int j = 0; j < n; j++){
        		System.out.printf("%4.0f", data[i][j]);
        	}			
        	        System.out.print("\n");
        }
        System.out.print("\n");
    }

    /*public static Matrix KeyboardMatrix(final int n) {
		var m = new Matrix(n);
		var in = new Scanner(System.in);
		System.out.println("Prepare to fill the matrix");
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				System.out.printf("Matrix item (%d, %d)=", i, j);
				m.data[i][j] = in.nextDouble();
			}
		return m;
	}*/
}
