template<typename T>


void Renderer::render_entity(sf::RenderWindow& rwindow,Entity<T>& entity)
{
    // 2. Create the sprite and attach the texture
    auto size = entity.texture.getSize();
    auto middle = Vector<float>(size.x / 2, size.y / 2);
    sf::Sprite sprite(entity.texture);
    sprite.setOrigin({ middle.x, middle.y });
    sprite.setScale({ 1.0f, 1.0f });


    // Optional transforms:



    sprite.setPosition({ entity.position.x, entity.position.y });


    rwindow.draw(sprite);
}

template<typename T>
void Renderer::render_sprite(sf::RenderWindow& rwindow, std::string& sprite_path, Vector<T> position , Vector<T> scale)
{
    sf::Texture texture;
    if (!texture.loadFromFile(sprite_path))
    {
        exit(-1);
    }
    // 2. Create the sprite and attach the texture
    auto size = texture.getSize();
    auto middle = Vector<float>(size.x / 2, size.y / 2);
    sf::Sprite sprite(texture);
    //sprite.setOrigin({ middle.x, middle.y });
    sprite.setScale({ scale.x,scale.y});
    // Optional transforms:
    sprite.setPosition({position.x,position.y });
    rwindow.draw(sprite);

}
