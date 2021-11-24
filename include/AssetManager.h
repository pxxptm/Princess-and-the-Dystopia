#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace owner
{
    class AssetManager
    {
        public:

            AssetManager() {}
            virtual ~AssetManager() {}

            void LoadTexture(string name,string fileName);
            Texture &GetTexture(string name);

            void LoadFont(string name,string fileName);
            Font &GetFont(string name);

        private :

            map <string,Texture> textures;
            map <string,Font> fonts;
    };

}

#endif // ASSETMANAGER_H
