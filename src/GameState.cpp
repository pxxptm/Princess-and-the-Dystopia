#include "GameState.h"
#include "DEFINITION.h"
#include "BarrierUp.h"
#include "InputManager.h"
#include "GameOverState.h"
#include "WinnerState.h"
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

namespace owner
{
    GameState::GameState(GameDataRef data,string username) : Data(data)
	{
	    USERNAME = username;
	}

	void GameState::Init()
	{
	    // background load
	    Data->assets.LoadTexture("Game Background",GAME_BACKGROUND);
	    background.setTexture(this->Data->assets.GetTexture("Game Background"));

	    // Barrier Up  load
	    Data->assets.LoadTexture("Barrier Up Short",BARRIER_UP_SHORT);
	    barrierup = new BarrierUp(Data);

	    // Thorn load
	    Data->assets.LoadTexture("Thorn",THORN);
	    thorn = new Thorn(Data);

	    // Enemy level 1 load
	    Data->assets.LoadTexture("LV1",ENEMY_LEVEL_1);
	    enemyLV1 = new EnemyLevel1(Data);

	    // Enemy level 2 load
	    Data->assets.LoadTexture("LV2",ENEMY_LEVEL_2);
	    enemyLV2 = new EnemyLevel2(Data);

	    // Floor load
	    Data->assets.LoadTexture("Floor",FLOOR);
	    floor = new Floor(Data);

	    // Player load
	    Data->assets.LoadTexture("Player 1",PLAYER_INDEX_1);
	    Data->assets.LoadTexture("Player 2",PLAYER_INDEX_2);
	    Data->assets.LoadTexture("Player STAND",PLAYER_STAND);
	    Data->assets.LoadTexture("Player SLIDE",PLAYER_INDEX_SLIDE);
	    player = new Player(Data);

	    // player bullet load
        Data->assets.LoadTexture("PINK",PLAYER_POWER);
        bullet = new Bullet(Data);

        // thorn bullet load
        Data->assets.LoadTexture("GREEN",ENEMY_POWER);
        attackthorn = new AttackThorn(Data);

        // Hp load
        Data->assets.LoadTexture("HP",HP);
        hp = new Hp(Data);


	    // score
	    HUD = new HeadUpDisplay(Data);
	    HUD->UpdateScore(score);

	    // Game over Flash
	    flash = new Flash(Data);

	    // Pause
	    Data->assets.LoadTexture("Pause Button",PAUSE_RESUME);
	    pausebutton.setTexture(this->Data->assets.GetTexture("Pause Button"));
	    pausebutton.setScale(1.3,1.3);
	    pausebutton.setPosition(WIDTH - 15 - pausebutton.getGlobalBounds().width,15);

	    /// resume & quit

        Data->assets.LoadTexture("Pause Background",TP_BLACK);
	    pausebackground.setTexture(this->Data->assets.GetTexture("Pause Background"));
	    pausebackground.setPosition(0,0);

	    // Font
	    barchella.loadFromFile(BARCHELLLA);
	    EG.loadFromFile(EDGE_OF_THE_GALAXY);
	    day28.loadFromFile(DAY28);
	    barbaro.loadFromFile(BARBARO);

	    // princess
		princess.setString("PrincesS");
		princess.setFont(barchella);
		princess.setCharacterSize(180);
		princess.setPosition(427,137);
		princess.setOutlineThickness(1);
		princess.setOutlineColor(Color::Black);

		// and the
		andthe.setString("and             the");
		andthe.setFont(EG);
		andthe.setCharacterSize(35);
		andthe.setPosition(615,352);
		andthe.setOutlineThickness(1);
		andthe.setOutlineColor(Color::Black);

		// dystopia
		dystopia.setString("DYSTOPIA");
		dystopia.setFont(day28);
		dystopia.setCharacterSize(155);
		dystopia.setPosition(425,390);
		dystopia.setOutlineThickness(1);
		dystopia.setOutlineColor(Color::Black);

		// quit
		quit.setString("QUIT");
		quit.setFont(barbaro);
		quit.setCharacterSize(40);
		quit.setPosition(dystopia.getPosition().y + dystopia.getGlobalBounds().width - quit.getGlobalBounds().width,743 - quit.getGlobalBounds().height);
		quit.setOutlineThickness(1);
		quit.setOutlineColor(Color::Black);

		// play
		play.setString("RESUME");
		play.setFont(barbaro);
		play.setCharacterSize(40);
		play.setPosition(425,743 - quit.getGlobalBounds().height);
		play.setOutlineThickness(1);
		play.setOutlineColor(Color::Black);

		// background accessories
		smallrock.loadFromFile(SMALL_ROCK);


		////////////////////////////////////

	    gamestate = GameStates::ePlaying;

	    Player_Hp = PLAYER_HP;

	    level1 = 0;
	    level2 = 0;

	    drop_1 = true;

	    spawnLevel1 = true;
	    spawnLevel2 = false;

	    ShootABLE = true;
	    amourload = 0;

	    isx2 = false;

	    ////////////////////////////////////

	    /// AUDIO

	    collectbuff.loadFromFile(COLLECT);
	    gameoverbuff.loadFromFile(GAMEOVER);
	    winningbuff.loadFromFile(WINNING);
	    jumpbuff.loadFromFile(JUMP);
	    slidebuff.loadFromFile(SLIDE);
	    roarbuff.loadFromFile(ROAR);
	    hitbuff.loadFromFile(HIT);
	    shootbuff.loadFromFile(SHOOT);

	    collect.setBuffer(collectbuff);
	    gameover.setBuffer(gameoverbuff);
	    winning.setBuffer(winningbuff);
	    jump.setBuffer(jumpbuff);
	    slide.setBuffer(slidebuff);
	    roar.setBuffer(roarbuff);
	    hit.setBuffer(hitbuff);
	    shoot.setBuffer(shootbuff);
	}

	void GameState::HandleInput()
	{
		Event event;

		while (this->Data->app.pollEvent(event))
		{
		    if (event.type == Event::Closed)
			{
				this->Data->app.close();
			}

			/// Jump
			if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                if(gamestate != GameStates::eGameOver && gamestate != GameStates::ePause)
                {
                    player->Tap_Up();
                    jump.play();
                    Player_Hp -= 0.01;
                    // cout << "up\n";
                }
            }

            /// Slide
            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                if(gamestate != GameStates::eGameOver && gamestate != GameStates::ePause)
                {
                    player->Tap_Down();
                    slide.play();
                    Player_Hp -= 0.01;
                    // cout << "down\n";
                }
            }

            /// load amour
            if (Keyboard::isKeyPressed(Keyboard::Tab))
            {
                if(gamestate != GameStates::eGameOver && gamestate != GameStates::ePause)
                {
                    amourload += 1;
                    AmourClock.restart();

                    if(amourload == 100)
                    {
                        isx2 = true;
                    }
                }
            }

            /// Pause & play
            if(event.key.code == Keyboard::Escape && gamestate != GameStates::ePause)
            {
                gamestate = GameStates::ePause;
            }

            if(gamestate == GameStates::ePause)
            {
                if(quit.getGlobalBounds().contains(Mouse::getPosition(this->Data->app).x,Mouse::getPosition(this->Data->app).y))
                {
                    quit.setFillColor(Color::Red);
                    if(Mouse::isButtonPressed(Mouse::Left))
                    {
                        Data->machine.AddState(StateRef(new GameOverState(Data,USERNAME,score)),true);
                    }
                }
                else
                {
                    quit.setFillColor(Color::White);
                }

                if(play.getGlobalBounds().contains(Mouse::getPosition(this->Data->app).x,Mouse::getPosition(this->Data->app).y))
                {
                    play.setFillColor(Color::Red);
                    if(Mouse::isButtonPressed(Mouse::Left))
                    {
                        gamestate = GameStates::ePlaying;
                    }
                }
                else
                {
                    play.setFillColor(Color::White);
                }
            }

            if(gamestate == GameStates::ePlaying)
            {
                if(pausebutton.getGlobalBounds().contains(Mouse::getPosition(this->Data->app).x,Mouse::getPosition(this->Data->app).y))
                {
                    if(Mouse::isButtonPressed(Mouse::Left))
                    {
                        gamestate = GameStates::ePause;
                    }
                }
            }

            if (gamestate == GameStates::ePlaying)
            {
                /// shoot

                if (event.type == Event::KeyPressed)
                {
                    if (event.key.code == Keyboard::Space)
                    {
                        if(ShootABLE)
                        {
                            shoot.play();
                            bullet->Spawn(player->GetSprite().getPosition().x + 30,player->GetSprite().getPosition().y + 100);
                            bulletActive.push_back(true);
                            CoolDownBullet.restart();
                            ShootABLE = false;
                        }
                    }
                }
            }
		}
	}

	void GameState::Update(float dt)
	{

	    vector<Sprite> barrierupsprites = barrierup->GetSprites();
        vector<Sprite> thornsprites = thorn->GetSprites();
        vector<Sprite> enemyLV1sprites = enemyLV1->GetSprites();
        vector<Sprite> enemyLV2sprites = enemyLV2->GetSprites();
        vector<Sprite> playerbulletsprites = bullet->GetSprites();
        vector<Sprite> thornbulletsprites = attackthorn->GetSprites();
        vector<Sprite> hpsprites = hp->GetSprites();

	    if(gamestate != GameStates::eGameOver && gamestate != GameStates::ePause)
	    {
	        floor->MoveFloor(dt);
	        player->Animate(dt);
	        enemyLV1->Move(dt);
            enemyLV2->Move(dt);
            hp->MoveHp(dt);
	    }

	    if(gamestate == GameStates::ePlaying)
        {
            barrierup->MoveBarriersUp(dt);
            thorn->MoveThorn(dt);

            if(level1 < 15 || level2 < 20)
            {
                // SPAWNING BARRIER UP
                if(BarrierUpClock.getElapsedTime().asSeconds() > BARRIERUP_SPAWNING_FREQ)
                {
                    if(barrierupsprites.size() < 2)
                    {
                        barrierup->SpawnBarriersUp();
                    }
                    BarrierUpClock.restart();
                }


                // SPAWNING THORN
                if(ThornClock.getElapsedTime().asSeconds() > THORN_SPAWNING_FREQ && !barrierup->isSpawn() )
                {
                    thorn->SpawnThorn();
                    ThornClock.restart();
                }
            }

            // SCORING PER DISRANCE
            if(ScoringClock.getElapsedTime().asSeconds()>SCORING_FREQ)
            {
                amourload -= 0.1;
                Player_Hp -= 0.1;

                ScoringClock.restart();
                score += (5 * (isx2 + 1));
            }
        }

        if(gamestate != GameStates::eGameOver && gamestate != GameStates::ePause)
        {
            // SPAWNING ENEMY LEVEL 1
            if(EnemyLevel1Clock.getElapsedTime().asSeconds() > ENEMY_1_SPAWNING_FREQ && spawnLevel1)
            {
                enemyLV1->Spawn();
                LV1Hp.push_back(LV1_HP);
                EnemyLevel1Alive.push_back(true);
                EnemyLevel1Clock.restart();
            }

            // SPAWNING ENEMY LEVEL 2
            if(EnemyLevel2Clock.getElapsedTime().asSeconds() > ENEMY_2_SPAWNING_FREQ && spawnLevel2)
            {
                if(LV2Hp.size() < 3)
                {
                    enemyLV2->Spawn();
                    LV2Hp.push_back(LV2_HP);
                    EnemyLevel2Alive.push_back(true);
                }
                EnemyLevel2Clock.restart();
            }

            // MOTION IN BG

            int spawnRock = rand() % 25;

            if(spawnRock == 4)
            {
                // small rock
                rock = new Rock();

                Animation sRock_small(smallrock,0,0,64,64,16,0.2);

                int x = rand()%3;

                if( x == 0 )
                {
                    rock->settings(sRock_small,0,rand()%(HEIGHT),rand()%360,15);
                }
                else
                {
                    x = rand()%WIDTH;
                    rock->settings(sRock_small,x,0,rand()%360,15);
                }
                entities.push_back(rock);
            }


            for(auto i=entities.begin();i!=entities.end();)
            {
                Entity *e = *i;

                e->update();
                e->anim.update();

                if (e->life==false)
                {
                    i=entities.erase(i);
                    delete e;
                }
                else
                {
                    i++;
                }
            }
        }

        // PLAYER UPDATE
        if(amourload < 0)
        {
            amourload = 0;
        }

        if(amourload > 100)
        {
            amourload = 100;
        }

        player->Update(dt,Player_Hp,amourload);

        // collision with barrier up

        for(unsigned int i=0;i<barrierupsprites.size();i++)
        {
            int count = 0;

            if(collision.CheckSpriteCollision(player->GetSprite(),PLAYER_SCALE,barrierupsprites.at(i),BARRIERUP_SCALE))
            {
                count ++;

                if(count == 1)
                {
                    hit.play();
                }
                Player_Hp -= 0.5;
                amourload -= 1;
                // << "hit barrier" << endl;
                //// << Player_Hp << endl;
                BarrierUpClock.restart();
            }
        }

        // collision with thorn

        for(unsigned int j=0;j<thornsprites.size();j++)
        {
            int count = 0;

            if(collision.CheckSpriteCollision(player->GetSprite(),PLAYER_SCALE,thornsprites.at(j),THORN_SCALE))
            {
                count ++;

                if(count == 1)
                {
                    hit.play();
                }

                Player_Hp -= 0.5;
                amourload -= 1;
                // << "hit thorn" << endl;
                //// << Player_Hp << endl;
                ThornClock.restart();
            }
        }

        // ENEMY

        //// LV1
        LV1Hp = enemyLV1->Hp;

        for(unsigned int j=0;j<enemyLV1sprites.size();j++)
        {
            int count = 0;

            if(collision.CheckSpriteCollision(player->GetSprite(),PLAYER_SCALE,enemyLV1sprites.at(j),ENEMY_1_SCALE) && LV1Hp.at(j) > 0)
            {
                count ++;

                if(count == 1)
                {
                    hit.play();
                }

                Player_Hp -= 0.5;
                amourload -= 1;
                // << "hit enemy 1" << endl;
                //// << Player_Hp << endl;
                EnemyLevel1Clock.restart();
            }

            for(unsigned int i=0;i<playerbulletsprites.size();i++)
            {
                int count = 0;
                if(collision.CheckSpriteCollision(playerbulletsprites.at(i),PINK_POWER_SCALE,enemyLV1sprites.at(j),ENEMY_1_SCALE))
                {
                    slide.play();

                    bulletActive.at(i) = false;
                    hit.play();
                    LV1Hp.at(j) -= 67;

                    if(LV1Hp.at(j) <= 0)
                    {
                        roar.play();
                        level1 ++;
                        // << "LEVEL 1 : "  << level1 << endl;
                    }

                    score += 20;
                    //// << "get point :: enemy" << endl;
                    EnemyLevel1Clock.restart();
                }
            }

            if(enemyLV1sprites.at(j).getPosition().x <= 0)
            {
                // << "lose 100" << endl;
                score -= 10;
            }
        }

        //// LV 2
        LV2Hp = enemyLV2->Hp;

        for(unsigned int j=0;j<enemyLV2sprites.size();j++)
        {
            int count = 0;
            if(collision.CheckSpriteCollision(player->GetSprite(),PLAYER_SCALE,enemyLV2sprites.at(j),ENEMY_2_SCALE) && LV2Hp.at(j) > 0)
            {
                count ++;

                if(count == 1)
                {
                    hit.play();
                }

                Player_Hp -= 1;
                amourload -= 1;
                // << "hit enemy 2" << endl;
                //// << Player_Hp << endl;
                EnemyLevel1Clock.restart();
            }

            for(unsigned int i=0;i<playerbulletsprites.size();i++)
            {
                int count = 0;
                if(collision.CheckSpriteCollision(playerbulletsprites.at(i),PINK_POWER_SCALE,enemyLV2sprites.at(j),ENEMY_2_SCALE))
                {
                    bulletActive.at(i) = false;
                    LV2Hp.at(j) -= 60;

                    slide.play();

                    if(LV2Hp.at(j) <= 0)
                    {
                        roar.play();
                        level2 ++;
                        // << "LEVEL 2 : "  << level2 << endl;
                    }

                    score += 40;
                    //// << "get point :: enemy" << endl;
                    EnemyLevel2Clock.restart();
                }
            }

            if(enemyLV2sprites.at(j).getPosition().x <= 0)
            {
                // << "lose 150" << endl;
                score -= 20;
            }
        }

        for(unsigned int j=0;j<thornbulletsprites.size();j++)
        {
            int count =0;
            if(collision.CheckSpriteCollision(player->GetSprite(),PLAYER_SCALE,thornbulletsprites.at(j),THORN_BULLET_SCALE))
            {
                slide.play();

                Player_Hp -= 2;
                amourload -= 1;
                thornbulletActive.at(j) = false;
            }
        }

        isThornActive = thorn->isActive;
        thornbulletActive = attackthorn->Active;

        for(unsigned int j=0;j<thornsprites.size();j++)
        {
            for(unsigned int i=0;i<playerbulletsprites.size();i++)
            {

                if(collision.CheckSpriteCollision(playerbulletsprites.at(i),PINK_POWER_SCALE,thornsprites.at(j),THORN_SCALE))
                {
                    bulletActive.at(i) = false;
                    score += 10;

                    int shootback;

                    // shoot back
                    for(unsigned int k=0;k<barrierupsprites.size();k++)
                    {
                        if(encounter.CheckSpriteEncounter(barrierupsprites.at(k),thornsprites.at(j),100))
                        {
                            shootback = 0;
                            // << "shoot back" << endl;
                        }
                    }

                    if(thornsprites.at(j).getPosition().x >= 100)
                    {
                        shootback = rand() % 2;
                    }

                    if(shootback)
                    {
                        attackthorn->Spawn(thornsprites.at(j).getPosition().x,thornsprites.at(j).getPosition().y);
                        thornbulletActive.push_back(true);
                    }

                    Player_Hp -= 2;
                    // << "get point :: thorn" << endl;
                    isThornActive.at(j) = false;
                    ThornClock.restart();
                }
            }
        }

        /// BULLET VS ENEMY

        if(gamestate != GameStates::eGameOver && gamestate != GameStates::ePause)
        {
            // cool down
            if(CoolDownBullet.getElapsedTime().asSeconds() > BULLET_COOLDOWN && playerbulletsprites.size() <= 9)
            {
                CoolDownBullet.restart();
                ShootABLE = true;
            }

            bullet->Move(dt);
            attackthorn->Move(dt);
        }

        for(unsigned int i=0;i<playerbulletsprites.size();i++)
        {
            for(unsigned int j=0;j<thornbulletsprites.size();j++)
            {
                if(collision.CheckSpriteCollision(playerbulletsprites.at(i),PINK_POWER_SCALE,thornbulletsprites.at(j),THORN_BULLET_SCALE))
                {
                     bulletActive.at(i) = false;
                     thornbulletActive.at(j) = false;
                }
            }
        }

        // collision

        bullet->Update(bulletActive);
        attackthorn->Update(thornbulletActive);
        enemyLV1->Update(LV1Hp);
        enemyLV2->Update(LV2Hp);
        thorn->UpdateThorn(isThornActive);
        hp->UpdateHp(isHpActive);

        bulletActive = bullet->Active;

        for(unsigned int j=0;j<bulletActive.size();j++)
        {
            if(!bulletActive.at(j))
            {
                bulletActive.erase(bulletActive.begin()+j);
            }
        }


        for(unsigned int i=0;i<hpsprites.size();i++)
        {
            if(collision.CheckSpriteCollision(player->GetSprite(),PLAYER_SCALE,hpsprites.at(i),BARRIERUP_SCALE))
            {
                Player_Hp += DROP_HP;
                // << "get hp" << endl;
                //// << Player_Hp << endl;
                collect.play();
                isHpActive.at(i) = false;
            }
        }

        if(level1 >= ENDSTAGE)
        {
            spawnLevel1 = false;
            spawnLevel2 = true;
        }

        if(level2 >= 20)
        {
            spawnLevel2 = false;
            gamestate = GameStates::ewin;

            if (clock.getElapsedTime().asSeconds() > 3)
            {
                // Switch Page
                winning.play();
                Data->machine.AddState(StateRef(new WinnerState(Data,USERNAME,score)),true);
            }
        }

        if(level1 >=15 && drop_1)
        {
            // << "drop" << endl;

            hp->SpawnHp(WIDTH);
            isHpActive.push_back(true);

            drop_1 = false;
        }

        if(gamestate == GameStates::eGameOver)
        {
            flash->Show(dt);
        }

        if(Player_Hp >= PLAYER_HP)
        {
            Player_Hp = PLAYER_HP;
        }

        if(amourload <= 0)
        {
            amourload = 0;
        }

        if(score <= 0)
        {
            score = 0;
        }

        HUD->UpdateScore(score);
	}

	void GameState::Draw(float dt)
	{
		if(gamestate != GameStates::ePause) this->Data->app.clear();

		this->Data->app.draw(background);

		for(auto i:entities)
        {
            i->draw(this->Data->app);
        }

		this->Data->app.draw(pausebutton);

		floor->DrawFloor();

		bullet->Draw();
		player->DrawPlayer();

		barrierup->DrawBarriersUp();
		attackthorn->Draw();
		thorn->DrawThorn();
        enemyLV1->Draw();
        enemyLV2->Draw();
        hp->DrawHp();

        flash->Draw();
        HUD->ShowScore();

        if(Player_Hp <= 0)
        {
            Player_Hp = 0;
            gameover.play();
            gamestate = GameStates::eGameOver;
            Data->machine.AddState(StateRef(new GameOverState(Data,USERNAME,score)),true);
        }

        if(gamestate == GameStates::ePause)
        {
            Data->app.draw(pausebackground);
            Data->app.draw(princess);
            Data->app.draw(andthe);
            Data->app.draw(dystopia);
            Data->app.draw(play);
            Data->app.draw(quit);
        }

		//// << score << endl;

		//cout << level1 << " " << level2 << endl;

		this->Data->app.display();
	}
}
