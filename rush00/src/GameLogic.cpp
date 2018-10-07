#include "GameLogic.hpp"

GameLogic::GameLogic()
{
	this->spawnTime = clock();
	return ;
}

GameLogic::GameLogic(GameLogic const &gl)
{
	*this = gl;
	return ;
}

GameLogic &GameLogic::operator=(GameLogic const &gl)
{
	if (this != &gl)
	{
		this->_ch = gl._ch;
		this->_pShip = gl._pShip;
		this->_score = gl._score;
		this->_win = gl._win;
		this->_gScore = gl._gScore;
	}
	return (*this);
}

void	GameLogic::gameStart()
{
	this->_pShip = new SpaceShip(PLAYER_SHIP);
	this->_gScore = new GameScore();
	Bullet *bullet = NULL;
	SpaceShip *enemy = NULL;
	int sec = 0;
	time_t start = time(0);
	this->toEnemyMoveStart = clock();

	initscr();
	
	cbreak();
	curs_set(0);
	noecho();
	
	this->_win = newwin(WIN_WIDTH, WIN_HEIGHT, 2, 0);
	refresh();
	this->_score = newwin(3, WIN_HEIGHT, 0, 0);
	refresh();
	nodelay(stdscr, TRUE);
	while (true)
	{
		sec = difftime(time(0), start);
		if ((sec % 10) == 0 && sec != 0)
		{
			this->_gScore->setGameScore(this->_gScore->getGameScore() + 1);
		}
		werase(this->_win);
		this->_gScore->displayGameScore(sec, this->_score, *(this->_pShip));
		box(this->_win, 0, 0);
		keypad(this->_win, true);

		/*
		** Key Manipulating
		*/

		if ((this->_ch  = getch()) != ERR)
		{
			if (this->_ch == KEY_Q)
			{
				delete bullet;
				endwin();
				return ;
			}
			if (this->_ch == KEY_A)
			{
				this->_pShip->setPosition(-1, 0);
			}
			if (this->_ch == KEY_D)
			{
				this->_pShip->setPosition(1, 0);
			}
			if (this->_ch == KEY_W)
			{
				this->_pShip->setPosition(0, -1);
			}
			if (this->_ch == KEY_S)
			{
				this->_pShip->setPosition(0, 1);
			}
			if (this->_ch == KEY_SPACE)
			{
				if (!this->_pShip->bul)
					this->_pShip->bul = this->_pShip->createBullet();
			}
		}

		/*
		** Spawn enemy
		*/

		size_t toSpawn = clock();
		if (toSpawn - this->spawnTime > 150000)
		{
			this->spawnTime = toSpawn;
			if (enemy == NULL){
				enemy = this->enemySpawn();
			}
			else{
				SpaceShip *temp_enemy = enemy;
				enemy = this->enemySpawn();
				enemy->nextS = temp_enemy;
				temp_enemy->prevS = enemy;
				enemy->prevS = NULL;
			}
		}

	
		
		/*
		** Player Ship collision
		*/
		SpaceShip *enemyToCollide = enemy;
		
		while (enemyToCollide)
		{
			SpaceShip *tmp = enemyToCollide;
			if (((this->_pShip->getCol() == enemyToCollide->getCol()) && (this->_pShip->getRow() == enemyToCollide->getRow())))
			{
				if (enemyToCollide->prevS)
				{
					enemyToCollide = enemyToCollide->prevS;
					enemyToCollide->nextS = tmp->nextS;
					delete tmp;
				}
				if (this->_pShip->getLives() > 0)
				{
					this->_pShip->setLives(this->_pShip->getLives() - 1);
				}
				else
				{
					endwin();
					std::cout << "You are dead! Your Score: " << this->_gScore->getGameScore() << std::endl;
					return ;
				}
			}
			if (((this->_pShip->getCol() == enemyToCollide->bul->getCol()) && (this->_pShip->getRow() == enemyToCollide->bul->getRow())))
			{
				enemyToCollide->bul->setCol(enemyToCollide->getCol());
				enemyToCollide->bul->setRow(enemyToCollide->getRow() - 1);
				if (this->_pShip->getLives() > 0)
				{
					this->_pShip->setLives(this->_pShip->getLives() - 1);
				}
				else
				{
					endwin();
					std::cout << "You are dead!  Your Score: " << this->_gScore->getGameScore() << std::endl;
					return ;
				}
			}
			if (enemyToCollide)
			{
				enemyToCollide = enemyToCollide->nextS;
			}
			else{
				break;
			}
		}

		/*
		** Enemy Move and enemy bullets
		*/

		SpaceShip *enemyPoint = enemy;
		size_t enemyMoveEnd = clock();
		while (enemyPoint)
		{
			if (enemyPoint->getCol() < MIN_X + 2)
			{
				if (enemyPoint->prevS)
					enemyPoint->prevS->nextS = enemyPoint->nextS;
				enemyPoint = NULL;
				continue ;
			}
			mvwaddch(this->_win, enemyPoint->getRow(), enemyPoint->getCol(), enemyPoint->getSymb());
			this->enemyShipMove(enemyPoint, enemyMoveEnd);
			mvwaddch(this->_win, enemyPoint->bul->getRow(), enemyPoint->bul->getCol(), enemyPoint->bul->getSymb());
			enemyPoint->bul->move();
			if (enemyPoint->bul->getCol() < MIN_X + 2)
			{
				enemyPoint->bul->setCol(enemyPoint->getCol());
				enemyPoint->bul->setRow(enemyPoint->getRow());
			}
			enemyPoint = enemyPoint->nextS;
		}
		if (enemyMoveEnd - this->toEnemyMoveStart > 30000)
		{
			this->toEnemyMoveStart = enemyMoveEnd;
		}
		
		/*
		** check collision bullets and enemy
		*/
		enemyToCollide = enemy;
		if (this->_pShip->bul)
		{
			while (enemyToCollide)
			{
				if (((this->_pShip->bul->getCol() == enemyToCollide->getCol()) && (this->_pShip->bul->getRow() == enemyToCollide->getRow())))
				{
					this->_gScore->setGameScore(this->_gScore->getGameScore() + 200);
				}else if (((this->_pShip->bul->getCol() == enemyToCollide->bul->getCol()) && (this->_pShip->bul->getRow() == enemyToCollide->bul->getRow())))
				{
					enemyToCollide->bul->setCol(enemyToCollide->getCol());
					enemyToCollide->bul->setRow(enemyToCollide->getRow() - 1);
					this->_gScore->setGameScore(this->_gScore->getGameScore() + 50);
				}
				if (enemyToCollide)
				{
					enemyToCollide = enemyToCollide->nextS;
				}
				else{
					break;
				}
			}
		}

		/*
		** player bullets move
		*/
	
		if (this->_pShip->bul)
		{
			mvwaddch(this->_win, this->_pShip->bul->getRow(), this->_pShip->bul->getCol(), this->_pShip->bul->getSymb());
			this->_pShip->bul->move();
			if (this->_pShip->bul->getCol() > MAX_X - 2)
			{
				if (this->_pShip->bul)
					this->_pShip->bul = NULL;
			}
		}
		mvwaddch(this->_win, this->_pShip->getRow(), this->_pShip->getCol(), this->_pShip->getSymb());
		wrefresh(this->_win);
		wrefresh(this->_score);
		usleep(1000);
	}         
    endwin();
}

SpaceShip *GameLogic::enemySpawn()
{
	SpaceShip *ship = new SpaceShip();
	ship->bul = new Bullet(ship->getCol(), ship->getRow(), ship->getType());
	return ship;
}

GameLogic::~GameLogic()
{
	return ;
}

void	GameLogic::enemyShipMove(SpaceShip *enemy, size_t enemyMoveEnd)
{
	int		i;

	if (enemyMoveEnd - this->toEnemyMoveStart > 30000)
	{
		srand(clock());
		i = rand() % 5;
		if (i == 0)
			enemy->setPosition(-1, 0);
		else if (i == 1)
			enemy->setPosition(-1, 1);
		else if (i == 2)
			enemy->setPosition(-1, 1);
		else if (i == 3)
			enemy->setPosition(-1, -1);
		else if (i == 4)
			enemy->setPosition(-1, -1);
	}
}
