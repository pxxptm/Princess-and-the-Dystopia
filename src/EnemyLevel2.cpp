#include "EnemyLevel2.h"
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

namespace owner
{
    EnemyLevel2::EnemyLevel2(GameDataRef data) : Data(data)
    {

    }

    void EnemyLevel2::Spawn()
    {
        Sprite sprite(Data->assets.GetTexture("LV2"));
        sprite.setScale(ENEMY_2_SCALE,ENEMY_2_SCALE);
        sprite.setPosition(Data->app.getSize().x + sprite.getGlobalBounds().width,HEIGHT - 180 - sprite.getGlobalBounds().height);

        full = RectangleShape(Vector2f(sprite.getGlobalBounds().width,10));
        full.setFillColor(Color::Black);
        full.setPosition(sprite.getPosition().x,sprite.getPosition().y - 20);

        rest = RectangleShape(Vector2f(sprite.getGlobalBounds().width,10));
        rest.setFillColor(Color::Magenta);
        rest.setPosition(sprite.getPosition().x,sprite.getPosition().y - 20);

        int spawn = rand() % 7;

        if(spawn == 2 && Sprite2.size() < 3)
        {
            Sprite2.push_back(sprite);
            Hp.push_back(LV2_HP);
            isAlive.push_back(true);
            fullbar.push_back(full);
            restbar.push_back(rest);
        }
    }

    void EnemyLevel2::Move(float dt)
    {
        for(unsigned short int i=0;i<Sprite2.size();i++)
        {
            float movement = ENEMY_2_SPEED * dt;

            if(Sprite2.at(i).getPosition().x < 0 - Sprite2.at(i).getGlobalBounds().width)
            {
                Sprite2.erase(Sprite2.begin()+i);
                fullbar.erase(fullbar.begin()+i);
                restbar.erase(restbar.begin()+i);
            }
            else
            {
                if( i != 0 )
                {
                    if(Sprite2.at(i).getPosition().x >= Sprite2.at(i-1).getPosition().x + 30 )
                    {
                        Sprite2.at(i).move(-movement,0);
                        fullbar.at(i).move(-movement,0);
                    }
                }
                else
                {
                    Sprite2.at(i).move(-movement,0);
                    fullbar.at(i).move(-movement,0);
                }
            }
        }
    }

    void EnemyLevel2::Draw()
    {
        for(unsigned short int i=0;i<Sprite2.size();i++)
        {
            //cout << Hp.at(i) << endl;
            if(Hp.at(i) > 0 )
            {
                Data->app.draw(Sprite2.at(i));
                Data->app.draw(fullbar.at(i));
                Data->app.draw(restbar.at(i));
            }
            else
            {
                Sprite2.erase(Sprite2.begin()+i);
                Hp.erase(Hp.begin()+i);
                fullbar.erase(fullbar.begin()+i);
                restbar.erase(restbar.begin()+i);
            }
        }
    }

    void EnemyLevel2::Update(vector<int> hp)
    {
        for(unsigned short int i=0;i<Sprite2.size();i++)
        {
            Hp.at(i) = hp.at(i);

            if(Hp.at(i) < 0 )
            {
                hp.at(i) = 0;
            }

            restbar.at(i) = RectangleShape(Vector2f(Sprite2.at(i).getGlobalBounds().width * Hp.at(i) / LV2_HP,10));

            if(Hp.at(i) <= 50)
            {
                restbar.at(i).setFillColor(Color::Red);
            }
            else
            {
                restbar.at(i).setFillColor(Color::Magenta);
            }
            restbar.at(i).setPosition(fullbar.at(i).getPosition().x,Sprite2.at(i).getPosition().y - 20);
        }
    }

    const vector<Sprite> &EnemyLevel2::GetSprites() const
    {
        return Sprite2;
    }
}
