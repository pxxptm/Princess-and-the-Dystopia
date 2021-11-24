#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

namespace owner
{
    class Animation
    {
        public:

            float Frame;
            float speed;

            Sprite sprite;
            vector<IntRect> frames;

            Animation(){}

            Animation (Texture &t,int x,int y,int w,int h,int count,float Speed);
            void update();
            bool isEnd();
};

}
#endif // ANIMATION_H
