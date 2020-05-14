.PHONY: clean

main.jar: pro/lab/main/Main.class manifest
	jar -cfm main.jar manifest pro/lab/main/Main.class pro/lab/matrix/Matrix.class pro/lab/task/Task.class

pro/lab/main/Main.class: pro/lab/main/Main.java pro/lab/task/Task.class pro/lab/matrix/Matrix.class
	javac pro/lab/main/Main.java

pro/lab/task/Task.class: pro/lab/matrix/Matrix.class pro/lab/task/Task.java
	javac pro/lab/task/Task.java

pro/lab/matrix/Matrix.class: pro/lab/matrix/Matrix.java
	javac pro/lab/matrix/Matrix.java

clean:
	rm -rfv main.jar
	find pro/ -type f -name "*.class" -delete
