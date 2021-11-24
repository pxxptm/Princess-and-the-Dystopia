#include "EnemyLevel1.h"
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

namespace owner
{
    EnemyLevel1::EnemyLevel1(GameDataRef data) : Data(data)
    {

    }

    void EnemyLevel1::Spawn()
    {
        Sprite sprite(Data->assets.GetTexture("LV1"));
        sprite.setScale(ENEMY_1_SCALE,ENEMY_1_SCALE);
        sprite.setPosition(Data->app.getSize().x + sprite.getGlobalBounds().width,HEIGHT - 180 - sprite.getGlobalBounds().height);

        full = RectangleShape(Vector2f(sprite.getGlobalBounds().width,10));
        full.setFillColor(Color::Black);
        full.setPosition(sprite.getPosition().x,sprite.getPosition().y - 20);

        rest = RectangleShape(Vector2f(sprite.getGlobalBounds().width,10));
        rest.setFillColor(Color::Magenta);
        rest.setPosition(sprite.getPosition().x,sprite.getPosition().y - 20);

        int spawn = rand() % 7;

        if(spawn == 2 && Sprite1.size() < 3)
        {
            Sprite1.push_back(sprite);
            Hp.push_back(LV1_HP);
            isAlive.push_back(true);
            fullbar.push_back(full);
            restbar.push_back(rest);
        }
    }

    void EnemyLevel1::Move(float dt)
    {
        for(unsigned short int i=0;i<Sprite1.size();i++)
        {
            float movement = ENEMY_1_SPEED * dt;

            if(Sprite1.at(i).getPosition().x < 0 - Sprite1.at(i).getGlobalBounds().width)
            {
                Sprite1.erase(Sprite1.begin()+i);
                fullbar.erase(fullbar.begin()+i);
                restbar.erase(restbar.begin()+i);
            }
            else
            {
                if( i != 0 )
                {
                    if(Sprite1.at(i).getPosition().x >= Sprite1.at(i-1).getPosition().x + 30 )
                    {
                        Sprite1.at(i).move(-movement,0);
                        fullbar.at(i).move(-movement,0);
                    }
                }
                else
                {
                    Sprite1.at(i).move(-movement,0);
                    fullbar.at(i).move(-movement,0);
                }
            }
        }
    }

    void EnemyLevel1::Draw()
    {
        for(unsigned short int i=0;i<Sprite1.size();i++)
        {
            //cout << Hp.at(i) << endl;
            if(Hp.at(i) > 0 )
            {
                Data->app.draw(Sprite1.at(i));
                Data->app.draw(fullbar.at(i));
                Data->app.draw(restbar.at(i));
            }
            else
            {
                Sprite1.erase(Sprite1.begin()+i);
                Hp.erase(Hp.begin()+i);
                fullbar.erase(fullbar.begin()+i);
                restbar.erase(restbar.begin()+i);
            }
        }
    }

    void EnemyLevel1::Update(vector<int> hp)
    {
        for(unsigned short int i=0;i<Sprite1.size();i++)
        {
            Hp.at(i) = hp.at(i);

            if(Hp.at(i) < 0 )
            {
                hp.at(i) = 0;
            }

            restbar.at(i) = RectangleShape(Vector2f(Sprite1.at(i).getGlobalBounds().width * Hp.at(i) / LV1_HP,10));

            if(Hp.at(i) <= 50)
            {
                restbar.at(i).setFillColor(Color::Red);
            }
            else
            {
                restbar.at(i).setFillColor(Color::Magenta);
            }
            restbar.at(i).setPosition(fullbar.at(i).getPosition().x,Sprite1.at(i).getPosition().y - 20);
        }
    }

    const vector<Sprite> &EnemyLevel1::GetSprites() const
    {
        return Sprite1;
    }
}
