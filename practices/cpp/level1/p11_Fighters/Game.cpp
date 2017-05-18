#include"Game.h"

Game::Game()

    :Window(sf::VideoMode(1920, 1080), "My+1sflight")
    ,Player(){
        Player.setPosition(960,980);
    }

void Game::processEvents(){
    sf::Event event;
        while(Window.pollEvent(event)){
//            if (event.type == sf::Event::Closed)
            switch (event.type){
                case sf::Event::KeyPressed:
                    handlePlayerInput(event.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    handlePlayerInput(event.key.code, false);
                    break;
                case sf::Event::Closed:
                    Window.close();
                    break;
            }
        }
}



void Game::handlePlayerInput(sf::Keyboard::Key key,
bool isPressed){
    if (key == sf::Keyboard::Up)
        IsMovingUp=isPressed;
    else if (key==sf::Keyboard::Down)
        IsMovingDown = isPressed;
    else if (key==sf::Keyboard::Left)
        IsMovingLeft = isPressed;
    else if (key==sf::Keyboard::Right)
        IsMovingRight = isPressed;
}




void Game::update(sf::Time deltaTime)
{   int PlayerSpeed=300;
    sf::Vector2f movement(0, 0);
    if (IsMovingUp)
        movement.y -= PlayerSpeed;
    if (IsMovingDown)
        movement.y += PlayerSpeed;
    if (IsMovingLeft)
        movement.x -= PlayerSpeed;
    if (IsMovingRight)
        movement.x += PlayerSpeed;
        Player.move(movement * deltaTime.asSeconds());
}



/*void Game::run(){
    sf::Clock clock;
    while (Window.isOpen()){
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while(Window.isOpen()){
            processEvents();
            while (timeSinceLastUpdate > sf::seconds(1.f/60.f)){
                timeSinceLastUpdate -= sf::seconds(1.f/60.f);
                processEvents();
                update(sf::seconds(1.f/60.f));
            }
        }
        render();
    }
}
*/
void Game::run(){
    sf::Clock clock;
    while(Window.isOpen()){
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::render(){
//////////background///////////////
    sf::Sprite background;
    sf::Texture rmdht;
    if(!rmdht.loadFromFile("rmdht.jpg")){}
    background.setTexture(rmdht);
    background.setPosition(0,0);
///////////////flight//////////////
    sf::Texture surfaceofflight;
    if(!surfaceofflight.loadFromFile("jzm.jpg")){}
    Player.setTexture(surfaceofflight);
/////////////render////////////////
    Window.clear();
    Window.draw(background);
    Window.draw(Player);
    Window.display();
}
