#include "Player.h"
#include "AssetManager.h"
#include "Floor.h"

using namespace sf;

namespace owner
{
    Player::Player(GameDataRef data) : Data(data)
    {
        animationiterator = 0;

        AnimationFrames.push_back(Data->assets.GetTexture("Player 1"));
        AnimationFrames.push_back(Data->assets.GetTexture("Player STAND"));
        AnimationFrames.push_back(Data->assets.GetTexture("Player 2"));
        AnimationFrames.push_back(Data->assets.GetTexture("Player STAND"));

        PlayerSprite.setTexture(AnimationFrames.at(animationiterator));
        PlayerSprite.setScale(PLAYER_SCALE,PLAYER_SCALE);
        PlayerSprite.setPosition(15,HEIGHT - 170 - PlayerSprite.getGlobalBounds().height);

        SlidePlayer = Data->assets.GetTexture("Player SLIDE");
        SlideFrame.setTexture(SlidePlayer);
        SlideFrame.setScale(PLAYER_SCALE,PLAYER_SCALE);
        SlideFrame.setPosition(15,HEIGHT - 180 - SlideFrame.getGlobalBounds().height);

        // GUI
        fullbar = RectangleShape(Vector2f(800,30));
        fullbar.setFillColor(Color::Black);
        fullbar.setPosition(20,20);

        fullamourbar = RectangleShape(Vector2f(600,15));
        fullamourbar.setFillColor(Color::Black);
        fullamourbar.setPosition(20,55);

        PlayerState = PLAYER_BOTTOM;
    }

    void Player::DrawPlayer()
    {
        if(PlayerState == PLAYER_SLIDE)
        {
             Data->app.draw(SlideFrame);
        }
        else
        {
             Data->app.draw(PlayerSprite);
        }

        Data->app.draw(fullbar);
        Data->app.draw(restbar);

        Data->app.draw(fullamourbar);
        Data->app.draw(getamourbar);
    }

    void Player::Animate(float dt)
    {
        if(PlayerState != PLAYER_SLIDE)
        {
            if(clock.getElapsedTime().asSeconds() > PLAYER_ANIMATION_DURATION / AnimationFrames.size())
            {
                if(animationiterator < AnimationFrames.size() - 1)
                {
                    animationiterator++;
                }
                else
                {
                    animationiterator = 0;
                }

                PlayerSprite.setTexture(AnimationFrames.at(animationiterator));
                clock.restart();
            }
        }

        // for while press RIGHT , player is sliding

        if(!Keyboard::isKeyPressed(Keyboard::Down) &&PlayerState != PLAYER_JUMP && PlayerState != PLAYER_FALLING)
        {
            PlayerState = PLAYER_BOTTOM;
        }
    }

    void Player::Update(float dt, long double hp,long double amou)
    {
        /// JUMP

        if(PlayerState == PLAYER_JUMP)
        {
            PlayerSprite.move(0, - JUMP_SPEED * dt);
        }

        if (PlayerState == PLAYER_FALLING)
        {
            PlayerSprite.move(0,JUMP_SPEED * dt);

            if(PlayerSprite.getPosition().y >= HEIGHT - 180 - PlayerSprite.getGlobalBounds().height)
            {
                PlayerSprite.setPosition(15,HEIGHT - 180 - PlayerSprite.getGlobalBounds().height);
                PlayerState = PLAYER_BOTTOM;
                JumpLimit = 0;
            }
        }


        if(PlayerSprite.getPosition().y <= 200 && JumpLimit ==1)
        {
            PlayerState = PLAYER_FALLING;
        }
        else if(PlayerSprite.getPosition().y <= 100 && JumpLimit ==2)
        {
            PlayerState = PLAYER_FALLING;
        }

        restbar = RectangleShape(Vector2f(1.6 * hp , 30));
        if(hp >= 300)
        {
            restbar.setFillColor(Color::Green);
        }
        else if(hp >= 100)
        {
            restbar.setFillColor(Color::Yellow);
        }
        else
        {
            restbar.setFillColor(Color::Red);
        }
        restbar.setPosition(20,20);

        getamourbar = RectangleShape(Vector2f(amou * 600 / 100,15));
        getamourbar.setFillColor(Color::Blue);
        getamourbar.setPosition(20,55);
        amour.setPosition(PlayerSprite.getPosition().x,PlayerSprite.getPosition().y);
    }

    void Player::Tap_Up()
    {
        if(PlayerState != PLAYER_JUMP && JumpLimit == 0)
        {
            PlayerState = PLAYER_JUMP;
            JumpLimit = 1;
        }
        else if((PlayerState == PLAYER_JUMP || PlayerState == PLAYER_FALLING) && JumpLimit == 1)
        {
            PlayerState = PLAYER_JUMP;
            JumpLimit = 2;
        }
    }

    void Player::Tap_Down()
    {
        if(PlayerState != PLAYER_JUMP && PlayerState != PLAYER_FALLING)
        {
            PlayerState = PLAYER_SLIDE;
        }
    }

    const Sprite &Player::GetSprite() const
    {
        if(PlayerState == PLAYER_SLIDE)
        {
            return SlideFrame;
        }
        else
        {
            return PlayerSprite;
        }
    }
}
