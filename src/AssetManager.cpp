#include "AssetManager.h"

using namespace sf;

namespace owner
{
    void AssetManager::LoadTexture(string name,string fileName)
    {
        Texture  texture;

        if(texture.loadFromFile(fileName))
        {
            this->textures[name] = texture;
        }
    }

    Texture &AssetManager::GetTexture(string name)
    {
        return this->textures.at(name);
    }

    void AssetManager::LoadFont(string name,string fileName)
    {
        Font font;

        if(font.loadFromFile(fileName))
        {
            this->fonts[name] = font;
        }
    }

    Font &AssetManager::GetFont(string name)
    {
        return this->fonts.at(name);
    }
}
