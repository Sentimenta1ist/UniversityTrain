#include <SFML/Graphics.hpp>
#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h> 
#include <conio.h>   
#include <iostream> 
#include <locale.h>


int color1;
int color2;

void REC_2d(sf::RectangleShape &square, sf::RenderWindow &window, int k, int m);
void REC(sf::RectangleShape &square, sf::ConvexShape &convex, sf::ConvexShape &convex1, sf::RenderWindow &window, int k, int m);
void left(sf::RectangleShape &square, sf::ConvexShape &convex, sf::ConvexShape &convex1, sf::RenderWindow &window);
void right(sf::RectangleShape &square, sf::ConvexShape &convex, sf::ConvexShape &convex1, sf::RenderWindow &window);
void up(sf::RectangleShape &square, sf::ConvexShape &convex, sf::ConvexShape &convex1, sf::RenderWindow &window);
void down(sf::RectangleShape &square, sf::ConvexShape &convex, sf::ConvexShape &convex1, sf::RenderWindow &window);
void left1(sf::RectangleShape &square, sf::RenderWindow &window);
void right1(sf::RectangleShape &square, sf::RenderWindow &window);
void up1(sf::RectangleShape &square, sf::RenderWindow &window);
void down1(sf::RectangleShape &square, sf::RenderWindow &window);
void colorBack_square(sf::RectangleShape &square);
void colorBack_convex(sf::ConvexShape &convex);
void color_liter_sq(sf::RectangleShape &square);
void color_lit_convex(sf::ConvexShape &square);
void colorBack(sf::RenderWindow &window);
void MenuColor();
void lit_2d();
void Menu();
void repeat(int m);
void lit_3d();
void color_back();
void color_liter();


int main()
{
	system("color 02");
	Menu();
	system("pause");
	int m;
	scanf_s("%d", &m);
	repeat(m);
	return 0;
}


void REC_2d(sf::RectangleShape &square, sf::RenderWindow &window, int k, int m) {
	square.setSize(sf::Vector2f(50, 50));
	colorBack_square(square);
	color_liter_sq(square);
	square.setOutlineThickness(2);
	square.setPosition(k, m);
	window.draw(square);
}

void REC(sf::RectangleShape &square, sf::ConvexShape &convex, sf::ConvexShape &convex1, sf::RenderWindow &window, int k, int m) {

	square.setSize(sf::Vector2f(50, 50));
	colorBack_square(square);
	color_liter_sq(square);
	square.setOutlineThickness(2);
	square.setPosition(k, m);
	window.draw(square);

	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(k, m));
	convex.setPoint(1, sf::Vector2f(k + 25, m - 25));
	convex.setPoint(2, sf::Vector2f(k + 75, m - 25));
	convex.setPoint(3, sf::Vector2f(k + 50, m));
	colorBack_convex(convex);
	color_lit_convex(convex);
	convex.setOutlineThickness(2);
	window.draw(convex);

	convex1.setPointCount(4);
	convex1.setPoint(0, sf::Vector2f(k + 75, m - 25));
	convex1.setPoint(1, sf::Vector2f(k + 50, m));
	convex1.setPoint(2, sf::Vector2f(k + 50, m + 50));
	convex1.setPoint(3, sf::Vector2f(k + 75, m + 25));
	colorBack_convex(convex1);
	color_lit_convex(convex1);
	convex1.setOutlineThickness(2);
	window.draw(convex1);

	window.display();
}

void Menu() {
	system("cls");
	printf("\n\n");
	printf("\t\t ------------------------------------------------\n");
	printf("\t\t|               MENU(make a choice)              |\n");
	printf("\t\t|               1.2D letter                      |\n");
	printf("\t\t|               2.3D letter                      |\n");
	printf("\t\t|               3.Backgrounnd color              |\n");
	printf("\t\t|               4.Letter color                   |\n");
	printf("\t\t|               5.Exit                           |\n");
	printf("\t\t ------------------------------------------------ \n");
	printf("\n\n\n");
}

void MenuColor() {
	system("cls");
	printf("\n\n");
	printf("\t\t ------------------------------------------------\n");
	printf("\t\t|               COLOR(make a choice)             |\n");
	printf("\t\t|               1.White                          |\n");
	printf("\t\t|               2.Black                          |\n");
	printf("\t\t|               3.Green                          |\n");
	printf("\t\t|               4.Red                            |\n");
	printf("\t\t|               5.Yellow                         |\n");
	printf("\t\t ------------------------------------------------ \n");
	printf("\n\n\n");
}

void repeat(int m) {
	switch (m)
	{
	case 1:
		lit_2d();
		break;

	case 2:
		lit_3d();
		break;
	case 3:
		color_back();
		break;
	case 4:
		color_liter();
		break;
	case 5:
		return;
	}
}

void left(sf::RectangleShape &square, sf::ConvexShape &convex, sf::ConvexShape &convex1, sf::RenderWindow &window) {
	square.move(-1.f, 0.f);
	convex.move(-1.f, 0.f);
	convex1.move(-1.f, 0.f);
	window.draw(square);
	window.draw(convex);
	window.draw(convex1);
}
void right(sf::RectangleShape &square, sf::ConvexShape &convex, sf::ConvexShape &convex1, sf::RenderWindow &window) {
	square.move(1.f, 0.f);
	convex.move(1.f, 0.f);
	convex1.move(1.f, 0.f);
	window.draw(square);
	window.draw(convex);
	window.draw(convex1);
}
void up(sf::RectangleShape &square, sf::ConvexShape &convex, sf::ConvexShape &convex1, sf::RenderWindow &window) {

	square.move(0.f, -1.f);
	convex.move(0.f, -1.f);
	convex1.move(0.f, -1.f);
	window.draw(square);
	window.draw(convex);
	window.draw(convex1);

}
void down(sf::RectangleShape &square, sf::ConvexShape &convex, sf::ConvexShape &convex1, sf::RenderWindow &window) {
	square.move(0.f, 1.f);
	convex.move(0.f, 1.f);
	convex1.move(0.f, 1.f);
	window.draw(square);
	window.draw(convex);
	window.draw(convex1);
}

void left1(sf::RectangleShape &square, sf::RenderWindow &window) {
	square.move(-1.f, 0.f);
	window.draw(square);

}
void right1(sf::RectangleShape &square, sf::RenderWindow &window) {
	square.move(1.f, 0.f);
	window.draw(square);

}
void up1(sf::RectangleShape &square, sf::RenderWindow &window) {

	square.move(0.f, -1.f);
	window.draw(square);


}
void down1(sf::RectangleShape &square, sf::RenderWindow &window) {
	square.move(0.f, 1.f);
	window.draw(square);

}


void lit_3d() {
	sf::RenderWindow window(sf::VideoMode(1400, 900), "My window");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		sf::RectangleShape square1(sf::Vector2f(50, 50));
		sf::ConvexShape convex_;
		sf::ConvexShape convex1_;
		REC(square1, convex_, convex1_, window, 600, 400);

		sf::RectangleShape square2(sf::Vector2f(50, 50));
		sf::ConvexShape convex_2;
		sf::ConvexShape convex1_2;
		REC(square2, convex_2, convex1_2, window, 650, 350);

		sf::RectangleShape square3(sf::Vector2f(50, 50));
		sf::ConvexShape convex_3;
		sf::ConvexShape convex1_3;
		REC(square3, convex_3, convex1_3, window, 650, 300);

		sf::RectangleShape square4(sf::Vector2f(50, 50));
		sf::ConvexShape convex_4;
		sf::ConvexShape convex1_4;
		REC(square4, convex_4, convex1_4, window, 500, 300);

		sf::RectangleShape square5(sf::Vector2f(50, 50));
		sf::ConvexShape convex_5;
		sf::ConvexShape convex1_5;
		REC(square5, convex_5, convex1_5, window, 550, 250);

		sf::RectangleShape square6(sf::Vector2f(50, 50));
		sf::ConvexShape convex_6;
		sf::ConvexShape convex1_6;
		REC(square6, convex_6, convex1_6, window, 600, 250);

		sf::RectangleShape square7(sf::Vector2f(50, 50));
		sf::ConvexShape convex_7;
		sf::ConvexShape convex1_7;
		REC(square7, convex_7, convex1_7, window, 500, 500);

		sf::RectangleShape square8(sf::Vector2f(50, 50));
		sf::ConvexShape convex_8;
		sf::ConvexShape convex1_8;
		REC(square8, convex_8, convex1_8, window, 550, 550);

		sf::RectangleShape square9(sf::Vector2f(50, 50));
		sf::ConvexShape convex_9;
		sf::ConvexShape convex1_9;
		REC(square9, convex_9, convex1_9, window, 600, 550);

		sf::RectangleShape square10(sf::Vector2f(50, 50));
		sf::ConvexShape convex_10;
		sf::ConvexShape convex1_10;
		REC(square10, convex_10, convex1_10, window, 650, 500);

		sf::RectangleShape square11(sf::Vector2f(50, 50));
		sf::ConvexShape convex_11;
		sf::ConvexShape convex1_11;
		REC(square11, convex_11, convex1_11, window, 650, 450);

		while (1) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				colorBack(window);
				left(square1, convex_, convex1_, window);
				left(square2, convex_2, convex1_2, window);
				left(square3, convex_3, convex1_3, window);
				left(square4, convex_4, convex1_4, window);
				left(square5, convex_5, convex1_5, window);
				left(square6, convex_6, convex1_6, window);
				left(square7, convex_7, convex1_7, window);
				left(square8, convex_8, convex1_8, window);
				left(square9, convex_9, convex1_9, window);
				left(square10, convex_10, convex1_10, window);
				left(square11, convex_11, convex1_11, window);
				window.display();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				colorBack(window);
				right(square1, convex_, convex1_, window);
				right(square2, convex_2, convex1_2, window);
				right(square3, convex_3, convex1_3, window);
				right(square4, convex_4, convex1_4, window);
				right(square5, convex_5, convex1_5, window);
				right(square6, convex_6, convex1_6, window);
				right(square7, convex_7, convex1_7, window);
				right(square8, convex_8, convex1_8, window);
				right(square9, convex_9, convex1_9, window);
				right(square10, convex_10, convex1_10, window);
				right(square11, convex_11, convex1_11, window);
				window.display();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				colorBack(window);
				up(square1, convex_, convex1_, window);
				up(square2, convex_2, convex1_2, window);
				up(square3, convex_3, convex1_3, window);
				up(square4, convex_4, convex1_4, window);
				up(square5, convex_5, convex1_5, window);
				up(square6, convex_6, convex1_6, window);
				up(square7, convex_7, convex1_7, window);
				up(square8, convex_8, convex1_8, window);
				up(square9, convex_9, convex1_9, window);
				up(square10, convex_10, convex1_10, window);
				up(square11, convex_11, convex1_11, window);
				window.display();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				colorBack(window);
				down(square1, convex_, convex1_, window);
				down(square2, convex_2, convex1_2, window);
				down(square3, convex_3, convex1_3, window);
				down(square4, convex_4, convex1_4, window);
				down(square5, convex_5, convex1_5, window);
				down(square6, convex_6, convex1_6, window);
				down(square7, convex_7, convex1_7, window);
				down(square8, convex_8, convex1_8, window);
				down(square9, convex_9, convex1_9, window);
				down(square10, convex_10, convex1_10, window);
				down(square11, convex_11, convex1_11, window);
				window.display();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
				system("cls");
				Menu();
				system("pause");
				int m;
				scanf_s("%d", &m);
				repeat(m);
			}
		}
	}
}

void lit_2d() {
	sf::RenderWindow window(sf::VideoMode(1400, 900), "My window");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		sf::RectangleShape square1(sf::Vector2f(50, 50));
		REC_2d(square1, window, 600, 400);

		sf::RectangleShape square2(sf::Vector2f(50, 50));
		REC_2d(square2, window, 650, 350);

		sf::RectangleShape square3(sf::Vector2f(50, 50));
		REC_2d(square3, window, 650, 300);

		sf::RectangleShape square4(sf::Vector2f(50, 50));
		REC_2d(square4, window, 500, 300);

		sf::RectangleShape square5(sf::Vector2f(50, 50));
		REC_2d(square5, window, 550, 250);

		sf::RectangleShape square6(sf::Vector2f(50, 50));
		REC_2d(square6, window, 600, 250);

		sf::RectangleShape square7(sf::Vector2f(50, 50));
		REC_2d(square7, window, 500, 500);

		sf::RectangleShape square8(sf::Vector2f(50, 50));
		REC_2d(square8, window, 550, 550);

		sf::RectangleShape square9(sf::Vector2f(50, 50));
		REC_2d(square9, window, 600, 550);

		sf::RectangleShape square10(sf::Vector2f(50, 50));
		REC_2d(square10, window, 650, 500);

		sf::RectangleShape square11(sf::Vector2f(50, 50));
		REC_2d(square11, window, 650, 450);


		while (1) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				colorBack(window);
				left1(square1, window);
				left1(square2, window);
				left1(square3, window);
				left1(square4, window);
				left1(square5, window);
				left1(square6, window);
				left1(square7, window);
				left1(square8, window);
				left1(square9, window);
				left1(square10, window);
				left1(square11, window);
				window.display();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				colorBack(window);
				right1(square1, window);
				right1(square2, window);
				right1(square3, window);
				right1(square4, window);
				right1(square5, window);
				right1(square6, window);
				right1(square7, window);
				right1(square8, window);
				right1(square9, window);
				right1(square10, window);
				right1(square11, window);
				window.display();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				colorBack(window);
				up1(square1, window);
				up1(square2, window);
				up1(square3, window);
				up1(square4, window);
				up1(square5, window);
				up1(square6, window);
				up1(square7, window);
				up1(square8, window);
				up1(square9, window);
				up1(square10, window);
				up1(square11, window);
				window.display();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				colorBack(window);
				down1(square1, window);
				down1(square2, window);
				down1(square3, window);
				down1(square4, window);
				down1(square5, window);
				down1(square6, window);
				down1(square7, window);
				down1(square8, window);
				down1(square9, window);
				down1(square10, window);
				down1(square11, window);
				window.display();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
				system("cls");
				Menu();
				system("pause");
				int m;
				scanf_s("%d", &m);
				repeat(m);
			}
		}
	}
}

void colorBack(sf::RenderWindow &window) {
	switch (color1) {
	case 1:
		window.clear(sf::Color::White);
		break;
	case 2:
		window.clear(sf::Color::Black);
		break;
	case 3:
		window.clear(sf::Color::Blue);
		break;
	case 4:
		window.clear(sf::Color::Red);
		break;
	case 5:
		window.clear(sf::Color::Yellow);
		break;
	default:
		window.clear(sf::Color::Black);
	};
}

void colorBack_square(sf::RectangleShape &square) {
	switch (color1) {
	case 1:
		square.setFillColor(sf::Color::White);
		break;
	case 2:
		square.setFillColor(sf::Color::Black);
		break;
	case 3:
		square.setFillColor(sf::Color::Blue);
		break;
	case 4:
		square.setFillColor(sf::Color::Red);
		break;
	case 5:
		square.setFillColor(sf::Color::Yellow);
		break;
	default:
		square.setFillColor(sf::Color::Black);
	};
}

void colorBack_convex(sf::ConvexShape &square) {
	switch (color1) {
	case 1:
		square.setFillColor(sf::Color::White);
		break;
	case 2:
		square.setFillColor(sf::Color::Black);
		break;
	case 3:
		square.setFillColor(sf::Color::Blue);
		break;
	case 4:
		square.setFillColor(sf::Color::Red);
		break;
	case 5:
		square.setFillColor(sf::Color::Yellow);
		break;
	default:
		square.setFillColor(sf::Color::Black);
	};
}

void color_back() {
	MenuColor();

	scanf_s("%d", &color1);
	system("cls");
	Menu();
	int m;
	scanf_s("%d", &m);
	repeat(m);

}

void color_liter_sq(sf::RectangleShape &square) {
	switch (color2) {
	case 1:
		square.setOutlineColor(sf::Color::White);
		break;
	case 2:
		square.setOutlineColor(sf::Color::Black);
		break;
	case 3:
		square.setOutlineColor(sf::Color::Green);
		break;
	case 4:
		square.setOutlineColor(sf::Color::Red);
		break;
	case 5:
		square.setOutlineColor(sf::Color::Yellow);
		break;
	default:
		square.setOutlineColor(sf::Color::Red);
	}

}
void color_lit_convex(sf::ConvexShape &square) {
	switch (color2) {
	case 1:
		square.setOutlineColor(sf::Color::White);
		break;
	case 2:
		square.setOutlineColor(sf::Color::Black);
		break;
	case 3:
		square.setOutlineColor(sf::Color::Green);
		break;
	case 4:
		square.setOutlineColor(sf::Color::Red);
		break;
	case 5:
		square.setOutlineColor(sf::Color::Yellow);
		break;
	default:
		square.setOutlineColor(sf::Color::Red);
	}
}

void color_liter() {
	MenuColor();
	scanf_s("%d", &color2);
	system("cls");
	Menu();
	int m;
	scanf_s("%d", &m);

	repeat(m);
}


