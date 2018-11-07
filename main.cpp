#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


void updateMovement(int &x,int &y,float &velY,float &velX,float &accelX,float &accelY ) {
    if(y < 450)
//If you are above ground velocityY += gravity;
//Add gravity else if(y > 500)
//If you are below ground y = 500;
//That's not supposed to happen, put him back up
    velX += accelX;
    velY += accelY;
    x += velX;
    y += velY;
}
/*
int main(){
    sf::RenderWindow window(sf::VideoMode(800,600),"mi window");
    window.setFramerateLimit(60);
    sf::Texture Image;
    Image.loadFromFile("tortuga.png");
    sf::Sprite sprite(Image);
    sprite.setPosition(-230,100);
    sf::CircleShape figura(10);
    while (window.isOpen()) {
            //Eventos
            while(window.pollEvent(miEvento))
            {
                if (miEvento.type==sf::Event::Closed){
                        window.close();
                }
                else

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                velocityX = -5;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                velocityX = 5;
            updateMovement();
            sprite.setPosition(x, y);
            //Renderizado
            window.clear();
            window.draw(sprite);
            window.display();
            }
            return 0; }
*/
int main()
{
    int ancho_ventana= 900,alto_ventana=650;
    int x_coord=ancho_ventana/2;
    int y_coord=alto_ventana/2;//cordenadas de incializacion del triangulo
    //int radio_nave=15;
    int ancho_dora=105;
    int alto_dora=120;
    int posicion[]={0,222,480,737};
    int c=0;
    int x_1;

    float velocityX = 0;
    float velocityY = 0;
    float accelerationX = 0;
    float accelerationY = 0;

    float gravity = 2;

    sf::RenderWindow ventana(sf::VideoMode(ancho_ventana,alto_ventana),"¡Nave en movimientoooo!");
    sf::Texture textura;
    //imagen.

    //imagen.create(100,100);

    textura.loadFromFile("imagenes/ole.png");
    sf::Sprite sprite;
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0,310,230,300));//(0,0,230,300)-(222,0,230,300)-(480,0,230,300)-(737,0,230,300) o (0,-10,230,300) abajo
    // (222,310,230,300)-(0,310,230,300)-
    sprite.move(300,450);
    sf::Vector2f centro;

    centro.x =sprite.getTextureRect().width/2.f;
    centro.y =sprite.getTextureRect().height/2.f;
    sprite.setOrigin(centro);
    //sprite.rotate(45);

    //sf::CircleShape nave(radio_nave,4);
    //nave.setPosition(x_coord,y_coord);
    //nave.setFillColor(sf::Color::Red);

    while(ventana.isOpen())
    {

        sf::Event evento;

        while(ventana.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                ventana.close();

            while(window.pollEvent(miEvento)){
            if (miEvento.type==sf::Event::Closed){
   		window.close();
		}
        else if(miEvento.type==sf::Event::KeyPressed && miEvento.key.code==sf::Keyboard::Space){
		velocityY = -10;
		}
	}

            while ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (x_coord < ancho_ventana - ancho_dora *2))
            {

                //x_coord  += 10;//int c=0;
                x_1=posicion[c];
                sprite.setTextureRect(sf::IntRect(x_1,0,230,300));
                c++;
                if(c==3)
                    c=0;}

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (x_coord > 0 ))
            {
                //x_1-=200;
                //x_coord  -= 10;
                //sprite.setTextureRect(sf::IntRect(x_1,310,230,300));
                velocityX = 5;
                c-=1;
                x_1=posicion[c];
                sprite.setTextureRect(sf::IntRect(x_1,0,230,300));

            }

            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                velocityX = -5;
            updateMovement(x_coord,y_coord,velocityY, velocityX ,accelerationX,accelerationY);

            /*if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (y_coord > 0))
            {
                y_coord  -= 10;

            }*/


            /*
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (y_coord < alto_ventana - alto_dora*2))
            {
                y_coord  += 10;
                //sprite.setTextureRect(sf::IntRect(0,310,230,300))
            }
            */
            /*####################################################
            //MOVER NAVE DENTRO DE LA VENTANA SIN LIMITES
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                x_coord  += 10;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                x_coord  -= 10;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                y_coord  -= 10;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
             y_coord  += 10;
             //####################################################
             */
        }


    ventana.clear();
    //nave.setPosition(x_coord,y_coord);//actualizacion de la posicion de la nave
    sprite.setPosition(x_coord,y_coord);
    ventana.draw(sprite);
    //ventana.draw(nave);
    ventana.display();}

    return 0;
}
