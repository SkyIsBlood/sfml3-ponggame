
void core::border(Entity<float>& e)
{
    {
        float bounce = 1;
        //check right and left
        if ((e.position.x + e.texture.getSize().x/2) >= Config::WindowWidth)
        {
            e.position.x = Config::WindowWidth - e.texture.getSize().x/2;
            e.velocity.x = e.velocity.x * -bounce;
        }
        else if (e.position.x < 0)
        {
            e.position.x = e.texture.getSize().x/2;
            e.velocity.x *= -bounce;

        }
        //check down and up
        if ((e.position.y + e.texture.getSize().y/2) >= Config::WindowHeight)
        {
            e.position.y = Config::WindowHeight - e.texture.getSize().y/2;
            e.velocity.y = e.velocity.y * -bounce;
        }
        else if (e.position.y < 0)
        {
            e.position.y = e.texture.getSize().y/2;
            e.velocity.y = e.velocity.y * -bounce;
        }
    }

}
void core::withblock(Entity<float>& A, const Entity<float>& B)
{
    // entity A is the ball while entity B is the static object
    float bounce = 1;
    auto sizeA = A.texture.getSize();
    auto sizeB = B.texture.getSize();
    float halfsizeB = static_cast<float>(sizeB.x / 2);
    float halfsizeA = static_cast<float>(sizeA.x / 2);

    //check right and left
    Vector<float> rpA = (A.position) - (B.position);
    Vector<float> rpAF = rpA + A.velocity + Vector<float>(0, sizeA.y / 2) + Config::GRAVITY;
    if ((rpA.x + halfsizeA > -halfsizeB) && (rpA.x - halfsizeA < halfsizeB))
    {
        if ((rpA.y == 0) || ((rpA.y < 0 ) && (rpAF.y > 0)))
        {
            //A.position.y = B.position.y - B.texture.getSize().y - sizeA.y / 2;
            A.velocity *= -bounce;
            std::cout << "bounce" << std::endl;

    }
    
}

void core::mainloop(sf::RenderWindow& mainwindow)
{
    auto s = Vector<float>(Config::WindowWidth / 2, 0);
    auto e = Vector<float>(Config::WindowWidth / 2, Config::WindowHeight) ;
    const float SPEED = 80;
    const float MAX_SPEED = 120;

    //init the entities
    Entity<float> ball(Assets::ball, Vector<float>(Config::WindowWidth/2,Config::WindowHeight/2), 1 ,1,15);
    Entity<float> block(Assets::block, Vector<float>(Config::WindowWidth / 2, 500), 1.f,0.7,MAX_SPEED);
    
    ball.velocity = Vector<float>(3, 10);
    
    float dt;
    Vector<float> gravity = Config::GRAVITY;
    clock.start();
    while (mainwindow.isOpen())
    
    {
        mainwindow.clear(Config::BACKGROUND);
        now = clock.getElapsedTime().asSeconds();
        dt = now - last;
        last = now;
        while (const auto event = mainwindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                mainwindow.close();
            }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Escape)
                {
                    mainwindow.close();
                }
                if (keyPressed->code == sf::Keyboard::Key::D)
                {
                    right = true;
                }
                if (keyPressed->code == sf::Keyboard::Key::A)
                {
                    left = true;
                }
            }
            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
            {
                if (keyReleased->code == sf::Keyboard::Key::D)
                {
                    right = false;
                }
                if (keyReleased->code == sf::Keyboard::Key::A)
                {
                    left = false;
                }
            }

        }


        // holding a key
        if (right) 
        { 
                block.applyforce(Vector<float>(SPEED, 0)); 
        }
        if (left)
        {
                block.applyforce(Vector<float>(-SPEED, 0));
        }

        block.update(dt);
        ball.update(dt);
        core::border(ball);
        core::withblock(ball, block);
        Renderer::draw(mainwindow,myline);
        Renderer::render(mainwindow,ball);
        Renderer::render(mainwindow, block);
        mainwindow.display();
    }
}
