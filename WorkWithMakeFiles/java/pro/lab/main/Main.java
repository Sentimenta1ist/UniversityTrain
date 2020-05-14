package pro.lab.main;

import pro.lab.matrix.Matrix;
import pro.lab.task.Task;

class Main {
    public static void main(String[] args) {
		final int n = 7;

		//sort matrix
		System.out.print("Sorted Before:\n");
		var m1 = Matrix.Sorted(n);
		m1.display();
		m1 = Task.Func(m1);
		System.out.print("Sorted After:\n");
		m1.display();
		System.out.print("\n\n");

		//random matrix
		System.out.print("Random Before:\n");
		m1 = Matrix.Random(n);
		m1.display();
		m1 = Task.Func(m1);
		System.out.print("Random After:\n");
		m1.display();
		System.out.print("\n\n");

		//backsorted
		System.out.print("BackSorted Before:\n");
		m1 = Matrix.BackSorted(n);
		m1.display();
		m1 = Task.Func(m1);
		System.out.print("BackSorted After:\n");
		m1.display();
		System.out.print("\n\n");

		//test
		System.out.print("Test Before:\n");
		m1 = Matrix.Test(n);
		m1.display();
		m1 = Task.Func(m1);
		System.out.print("Test After:\n");
		m1.display();
		System.out.print("\n\n");		
    }
}
