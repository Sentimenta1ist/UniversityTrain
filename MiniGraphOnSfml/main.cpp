#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>а
using namespace std;
using namespace sf;

View view;

void draw_line(int x1, int x2, int x3, int x4, RenderWindow &window)
{
    Vertex line[]
            {
                    Vertex(Vector2f(x1, x2)),     // function of line
                    Vertex(Vector2f(x3, x4))
            };
    window.draw(line, 2, Lines);
}

void draw_point(double x, double y, RenderWindow &window)
{
    CircleShape shape(1);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(x, y);
    window.draw(shape);
}

void draw_text(string res, double x, double y, RenderWindow &window, int size)
{
    Font font;
    font.loadFromFile("HelveticaThinItalic.ttf");
    Text N(res, font, size);
    N.setFillColor(Color::White);
    N.setStyle(Text::Regular);
    N.setPosition(x,y);
    window.draw(N);
}

int main()
{
    RenderWindow window(VideoMode(2000, 1000), "graph");
    view.setSize(2000, 1000);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        draw_line(900, 100, 900, 900, window);  // oY
        draw_line(100, 700, 1800, 700, window); // oX

        draw_text("Ivanenko Alexander \nFAM  KV - 82", 1200, 800, window, 25);// table
        draw_text("y = -a cosh(x/a) = a/2 (e^(x/a) + e^-(x/a)) \n", 1200, 850, window, 25);

        draw_text("0",900,700,window,15);
        draw_text("30",920,705,window,15);
        draw_text("60",950,705,window,15);
        draw_text("-60",825,705,window,15);
        draw_text("-30",860,705,window,15);

        draw_text("-30",910,720,window,15);
        draw_text("-60",910,750,window,15);
        draw_text("30",900,670,window,15);

        for(int i = 120; i < 1790; i = i + 30)
        {
            draw_line(i, 696, i, 704, window);       // markup X
        }

        for(int i = 130; i < 890; i = i + 30)
        {
            draw_line(896, i, 904, i, window);       // markup Y
        }

        draw_line(900, 100, 895, 110, window); // arrows
        draw_line(900, 100, 905, 110, window);
        draw_line(1790, 705, 1800, 700, window);
        draw_line(1790, 695, 1800, 700, window);


        draw_text("oX", 1790, 700, window, 25);
        draw_text("oY", 910, 100, window, 25);


        double x;
        double y;
        for(double a = 1; a <= 1000; a = a*2)
        {
            for(double i = -2*a; i <= 2*a; i++)
            {
                x = i;
                y  = -a*cosh(x/a);
                draw_point(x + 900, y + 700, window);
            }
        }
        window.setView(view);
        view.setCenter(900, 500);
        if (Keyboard::isKeyPressed(Keyboard::Z))
        {

                view.zoom(1.0080f);
        }
        if (Keyboard::isKeyPressed(Keyboard::X))
        {

            view.zoom(0.992f);
        }

        window.display();
    }
    return 0;
}