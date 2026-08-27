

void Renderer::render(sf::RenderWindow& rwindow,auto& entity)
{
    // 2. Create the sprite and attach the texture
    auto size = entity.texture.getSize();
    auto middle = Vector<float>(size.x/2,size.y/2);
    sf::Sprite sprite(entity.texture);
    sprite.setOrigin({middle.x, middle.y});
    sprite.setScale({ 1.0f, 1.0f });
    

    // Optional transforms:
    
    
    
    sprite.setPosition({ entity.position.x, entity.position.y });
    
    
    rwindow.draw(sprite);
}
void Renderer::draw(sf::RenderWindow& rwindow, auto& shape)
{
    rwindow.draw(shape);
}